[Japanese] | [English](README.md)
# FLL
Foundation Lightweight Library  
Status: In development (alpha version)  
Prerequisites: To use this library, you need a compiler that supports C++26 (e.g., GCC 13 or later, Clang 18 or later, MSVC 2022 17.8 or later). You will also need to adjust your configuration.
## What is FLL?
This library can be used for both general app and game development and is planned to become cross-platform in the future.  
Since I am primarily building this for my own use, I have **not considered backward compatibility at all**.  
This project is in a very early alpha stage.  
* **Please do not use it** at this time. It does not work fully and its features are incomplete.  
* Over the next six months or more, I will actively work on adding code and rewriting the core architecture.  
* **No testing has been performed at all**. Therefore, I expect bugs to occur.  
Regarding OS-dependent code, I plan to write the Windows code first, but I intend to support Linux and Mac in the future.
## About the License
This project is provided under both the **MIT License** and the **Apache License 2.0**.
You may use this project under the terms of either license.
Please see the LICENSE file for details.
## Structure
This library is divided into three parts.  
1. Core: This is loaded by both components and serves as the foundation. If you choose IRenderer2D for your project, it provides basic window creation, drawing, and image loading, making it quite useful.
2. AppFramework: Designed for standard applications, it includes UI creation features and support for window resizing.  
3. Engine: Designed for games, it includes scenes, game loops, and renderers. I am confident that the 2D version will be completed, but the 3D version may not be finished due to its complex structure. Even if it is completed, I expect it will take about three years.