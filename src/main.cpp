#include <MedialAxis.h>
#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
    std::string path = "data/test_wound.png";
    cv::Mat img = cv::imread(path);

    if (img.isEmpty()) {
        std::cout << "an error occured. check the path: " << path << "\n";
        return -1;
    }

    return 0;
}