#include <string>
#include <malloc.h>
#include <iostream>
#include <math_constants.h>
#include <unistd.h>
#include <pthread.h>
#include "../Server/simconnectData.pb.h"

#define N 15 // This is one less than the fields in proto since we omit sztitle for processing
#define cudaSuccess(result) {gpuAssert((result), __FILE__, __LINE__);}
inline void gpuAssert(cudaError_t err, const char *file, int line, bool abort=true) {
    if (err != cudaSuccess) {
        fprintf(stderr, "GPU Assert Error: %s %s %d\n", cudaGetErrorString(err), file, line);
        if (abort) {
            exit(err);
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

typedef struct hTime {
    int hour;
    int min;
    int sec;
} hTime_t;

typedef struct absoluteTime {
    int year;
    int month;
    int day;
    int hour;
    int min;
    double sec;
} absoluteTime_t;

typedef struct processedData {
    absoluteTime_t *absTime;
    hTime_t *zulu;
    bool onGround;
    int altitude;
    int heading;
    int speed;
    int verticalSpeed;
    hTime_t *gpsEta;
    double lat;
    double longi;
    hTime_t *simulationTime;
    double temp;
    double pressure;
    int windVelo;
    int windDir;
} processedData_t;

typedef struct threadParams {
    int GPU;
} threadParams_t;

typedef struct gpuThread {
    pthread_t threadID;
    threadParams_t *gpuParams;
} gpuThread_t;

void cudaProcess(simConnect::simData);