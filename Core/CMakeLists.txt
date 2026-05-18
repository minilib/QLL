# 🌟重要：CMakeに標準ライブラリ(std)のモジュール自動ビルドを許可する設定
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
cmake_minimum_required(VERSION 4.2.1)
project(FLL_Core CXX)
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STDLIB_MODULES_JSON "C:/msys64/clang64/share/libc++/libc++.modules.json")
set(PCM_DIR "${CMAKE_BINARY_DIR}/pcm") 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS OFF)

add_library(FLL_Core)
target_compile_features(FLL_Core PUBLIC cxx_std_23)
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
set_target_properties(FLL_Core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)
target_sources(FLL_Core PRIVATE FILE_SET modules TYPE CXX_MODULES
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include" FILES
    include/Base/Macros.cppm
    include/Base/Types.cppm
)