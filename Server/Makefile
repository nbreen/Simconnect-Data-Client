CXX = /usr/bin/g++
CXXFLAGS = -g -c
PKGFLAGS = `pkg-config --cflags --libs protobuf`
CPROTO = protoc
PROTOFLAGS = -I=$(PROTODIR) --cpp_out=.
PROTODIR = ../Proto
CCUDA = nvcc
CCUDAFLAGS = -g -c -arch=sm_30 -std=c++11
CUDADIR = ./Cuda
BOOST_DIR = /usr/lib/x86_64-linux-gnu/cmake/Boost-1.71.0
API_DIR = ./API
CCBOOST = c++
CCBOOSTFLAGS = -I $(BOOST_DIR)
BOOST_LIBS = -lpthread -lboost_filesystem

all: server

api: $(API_DIR)/simDataAPI.cpp
	$(CCBOOST) $(CCBOOSTFLAGS) $(API_DIR)/simDataAPI.cpp $(BOOST_LIBS) -o simDataAPI

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

