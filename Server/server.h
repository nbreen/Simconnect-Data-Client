#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#include "simconnectData.pb.h"
#include "processProtobuff.h"
#include "API.h"

#define PORT "5000"  // the port users will be connecting to
#define BACKLOG 10	 // how many pending connections queue will hold
#define BUFF_SIZE 512

int gpuCount = -1;

processedData_t newData;
std::mutex dataMutex;
std::string aircraftTitle;

extern int wrapperGetCudaDevCount();
extern void *startAPI(void*);