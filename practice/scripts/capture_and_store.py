#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# This program captures frames from camera and stores
# them in a file after downsampling the video frames
# A trackbar is included which decides the
# downsampling from 2 to 8.
# 
# author: Anshay
# Date: 06/01/2021


# In[ ]:


import numpy as np
import cv2
import sys


# In[ ]:


def scaleFrame(frame, trackbar_name, window_name):
    factor = cv2.getTrackbarPos(trackbar_name, window_name)
    while(factor>0):
        frame = cv2.pyrDown(frame)
        factor -= 1
    return frame


# In[ ]:


def capture_and_store(FILENAME):
    window_name = "Capture"
    trackbar_name = "Downsampling"
    cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)
    cap = cv2.VideoCapture()
    writer = cv2.VideoWriter()
    cap.open(0)
    if(not cap.isOpened()):
        print("\nCould not open camera")
        exit()
    try:
        cv2.createTrackbar(trackbar_name, window_name, 0, 3, (lambda a: None))
        ret, frame = cap.read()
        fps = 24.0
        size = (frame.shape[1],frame.shape[0])
        writer.open(FILENAME, cv2.VideoWriter_fourcc(*"MJPG"), fps, size)
        while(ret):
            frameScaled = scaleFrame(frame, trackbar_name, window_name)
            cv2.imshow(window_name, frameScaled)
            writer.write(frame)
            if(cv2.waitKey(33)==27):
                print("\nExiting and closing camera")
                break
            ret, frame = cap.read()
    finally:
        writer.release()
        cap.release()


# In[ ]:


if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("\nCorrect usage: capture_and_store <output_file_path>\n")
        exit()
    filename = sys.argv[1]
    capture_and_store(filename)
    cv2.destroyAllWindows()


# In[ ]:





# In[ ]:




