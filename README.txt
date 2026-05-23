FLL: Foundation Lightweight Library
[English] | [日本語](README.ja.txt)
Status: Under Development (Alpha)
Requirements: To use this library, you need a compiler that fully supports C++23 (e.g., GCC 13 or later, Clang 18 or later, MSVC 2022 17.8 or later).
• This project is in a very early alpha stage.
• Do not use it at this time. It is not fully functional and has incomplete features.
• We will be actively adding code and rewriting the core architecture over the next six months or more.
• A usable preview version is planned for release around late 2026.

This project is provided under both the MIT License and the Apache License 2.0.
You can use this project under the terms of either license.

For OS-dependent code, we plan to write Windows code first, but will support Linux and Mac in the future.
It can be used for both regular app and game development.

This library is divided into three parts.
• Core: This is loaded from both parts and forms the foundation. Selecting IRenderer2D for what you want to create will provide basic window creation, rendering, and image loading capabilities, making it quite useful. Implementation is planned for late 2026.
• AppFlamgeWork: This is for regular apps and includes UI creation functionality. This will definitely be completed.
• Engine: This is for games and includes scenes, game loops, and renderers. 2D will definitely be completed, but 3D may not be completed due to its complex structure. Even if it is completed, it will likely be around 3 years from now.
Note: The implementation dates for AppFlamgeWork and Engine will be announced after the Core is implemented.