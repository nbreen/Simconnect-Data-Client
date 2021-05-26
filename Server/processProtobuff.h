#include "simconnectData.pb.h"
#include "processedData.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <ostream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#define HDR_SZ 4

google::protobuf::uint64 readHeader(char *);
void readMessage(int ,google::protobuf::uint64, int);

extern processedData_t cudaSchedule(int, simConnect::simData);
extern int wrapperGetCudaDevCount();