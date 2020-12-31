CCUDA = nvcc
CCUDAFLAGS = -g -std=c++11 -arch=sm_30
CUDALIB = -lprotobuf -lpthread
PROTODIR = ../Server

all: perfTest cudaMod

perfTest: cudaPerfTest.cu $(PROTODIR)/simconnectData.pb.cc
	$(CCUDA) $(CCUDAFLAGS) cudaPerfTest.cu $(PROTODIR)/simconnectData.pb.cc $(CUDALIB) -o perfTest

cudaMod: cudaMod.cu $(PROTODIR)/simconnectData.pb.cc
	$(CCUDA) $(CCUDAFLAGS) cudaMod.cu $(PROTODIR)/simconnectData.pb.cc $(CUDALIB) -o cudaMod

clean: 
	rm perfTest cudaMod