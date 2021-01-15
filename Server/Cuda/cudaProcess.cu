#include "cudaProcess.h"

void logToFile(simConnect::simData payload, double *convertedData, processedData_t *processedData ) {
  FILE *output = fopen("out.txt", "a+");
  std::string  printString ("");
  
  fprintf(output, "Object sztitle: %s\n", payload.sztitle().c_str());
  
  for (int i = 0; i < N; i++ ) {
    switch(i) {
      case dAbsoluteTime:
        // processedData->absTime->year
        // processedData->absTime->month
        // processedData->absTime->day
        // processedData->absTime->hour
        // processedData->absTime->min
        printString = "Absolute time Unprocessed: " + 
                      std::to_string(convertedData[dAbsoluteTime]);
        printString.append( " Processed: ");
        printString += std::to_string(processedData->absTime->sec);
        printString.append(" Seconds");
        break;
      case dTime:
        printString = "Zulu Time Unprocessed: " +
                      std::to_string(convertedData[dTime]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->zulu->hour);
        printString.append(":");
        printString += std::to_string(processedData->zulu->min); 
        printString.append(":");
        printString += std::to_string(processedData->zulu->sec);
        break;
      case uSimOnGround: {
        std::string onG;

        if (processedData->onGround) {
          onG = "True";
        } else {
          onG = "False";
        }
        printString = "Sim On Ground Unprocessed: " + 
                      std::to_string(convertedData[uSimOnGround]);
        printString.append(" Processed: ");
        printString += onG;
        break;
      }
      case dAltitude:
        printString = "Altitude Unprocessed: " +
                      std::to_string(convertedData[dAltitude]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->altitude);
        printString.append(" Feet");
        break;
      case dHeading:
        printString = "Heading Unprocessed: " +
                      std::to_string(convertedData[dHeading]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->heading); 
        printString.append(" Degrees");
        break;
      case dSpeed:
        printString = "Speed  Unprocessed: " +
                      std::to_string(convertedData[dSpeed]);
        printString.append(" Processed: ");
        printString += std::to_string(processedData->speed); 
        printString.append(" Knots");
        break;
      case dVerticalSpeed:
        printString = "Vertical Speed Unprocessed: " +
                      std::to_string(convertedData[dVerticalSpeed]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->verticalSpeed); 
        printString.append(" Feet Per Minute");
        break;
      case dGpsEta:
        printString = "GPS ETA  Unprocessed: " +
                      std::to_string(convertedData[dGpsEta]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->gpsEta->hour);
        printString.append(":"); 
        printString += std::to_string(processedData->gpsEta->min);
        printString.append(":");
        printString +=std::to_string(processedData->gpsEta->sec);
        break;
      case dLatitude:
        printString = "Latitude Unprocessed: " +
                      std::to_string(convertedData[dLatitude]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->lat);
        printString.append(" Degrees");
        break;
      case dLongitude:
        printString = "Longitude Unprocessed: " +
                      std::to_string(convertedData[dLongitude]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->longi);
        printString.append(" Degrees");
        break;
      case dSimTime:
        printString = "Sim time  Unprocessed: " +
                      std::to_string(convertedData[dSimTime]); 
        printString.append(" Processed: ");
        printString += std::to_string(processedData->simulationTime->hour);
        printString.append(":"); 
        printString += std::to_string(processedData->simulationTime->min);
        printString.append(":");
        printString += std::to_string(processedData->simulationTime->sec);
        break;
      case dTemperature:
        printString = "Temperature Unprocessed: " +
                      std::to_string(convertedData[dTemperature]);
        printString.append(" Processed: ");
        printString += std::to_string(processedData->temp);
        printString.append(" Degrees Celsius");
        break;
      case dPressure:
        printString = "Air Pressure Unprocessed: " +
                      std::to_string(convertedData[dPressure]);
        printString.append(" Processed: ");
        printString += std::to_string(processedData->pressure);
        printString.append(" In Hg");
        break;
      case dWindVelocity:
        printString = "Wind Velocity Unprocessed: " +
                      std::to_string(convertedData[dWindVelocity]);
        printString.append(" Processed: ");
        printString += std::to_string(processedData->windVelo);
        printString.append(" Knots");
        break;
      case dWindDirection:
        printString = "Wind Direction Unprocessed: " +
                      std::to_string(convertedData[dWindDirection]);
        printString.append(" Processed: ");
        printString += std::to_string(processedData->windDir);
        printString.append(" Degrees");
        break;
    }

    fprintf(output, "%s\n", printString.c_str());
  }

  fprintf(output, "\n\n");
  fclose(output);
}

double *toArray(simConnect::simData toConvert) {
  double *convertedData = (double *)malloc(sizeof(double) * N);

  for (int i = 0; i < N; i++ ) {
    switch(i) {
      case dAbsoluteTime:
        convertedData[i] = toConvert.dabsolutetime();
        break;
      case dTime:
        convertedData[i] = toConvert.dtime();
        break;
      case uSimOnGround:
        convertedData[i] = toConvert.usimonground();
        break;
      case dAltitude:
        convertedData[i] = toConvert.daltitude();
        break;
      case dHeading:
        convertedData[i] = toConvert.dheading();
        break;
      case dSpeed:
        convertedData[i] = toConvert.dspeed();
        break;
      case dVerticalSpeed:
        convertedData[i] = toConvert.dverticalspeed();
        break;
      case dGpsEta:
        convertedData[i] = toConvert.dgpseta();
        break;
      case dLatitude:
        convertedData[i] = toConvert.dlatitude();
        break;
      case dLongitude:
        convertedData[i] = toConvert.dlongitude();
        break;
      case dSimTime:
        convertedData[i] = toConvert.dsimtime();
        break;
      case dTemperature:
        convertedData[i] = toConvert.dtemperature();
        break;
      case dPressure:
        convertedData[i] = toConvert.dairpressure();
        break;
      case dWindVelocity:
        convertedData[i] = toConvert.dwindvelocity();
        break;
      case dWindDirection:
        convertedData[i] = toConvert.dwinddirection();
        break;
    }
  }

  return convertedData;
}

__global__ void cudaHandle(processedData_t *processedData, double *toProcess) {
  /* Process each field differently */
  switch(blockIdx.x) {
    case dAbsoluteTime:
      /* Seconds since 12:00AM Jan. 1 0000 -> YYYY-MM-DD-HH-MM-SS */
      //processedData->absTime->year
      //processedData->absTime->month
      //processedData->absTime->day
      //processedData->absTime->hour
      //processedData->absTime->min
      processedData->absTime->sec = toProcess[dAbsoluteTime];
      
      break;
    case dTime:
      /* Seconds -> HH-MM-SS */
      processedData->zulu->hour = toProcess[dTime] / 3600;
      processedData->zulu->min = (toProcess[dTime] / 60) - (processedData->zulu->hour * 60) ;
      processedData->zulu->sec = toProcess[dTime] - 60 - (processedData->zulu->hour * 3600) - (processedData->zulu->min * 60) ;
      
      break;
    case uSimOnGround: {
      /* int -> bool */
      int onground = __double2int_rn(toProcess[uSimOnGround]);
      
      if (onground == 1) {
        processedData->onGround = true;
      } else {
        processedData->onGround = false;
      }
      
      break;
    }
    case dAltitude:
      /* feet -> rounded feet */
      processedData->altitude = __double2int_rn(toProcess[dAltitude]);
      break;
    case dHeading:
      /* Radians -> degrees */
      processedData->heading = __double2int_rn(toProcess[dHeading] * (180/CUDART_PI_F));
      break;
    case dSpeed:
      /* Knots -> rounded knots */
      processedData->speed = __double2int_rn(toProcess[dSpeed]);
      break;
    case dVerticalSpeed:
      /* Feet per Sec -> Feet Per Min */
      processedData->verticalSpeed = __double2int_rn(toProcess[dVerticalSpeed] * 60);
      break;
    case dGpsEta:
      /* Seconds -> HH-MM-SS */
      processedData->gpsEta->hour = toProcess[dGpsEta] / 3600;
      processedData->gpsEta->min = (toProcess[dGpsEta] / 60) - (processedData->gpsEta->hour * 60) ;
      processedData->gpsEta->sec = toProcess[dGpsEta] - 60 - (processedData->gpsEta->hour * 3600) - (processedData->gpsEta->min * 60) ;
      break;
    case dLatitude:
      /* Leaving identity for the moment */
      processedData->lat = toProcess[dLatitude];
      break;
    case dLongitude:
      /* Leaving identity for the moment */
      processedData->longi = toProcess[dLongitude];
      break;
    case dSimTime:
      /* Seconds -> HH-MM-SS */
      processedData->simulationTime->hour = toProcess[dSimTime] / 3600;
      processedData->simulationTime->min = (toProcess[dSimTime] / 60) - (processedData->simulationTime->hour * 60) ;
      processedData->simulationTime->sec = toProcess[dSimTime] - 60 - (processedData->simulationTime->hour * 3600) - (processedData->simulationTime->min * 60) ;
      break;
    case dTemperature:
      /* Celsius -> rounded to tenths Celsius */
      processedData->temp = toProcess[dTemperature];
      break;
    case dPressure:
      /* Millibars -> in Hg */
      processedData->pressure = toProcess[dPressure] / 33.864;
      break;
    case dWindVelocity:
      /* Feet per Second -> Knots  */
      processedData->windVelo = __double2int_rn(toProcess[dWindVelocity] / 1.688);
      break;
    case dWindDirection:
      /* Degrees -> rounded degrees */
      processedData->windDir = __double2int_rn(toProcess[dWindDirection]);
      break;
  }
}

void cudaProcess(simConnect::simData payload) {
  double *convertedData = toArray(payload);
  double *d_unprocessedData;
  processedData_t *d_processedData;
  absoluteTime_t *d_processedAbsolute;
  hTime_t *d_processedZulu;
  hTime_t *d_processedgpseta;
  hTime_t *d_processedsimulationTime;
  processedData_t  *processedData;
  int size = N * sizeof(double);

  /* Make space for our processed data */
  processedData = (processedData_t *) malloc(sizeof(processedData_t));
  processedData->absTime = (absoluteTime_t *) malloc(sizeof(absoluteTime_t));
  processedData->zulu = (hTime_t *) malloc(sizeof(hTime_t));
  processedData->gpsEta = (hTime_t *) malloc(sizeof(hTime_t));
  processedData->simulationTime = (hTime_t *) malloc(sizeof(hTime_t));
  /* Make space on GPU memory for our array */
  cudaSuccess(cudaMallocManaged((void **)&d_unprocessedData, size));
  /* Make space for processed data on the GPU */
  /* We use cudaMallocManaged so we can derefference 
     the pointers on host or device                 */
  cudaSuccess(cudaMallocManaged((void **)&d_processedData, sizeof(processedData_t)));
  cudaSuccess(cudaMallocManaged((void **)&d_processedAbsolute, sizeof(absoluteTime_t)));
  cudaSuccess(cudaMallocManaged((void **)&d_processedZulu, sizeof(hTime_t)));
  cudaSuccess(cudaMallocManaged((void **)&d_processedgpseta, sizeof(hTime_t)));
  cudaSuccess(cudaMallocManaged((void **)&d_processedsimulationTime, sizeof(hTime_t)));
  /* Assign pointers*/
  d_processedData->absTime = d_processedAbsolute;
  d_processedData->zulu = d_processedZulu;
  d_processedData->gpsEta = d_processedgpseta;
  d_processedData->simulationTime = d_processedsimulationTime;
  /* Copy our data from host to device */
  cudaSuccess(cudaMemcpy(d_unprocessedData, convertedData, size, cudaMemcpyHostToDevice));
  /* Launch kernel on the GPU to process the data we just copied */
  cudaHandle<<<N,1>>>(d_processedData ,d_unprocessedData);
  cudaSuccess(cudaGetLastError());
  /* Synchronize here so we're not touching managed memory */
  /* Make sure any device jobs finish before we cleanup and exit */
  cudaSuccess(cudaDeviceSynchronize());
  /* Log our processed object to file */
  logToFile(payload, convertedData, d_processedData); 
  /* Cleanup */
  free(processedData->absTime);
  free(processedData->zulu);
  free(processedData->gpsEta);
  free(processedData->simulationTime);
  free(processedData);
  free(convertedData);
  cudaSuccess(cudaFree(d_processedAbsolute));
  cudaSuccess(cudaFree(d_processedZulu));
  cudaSuccess(cudaFree(d_processedgpseta));
  cudaSuccess(cudaFree(d_processedsimulationTime));
  cudaSuccess(cudaFree(d_unprocessedData));
  cudaSuccess(cudaFree(d_processedData));
}

void cudaSchedule(int device, simConnect::simData payload) {
  cudaSuccess(cudaSetDevice(device));
  cudaProcess(payload);
}

int wrapperGetCudaDevCount() {
  int count = -1;
  cudaSuccess(cudaGetDeviceCount(&count));

  return count;
}