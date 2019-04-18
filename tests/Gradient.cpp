#include<iostream>
using namespace std;

#include <opencv2/core.hpp>
using namespace cv;

#include "equal.hpp"

#include "../src/inpainter/Gradient.h"

int main()
{
    Mat origial_01 = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    Mat origial_02 = (Mat_<double>(3,3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat expected_01_01 =  (Mat_<double>(6,3) << -1, 6, -1, 0, 0, 0 , 1 , -6, 1, -1, 0, 1, 6, 0, -6, -1, 0, 1);
    bool TEST_PASS = true;
    TEST_PASS = TEST_PASS && equal(Gradient(origial_01),expected_01_01);
    cout << (origial_02)  << endl;
    cout << "====" << endl;
    cout << Gradient(origial_02)  << endl;
    cout << "====" << endl;

    if(TEST_PASS){
        return 0;
    }else{
        return 1;
    }
}