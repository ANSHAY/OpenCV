#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
    Mat img = imread(argv[1],-1);
    if(img.empty()) return -1;
    namedWindow("win_ex", WINDOW_AUTOSIZE);
    imshow("win_ex", img);
    waitKey(0);
    destroyWindow("win_ex");
    return 0;
}
