#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//if we give it 2 it will return 4
float train[][2] = {
    {0, 0}, 
    {1, 2},
    {2, 4}, 
    {3, 6},
    {4, 8},
};
#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}
float cost(float w, float bias)
{
    float result = 0.0f;
    for (size_t i =0; i<train_count; ++i){
        float x = train[i][0];
        float y = x*w + bias;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main()
{
    // y = x*w;
    srand(69);
    float w = rand_float()*1.0f;
    // adding another parameter
    float bias = rand_float()*5.0f;
    //float w = 1.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", cost(w, bias));
    for (size_t i = 0; i < 5000; ++i){
        float c = cost(w, bias);
        float dw = (cost(w + eps, bias) - c)/eps;
        float db = (cost(w, bias + eps) - c)/eps;
        w -= rate*dw;
        bias -= rate*db;
        printf("cost = %f, w = %f, b = %f\n", cost(w, bias), w, bias);
    }
    printf("-----------------------------\n");
    printf("%f\n", w);
    return 0;
}