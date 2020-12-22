#include <string>
#include <malloc.h>
#include <iostream>
#include "../Server/simconnectData.pb.h"

#define N 15 // This is one less than the fields in proto since we omit sztitle for processing

enum fieldName {
    dAbsoluteTime = 0,
    dTime = 1,
    uSimOnGround = 2,
    dAltitude = 3,
    dHeading = 4,
    dSpeed = 5,
    dVerticalSpeed = 6,
    dGpsEta = 7,
    dLatitude = 8,
    dLongitude = 9,
    dSimTime = 10,
    dTemperature = 11,
    dPressure = 12,
    dWindVelocity = 13,
    dWindDirection = 14,
};

void cudaProcess(simConnect::simData);