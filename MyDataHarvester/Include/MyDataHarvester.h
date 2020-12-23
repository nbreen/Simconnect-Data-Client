#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#pragma once
#include <Windows.h>
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <math.h>
#include <SimConnect.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"ws2_32")

#define BUFF_LEN 512
#define HDR_SZ 4

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

struct PropertyDefinition {
    const char* pszName;
    const char* pszUnits;
    SIMCONNECT_DATATYPE eDataType;
};

struct ObjectData {
    char   szTitle[256];
    double dAbsoluteTime;
    double dTime;
    double uSimOnGround;
    double dAltitude;
    double dHeading;
    double dSpeed;
    double dVerticalSpeed;
    double dGpsEta;
    double dLatitude;
    double dLongitude;
    double dSimTime;
    double dTemperature;
    double dPressure;
    double dWindVelocity;
    double dWindDirection;
};

const PropertyDefinition g_aVariables[] = {
    { "TITLE",                          NULL,                   SIMCONNECT_DATATYPE_STRING256 },
    { "ABSOLUTE TIME",                  "Seconds",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "ZULU TIME",                      "Seconds",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "SIM ON GROUND",                  "Bool",                 SIMCONNECT_DATATYPE_FLOAT64   },
    { "PLANE ALTITUDE",                 "Feet",                 SIMCONNECT_DATATYPE_FLOAT64   },
    { "PLANE HEADING DEGREES MAGNETIC", "Radians",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "AIRSPEED TRUE",                  "Knots",                SIMCONNECT_DATATYPE_FLOAT64   },
    { "VERTICAL SPEED",                 "Feet per second",      SIMCONNECT_DATATYPE_FLOAT64   },
    { "GPS ETA",                        "Seconds",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "PLANE LATITUDE",                 "Degrees",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "PLANE LONGITUDE",                "Degrees",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "SIM TIME",                       "Seconds",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "AMBIENT TEMPERATURE",            "Celsius",              SIMCONNECT_DATATYPE_FLOAT64   },
    { "AMBIENT PRESSURE",               "Millibars",            SIMCONNECT_DATATYPE_FLOAT64   },
    { "AMBIENT WIND VELOCITY",          "Feet Per Second",      SIMCONNECT_DATATYPE_FLOAT64   },
    { "AMBIENT WIND DIRECTION",         "Degrees",              SIMCONNECT_DATATYPE_FLOAT64   },
};

bool ConnectToSim(SOCKET);
DWORD WINAPI simConnectDispatch(LPVOID);