cmake_minimum_required(VERSION 3.4)

project(Test)

set(src_server
    server.cpp
    soapcalcService.cpp

    soapC.cpp
    stdsoap2.cpp
)

set(src_client soapcalcProxy.cpp
    client.cpp
    stdsoap2.cpp
    soapC.cpp

)

add_executable(server ${src_server})
add_executable(client ${src_client})
