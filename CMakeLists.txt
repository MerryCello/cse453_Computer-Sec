cmake_minimum_required(VERSION 3.17)
project(Homographs)
project(InjectionMitigation)
project(MemoryOrg)
project(Vulnerabilities)
project(AccessControl)
project(Encryption)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homographs pathDebunker.cpp)
add_executable(InjectionMitigation injection.cpp)
add_executable(MemoryOrg memoryOrganization.cpp)
add_executable(Vulnerabilities vulnerabilitiesAndExploits.cpp)
add_executable(AccessControl
        accessControl/control.h
        accessControl/control.cpp
        accessControl/message.h
        accessControl/message.cpp
        accessControl/messages.h
        accessControl/messages.cpp
        accessControl/interact.h
        accessControl/interact.cpp
        accessControl/lab12.cpp)
add_executable(Encryption
        encryption/cipher.h
        encryption/caesarisQuadratum.h
        encryption/ZigZagRoute.h
        encryption/Baconian.h
        encryption/fourSquare.h
        encryption/cipher05.h
        encryption/cipher06.h
        encryption/Substitution.h
        encryption/example.h
        encryption/ui.cpp)
