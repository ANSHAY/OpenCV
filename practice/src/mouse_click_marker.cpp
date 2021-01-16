// This program plays back a video file
// with seek and pause features and blurs
// the video with Gaussian blur.
// Also adds a ripple (3 concentric circles)
// of red color on mouse click
//
// author: Anshay
// Date: 09/01/2021

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

cv::VideoCapture g_cap;
int g_slider_position;
int g_run = -1;
bool g_pauseit = false;
cv::Point g_loc = cv::Point(0,0);
int g_timer = 0;

void onTrackbarSlide(int pos, void*){
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if(g_pauseit) g_run = 1;
    g_pauseit = true;
}

void draw_ripple(cv::Mat &frame){
    if(g_timer>0){
        int radius = frame.size().width/64;
        cv::circle(frame, g_loc, radius, cv::Scalar(0,0,255), 1);
        cv::circle(frame, g_loc, radius*2, cv::Scalar(100,100,255), 1);
        cv::circle(frame, g_loc, radius*3, cv::Scalar(200,200,255), 1);
        g_timer--;
    }
}

void onMouseClick(int event, int x, int y, int, void*){
    if (event != cv::EVENT_LBUTTONUP) return;
    g_loc = cv::Point(x,y);
    g_timer = 10;
}

int main(int argc, char** argv){
    if(argc!=2){
        std::cout<<"\nNot enough arguments provided!\n"
                    "Usage: mouse_click_marker <input_file_path>\n";
        return 1;
    }
    std::string WINDOW_NAME = "video";
    cv::namedWindow(WINDOW_NAME);
    try{
        g_cap.open(std::string(argv[1]));
    }
    catch(...){
        std::cout<<"\nCannot open file\n";
        exit(0);
    }
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int fw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int fh = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout<<"\nVideo has "<<frames<<" frames with resolution: "<<fh<<"x"<<fw;
    cv::Mat frame;
    cv::createTrackbar("Position", WINDOW_NAME, &g_slider_position, frames, onTrackbarSlide);
    cv::setMouseCallback(WINDOW_NAME, onMouseClick);
    while(true){
        if(g_run!=0){
            g_cap>>frame;
            if(frame.empty()) break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_pauseit = false;
            cv::setTrackbarPos("Position", WINDOW_NAME, current_pos);
            // apply blur to the frame with Gaussian filter
            cv::GaussianBlur(frame, frame, cv::Size(5,5), 3, 3);
            draw_ripple(frame);
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
