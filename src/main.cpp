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

    cv::Mat skeleton;
    float step = 40.0f; // расстояние между точками уколов

    std::vector<cv::Point2f> targetPoints = getSuturePoints(img, step, skeleton);
    cv::Mat result;

    

    return 0;
}