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

    cv::Mat skeleton; // сам скелет белый, остальные точки черные
    float step = 40.0f; // расстояние между точками уколов

    std::vector<cv::Point2f> targetPoints = getSuturePoints(img, step, skeleton);
    cv::Mat result = img.clone(); // поверх оригинала будем рисовать скелет и куда колоть

    // сначала нарисуем скелет
    for (int y = 0; y < skeleton.rows; ++y) {
        for (int x = 0; x < skeleton.cols; ++x) {
            if (skeleton.at<uchar>(y, x) == 255) { // если это точка на скелете
                cv::circle(result, cv::Point(x, y), 1, cv::Scalar(0, 255, 0), cv::FILLED); // рисуем скелет зелеными кругами радиуса 1
            }
        }
    }

    // дальше рисуем уколы
    for (const auto& pt: targetPoints) {
        cv::circle(result, pt, 5, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    std::cout << "congratulations! points found: " << targetPoints.size() << std::endl;

    cv::imshow("1. Original", img);
    cv::imshow("2. Skeleton (Line)", skeleton);
    cv::imshow("3. Final Points (Red)", result);

    cv::waitKey(0);
    return 0;
}