#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import cv2
import sys


# In[ ]:


def view_camera():
    window = cv2.namedWindow("Camera Preview")
    cap = cv2.VideoCapture()
    cap.open(0)
    if(not cap.isOpened()):
        print("\nCould not open camera")
        exit()
    ret, frame = cap.read()
    while(ret):
        frame = cv2.resize(frame, (1080, 720))
        cv2.imshow(window, frame)
        if(cv2.waitKey(25)==27):
            break
        ret, frame = cap.read()
    cap.release()
    print("\nClosing camera and exiting")


# In[ ]:


if __name__ == "__main__":
    view_camera()
    cv2.destroyAllWindows()


# In[ ]:




