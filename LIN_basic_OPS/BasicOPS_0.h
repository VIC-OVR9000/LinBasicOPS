#pragma once
#include "BasisVCTR.h"
int trial();
void BASE_transformation_3D();
vector<vector<double>> ConstructBASIS_MAT();
vector<vector<double>> MATRIX_PRODUCT(vector<vector<double>>, vector<vector<double>>);//teaser
vector<vector<double>> TRANSFORM(vector<vector<double>> X);
vector<vector<double>> Construct_MATRIX();//TBM
void PrintVCTR(vector<vector<double>> V);