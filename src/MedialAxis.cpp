#include "MedialAxis.h"
#include <opencv2/ximgproc.hpp> // для thinning
#include <algorithm>
#include <cmath>
#include <iostream>

/*
struct cv::Point2f {
    float x;
    float y;
}
*/


std::vector<cv::Point2f> getSuturePoints(const cv::Mat& img, float stepDistance, cv::Mat& outSkeleton) {
    cv::Mat gray, bin;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); // превращаем из bgr в оттенки серого
    cv::threshold(gray, bin, 127, 255, cv::THRESH_BINARY_INV); // делаем из оттенков серого ч/б с инверсией

    cv::ximgproc::thinning(bin, outSkeleton, cv::ximgproc::THINNING_ZHANGSUEN); // алгоритм смотрит на 8 соседей пикселя и если он крайний становится черным

    std::vector<cv::Point2f> skeletonPoints;
    for (int y = 0; y < outSkeleton.rows; ++y) {
        for (int x = 0; x < outSkeleton.cols; ++x) {
            if (outSkeleton.at<uchar>(y, x) == 255) { // если белая то есть скелет
                skeletonPoints.push_back(cv::Point2f(x, y));
            }
        }
    }

    sort(skeletonPoints.begin(), skeletonPoints.end(), [](const auto& p1, const auto& p2) {return std::tie(p1.x, p1.y) < std::tie(p2.x, p2.y);});

    std::vector<cv::Point2f> targetPoints;
    if (!skeletonPoints.empty()) {
        cv::Point2f lastPoint = skeletonPoints[0];
        targetPoints.push_back(lastPoint);

        for (size_t i = 1; i < skeletonPoints.size(); ++i) {
            float distance = cv::norm(skeletonPoints[i] - lastPoint); // длина
            if (distance >= stepDistance) {
                lastPoint = skeletonPoints[i];
                targetPoints.push_back(lastPoint);
            }
        }
    }
    else {
        std::cout << "warning! skeleton is empty!\n";
    }
    return targetPoints;
}