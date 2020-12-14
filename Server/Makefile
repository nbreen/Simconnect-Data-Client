CXX = g++
PROTODIR = ../Proto
VSINCLUDEPATH = ../MyDataHarvester/Include
VSSRCPATH = ../MyDataHarvester/MyDataHarvester
CPROTO = protoc
PROTOFLAGS = -I=$(PROTODIR) --cpp_out=.
CXXFLAGS = -g -c
PKGFLAGS = `pkg-config --cflags --libs protobuf`

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

server: basicServer protoBuf protoHelper
	$(CXX) -o server basicServer.o simconnectProto.o processProtobuff.o $(PKGFLAGS)

clean:
	rm *.o server

