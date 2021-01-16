#!/usr/bin/env python
# coding: utf-8

# In[1]:


# This program captures frames from camera and stores
# them in a file in log polar form
# 
# author: Anshay
# Date: 06/01/2021


# In[2]:


import numpy as np
import cv2
import sys


# In[13]:


def log_polar(FILENAME):
    window_name = "Log Polar"
    cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)
    cap = cv2.VideoCapture()
    writer = cv2.VideoWriter()
    cap.open(0)
    if(not cap.isOpened()):
        print("\nCould not open camera")
        exit()
    try:
        ret, frame = cap.read()
        fps = 24.0
        size = (frame.shape[1],frame.shape[0])
        writer.open(FILENAME, cv2.VideoWriter_fourcc(*"MJPG"), fps, size)
        while(ret):
            frame = cv2.warpPolar(frame, size, (size[0]/2, size[1]/2), 40, cv2.WARP_POLAR_LINEAR)
            cv2.imshow(window_name, frame)
            writer.write(frame)
            if(cv2.waitKey(33)==27):
                print("\nExiting and closing camera")
                break
            ret, frame = cap.read()
    finally:
        writer.release()
        cap.release()


# In[14]:


if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("\nCorrect usage: capture_and_store <output_file_path>\n")
        exit()
    filename = sys.argv[1]
    log_polar(filename)
    cv2.destroyAllWindows()


# In[ ]:




