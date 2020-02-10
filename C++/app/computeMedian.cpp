/**
 *  @copyright Copyright © 2020, Prasheel Renkuntla
 *  @file    computeMedian.cpp
 *  @author  Prasheel Renkuntla
 *  @date    02/09/2020
 *  @version 1.0
 *  @brief   Background Estimation
 *  @section Implements Median Filter for background estimation
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <vector>
 
#include <computeMedian.hpp>

ComputeMedian::ComputeMedian() {
}

ComputeMedian::~ComputeMedian() {
}


int ComputeMedian::computeMedian(std::vector<int> elements) 
{
  //  sort the vector using nth element to find median frame.
  std::nth_element(elements.begin(), elements.begin()+elements.size()/2, elements.end());
 
  //  sort(elements.begin(),elements.end());
  return elements[elements.size()/2];
}
 
cv::Mat ComputeMedian::computeMedian(std::vector<cv::Mat> vec) 
{
  //  Note: Expects the image to be CV_8UC3
  cv::Mat medianImg(vec[0].rows, vec[0].cols, CV_8UC3, cv::Scalar(0, 0, 0));
 
  for(int row=0; row<vec[0].rows; row++) 
  {
    for(int col=0; col<vec[0].cols; col++) 
    {
      std::vector<int> elements_B;
      std::vector<int> elements_G;
      std::vector<int> elements_R;
 
      for(uint imgNumber=0; imgNumber<vec.size(); imgNumber++) 
      {
        int B = vec[imgNumber].at<cv::Vec3b>(row, col)[0];
        int G = vec[imgNumber].at<cv::Vec3b>(row, col)[1];
        int R = vec[imgNumber].at<cv::Vec3b>(row, col)[2];
 
        elements_B.push_back(B);
        elements_G.push_back(G);
        elements_R.push_back(R);
      }
 
      medianImg.at<cv::Vec3b>(row, col)[0]= computeMedian(elements_B);
      medianImg.at<cv::Vec3b>(row, col)[1]= computeMedian(elements_G);
      medianImg.at<cv::Vec3b>(row, col)[2]= computeMedian(elements_R);
    }
  }
  return medianImg;
}