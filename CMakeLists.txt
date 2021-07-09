cmake_minimum_required(VERSION 3.17)
project(computerSecurity)

set(CMAKE_CXX_STANDARD 14)

#add_executable(computerSecurity pathDebunker.cpp)
#add_executable(computerSecurity injection.cpp)
#add_executable(computerSecurity memoryOrganization.cpp)
#add_executable(computerSecurity vulnerabilitiesAndExploits.cpp)
add_executable(computerSecurity
        accessControl/lab12.cpp
        accessControl/control.cpp
        accessControl/control.h
        accessControl/interact.cpp
        accessControl/interact.h
        accessControl/message.cpp
        accessControl/message.h
        accessControl/messages.cpp
        accessControl/messages.h)