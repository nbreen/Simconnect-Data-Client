#include <string>

typedef struct SimData {
    size_t strSize;
    std::string  szTitle = {};
    double  dAbsoluteTime;
    double  dTime;
    double  usimOnGround;
    double  dAltitude;
    double  dHeading;
    double  dSpeed;
    double  dVerticalSpeed;
    double  dGpsEta;
    double  dLatitude;
    double  dLongitude;
    double  dSimTime;
    double  dTemperature;
    double  dAirPressure;
    double  dWindVelocity;
    double  dWindDirection;

    void Serialize(char* buff) {
        int buffIndex = 0;

        strSize = szTitle.length() + 1;
        memcpy(&buff[buffIndex], &strSize, sizeof(strSize));
        buffIndex += sizeof(strSize);
        memcpy(&buff[buffIndex], szTitle.c_str(), strSize);
        buffIndex += strSize;
        memcpy(&buff[buffIndex], &dAbsoluteTime, sizeof(dAbsoluteTime));
        buffIndex += sizeof(dAbsoluteTime);
        memcpy(&buff[buffIndex], &dTime, sizeof(dTime));
        buffIndex += sizeof(dTime);
        memcpy(&buff[buffIndex], &usimOnGround, sizeof(usimOnGround));
        buffIndex += sizeof(usimOnGround);
        memcpy(&buff[buffIndex], &dAltitude, sizeof(dAltitude));
        buffIndex += sizeof(dAltitude);
        memcpy(&buff[buffIndex], &dHeading, sizeof(dHeading));
        buffIndex += sizeof(dHeading);
        memcpy(&buff[buffIndex], &dSpeed, sizeof(dSpeed));
        buffIndex += sizeof(dSpeed);
        memcpy(&buff[buffIndex], &dVerticalSpeed, sizeof(dVerticalSpeed));
        buffIndex += sizeof(dVerticalSpeed);
        memcpy(&buff[buffIndex], &dGpsEta, sizeof(dGpsEta));
        buffIndex += sizeof(dGpsEta);
        memcpy(&buff[buffIndex], &dLatitude, sizeof(dLatitude));
        buffIndex += sizeof(dLatitude);
        memcpy(&buff[buffIndex], &dLongitude, sizeof(dLongitude));
        buffIndex += sizeof(dLongitude);
        memcpy(&buff[buffIndex], &dSimTime, sizeof(dSimTime));
        buffIndex += sizeof(dSimTime);
        memcpy(&buff[buffIndex], &dTemperature, sizeof(dTemperature));
        buffIndex += sizeof(dTemperature);
        memcpy(&buff[buffIndex], &dAirPressure, sizeof(dAirPressure));
        buffIndex += sizeof(dAirPressure);
        memcpy(&buff[buffIndex], &dWindVelocity, sizeof(dWindVelocity));
        buffIndex += sizeof(dWindVelocity);
        memcpy(&buff[buffIndex], &dWindDirection, sizeof(dWindDirection));
        buffIndex += sizeof(dWindDirection);
    }

    void Deserialize(char* buff) {
        int buffIndex = 0;
        
        memcpy(&strSize, &buff[buffIndex], sizeof(strSize));
        buffIndex += sizeof(strSize);
        szTitle.resize(strSize);
        memcpy(&szTitle[0], &buff[buffIndex], strSize);
        szTitle[strSize] = '\0';
        buffIndex += strSize;
        memcpy(&dAbsoluteTime, &buff[buffIndex], sizeof(dAbsoluteTime));
        buffIndex += sizeof(dAbsoluteTime);
        memcpy(&dTime, &buff[buffIndex], sizeof(dTime));
        buffIndex += sizeof(dTime);
        memcpy(&usimOnGround, &buff[buffIndex], sizeof(usimOnGround));
        buffIndex += sizeof(usimOnGround);
        memcpy(&dAltitude, &buff[buffIndex], sizeof(dAltitude));
        buffIndex += sizeof(dAltitude);
        memcpy(&dHeading, &buff[buffIndex], sizeof(dHeading));
        buffIndex += sizeof(dHeading);
        memcpy(&dSpeed, &buff[buffIndex], sizeof(dSpeed));
        buffIndex += sizeof(dSpeed);
        memcpy(&dVerticalSpeed, &buff[buffIndex], sizeof(dVerticalSpeed));
        buffIndex += sizeof(dVerticalSpeed);
        memcpy(&dGpsEta, &buff[buffIndex], sizeof(dGpsEta));
        buffIndex += sizeof(dGpsEta);
        memcpy(&dLatitude, &buff[buffIndex], sizeof(dLatitude));
        buffIndex += sizeof(dLatitude);
        memcpy(&dLongitude, &buff[buffIndex], sizeof(dLongitude));
        buffIndex += sizeof(dLongitude);
        memcpy(&dSimTime, &buff[buffIndex], sizeof(dSimTime));
        buffIndex += sizeof(dSimTime);
        memcpy(&dTemperature, &buff[buffIndex], sizeof(dTemperature));
        buffIndex += sizeof(dTemperature);
        memcpy(&dAirPressure, &buff[buffIndex], sizeof(dAirPressure));
        buffIndex += sizeof(dAirPressure);
        memcpy(&dWindVelocity, &buff[buffIndex], sizeof(dWindVelocity));
        buffIndex += sizeof(dWindVelocity);
        memcpy(&dWindDirection, &buff[buffIndex], sizeof(dWindDirection));
        buffIndex += sizeof(dWindDirection);
    }
} SimData_t;