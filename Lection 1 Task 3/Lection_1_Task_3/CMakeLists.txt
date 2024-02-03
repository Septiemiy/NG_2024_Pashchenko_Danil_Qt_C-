cmake_minimum_required(VERSION 3.5)

project(Lection_1_Task_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lection_1_Task_3 main.cpp)

include(GNUInstallDirs)
install(TARGETS Lection_1_Task_3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
