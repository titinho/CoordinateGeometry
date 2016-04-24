#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "math.h"
#include <iostream>

using namespace std;
using namespace cv;

Point intersectPoints(double rho1, double rho2, double theta1, double theta2) {
    double x = (rho2 * sin(theta1) - rho1 * sin(theta2)) / (cos(theta2) * sin(theta1) - cos(theta1) * sin(theta2));
    double y = (rho1 - x * cos(theta1)) / sin(theta1);
    return Point((int) round(x), (int) round(y));
}

void drawLine(Mat &image, double rho, double theta, Scalar colour) {
    if (abs(sin(theta)) < 0.00001) {
        line(image, Point(rho, 0), Point(rho, image.rows), Scalar(1.0, 0.5, 0.2));
    }
    else {
        int x1 = 0;
        int y1 = (int) round((rho - (double) x1 * cos(theta)) / sin(theta));
        int x2 = image.cols;
        int y2 = (int) round((rho - (double) x2 * cos(theta)) / sin(theta));
        line(image, Point(x1, y1), Point(x2, y2), colour);
    }
}

int main() {
    namedWindow("main", CV_WINDOW_AUTOSIZE);
//    for (int i = 0; i < 36; i++) {
//        cout << i << endl;
//        Mat image = Mat(Size(640, 480), CV_32FC3, Scalar(0.0, 0.0, 0.0));
//        drawLine(image, 100 , CV_PI/2 + CV_PI / 9 * (double) i, Scalar(1.0,0.5,0.5));
//        imshow("main", image);
//        waitKey(0);
//    }
    Mat image = Mat(Size(640, 480), CV_32FC3, Scalar(0.0, 0.0, 0.0));
    Point p(1, 100);
    image.at<Vec3f>(p).val[2] = 0.9;
    drawLine(image, 100, 45 * CV_PI / 180, Scalar(1.0, 0.5, 0.5));
    drawLine(image, 0, 135 * CV_PI / 180, Scalar(0.5, 1.0, 0.5));
    Point ppp = intersectPoints(100,0,45 * CV_PI / 180,135 * CV_PI / 180);
    circle(image,ppp,3,Scalar(0.0,0.0,1.0),-1);
    cout << ppp << endl;
    imshow("main", image);
    waitKey(0);
    return 0;
}