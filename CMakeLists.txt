cmake_minimum_required(VERSION 3.9)
set(CMAKE_BUILD_TYPE debug)
set(ser_src 
discovery_server.c
soapC.c
stdsoap2.c
soapServer.c 
soapClient.c 
threads.c
wsaapi.c
wsddapi.c
)

set(cli_src discovery_client.c
soapC.c
stdsoap2.c
soapServer.c 
soapClient.c 
threads.c
wsaapi.c
wsddapi.c
)
add_executable(server ${ser_src})
add_executable(client ${cli_src})

