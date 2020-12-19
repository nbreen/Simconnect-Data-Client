#include <string>
#include <malloc.h>
#include <iostream>
#include "../Server/simconnectData.pb.h"

#define N 15 // This is one less than the fields in proto since we omit sztitle for processing

void cudaProcess(simConnect::simData);