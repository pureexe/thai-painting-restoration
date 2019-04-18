#include<iostream>
using namespace std;

#include <opencv2/core.hpp>
using namespace cv;

#include "equal.hpp"

#include "../src/inpainter/Graident.h"

int main()
{
    Mat origial_01 = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    Mat expected_01_01 =  (Mat_<double>(3,6) << -1, 6, -1, 0, 0, 0 , 1 , -6, 1, -1, 0, 1, 6, 0, -6, -1, 0, 1);
    bool TEST_PASS = TRUE;
    TEST_PASS = TEST_PASS && equal(Gradient(origial_01),expected_01_01);
    if(TEST_PASS){
        return 0;
    }else{
        return 1;
    }
}