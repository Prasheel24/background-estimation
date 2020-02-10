/**
 *  @copyright Copyright © 2020, Prasheel Renkuntla
 *  @file    main.cpp
 *  @author  Prasheel Renkuntla
 *  @date    02/09/2020
 *  @version 1.0
 *  @brief   Background Estimation
 *  @section Main program to estimate the BG with median filter
 */
#include <iostream>
#include <vector>
#include "computeMedian.hpp"

/**
 *  @brief  Main Function
 *  @param  argc, for video 
 *  @param  argv, Video goes as an argument
 *  @return 0
 */
int main(int argc, char const *argv[])
{
  ComputeMedian cm = ComputeMedian();
  std::string video_file;
  
  // Read video file
  if(argc > 1) {
    video_file = argv[1];
  } else {
    video_file = "../MorganBridgeFeed.mp4";
  }

  cv::VideoCapture cap(video_file);
  if(!cap.isOpened())
  std::cerr << "Error opening video file\n";

  // Randomly select 25 frames
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,cap.get(CV_CAP_PROP_FRAME_COUNT));

  std::vector<cv::Mat> frames;
  cv::Mat frame;

  for(int i=0; i<25; i++) 
  {
    int fid = distribution(generator);
    cap.set(CV_CAP_PROP_POS_FRAMES, fid);
    cv::Mat frame;
    cap >> frame;
    if(frame.empty())
     continue;
    frames.push_back(frame);
  }
  
  // Calculate the median along the time axis
  cv::Mat medianFrame = cm.computeMedian(frames);

  // Display median frame
  cv::imshow("frame", medianFrame);
  cv::waitKey(0);
  
  //  Reset frame number to 0
  cap.set(CV_CAP_PROP_POS_FRAMES, 0);

  // Convert background to grayscale
  cv::Mat grayMedianFrame;
  cvtColor(medianFrame, grayMedianFrame, cv::COLOR_BGR2GRAY);

  // Loop over all frames
  while(1) 
  {
    // Read frame
    cap >> frame;

    if (frame.empty())
    break;

    // Convert current frame to grayscale
    cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

    // Calculate absolute difference of current frame and the median frame
    cv::Mat dframe;
    cv::absdiff(frame, grayMedianFrame, dframe);

    // Threshold to binarize
    cv::threshold(dframe, dframe, 30, 255, CV_THRESH_BINARY);

    // Display Image
    cv::imshow("frame", dframe);
    cv::waitKey(20);
  }

cap.release();
return 0;
}