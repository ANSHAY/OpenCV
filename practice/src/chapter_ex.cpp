#include<iostream>
#include<opencv2/opencv.hpp>

void ex2(){
    cv::Mat mat33f = cv::Mat::eye(3,3,CV_32FC1);
    cv::Vec3f vec3f(1,2,3);
    cv::Mat mat33i = cv::Mat3i::eye(3,3);
    std::cout<<mat33f<<std::endl;
    std::cout<<mat33i<<std::endl;
    std::cout<<vec3f.t()<<std::endl;
    std::cout<<mat33f*vec3f<<std::endl;
}

int main(int argc, char** argv){
    ex2();
    return 0;
}
