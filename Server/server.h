#define PORT "5000"  // the port users will be connecting to
#define BACKLOG 10	 // how many pending connections queue will hold
#define BUFF_SIZE 512
int gpuCount = -1;

extern int wrapperGetCudaDevCount();