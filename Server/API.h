#include "API/client_http.hpp"
#include "API/server_http.hpp"
#include "processedData.h"
#include <future>
// Added for the json-example
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

// Added for the default_resource example
#include <algorithm>
#include <boost/filesystem.hpp> //Have to compile this seperately
#include <fstream>
#include <vector>

#define API_PORT 7378
#define DEBUG 1
void *startAPI(void*);