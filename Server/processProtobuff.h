#include "simconnectData.pb.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <ostream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

typedef struct processingThreadParams {
	int clientSocket;
	int headerSize;
} processingParams_t;

google::protobuf::uint32 readHeader(char *);
void *processingWrapper(void* args);
void readMessage(int ,google::protobuf::uint32);