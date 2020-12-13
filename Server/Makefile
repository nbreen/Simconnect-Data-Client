CC = gcc
CCFLAGS = -g -c -lpthread -lprotobuf
CXX = g++
CXXFLAGS = -g -c -std=c++11 -lprotobuf -std=c++11
CXXX = c++
CXXXFLAGS = -o
CXXXPKGFLAGS = `pkg-config --cflags --libs protobuf`

all: server

basicServer: server.c
	$(CXX) server.c $(CCFLAGS) -o basicServer.o

protoBuf: simconnectData.pb.cc
	c++ -c simconnectData.pb.cc -o simconnectProto.o $(CXXXPKGFLAGS)

protoHelper: processProtobuff.cc
	$(CXX) processProtobuff.cc $(CXXFLAGS) -o processProtobuff.o

server: basicServer protoBuf protoHelper
	$(CXXX) $(CXXXFLAGS) server basicServer.o simconnectProto.o processProtobuff.o $(CXXXPKGFLAGS)

clean:
	rm basicServer.o simconnectProto.o processProtobuff.o server

