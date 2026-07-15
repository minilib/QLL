[English] | [Japanese](README.ja.md)
# QLL
Quick Lightweight Library  
Status: In development (alpha version)  
Prerequisites: To use this library, you need a compiler that supports C++20 (e.g., GCC 13 or later, Clang 18 or later, MSVC 2022 17.8 or later). You will also need to adjust your configuration.
## What is QLL?
This library can be used for both general app and game development and is planned to become cross-platform in the future.  
Since I’m primarily building this for my own use, I have **absolutely no intention** of maintaining backward compatibility.  
This project is in a very early alpha stage.  
* **Please do not use it** at this time. It does not work properly, and its features are incomplete.  
* Over the next six months or more, I will be actively adding code and rewriting the core architecture.  
* I have **not performed any testing**. Therefore, you can expect to encounter bugs.  
For OS-dependent code, I plan to write the Windows code first, but I intend to add support for Linux and Mac in the future.
If you wish to modify or develop the code, please use Clang (preferably version 22.1.3).
## About the License
This project is provided under four licenses: **MIT-0**, **zlib**, **MIT**, and **Apache-2.0**.
You may use this project under the terms of any of these licenses.
Please see the LICENSE file for details.
## Structure
This library is divided into three parts.  
1. Core: This is the foundation, loaded by both other components. If you choose *IRenderer2D* for your project, you’ll find it quite useful, as it provides basic window creation, drawing, image loading, and more.
2. AppFramework: Designed for standard applications, it includes features for creating UIs and handling window resizing.  
3. Engine: Designed for games, it includes scenes, game loops, and renderers. I’m confident the 2D version will be completed, but the 3D version may not be finished due to its complex structure. Even if it is completed, I expect it will take about three years.
![](https://pixel.flatypus.me/minilib-qll)