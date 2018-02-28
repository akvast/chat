cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)

set(SERVER_PROJECT_NAME chat_server)
set(CLIENT_PROJECT_NAME chat_client)

project(${SERVER_PROJECT_NAME})
project(${CLIENT_PROJECT_NAME})

link_directories(/usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

AUX_SOURCE_DIRECTORY(./gen/cpp COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/network COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/tools COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/ecdh COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/aes COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/entities COMMON_SOURCES)

AUX_SOURCE_DIRECTORY(./src/server SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(src/server/network SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/database SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/managers SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/tools SERVER_SOURCES)

AUX_SOURCE_DIRECTORY(./src/client CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/vm CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/app CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/network CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/adapters CLIENT_SOURCES)

include_directories(gen/cpp)
include_directories(src/common)
include_directories(src/common/network)
include_directories(src/common/tools)
include_directories(src/common/ecdh)
include_directories(src/common/aes)
include_directories(src/common/entities)

include_directories(src/server)
include_directories(src/server/network)
include_directories(src/server/database)
include_directories(src/server/managers)
include_directories(src/server/tools)

include_directories(src/client)
include_directories(src/client/vm)
include_directories(src/client/app)
include_directories(src/client/network)
include_directories(src/client/adapters)

# BOOST

set(BOOST_COMPONENTS
        iostreams
        filesystem
        system)

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else ()
    message(ERROR " BOOST not found!")
endif ()

# OpenSSL

find_package(OpenSSL REQUIRED)

message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})

### SERVER:

add_executable(${SERVER_PROJECT_NAME} ${COMMON_SOURCES} ${SERVER_SOURCES})
target_link_libraries(${SERVER_PROJECT_NAME}
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        protobuf
        mysqlcppconn)

### CLIENT:

add_executable(${CLIENT_PROJECT_NAME} ${COMMON_SOURCES} ${CLIENT_SOURCES})
target_link_libraries(${CLIENT_PROJECT_NAME}
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        protobuf)