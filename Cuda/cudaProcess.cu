#include "cudaProcess.h"

__global__ void cudaHandle(double *toProcess) {
  toProcess[blockIdx.x] = toProcess[blockIdx.x];
}

double* toArray(simConnect::simData toConvert) {
  double *converted = (double *) malloc(sizeof(double) * N);
  converted[0] = toConvert.dabsolutetime();
  converted[1] = toConvert.dtime();
  converted[2] = toConvert.usimonground();
  converted[3] = toConvert.daltitude();
  converted[4] = toConvert.dheading();
  converted[5] = toConvert.dspeed();
  converted[6] = toConvert.dverticalspeed();
  converted[7] = toConvert.dgpseta();
  converted[8] = toConvert.dlatitude();
  converted[9] = toConvert.dlongitude();
  converted[10] = toConvert.dsimtime();
  converted[11] = toConvert.dtemperature();
  converted[12] = toConvert.dairpressure();
  converted[13] = toConvert.dwindvelocity();
  converted[14] = toConvert.dwinddirection();

  return converted;
}

void cudaProcess(simConnect::simData payload) {
  double *convertedData;
  double *d_convertedData;
  double *processedData;
  std::string  printString ("");
  int size = N * sizeof(double);
  FILE *output = fopen("out.txt", "a+");

  /* In order to process the data we first need it in an array for easier access */
  convertedData = toArray(payload);
  /* Make space for our processed data */
  processedData = (double *)malloc(size);
  /* Make space on GPU memory for our array */
  cudaMalloc((void **)&d_convertedData, size);
  /* Copy our array from host to device */
  cudaMemcpy(d_convertedData, convertedData, size, cudaMemcpyHostToDevice);
  /* Launch kernel on the GPU to process the data we just copied */
  cudaHandle<<<N,1>>>(d_convertedData);
  /* Copy our pocessed data back from device to host */
  cudaMemcpy(processedData, d_convertedData, size, cudaMemcpyDeviceToHost);
  /* Make sure any device jobs finish before we cleanup and exit */
  cudaDeviceSynchronize();

  fprintf(output, "Object sztitle: %s\n", payload.sztitle().c_str());
  for (int i = 0; i < N; i++ ) {
    double toPrint;

    switch(i) {
      case 0:
        toPrint = convertedData[i];
        printString = "Absolute time";
        break;
      case 1:
        toPrint = convertedData[i];
        printString = "Zulu Time";
        break;
      case 2:
        toPrint = convertedData[i];
        printString = "Sim On Ground";
        break;
      case 3:
        toPrint = convertedData[i];
        printString = "Altitude";
        break;
      case 4:
        toPrint = convertedData[i];
        printString = "Heading";
        break;
      case 5:
        toPrint = convertedData[i];
        printString = "Speed";
        break;
      case 6:
        toPrint = convertedData[i];
        printString = "Vertical Speed";
        break;
      case 7:
        toPrint = convertedData[i];
        printString = "GPS ETA";
        break;
      case 8:
        toPrint = convertedData[i];
        printString = "Latitude";
        break;
      case 9:
        toPrint = convertedData[i];
        printString = "Longitude";
        break;
      case 10:
        toPrint = convertedData[i];
        printString = "Sim time";
        break;
      case 11:
        toPrint = convertedData[i];
        printString = "Temperature";
        break;
      case 12:
        toPrint = convertedData[i];
        printString = "Air Pressure";
        break;
      case 13:
        toPrint = convertedData[i];
        printString = "Wind Velocity";
        break;
      case 14:
        toPrint = convertedData[i];
        printString = "Wind Direction";
        break;
    }
    fprintf(output, "Unprocessed %s %d: %f    ", printString.c_str(), i, toPrint);
    fprintf(output, "processedData %d: %f \n", i, processedData[i]);
  }

  /* Cleanup */
  fprintf(output, "\n\n");
  fclose(output);
  free(convertedData);
  free(processedData);
  cudaFree(d_convertedData);

}
