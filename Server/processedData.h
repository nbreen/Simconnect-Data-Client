#include <mutex>

#ifndef PROCESSED_DATA_H
#define PROCESSED_DATA_H
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
    hTime_t *gpsEta;
    hTime_t *simulationTime;
    double lat;
    double longi;
    double temp;
    double pressure;
    int altitude;
    int heading;
    int speed;
    int verticalSpeed;
    int windVelo;
    int windDir;
    bool onGround;
} processedData_t;



extern processedData_t newData;
extern std::mutex dataMutex;
extern std::string aircraftTitle;
#endif