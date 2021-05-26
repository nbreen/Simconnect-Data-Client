/*
** server.c -- a stream socket server demo
*/

#include "server.h"

void *receiveData(void* clientSocket) {
	char helloBuff[BUFF_SIZE];
	int result;
	int *sock = (int *)clientSocket;
	int client = *sock;
	char sizeBuff[4];
	int pktCounter = 0;
	pthread_t processingThread;

	//printf("Received client socket\n");

	result = recv(client, helloBuff, BUFF_SIZE - 1, 0);
	//printf("From client: %s\n", helloBuff);

	result = send(client, "Hello world from server", sizeof("Hello world from server"), 0);

	//printf("Result of send is %d\n", result);
	printf("Entering receive loop\n");

	while(1) {
		result = recv(client, sizeBuff, 4, MSG_PEEK);
		//printf("Receive is %d\n", result);
		if (result == -1) {
			printf("Error receiving data with byteSize\n");
			break;
		}else if (result == 0) {
			break;
		}

		if (result > 0) {
			int gpu = pktCounter % gpuCount;;
			//printf("First read byte count is %d\n", result);
			/* This isn't the most efficient as this 
			 * will run all the way through cuda     */
			readMessage(client, readHeader(sizeBuff), gpu);
			pktCounter++;
		}
	}

	printf("Client disconnected. Processed %d packets\n", pktCounter);
	return 0;
}

void sigchld_handler(int s)
{
	(void)s; // quiet unused variable warning

	// waitpid() might overwrite errno, so we save and restore it:
	int saved_errno = errno;

	while(waitpid(-1, NULL, WNOHANG) > 0);

	errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN];
	int rv;
	pthread_t clientThread;
	pthread_t apiThread;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	freeaddrinfo(servinfo); // all done with this structure

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		exit(1);
	}

	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	gpuCount = wrapperGetCudaDevCount();

    /*inet_ntop(p->ai_family, get_in_addr(p->ai_addr),
			s, sizeof(s));*/
	printf("Server listening with %d GPUs waiting for connections...\n", gpuCount);
	printf("Starting API.....\n");

	pthread_create(&apiThread, NULL, &startAPI, NULL);

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof(s));
		printf("server: got connection from %s\n", s);

		/* This way the receiver doesn't get bogged down with new sockets*/
		pthread_create(&clientThread, NULL, &receiveData, &new_fd);

	}

	pthread_join(clientThread, NULL);

	return 0;
}
