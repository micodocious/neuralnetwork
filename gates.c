#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float sigmoidf(float x)
{
    return 1.f / (1.f + expf(-x));
}

// OR-agate
float train[][3] = {
    {0,0,0},
    {1,0,1},
    {0,1,1},
    {1,1,1},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float cost(float w1, float w2)
{
    float result = 0.0f;
    for (size_t i =0; i<train_count; ++i){
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf(x1*w1 + x2*w2);
        float d = y - train[i][2];
        result += d*d;
    }
    result /= train_count;
    return result;
}

float rand_float(void)
{
    return (float) rand() / (float) RAND_MAX;
}

int main (void)
{

    /*
    for (float x = -10.f; x <=10.f; x+=1.f){
        printf("%f => %f\n", x, sigmoidf(x));
    }

    return 0;
    */
    srand(time(0));
    float w1 = rand_float()*10-5;
    float w2 = rand_float()*10-5;

    float eps = 1e-1;   // Small value for gradient approx
    float rate = 1e-1;  // Learning rate

    for(size_t i = 0; i < 50000; ++i){
        float c = cost(w1, w2); 
        //printf("w1 = %f, w2 = %f, c = %f\n", w1, w2, c);
        float dw1 = (cost(w1 + eps, w2) - c)/eps;   // Derivative
        float dw2 = (cost(w1, w2 + eps) - c)/eps;
        w1 -= rate*dw1; // Update gradient descent
        w2 -= rate*dw2; 
    }
    printf("w1 = %f, w2 = %f, c = %f\n", w1, w2, cost(w1,w2));

    for(size_t i = 0; i < 2; ++i){
        for(size_t j = 0; j < 2; ++j){
            printf("%zu | %zu = %f", i,j,sigmoidf(i*w1 + j*w2));
        }
    }

    return 0;
   


}
