#!/usr/bin/env python
# coding: utf-8

# In[1]:


# This program plays back a video file
# with seek and pause features and blurs
# the video with Gaussian blur.
# Also adds a ripple (3 concentric circles)
# of red color on mouse click
#
# author: Anshay
# Date: 09/01/2021


# In[2]:


import numpy as np
import cv2
import sys


# In[25]:


## Global Variables
g_cap = cv2.VideoCapture()
g_play = True
g_current_frame = 0
g_loc = (0,0)
g_timer = 0


# In[4]:


def onTrackbarSlide(pos):
    global g_play
    global g_current_frame
    g_cap.set(cv2.CAP_PROP_POS_FRAMES, pos)
    if(pos != g_current_frame):
        g_current_frame = pos
        g_play = False


# In[24]:


def draw_ripple(frame):
    global g_loc, g_timer
    if g_timer>0:
        radius = int(frame.shape[0]/64)
        cv2.circle(frame, g_loc, radius, (0,0,255), 1)
        cv2.circle(frame, g_loc, radius*2, (100,100,255), 1)
        cv2.circle(frame, g_loc, radius*3, (200,200,255), 1)
        g_timer -= 1


# In[14]:


def onMouseClick(event, x, y, flags, param):
    global g_loc, g_timer
    if(event==cv2.EVENT_LBUTTONUP):
        g_loc = (x,y)
        g_timer = 10


# In[9]:


def view_video(filepath):
    global g_play, g_loc, g_current_frame
    g_cap.open(filepath)
    trackbar_name = "Slider"
    window_name = "Video Play"
    cv2.namedWindow(window_name)
    max_frames = int(g_cap.get(cv2.CAP_PROP_FRAME_COUNT))
    cv2.createTrackbar(trackbar_name, window_name, 0, max_frames, onTrackbarSlide)
    ret, frame = g_cap.read()
    cv2.setMouseCallback(window_name, onMouseClick, frame)
    while(ret):
        if(g_play):
            frame = cv2.resize(frame, (640, 480))
            # apply Gaussian blur
            frame = cv2.GaussianBlur(frame, (5,5), 3, 3)
            draw_ripple(frame)
            cv2.imshow(window_name, frame)
            g_current_frame += 1
            cv2.setTrackbarPos(trackbar_name, window_name, g_current_frame)
            ret, frame = g_cap.read()
        key = cv2.waitKey(30)
        if(key==27):
            break
        if(key==ord('p') or key==ord('P')):
            g_play = not g_play
    g_cap.release()
    print("\nVideo finished or error occured")


# In[26]:


if __name__== "__main__":
    if(len(sys.argv) != 2):
        print("\nCheck correct usage: 'mouse_click_marker.py <filepath>' ")
        sys.exit()
    filename = sys.argv[1]
    view_video(filename)
    cv2.destroyAllWindows()


# In[ ]:
