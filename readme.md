# Linear Regression with Gradient Descent in C

## Overview

This C program demonstrates a simple linear regression model using gradient descent. The goal is to find the best-fit line for a set of training data, where each input \( x \) corresponds to an output \( y \). The program iteratively optimizes the weight \( w \) and bias \( b \) to minimize the cost function.

## Code Explanation

### 1. **Including Standard Libraries**
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```
- `stdio.h`: For standard input and output functions (`printf`).
- `stdlib.h`: For random number generation (`rand()`).
- `time.h`: Not used in this code but typically used for seeding random values.

### 2. **Training Data**
```c
float train[][2] = {
    {0, 0}, 
    {1, 2},
    {2, 4}, 
    {3, 6},
    {4, 8},
};
#define train_count (sizeof(train)/sizeof(train[0]))
```
- This represents a dataset where \( y = 2x \).
- `train_count` calculates the number of training samples.

### 3. **Random Float Generator**
```c
float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}
```
- Generates a random float between 0 and 1.

### 4. **Cost Function**
```c
float cost(float w, float bias)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i){
        float x = train[i][0];
        float y = x * w + bias;
        float d = y - train[i][1];
        result += d * d;
    }
    result /= train_count;
    return result;
}
```
- Computes the mean squared error (MSE) between predicted and actual values.
- Formula:  
  \[
  \text{cost}(w, b) = \frac{1}{N} \sum_{i=1}^{N} (w x_i + b - y_i)^2
  \]
- Measures how far the current line is from the actual data.

### 5. **Main Function**
```c
int main()
{
    srand(69);
    float w = rand_float() * 1.0f;
    float bias = rand_float() * 5.0f;
```
- Initializes `w` (weight) and `bias` with small random values.

```c
    float eps = 1e-3;
    float rate = 1e-3;
```
- `eps`: A small value for numerical differentiation (gradient estimation).
- `rate`: Learning rate for gradient descent.

```c
    printf("%f\n", cost(w, bias));
```
- Prints initial cost.

```c
    for (size_t i = 0; i < 5000; ++i){
        float c = cost(w, bias);
        float dw = (cost(w + eps, bias) - c) / eps;
        float db = (cost(w, bias + eps) - c) / eps;
        w -= rate * dw;
        bias -= rate * db;
        printf("cost = %f, w = %f, b = %f\n", cost(w, bias), w, bias);
    }
```
- Uses **gradient descent** to update `w` and `b`:
  - \( \frac{d}{dw} \) and \( \frac{d}{db} \) are computed numerically.
  - Updates `w` and `b` using:  
    \[
    w = w - \text{rate} \times dw
    \]
    \[
    b = b - \text{rate} \times db
    \]
- Runs for **5000 iterations** to optimize the model.

```c
    printf("-----------------------------\n");
    printf("%f\n", w);
    return 0;
}
```
- Prints the final optimized weight.

---

## Expected Output

The program starts with random values for `w` and `b` and gradually adjusts them to fit the equation \( y = 2x \). The expected final `w` should be close to `2`, and `b` close to `0`.

Example output:
```
cost = 12.345678, w = 0.432, b = 3.210
...
cost = 0.000001, w = 1.999, b = 0.001
-----------------------------
1.999
```

---

## Summary

- Implements linear regression using **gradient descent**.
- Uses **numerical differentiation** to compute gradients.
- Adjusts `w` and `b` iteratively to minimize **mean squared error**.

