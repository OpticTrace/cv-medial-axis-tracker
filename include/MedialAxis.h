#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

std::vector<cv::Point2f> getSuturePoints(const cv::Mat& img, float stepDistance, cv::Mat& outSkeleton);