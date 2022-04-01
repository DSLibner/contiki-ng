#pragma once
#include <stdio.h>
#include <math.h>

double ** DCT_Matrix(void);
void DCT_Transform(double Matrix[8]);
void inv_DCT_Transform(double Matrix[8]);