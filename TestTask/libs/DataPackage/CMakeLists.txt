cmake_minimum_required(VERSION 3.5)

project(DataPackage LANGUAGES CXX)

add_subdirectory(DataPackageCommon)
add_subdirectory(DataPackageRead)
add_subdirectory(DataPackageWrite)


add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE DataPackageRead DataPackageWrite DataPackageCommon)


include("unittest.cmake")