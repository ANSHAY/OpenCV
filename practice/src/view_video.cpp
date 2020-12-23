#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

cv::VideoCapture g_cap;
int g_slider_position;
int g_run = -1;
bool g_pauseit = false;

void onTrackbarSlide(int pos, void*){
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if(g_pauseit) g_run = 1;
    g_pauseit = true;
}

int main(int argc, char** argv){
    std::string WINDOW_NAME = "video";
    cv::namedWindow(WINDOW_NAME);
    try{
        g_cap.open(std::string(argv[1]));
    }
    catch(...){
        std::cout<<"\nCannot open file";
        exit(0);
    }
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int fw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int fh = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout<<"\nVideo has "<<frames<<" frames with resolution: "<<fh<<"x"<<fw;
    cv::Mat frame;
    cv::createTrackbar("Position", WINDOW_NAME, &g_slider_position, frames, onTrackbarSlide);
    while(true){
        if(g_run!=0){
            g_cap>>frame;
            if(frame.empty()) break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_pauseit = false;
            cv::setTrackbarPos("Position", WINDOW_NAME, current_pos);
            cv::imshow(WINDOW_NAME, frame);
            g_run--;
        }
        char c = cv::waitKey(10);
        if(c == 's' || c == 'S'){
            g_run = 1;
        }
        if(c == 'r' || c == 'R'){
            g_run=-1;
        }
        if(c == 27) break;
    }
    std::cout<<"\nVideo complete or 'quit' key pressed!\n";
    cv::destroyWindow(WINDOW_NAME);
    return 0;
}
