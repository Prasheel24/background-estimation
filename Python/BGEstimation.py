# -*- coding: utf-8 -*-
"""Background Estimation with Median Filtering"""

__name__ = "BGEstimation"
__version__ = (1,0)
__author__ = "Prasheel Renkuntla <prasheel@umd.edu>"

_generator_name = __name__ + "-" + ".".join(map(str, __version__))


# Import the required libraries
import numpy as np
import cv2
from skimage import data, filters

# Capture the Video for Background Estimation in VideoCapture object
captured_video = cv2.VideoCapture('MorganBridgeFeed.mp4')

# Select 25 frames from the captured_video at Random
# CAP_PROP_FRAME_COUNT returns the frame count from the video file
# Product with np.random.uniform with specified size gives
# Random frames from the video of type ndarray
frame_ids = captured_video.get(cv2.CAP_PROP_FRAME_COUNT) * np.random.uniform(size=20)

# Store the frames in an empty array(list)
temp_frames = []

# Loop through to get each frame with its corresponding id
for frame_id in frame_ids:
	# mark each frame on videocapture object
	captured_video.set(cv2.CAP_PROP_POS_FRAMES, frame_id)
	# get each frame
	ret_val, individual_frame = captured_video.read()
	# append into temporary list
	temp_frames.append(individual_frame)
# print(ret_val)

# Now we calculate the median along the time axis
median_frame = np.median(temp_frames, axis=0).astype(dtype=np.uint8)

# Display the median frame thus calculated
cv2.imshow('Median Frame', median_frame)
cv2.waitKey(0)
# cv2.imwrite('median_frame.jpg',median_frame)



# Now we create a mask for every frame
# Reset previously set frame number to 0
captured_video.set(cv2.CAP_PROP_POS_FRAMES, 0)

# Now convert median frame to grayscale
gray_median_frame = cv2.cvtColor(median_frame, cv2.COLOR_BGR2GRAY)

# cv2.imshow('Gray Scale Image', gray_median_frame)
# cv2.waitKey(0)

while(ret_val):

	# Read the current frame
	ret, frame = captured_video.read()

	if frame is not None:
		# Convert the current frame to grayscale
		frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

		# Calculate absolute difference of current frame and the median frame
		diff_frame = cv2.absdiff(frame, gray_median_frame)

		# Threshold to binarize
		th, diff_frame = cv2.threshold(diff_frame, 30, 255, cv2.THRESH_BINARY)

		# Display the final image
		cv2.imshow('Difference Frame', diff_frame)
		cv2.waitKey(21)

# Release VideoCapture object 
captured_video.release()

# Close all Windows
# cv2.destroyAllWindows()