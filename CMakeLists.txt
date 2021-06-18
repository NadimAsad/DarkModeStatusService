cmake_minimum_required(VERSION 3.19)

if(WIN32)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

    project(DarkModeDetectionWIN32)

    find_package(Qt5 COMPONENTS Core REQUIRED)

    qt_wrap_cpp(APP_MOC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DarkModeDetection.hxx
    )

    add_executable(${PROJECT_NAME}
        ${APP_MOC}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cxx
        ${CMAKE_CURRENT_SOURCE_DIR}/source/DarkModeDetection.cxx
    )

    target_link_libraries(${PROJECT_NAME}
        PUBLIC
            Qt5::Core
            WindowsApp
    )

    target_include_directories(${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
endif()
