# CV Medial Axis Tracker

A C++ Computer Vision module designed for a laser-assisted suturing training system. 
This repository focuses purely on the image processing and mathematical logic required to find the wound edges, calculate the medial axis (centerline), and extract equidistant target points for a laser guidance system.

## Roadmap & Progress

### Phase 1: Environment & Setup
- [ ] Initialize C++ project with CMake.
- [ ] Configure OpenCV (including `opencv_contrib` for thinning).
- [ ] Load and display a static test image (felt with a slit).

### Phase 2: Wound Masking & Edge Detection
- [ ] Implement image pre-processing (grayscale, blur).
- [ ] Apply thresholding/binarization to isolate the wound area.
- [ ] Clean up noise using morphological operations (optional).

### Phase 3: Core Math - Medial Axis Extraction
- [ ] Apply Distance Transform (`cv::distanceTransform`) to calculate the distance of each pixel to the nearest edge.
- [ ] Extract the 1-pixel centerline using Skeletonization/Thinning (`cv::ximgproc::thinning`).
- [ ] Visualize the resulting medial axis on top of the original image.

### Phase 4: Path Ordering & Point Sampling
- [ ] Extract centerline pixels into a `std::vector<cv::Point>`.
- [ ] Sort the points into a continuous sequential path (from start to end of the wound).
- [ ] Implement a sampling algorithm to place target points along the path at an equal step distance (e.g., every N pixels).

### Phase 5: Output & Visualization
- [ ] Draw the final target points on the output image.
- [ ] Export the target coordinates `(X, Y)` to a text/JSON file for further use by the hardware team.

---
*Developed as part of a university mentoring project for a school robotics team.*