# SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
# Copyright (c) 2026 minilib
add_library(QLL_Core)
target_compile_features(QLL_Core PUBLIC cxx_std_26)
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
set_target_properties(QLL_Core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)
target_include_directories(QLL_Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "*.cppm")
target_sources(QLL_Core PUBLIC FILE_SET modules TYPE CXX_MODULES BASE_DIRS FILES ${CORE_SOURCES})