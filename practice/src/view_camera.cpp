#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

int main(int argc, char** argv){
    std::string WINDOW_NAME = "video";
    cv::namedWindow(WINDOW_NAME);
    cv::VideoCapture cap;
    try{
        if(argc==1){
            cap.open(0);
        }
        else{
            cap.open(std::string(argv[1]));
        }
    }
    catch(...){
        std::cout<<"\nCannot open file";
        exit(0);
    }
    if(!cap.isOpened()){
        std::cout<<"\nCould not open camera";
        exit(0);
    }
    cv::Mat frame;
    while(true){
        cap>>frame;
        if(frame.empty()) break;
        cv::imshow(WINDOW_NAME, frame);
        char c = cv::waitKey(20);
        if(c == 27) break;
    }
    std::cout<<"\nVideo complete or 'quit' key pressed!\n";
    cv::destroyWindow(WINDOW_NAME);
    return 0;
}
