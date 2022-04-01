#include <iostream>
#include <string>
#include <sstream>

#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv){
    if(argc!=2){
        std::cout<<"\nIncorrect call! Correct way is: image_read <file_path.png>";
        return -1;
    }
    cv::Mat img = cv::imread(argv[1]);
    if(!img.data){
        std::cout<<"\nCould not find or open image";
        return -1;
    }
    cv::imwrite("read_image.png", img);
    cv::imshow("Read image", img);
    cv::waitKey(0);
    return 0;
}