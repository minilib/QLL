[English] | [日本語](README.ja.md)
# FLL
Foundation Lightweight Library
Status: Under Development (Alpha)
Requirements: To use the library, you need a compiler that fully supports C++23 (e.g., GCC 13 or later, Clang 18 or later, MSVC 2022 17.8 or later).
## What is FLL?
A library usable in both regular app and game development, planned to be cross-platform in the future.
This project is in a very early alpha stage.
* **Do not use** at this time. It is not fully functional and has incomplete features.
* We will be actively adding code and rewriting the core architecture over the next 6 months or more.
* A usable preview version is planned for release around late 2026.
We plan to write Windows code first for OS-dependent code, with future support for Linux and Mac.
## About the License
This project is provided under both the **MIT License** and the **Apache License 2.0**.
You can use this project under the terms of either license.
See LICENSE for details.

## Structure
This library is divided into three parts:
1. Core: This is loaded from both parts and forms the foundation. By selecting IRenderer2D for what you want to create, you will find it quite useful as it includes basic window creation, rendering, and image loading. Implementation is scheduled for around the latter half of 2026.
2. AppFlamgeWork: This is for regular apps and includes UI creation functions. This will definitely be completed.
3. Engine: This is for games and includes scenes, game loops, renderers, etc. 2D will definitely be completed, but 3D may not be completed due to its complex structure. Even if it is completed, it will probably be around 3 years from now.
Note that the implementation dates for AppFlamgeWork and Engine will be announced after the Core is implemented.