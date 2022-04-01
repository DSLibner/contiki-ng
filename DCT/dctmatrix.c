#include "dctMatrix.h"
#include <math.h>
void DCT_Matrix(float matrix[8][8]){

    printf("Making DCT matrix\n");
    for (short k = 0; k < 8; k++)
    {
        
        for (short n = 0; n < 8; n++)
        {
            matrix[k][n] = cos(M_PI/(float)8*((float)n+0.5)*(float)k);
            printf("%d ", (int)(matrix[k][n]*100));
        }
        printf("\n");
    }
}

void INV_DCT_Matrix(float matrix[8][8]){
    int m = 8;
    float ci = 0;
    printf("Making DCT matrix\n");
    for (short k = 0; k < m; k++)
    {
        if (k == 0)
            ci = sqrt(1/(float)m);
        else
            ci = sqrt(2/(float)m);
        for (short n = 0; n < m; n++)
        {
            matrix[k][n] = ci * cos(M_PI/(float)m*((float)k+0.5)*(float)n);
            printf("%d ", (int)(matrix[k][n]*100));
        }
        printf("\n");
    }
}

void DCT_Transform(float Matrix[8])
{
    float ci = 0;
    float dct;
    for (short k = 0; k < 8; k++)
    {
        if (k == 0)
            ci = sqrt(1/(float)8);
        else
            ci = sqrt(2/(float)8);
        dct = 0;
        for (short n = 0; n < 8; n++)
        {
            dct += TheDCTMatrix[k][n]*Matrix[n];
        }
        Matrix[k] = ci*dct;
    }
    printf("\n");
}

void inv_DCT_Transform(float Matrix[8])
{
    float ci = 0;
    float tempMatrix[8] = {0};
    for (short k = 0; k < 8; k++) {
        if (k == 0)
            ci = sqrt(1/(float)8);
        else
            ci = sqrt(2/(float)8);
        for (short i = 0; i < 8; i++) {
            tempMatrix[k] += Matrix[i] * cos(3.14/((float)8)*(k+0.5)*i)*ci;         
        }
        
    }
    for (short i = 0; i < 8; i++)
    {
        Matrix[i] = tempMatrix[i];
    }
    
    printf("\n");
}

void DCT_Transform_preload(float Matrix[8], float TheMatrix[8][8])
{
    
}

void inv_DCT_Transform_preload(float Matrix[8], float TheMatrix[8][8])
{
    
}
