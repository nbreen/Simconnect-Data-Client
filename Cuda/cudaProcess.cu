#include "cudaProcess.h"

void logToFile(simConnect::simData payload, double *convertedData, double *processedData ) {
  FILE *output = fopen("out.txt", "a+");
  std::string  printString ("");
  
  fprintf(output, "Object sztitle: %s\n", payload.sztitle().c_str());
  
  for (int i = 0; i < N; i++ ) {
    double toPrint;

    switch(i) {
      case dAbsoluteTime:
        toPrint = convertedData[i];
        printString = "Absolute time";
        break;
      case dTime:
        toPrint = convertedData[i];
        printString = "Zulu Time";
        break;
      case uSimOnGround:
        toPrint = convertedData[i];
        printString = "Sim On Ground";
        break;
      case dAltitude:
        toPrint = convertedData[i];
        printString = "Altitude";
        break;
      case dHeading:
        toPrint = convertedData[i];
        printString = "Heading";
        break;
      case dSpeed:
        toPrint = convertedData[i];
        printString = "Speed";
        break;
      case dVerticalSpeed:
        toPrint = convertedData[i];
        printString = "Vertical Speed";
        break;
      case dGpsEta:
        toPrint = convertedData[i];
        printString = "GPS ETA";
        break;
      case dLatitude:
        toPrint = convertedData[i];
        printString = "Latitude";
        break;
      case dLongitude:
        toPrint = convertedData[i];
        printString = "Longitude";
        break;
      case dSimTime:
        toPrint = convertedData[i];
        printString = "Sim time";
        break;
      case dTemperature:
        toPrint = convertedData[i];
        printString = "Temperature";
        break;
      case dPressure:
        toPrint = convertedData[i];
        printString = "Air Pressure";
        break;
      case dWindVelocity:
        toPrint = convertedData[i];
        printString = "Wind Velocity";
        break;
      case dWindDirection:
        toPrint = convertedData[i];
        printString = "Wind Direction";
        break;
    }

    fprintf(output, "Unprocessed %s %d: %f    ", printString.c_str(), i, toPrint);
    fprintf(output, "processedData %d: %f \n", i, processedData[i]);
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

__global__ void cudaHandle(double * processedData, double *toProcess) {
  /* Process each field differently */
  switch(blockIdx.x) {
    case dAbsoluteTime:
      /* Seconds since 12:00AM Jan. 1 0000 -> YYYY-MM-DD-HH-MM-SS */
      
      processedData[dAbsoluteTime] = toProcess[dAbsoluteTime];
      break;
    case dTime:
      /* Seconds -> HH-MM-SS */
      processedData[dTime] = toProcess[dTime];
      break;
    case uSimOnGround:
      /* int -> bool */
      processedData[uSimOnGround] = toProcess[uSimOnGround];
      break;
    case dAltitude:
      /* feet -> rounded feet */
      processedData[dAltitude] = toProcess[dAltitude];
      break;
    case dHeading:
      /* Radians -> degrees */
      processedData[dHeading] = toProcess[dHeading];
      break;
    case dSpeed:
      /* Knots -> rounded knots */
      processedData[dSpeed] = toProcess[dSpeed];
      break;
    case dVerticalSpeed:
      /* Feet per Sec -> Feet Per Min */
      processedData[dVerticalSpeed] = toProcess[dVerticalSpeed];
      break;
    case dGpsEta:
      /* Seconds -> HH-MM-SS */
      processedData[dGpsEta] = toProcess[dGpsEta];
      break;
    case dLatitude:
      /* Leaving identity for the moment */
      processedData[dLatitude] = toProcess[dLatitude];
      break;
    case dLongitude:
      /* Leaving identity for the moment */
      processedData[dLongitude] = toProcess[dLongitude];
      break;
    case dSimTime:
      /* Seconds -> HH-MM-SS */
      processedData[dSimTime] = toProcess[dSimTime];
      break;
    case dTemperature:
      /* Celsius -> rounded to tenths Celsius */
      processedData[dTemperature] = toProcess[dTemperature];
      break;
    case dPressure:
      /* Millibars -> in Hg */
      processedData[dPressure] = toProcess[dPressure];
      break;
    case dWindVelocity:
      /* Feet per Second -> Knots  */
      processedData[dWindVelocity] = toProcess[dWindVelocity];
      break;
    case dWindDirection:
      /* Degrees -> rounded degrees */
      processedData[dWindDirection] = toProcess[dWindDirection];
      break;
  }
}

void cudaProcess(simConnect::simData payload) {
  double *convertedData = toArray(payload);
  double *d_unprocessedData;
  double *d_processedData;
  double *processedData;
  int size = N * sizeof(double);

  /* Make space for our processed data */
  processedData = (double *)malloc(size);
  /* Make space on GPU memory for our object */
  cudaMalloc((void **)&d_unprocessedData, size);
  /* Make space for processed data on the GPU */
  cudaMalloc((void **)&d_processedData, size);
  /* Copy our data from host to device */
  cudaMemcpy(d_unprocessedData, convertedData, size, cudaMemcpyHostToDevice);
  /* Launch kernel on the GPU to process the data we just copied */
  cudaHandle<<<N,1>>>(d_processedData ,d_unprocessedData);
  /* Copy our pocessed data back from device to host */
  cudaMemcpy(processedData, d_processedData, size, cudaMemcpyDeviceToHost);
  /* Make sure any device jobs finish before we cleanup and exit */
  cudaDeviceSynchronize();
  /* Log our processed object to file */
  logToFile(payload, convertedData, processedData);

  /* Cleanup */
  free(processedData);
  free(convertedData);
  cudaFree(d_processedData);
  cudaFree(d_unprocessedData);
}
