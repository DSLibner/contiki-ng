#pragma once
#include <stdio.h>
float TheDCTMatrix[8][8];
float TheInvDCTMatrix[8][8];
void INV_DCT_Matrix(float matrix[8][8]);
void DCT_Matrix(float [8][8]);
void DCT_Transform(float Matrix[8]);
void inv_DCT_Transform(float Matrix[8]);
void DCT_Transform_preload(float Matrix[8], float dctmat[8][8]);
void inv_DCT_Transform_preload(float Matrix[8], float dctmat[8][8]);