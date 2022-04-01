from ast import parse
import cv2
import sys
import argparse

def image_read(filepath):
    img = cv2.imread(filepath)
    if (not img.data):
        print("Could not open or find image")
        return
    cv2.imwrite("read_image.png", img)
    cv2.imshow("preview", img)
    print("Pixel at 3,5:",img[3, 5])
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("filepath", help="Path of png image to read and show")
    args = parser.parse_args()
    if(args.filepath[-4:] != ".png") and (args.filepath[-4:] != ".jpg"):
        print("Need a png or jpg image")
        exit()
    image_read(args.filepath)
    