#include "processProtobuff.h"

void logToFile(simConnect::simData toPrint) {
  FILE *outFile = fopen("out.txt", "a+");
  fprintf(outFile, "From socket\n%s\n\n", toPrint.DebugString().c_str());
  fclose(outFile);
}

google::protobuf::uint64 readHeader(char *buf) {
  google::protobuf::uint64 size;
  google::protobuf::io::ArrayInputStream ais(buf, HDR_SZ);
  google::protobuf::io::CodedInputStream coded_input(&ais);
  coded_input.ReadVarint64(&size);//Decode the HDR and get the size
  std::cout<<"size of payload is "<<size<<std::endl;
  return size;
}

void readMessage(int csock, google::protobuf::uint64 siz) {
  int bytecount;
  simConnect::simData payload;
  char buffer [siz + HDR_SZ];//size of the payload and hdr
  //Read the entire buffer including the hdr
  if((bytecount = recv(csock, (void *)buffer, HDR_SZ + siz, MSG_WAITALL))== -1) {
                fprintf(stderr, "Error receiving data %d\n", errno);
        }
  std::cout<<"Second read byte count is "<<bytecount<<std::endl;
  //Assign ArrayInputStream with enough memory 
  google::protobuf::io::ArrayInputStream ais(buffer, siz + HDR_SZ);
  google::protobuf::io::CodedInputStream coded_input(&ais);
  //Read an unsigned integer with Varint encoding, truncating to 32 bits.
  coded_input.ReadVarint64(&siz);
  //After the message's length is read, PushLimit() is used to prevent the CodedInputStream 
  //from reading beyond that length.Limits are used when parsing length-delimited 
  //embedded messages
  google::protobuf::io::CodedInputStream::Limit msgLimit = coded_input.PushLimit(siz);
  //De-Serialize
  payload.ParseFromCodedStream(&coded_input);
  //Once the embedded message has been parsed, PopLimit() is called to undo the limit
  coded_input.PopLimit(msgLimit);
  //Log the result from the socket
  logToFile(payload);
  cudaProcess(payload);
}
