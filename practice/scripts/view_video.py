#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# This program plays back a video file
# with seek and pause features
# 
# author: Anshay
# Date: 06/01/2021


# In[ ]:


import numpy as np
import cv2
import sys


# In[ ]:


## Global Variables
g_cap = cv2.VideoCapture()
g_play = True
print(g_play)


# In[ ]:


def onTrackbarSlide(pos):
    global g_play
    g_cap.set(cv2.CAP_PROP_POS_FRAMES, pos)
    g_play = False


# In[ ]:


def view_video(filepath):
    global g_play
    g_cap.open(filepath)
    trackbar_name = "Slider"
    window_name = "Video Play"
    cv2.namedWindow(window_name)
    max_frames = int(g_cap.get(cv2.CAP_PROP_FRAME_COUNT))
    cv2.createTrackbar(trackbar_name, window_name, 0, max_frames, onTrackbarSlide)
    ret, frame = g_cap.read()
    while(ret):
        if(g_play):
            frame = cv2.resize(frame, (640, 480))
            cv2.imshow(window_name, frame)
            ret, frame = g_cap.read()
        key = cv2.waitKey(30)
        if(key==27):
            break
        if(key==ord('p') or key==ord('P')):
            g_play = not g_play
    g_cap.release()
    print("\nVideo finished or error occured")


# In[ ]:


if __name__== "__main__":
    if(len(sys.argv) != 2):
        print("\nCheck correct usage: 'view_video <filepath>' ")
        sys.exit()
    filename = sys.argv[1]
    view_video(filename)
    cv2.destroyAllWindows()


# In[ ]:




