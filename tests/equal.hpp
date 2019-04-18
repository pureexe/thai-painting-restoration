#pragma once

#include <opencv2/core.hpp>
using namespace cv;

bool equal(const Mat & a, const Mat & b)
{
    if ( (a.rows != b.rows) || (a.cols != b.cols) )
        return false;
    Scalar s = sum( a - b );
    return (s[0]==0) && (s[1]==0) && (s[2]==0);
}