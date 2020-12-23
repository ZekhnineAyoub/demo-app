cmake_minimum_required(VERSION 3.0)
project(test)

find_package(wxWidgets REQUIRED base core adv)

INCLUDE(${wxWidgets_USE_FILE} )

add_executable(test WIN32 test.cpp)

target_link_libraries(test
   ${wxWidgets_LIBRARIES}
   )

install(TARGETS test RUNTIME DESTINATION bin)
