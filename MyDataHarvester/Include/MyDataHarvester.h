#pragma once
#include <Windows.h>
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <math.h>
#include <SimConnect.h>

enum EVENT_ID {
    START_CLIENT_APPLICATION,
    STOP_CLIENT_APPLICATION,
    DISPLAYING_TEXT
};

enum REQUEST_ID
{
    USER_OBJECT_DATA,
};

enum DEFINITION_ID
{
    USER_OBJECT_DEF,
};

struct ObjectData
{
    char    szTitle[256];
    double  dAbsoluteTime;
    double  dTime;
    int     uDayOfTheYear;
    int     uYear;
    int     uMonthOfTheYear;
    int     uDayOfTheMonth;
    int     uDayOfTheWeek;
    int     uTimeZoneOffset;
    double  dSimTime;
    double  dLatitude;
    double  dLongitude;
    double  dAltitude;
    double  dPitch;
    double  dBank;
    double  dHeading;
    double  dVelocityX;
    double  dVelocityY;
    double  dVelocityZ;
    double  dTemperature;
    double  dAirPressure;
    double  dAirDensity;
    double  dWindVelocity;
    double  dWindDirection;
    double  dWindX;
    double  dWindY;
    double  dWindZ;
};

struct PropertyDefinition
{
    const char* pszName;
    const char* pszUnits;
    SIMCONNECT_DATATYPE eDataType;
};

const PropertyDefinition g_aVariables[] =
{
    { "TITLE",                      NULL,                   SIMCONNECT_DATATYPE_STRING256   },
    { "ABSOLUTE TIME",              "Seconds",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "ZULU TIME",                  "Seconds",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "ZULU DAY OF YEAR",           "Number",               SIMCONNECT_DATATYPE_INT32       },
    { "ZULU YEAR",                  "Number",               SIMCONNECT_DATATYPE_INT32       },
    { "ZULU MONTH OF YEAR",         "Number",               SIMCONNECT_DATATYPE_INT32       },
    { "ZULU DAY OF MONTH",          "Number",               SIMCONNECT_DATATYPE_INT32       },
    { "ZULU DAY OF WEEK",           "Number",               SIMCONNECT_DATATYPE_INT32       },
    { "TIME ZONE OFFSET",           "Hours",                SIMCONNECT_DATATYPE_INT32       },
    { "SIM TIME",                   "Seconds",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE LATITUDE",             "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE LONGITUDE",            "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE ALTITUDE",             "Feet",                 SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE PITCH DEGREES",        "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE BANK DEGREES",         "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE HEADING DEGREES TRUE", "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "VELOCITY WORLD X",           "Feet per second",      SIMCONNECT_DATATYPE_FLOAT64     },
    { "VELOCITY WORLD Y",           "Feet per second",      SIMCONNECT_DATATYPE_FLOAT64     },
    { "VELOCITY WORLD Z",           "Feet per second",      SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT TEMPERATURE",        "Celsius",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT PRESSURE",           "Millibars",            SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT DENSITY",            "Slugs per cubic feet", SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT WIND VELOCITY",      "Knots",                SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT WIND DIRECTION",     "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT WIND X",             "Meters per second",    SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT WIND Y",             "Meters per second",    SIMCONNECT_DATATYPE_FLOAT64     },
    { "AMBIENT WIND Z",             "Meters per second",    SIMCONNECT_DATATYPE_FLOAT64     },
};

/*const PropertyDefinition g_aVariables[] =
{
    { "TITLE",                      NULL,                   SIMCONNECT_DATATYPE_STRING256   },
    { "SIM ON GROUND", NULL, SIMCONNECT_DATATYPE_STRING32},
    { "PLANE ALTITUDE",             "Feet",                 SIMCONNECT_DATATYPE_FLOAT64     },
    { "PLANE HEADING DEGREES TRUE", "Degrees",              SIMCONNECT_DATATYPE_FLOAT64     },
    { "AIRSPEED TRUE" , "Knots", SIMCONNECT_DATATYPE_FLOAT64 },
    { "VERTICAL SPEED", "Feet per second", SIMCONNECT_DATATYPE_FLOAT64 },
    { "GPS ETA", "Seconds", SIMCONNECT_DATATYPE_FLOAT64},


};*/

class MyDataHarvester {
public:
    void ConnectToSim();
    MyDataHarvester();
};