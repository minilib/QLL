# 🌟重要：CMakeに標準ライブラリ(std)のモジュール自動ビルドを許可する設定
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457") # このIDが必須
set(CMAKE_CXX_MODULE_STD ON)
cmake_minimum_required(VERSION 3.30)
project(FLL_Core CXX)


add_library(FLL_Core)
target_compile_features(FLL_Core PUBLIC cxx_std_23)
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
set_target_properties(FLL_Core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)
target_sources(FLL_Core PUBLIC FILE_SET modules TYPE CXX_MODULES
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include" FILES
    include/Base/Macros.cppm
    include/Base/Types.cppm
)
# ターゲット本体（バイナリとモジュールソース）の配置ルール
install(TARGETS FLL_Core
    EXPORT FLL_Core                        # 外部公開用の名前（任意の識別子）
    ARCHIVE DESTINATION lib                # スタティックライブラリ (.a / .lib) の出力先
    LIBRARY DESTINATION lib                # 共有ライブラリ (.so / .dylib) の出力先
    RUNTIME DESTINATION bin                # Windows DLL や 実行ファイルの出力先
    FILE_SET modules DESTINATION include   # .cppm ファイルの出力先
)