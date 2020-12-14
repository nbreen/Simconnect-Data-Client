#include <string>
#include <malloc.h>
#include <iostream>
#include "../simconnectData.pb.h"

#define N 26

__global__ void cudaProcess(double *toProcess) {
  toProcess[blockIdx.x] = toProcess[blockIdx.x];
}

double* toArray(simConnect::simData toConvert) {
  double *converted = (double *) malloc(sizeof(double) * N);
  converted[0] = toConvert.dabsolutetime();
  converted[1] = toConvert.dtime();
  converted[2] = toConvert.udayoftheyear();
  converted[3] = toConvert.uyear();
  converted[4] = toConvert.umonthoftheyear();
  converted[5] = toConvert.udayofthemonth();
  converted[6] = toConvert.udayoftheweek();
  converted[7] = toConvert.utimezoneoffset();
  converted[8] = toConvert.dsimtime();
  converted[9] = toConvert.dlatitude();
  converted[10] = toConvert.dlongitude();
  converted[11] = toConvert.daltitude();
  converted[12] = toConvert.dpitch();
  converted[13] = toConvert.dbank();
  converted[14] = toConvert.dheading();
  converted[15] = toConvert.dvelocityx();
  converted[16] = toConvert.dvelocityy();
  converted[17] = toConvert.dvelocityz();
  converted[18] = toConvert.dtemperature();
  converted[19] = toConvert.dairpressure();
  converted[20] = toConvert.dairdensity();
  converted[21] = toConvert.dwindvelocity();
  converted[22] = toConvert.dwinddirection();
  converted[23] = toConvert.dwindx();
  converted[24] = toConvert.dwindy();
  converted[25] = toConvert.dwindz();

  return converted;
}

int main(void) {
  simConnect::simData toProcess;
  std::string toStr("This is a test");
  double *convertedData;
  double *d_convertedData;
  double *processedData;
  int size = N * sizeof(double);

  toProcess.set_sztitle(toStr);
  toProcess.set_dabsolutetime(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dtime(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_udayoftheyear(5);
  toProcess.set_uyear(5);
  toProcess.set_umonthoftheyear(5);
  toProcess.set_udayofthemonth(5);
  toProcess.set_udayoftheweek(5);
  toProcess.set_utimezoneoffset(5);
  toProcess.set_dsimtime(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dlatitude(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dlongitude(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_daltitude(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dpitch(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dbank(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dheading(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dvelocityx(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dvelocityy(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dvelocityz(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dtemperature(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dairpressure(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dairdensity(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dwindvelocity(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dwinddirection(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dwindx(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dwindy(16.44444444444444444444444444444444444444444444444444444444444);
  toProcess.set_dwindz(16.44444444444444444444444444444444444444444444444444444444444);

  /* In order to process the data we first need it in an array for easier access */
  convertedData = toArray(toProcess);
  /* Make space for our processed data */
  processedData = (double *)malloc(size);
  /* Make space on GPU memory for our array */
  cudaMalloc((void **)&d_convertedData, size);
  /* Copy our array from host to device */
  cudaMemcpy(d_convertedData, convertedData, size, cudaMemcpyHostToDevice);
  /* Launch kernel on the GPU to process the data we just copied */
  cudaProcess<<<N,1>>>(d_convertedData);
  /* Copy our pocessed data back from device to host */
  cudaMemcpy(processedData, d_convertedData, size, cudaMemcpyDeviceToHost);
  /* Make sure any device jobs finish before we cleanup and exit */
  cudaDeviceSynchronize();

  std::cout << "Object sztitle: " << toStr <<std::endl;
  for (int i = 0; i < N; i++ ) {
    printf("processedData %d: %f \n", i, processedData[i]);
  }

  free(convertedData);
  free(processedData);
  cudaFree(d_convertedData);

  return 0;
}
