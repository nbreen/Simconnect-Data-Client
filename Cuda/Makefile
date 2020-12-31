CCUDA = nvcc
CCUDAFLAGS = -g -std=c++11 -arch=sm_30
CUDALIB = -lprotobuf -lpthread
PROTODIR = ../Server

all: perfTest

perfTest: cudaPerfTest.cu $(PROTODIR)/simconnectData.pb.cc
	$(CCUDA) $(CCUDAFLAGS) cudaPerfTest.cu $(PROTODIR)/simconnectData.pb.cc $(CUDALIB) -o perfTest

clean: 
	rm perfTest