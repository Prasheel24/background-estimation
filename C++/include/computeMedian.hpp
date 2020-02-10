/**
 *  @copyright Copyright © 2020, Prasheel Renkuntla
 *  @file    computeMedian.hpp
 *  @author  Prasheel Renkuntla
 *  @date    02/09/2020
 *  @version 1.0
 *  @brief   Background Estimation
 *  @section Header file for median filter to be applied.
 */

#ifndef INCLUDE_COMPUTEMEDIAN_HPP_
#define INCLUDE_COMPUTEMEDIAN_HPP_

#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <vector>

class ComputeMedian {
public:
  /**
   *  @brief Constructor of class Compute Median
   */
  ComputeMedian();

  /**
   *  @brief Destructor of class Compute Median
   */
  ~ComputeMedian();

  /**
   *  @brief Function to compute median elements of vector
   *  @param std::vector<int> elements, current elements
   *  @return int, median value
   */
  int computeMedian(std::vector<int> elements);
  

  /**
   *  @brief Function to compute median elements of matrix from cv
   *  @param std::vector<cv::Mat> vector, elements
   *  @return cv::Mat Median frame cv matrix
   */
  cv::Mat computeMedian(std::vector<cv::Mat> vec);
};
#endif  // INCLUDE_COMPUTEMEDIAN_HPP_