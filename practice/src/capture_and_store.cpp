/*************************************************
This program captures frames from camera and stores
them in a file after downsampling the video frames
A trackbar is included which decides the
downsampling from 2 to 8.

author: Anshay
Date: 23/12/2020
*************************************************/

#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

int g_max_downsampling = 2;
int g_slider_pos = 0;

int main(int argc, char** argv){
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    std::string WINDOW_NAME = "Video Camera";
    std::string WINDOW_NAME2 = "Downsampled";
    cv::namedWindow(WINDOW_NAME);
    cv::namedWindow(WINDOW_NAME2);
    cv::Mat frame;
    // error handling
    if(argc!=2){
        std::cout<<"\nUsage capture_and_store <output_file_path>\n";
        return -1;
    }
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    cap >> frame;
    if (frame.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        return -1;
    }
    // VideoWriter
    cv::Size size((int)cv::CAP_PROP_FRAME_WIDTH/2, (int)cv::CAP_PROP_FRAME_HEIGHT/2);
    double fps = 25.0;
    writer.open(argv[1], cv::VideoWriter::fourcc('M','J','P','G'), fps, size);
    if (!writer.isOpened()) {
        std::cerr << "Could not open the output video file for write\n";
        return -1;
    }
    // create a trackbar
    cv::createTrackbar("Downsampling", WINDOW_NAME, &g_slider_pos,
                        g_max_downsampling);
    // loop the frames
    while(true){
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            return -1;
        }
        cv::imshow(WINDOW_NAME, frame);
        // downsample the frame
        cv::pyrDown(frame, frame);
        writer << frame;
        for(int i=0; i<g_slider_pos; i++){
            cv::pyrDown(frame, frame);
        }
        cv::imshow(WINDOW_NAME2, frame);
        if(cv::waitKey(5)>=0) break;
    }
    // destroy windows
    cv::destroyWindow(WINDOW_NAME);
    cv::destroyWindow(WINDOW_NAME2);
    return 0;
}
