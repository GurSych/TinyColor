cmake_minimum_required(VERSION 3.16)
project(TinyColor
    VERSION 2.0.0
    DESCRIPTION "A tiny header-only library for terminal coloring"
    LANGUAGES CXX
)

add_library(TinyColor INTERFACE)
add_library(TinyColor::TinyColor ALIAS TinyColor)

target_include_directories(TinyColor
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(TinyColor INTERFACE cxx_std_20)

include(GNUInstallDirs)

install(TARGETS TinyColor
    EXPORT TinyColorTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES
    include/TinyColor.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT TinyColorTargets
    FILE TinyColorTargets.cmake
    NAMESPACE TinyColor::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TinyColor
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/TinyColorConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/TinyColorConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/TinyColorConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TinyColor
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/TinyColorConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/TinyColorConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TinyColor
)
