cmake_minimum_required(VERSION 3.20)
project(project)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")

set(HEADER_FILES
        utils/utils.h
        objects/complex.h
        objects/number.h
        objects/fraction.h
        objects/polar.h
        objects/point.h
        container/container.h
        )

set(SOURCE_FILES
        objects/complex.cpp
        objects/number.cpp
        objects/fraction.cpp
        objects/polar.cpp
        objects/point.cpp
        container/container.cpp
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")


add_executable(project
        main.cpp
        ${HEADER_FILES}
        ${SOURCE_FILES}
        )
