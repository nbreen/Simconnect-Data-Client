# Simconnect Data Client
This project creates an application to pull user aircraft data from Lockheed Martin's Prepar3d flight simulator using the SimConnect SDK.
Process it with Nvidia Cuda and make it available to an Angular based website. This project is largely a learning experience but to my knowledge there is no similar software out there.

# Client
The client code is written in C++ (Windows 10 Visual Studio 2019) and run on the same machine running the flight simulator. 
The SimConnect code is largely based on the DataHarvester example from the SimConnect SDK. 
Once data on the user object is captured from the simulator is it encoded using Google's Protocol Buffers.
Once the protocol buffer is made it is sent via socket to the server currently on 1 second intervals.

# Server
The server is running on a local networked machine running Ubuntu Server. The basic server code is taken from Beej's Guide and then extended.
The server receives and processes the Protocol Buffer and then passes it to a Cuda function for additional processing.
Currently the cuda function is just an identity function but this will be expanded on later.

# Known bugs
There were several bugs with struct alignment in memory and general memory layout issue which appear to now be fixed.
There is a known bug on the server side when the protocol buffer is received via socket the final field (WindDirection) is corrupted.

# Next Features
The next steps will be to mpdify to the Cuda function to process the data and then make it available to my Angular based website.
Most likely this will use the OpenMap API as it has an aviation layer that will be usefull.
