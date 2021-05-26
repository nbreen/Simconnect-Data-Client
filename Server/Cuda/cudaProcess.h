#include <string>
#include <malloc.h>
#include <iostream>
#include <math_constants.h>
#include "../processedData.h"
#include "../simconnectData.pb.h"

#define N 15 // This is one less than the fields in proto since we omit sztitle for processing
#define cudaSuccess(result) {gpuAssert((result), __FILE__, __LINE__);}
inline void gpuAssert(cudaError_t err, const char *file, int line, bool abort=true) {
    if (err != cudaSuccess) {
        fprintf(stderr, "GPU Assert Error: %s %s %d\n", cudaGetErrorString(err), file, line);
        if (abort) {
            fprintf(stderr, "Would abort\n");
            //exit(err);
        }
    }
}

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

extern std::mutex dataMutex;
extern processedData_t newData;

processedData_t cudaSchedule(int, simConnect::simData);
int wrapperGetCudaDevCount();