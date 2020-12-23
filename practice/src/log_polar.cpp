#include<opencv4/opencv2/opencv.hpp>
#include<iostream>
#include <string>

int main(int argc, char** argv){
    cv::VideoCapture cap;
    if(argc==1){
        std::cout<<"\nNot enough arguments provided!\n";
        exit(0);
    }
    else if(argc==2){
        cap.open(0);
    }
    else{
        cap.open(std::string(argv[1]));
    }
    if(!cap.isOpened()){
        std::cout<<"\nCould not open file/camera";
        exit(0);
    }
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size((int)cv::CAP_PROP_FRAME_WIDTH, (int)cv::CAP_PROP_FRAME_HEIGHT);

    cv::VideoWriter writer;
    writer.open(argv[argc-1], cv::VideoWriter::fourcc('M','J','P','G'), fps, size);

    std::string WINDOW_NAME = "Log Polar";
    cv::namedWindow(WINDOW_NAME);
    cv::Mat frame;
    while(true){
        cap >> frame;
        cv::logPolar(frame, frame, cv::Point2f(frame.cols/2, frame.rows/2), 40, cv::WARP_FILL_OUTLIERS);
        cv::imshow(WINDOW_NAME, frame);
        writer << frame;
        char c = cv::waitKey(33);
        if(c==27) break;
    }
    writer.release();
    std::cout<<"\nCapture complete";
    return 0;
}
