# Video background estimation
[![License MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/Prasheel24/background-estimation/blob/master/License)
---

## Author
Prasheel Renkuntla - [GitHub](https://github.com/Prasheel24)

I am pursuing my Master's in Robotics at the University of Maryland, College Park. My primary area of interest is in Vision integrated Robot Systems.

## Overview
* This project demonstrates the implementation of a simple logic to get the background from a video. It works on the fact that for every change in the frame of a video, the overall median frame has a background that is free from all the moving objects. 
* Code is available in both C++ and Python.

## Dependencies
* Python
* C++ 11/14/17
* CMake

## Run
Each folder has its own readme to run the code for Morgan Bridge traffic camera feed.

## Demo
The first output frame is the median frame given below-
<p align="center">
<h5>Median Frame</h5>
<img src="/output/medianFrame.png" width="70%">
</p>
Press Esc to get the next frame.

The second output is the gray median frame,
<p align="center">
<h5>Gray Median Frame</h5>
<img src="/output/grayFrame.png" width="70%">
</p>

The Final output shows the moving objects that were removed from the video.
<p align="center">
<h5>Difference Frames</h5>
<img src="/output/diffFrame.png" width="70%">
</p>

## Bugs
The python code has intermittent issues of a.any() or a.all(). Please run the code again to solve it.

## License 
```
MIT License

Copyright (c) 2020 Prasheel Renkuntla

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## References
* Video Background Estimation - [Tutorial](https://www.learnopencv.com/simple-background-estimation-in-videos-using-opencv-c-python/)