cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)

set(SERVER_PROJECT_NAME chat_server)
set(CLIENT_PROJECT_NAME chat_client)
set(COMMON_LIBRARY_NAME chat_common)

project(${SERVER_PROJECT_NAME})
project(${CLIENT_PROJECT_NAME})
project(${COMMON_LIBRARY_NAME})

link_directories(/usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_definitions(-DSQLITE_HAS_CODEC)

AUX_SOURCE_DIRECTORY(./gen/cpp COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/network COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/tools COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/ecdh COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(./src/common/aes COMMON_SOURCES)
AUX_SOURCE_DIRECTORY(src/server/entities COMMON_SOURCES)

AUX_SOURCE_DIRECTORY(./src/server SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/network SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/network/handlers SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/database SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/managers SERVER_SOURCES)
AUX_SOURCE_DIRECTORY(./src/server/tools SERVER_SOURCES)

AUX_SOURCE_DIRECTORY(./src/client CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/vm CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/app CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/network CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/adapters CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/database CLIENT_SOURCES)
AUX_SOURCE_DIRECTORY(./src/client/managers CLIENT_SOURCES)

AUX_SOURCE_DIRECTORY(./src/client/desktop CLIENT_SOURCES)

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

### Common library:

add_library(${COMMON_LIBRARY_NAME} ${COMMON_SOURCES})
target_link_libraries(${COMMON_LIBRARY_NAME}
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        protobuf)

### Server executable:

add_executable(${SERVER_PROJECT_NAME} ${SERVER_SOURCES})
target_link_libraries(${SERVER_PROJECT_NAME}
        ${COMMON_LIBRARY_NAME}
        mysqlcppconn)

### Client executable:

add_executable(${CLIENT_PROJECT_NAME} ${CLIENT_SOURCES})
target_link_libraries(${CLIENT_PROJECT_NAME}
        ${COMMON_LIBRARY_NAME}
        dl)

### Includes:

target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC gen/cpp)
target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC src/common)
target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC src/common/network)
target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC src/common/tools)
target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC src/common/ecdh)
target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC src/common/aes)

target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/network)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/network/handlers)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/database)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/entities)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/managers)
target_include_directories(${SERVER_PROJECT_NAME} PUBLIC src/server/tools)

target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/vm)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/app)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/network)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/adapters)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/database)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/entities)
target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/managers)

target_include_directories(${CLIENT_PROJECT_NAME} PUBLIC src/client/desktop)