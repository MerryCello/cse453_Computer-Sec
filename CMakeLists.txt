cmake_minimum_required(VERSION 3.17)
project(computerSecurity)

set(CMAKE_CXX_STANDARD 14)

#add_executable(computerSecurity pathDebunker.cpp)
#add_executable(computerSecurity injection.cpp)
#add_executable(computerSecurity memoryOrganization.cpp)
#add_executable(computerSecurity vulnerabilitiesAndExploits.cpp)
add_executable(computerSecurity
        authentication/lab12.cpp
        authentication/control.h
        authentication/interact.cpp
        authentication/interact.h
        authentication/message.cpp
        authentication/message.h
        authentication/messages.cpp
        authentication/messages.h)