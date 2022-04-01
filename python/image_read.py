import cv2
import sys

def image_read(filepath):
    img = cv2.imread(filepath)
    if (not img.data):
        print("Could not open or find image")
        return
    cv2.imwrite("read_image.png", img)
    cv2.imshow("preview", img)
    print("Pixel at 3,5:",img[3, 5])
    cv2.waitKey(0)
    return

if __name__ == "__main__":
    if(len(sys.argv)!=2):
        print("Incorrect usage! Correct usage is python image_read.py <file_path>")
        exit()
    print ("File format: "+sys.argv[1][-4:])
    if(sys.argv[1][-4:] != ".png") and (sys.argv[1][-4:] != ".jpg"):
        print("Need a png or jpg image")
        exit()
    image_read(sys.argv[1])
    