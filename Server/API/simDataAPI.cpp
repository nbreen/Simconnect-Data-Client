
#include "../API.h"

using namespace std;
// Added for the json-example:
using namespace boost::property_tree;

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;


std::string putAbsTime(absoluteTime_t *absTime){
  //Come back and fix this after I decide what to do here
  std::string ret(std::to_string(absTime->sec));

  return ret;
}

std::string putHTime(hTime_t *hTime){
  std::string ret(std::to_string(hTime->hour));
  ret.append(std::to_string(hTime->min));
  ret.append(std::to_string(hTime->sec));

  return ret;
}

/* Get's data from sim and fills ptree for JSON output*/
ptree getNewSimData() {
  ptree ret;
  processedData_t fromSim;

  dataMutex.lock();
  fromSim = newData;
  ret.put("aircraftTitle", aircraftTitle);
  dataMutex.unlock();

  ret.put("absoluteTime", putAbsTime(fromSim.absTime));
  ret.put("time", putHTime(fromSim.zulu));
  ret.put("gpsEta", putHTime(fromSim.gpsEta));
  ret.put("simTime", putHTime(fromSim.simulationTime));
  ret.put("lat", fromSim.lat);
  ret.put("long", fromSim.longi);
  ret.put("temp", fromSim.temp);
  ret.put("press", fromSim.pressure);
  ret.put("altitude", fromSim.altitude);
  ret.put("heading", fromSim.heading);
  ret.put("speed", fromSim.speed);
  ret.put("verticalSpeed", fromSim.verticalSpeed);
  ret.put("windVelocity", fromSim.windVelo);
  ret.put("windDirection", fromSim.windDir);
  ret.put("onGround", fromSim.onGround);

  return ret;
}

void *startAPI(void* args) {
  // HTTP-server at port 7378 using 1 thread
  // Unless you do more heavy non-threaded processing in the resources,
  // 1 thread is usually faster than several threads
  HttpServer server;
  server.config.port = API_PORT;

  server.resource["^/data$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
    printf("API Request for simData\n");

    try {
      ptree pt;
      stringstream outStream;

      if (!DEBUG) {
        pt = getNewSimData();
      } else {
        pt.put("aircraftTitle", "F22");
        pt.put("absoluteTime", "918249");
        pt.put("time", "12345");
        pt.put("onGround", "false");
        pt.put("altitude", "4000");
        pt.put("heading", "360");
        pt.put("speed", "250");
        pt.put("verticalSpeed", "500");
        pt.put("gpsEta", "9128374");
        pt.put("lat", "-39");
        pt.put("long","38");
        pt.put("simTime", "13");
        pt.put("temp", "20");
        pt.put("press", "0.00");
        pt.put("windVelocity", "14");
        pt.put("windDirection", "360");
      }
     
      write_json(outStream, pt, true);

      *response << "HTTP/1.1 200 OK\r\n"
                << "Access-Control-Allow-Origin: *\r\n"
                << "Content-Type: application/json \r\n\r\n"
                << outStream.str();
    }
    catch(const exception &e) {
      *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                << e.what();
    }
  };

  // GET-example for the path /info
  // Responds with request-information
  server.resource["^/info$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
    printf("API Request for info\n");
    stringstream stream;
    stream << "<h1>Request from " << request->remote_endpoint().address().to_string() << ":" << request->remote_endpoint().port() << "</h1>";

    stream << request->method << " " << request->path << " HTTP/" << request->http_version;

    stream << "<h2>Query Fields</h2>";
    auto query_fields = request->parse_query_string();
    for(auto &field : query_fields)
      stream << field.first << ": " << field.second << "<br>";

    stream << "<h2>Header Fields</h2>";
    for(auto &field : request->header)
      stream << field.first << ": " << field.second << "<br>";

    response->write(stream);
  };

  // Default GET-example. If no other matches, this anonymous function will be called.
  // Will respond with content in the web/-directory, and its subdirectories.
  // Default file: index.html
  // Can for instance be used to retrieve an HTML 5 client that uses REST-resources on this server
  server.default_resource["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
    printf("API Default Get\n");
    try {
      auto web_root_path = boost::filesystem::canonical("web");
      auto path = boost::filesystem::canonical(web_root_path / request->path);
      // Check if path is within web_root_path
      if(distance(web_root_path.begin(), web_root_path.end()) > distance(path.begin(), path.end()) ||
         !equal(web_root_path.begin(), web_root_path.end(), path.begin()))
        throw invalid_argument("path must be within root path");
      if(boost::filesystem::is_directory(path))
        path /= "index.html";

      SimpleWeb::CaseInsensitiveMultimap header;

      // Uncomment the following line to enable Cache-Control
      // header.emplace("Cache-Control", "max-age=86400");


      auto ifs = make_shared<ifstream>();
      ifs->open(path.string(), ifstream::in | ios::binary | ios::ate);

      if(*ifs) {
        auto length = ifs->tellg();
        ifs->seekg(0, ios::beg);

        header.emplace("Content-Length", to_string(length));
        response->write(header);

        // Trick to define a recursive function within this scope (for example purposes)
        class FileServer {
        public:
          static void read_and_send(const shared_ptr<HttpServer::Response> &response, const shared_ptr<ifstream> &ifs) {
            // Read and send 128 KB at a time
            static vector<char> buffer(131072); // Safe when server is running on one thread
            streamsize read_length;
            if((read_length = ifs->read(&buffer[0], static_cast<streamsize>(buffer.size())).gcount()) > 0) {
              response->write(&buffer[0], read_length);
              if(read_length == static_cast<streamsize>(buffer.size())) {
                response->send([response, ifs](const SimpleWeb::error_code &ec) {
                  if(!ec)
                    read_and_send(response, ifs);
                  else
                    cerr << "Connection interrupted" << endl;
                });
              }
            }
          }
        };
        FileServer::read_and_send(response, ifs);
      }
      else
        throw invalid_argument("could not read file");
    }
    catch(const exception &e) {
      response->write(SimpleWeb::StatusCode::client_error_bad_request, "Could not open path " + request->path + ": " + e.what());
    }
  };

  server.on_error = [](shared_ptr<HttpServer::Request> /*request*/, const SimpleWeb::error_code & /*ec*/) {
    // Handle errors here
    // Note that connection timeouts will also call this handle with ec set to SimpleWeb::errc::operation_canceled
  };

  // Start server and receive assigned port when server is listening for requests
  promise<unsigned short> server_port;
  thread server_thread([&server, &server_port]() {
    // Start server
    server.start([&server_port](unsigned short port) {
      server_port.set_value(port);
    });
  });
  cout << "API listening on port " << server_port.get_future().get() << endl
       << endl;

  server_thread.join();

  return 0;
}
