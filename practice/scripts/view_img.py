#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import cv2
import sys


# In[ ]:


def view_img(filepath):
    img = cv2.imread(filepath)
    window = cv2.namedWindow("Image Viewer", cv2.WINDOW_NORMAL)
    img = cv2.resize(img, (1080, 720))
    cv2.imshow(window, img)
    cv2.waitKey()
    print("image at "+filepath+" shown successfully.")


# In[ ]:


if __name__== "__main__":
    if(len(sys.argv) != 2):
        print("\nCheck correct usage: 'view_img <filepath>' ")
        sys.exit()
    filename = sys.argv[1]
    view_img(filename)
    cv2.destroyAllWindows()


# In[ ]:




