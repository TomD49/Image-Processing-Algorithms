#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

void blur(unsigned char* img, int num_of_cols, int num_of_rows);

vector<float> gradientCalculation(unsigned char* img, int num_of_cols, int num_of_rows);

void nonMaxSuppression(unsigned char* img, int num_of_cols, int num_of_rows, vector<float> angles);

unsigned char findArea(unsigned char value);

void doubleTresholding(unsigned char* img, int num_of_cols, int num_of_rows);

void hysteresis(unsigned char* img, int num_of_cols, int num_of_rows);
