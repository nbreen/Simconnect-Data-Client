# Simconnect Data Client
This project creates an application to pull user aircraft data from Lockheed Martin's Prepar3d v4 flight simulator using the SimConnect SDK.
Process it with Nvidia Cuda and make it available to an Angular based website. This project is largely a learning experience but to my knowledge there is no similar software out there.

# Client
The client code is written in C++ (Windows 10 Visual Studio 2019) and run on the same machine running the flight simulator. 
The SimConnect code is largely based on the DataHarvester example from the SimConnect SDK. 
Once data on the user object is captured from the simulator it is encoded using Google's Protocol Buffers.
Once the protocol buffer is made it is sent via socket to the server, currently on 1 second intervals.

# Server
The server is running on a locally networked machine running Ubuntu Server. The basic server code is taken from Beej's Guide and then extended.
The server receives and processes the Protocol Buffer and then passes it to a Cuda function for additional processing. Since the server is equipped with 2x GTX 680s
the workload is split across the two cards via mod counter. The cuda code currently used shared memory as a result of deepcopy limitations with cuda. Various performance experiments were done on whether shared memory should be used or if it can be eliminated. Shared memory comes with alot of overhead and the 680s don't support cudaMemcpyAsync()
to help curb the overhead. The best optimization here may be to flatten the struct that cuda processes to remove the deepcopy problem. The API is built in C++ with Boost, much of this code is directly from eidheim on Gitlab with slight alterations for this use case. The API replies to GET requests with the sim data in JSON format.

# Current Work
Currently working on passing data from the main server instance to the API instance probably using threads and a global buffer or fork() and shared memory.
Next will be displaying it on an Angular based website most likely using the OpenMap API as it has an aviation layer that will be usefull.

# Credits
This is my first project on my own, largely a hobby and learning experience for me. It started with an idea and I had no idea it would end up here.

SimConnect SDK
https://www.prepar3d.com/SDKv4/LearningCenter.php

Huge thanks to these two posts for helping out with Protocol Buffers and Sockets
https://stackoverflow.com/questions/65367111/protocol-buffer-corrupting-data/65387171#65387171
https://stackoverflow.com/questions/9496101/protocol-buffer-over-socket-in-c

Base server code from Beej's Guide to network programming
https://beej.us/guide/bgnet/

Base API code from eidheim on Gitlab
https://gitlab.com/eidheim/Simple-Web-Server
