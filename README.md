# CV Medial Axis Tracker

A C++ Computer Vision module designed for a laser-assisted suturing training system. 
The goal of this module is to process a camera feed of a wound (on felt), find the centerline (medial axis), and output the coordinates for the next suture points to a laser guidance system.

## Current Status (What is done)
- [x] C++ project configured with CMake and OpenCV (`opencv-contrib`).
- [x] Load and process static test images.
- [x] Binarization and image thresholding.
- [x] Medial axis extraction using Zhang-Suen thinning algorithm.
- [x] Point ordering and sampling algorithm with a custom step distance.
- [ ] Visualization of the skeleton and target points via OpenCV GUI.

## Roadmap (What's next)
- [ ] Implement Gaussian Blur / Adaptive Threshold to handle noisy camera feeds (shadows, felt texture).
- [ ] Export target coordinates `(X, Y)` to a JSON file or Serial Port for Arduino.
- [ ] Test the algorithm on a live video feed.
- [ ] Integrate with the physical servo/laser hardware.

## Tech Stack & Build Instructions
- **Language:** C++ (C++17 recommended)
- **Libraries:** OpenCV 4.x, `opencv-contrib` (requires `ximgproc` module)
- **Build System:** CMake
- **Environment:** Ubuntu (tested on WSL2)

### How to build:
```bash
mkdir build && cd build
cmake ..
make
```

### How to run:
```bash
cd ..
./build/MedialAxisTracker
```

## Implementation Details
The core algorithm works as follows:
1. **Preprocessing:** Convert image to grayscale and apply inverse binary thresholding to isolate the wound area.
2. **Skeletonization:** Apply `cv::ximgproc::thinning` (Zhang-Suen algorithm) to compress the wound mask into a 1-pixel line.
3. **Point Extraction & Sorting:** Extract all white pixels into a `std::vector<cv::Point2f>`. Sort them lexicographically to form a continuous path from start to end.
4. **Sampling:** Iterate through the sorted points and calculate the Euclidean distance (`cv::norm`). Save a point to the final array once the distance from the last saved point exceeds the `stepDistance`.

---
*Developed as part of a university mentoring project.*