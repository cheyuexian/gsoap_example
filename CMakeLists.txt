cmake_minimum_required(VERSION 3.9)

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

add_executable(server ${ser_src})

