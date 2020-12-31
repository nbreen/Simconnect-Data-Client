CXX = /usr/bin/g++
CXXFLAGS = -g -c
PKGFLAGS = `pkg-config --cflags --libs protobuf`
CPROTO = protoc
PROTOFLAGS = -I=$(PROTODIR) --cpp_out=.
PROTODIR = ../Proto
VSINCLUDEPATH = ../MyDataHarvester/Include
VSSRCPATH = ../MyDataHarvester/MyDataHarvester
CCUDA = nvcc
CCUDAFLAGS = -g -c -arch=sm_30 -std=c++11
CUDADIR = ../Cuda

all: server

proto: $(PROTODIR)/simconnectData.proto
	$(CPROTO) $(PROTOFLAGS) $(PROTODIR)/simconnectData.proto

cleanProto:
	rm simconnectData.pb.cc simconnectData.pb.h

basicServer: server.c
	$(CXX) $(CXXFLAGS) server.c -o basicServer.o

protoBuf: simconnectData.pb.cc
	$(CXX) $(CXXFLAGS) simconnectData.pb.cc -o simconnectProto.o

protoHelper: processProtobuff.cc
	$(CXX) $(CXXFLAGS) processProtobuff.cc -o processProtobuff.o

cudaProcess: $(CUDADIR)/cudaProcess.cu
	$(CCUDA) $(CCUDAFLAGS) $(CUDADIR)/cudaProcess.cu -o cudaProcess.o

server: basicServer protoBuf protoHelper cudaProcess
	$(CCUDA) -arch=sm_30 -o server basicServer.o simconnectProto.o processProtobuff.o cudaProcess.o -lprotobuf
	rm *.o
	
clean:
	rm server

