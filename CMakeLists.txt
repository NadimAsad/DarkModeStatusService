cmake_minimum_required(VERSION 3.19)

project(DarkModeStatusService)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
if(WIN32)
    # WinRT doesn't work with 20 currently. Investigate later
    set(CMAKE_CXX_STANDARD 17)
else()
    set(CMAKE_CXX_STANDARD 20)
endif()

qt_wrap_cpp(LIB_MOC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/DarkModeStatusService.hxx
)

add_library(${PROJECT_NAME}
    ${LIB_MOC}
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    Qt5::Core
)

target_include_directories(${PROJECT_NAME}
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(WIN32)
    target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/source/DarkModeStatusService_win32.cxx
    )

    target_link_libraries(${PROJECT_NAME}
    PUBLIC
        WindowsApp
    )
else()
    message(FATAL_ERROR "WIN32 supported currently!")
endif()
