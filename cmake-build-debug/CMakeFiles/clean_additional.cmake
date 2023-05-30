# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "TestTask/libs/GraficiProject/CMakeFiles/GraficiProject_autogen.dir/AutogenUsed.txt"
  "TestTask/libs/GraficiProject/CMakeFiles/GraficiProject_autogen.dir/ParseCache.txt"
  "TestTask/libs/GraficiProject/CMakeFiles/GraficiProject_t_autogen.dir/AutogenUsed.txt"
  "TestTask/libs/GraficiProject/CMakeFiles/GraficiProject_t_autogen.dir/ParseCache.txt"
  "TestTask/libs/GraficiProject/GraficiProject_autogen"
  "TestTask/libs/GraficiProject/GraficiProject_t_autogen"
  )
endif()
