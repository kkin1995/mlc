#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// OR Gate
// float train[][3] = {
//    {0, 0, 0},
//    {0, 1, 1},
//    {1, 0, 1},
//    {1, 1, 1}
// };

// AND Gate
float train[][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
};

#define train_count (sizeof(train) / sizeof(train[0]))

float sigmoidf(float x) {
    return 1.f / (1.f + expf(-x));
}

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w1, float w2, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf(x1*w1 + x2*w2 + b);
        float d = y - train[i][2];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main(void)
{
    float h = 1e-3;
    float learning_rate = 1e-2;

    srand(time(0));
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    
    for (int i = 0; i < 1000000; i++) {
        float c = cost(w1, w2, b);
        float dw1 = (cost(w1 + h, w2, b) - c) / h;
        float dw2 = (cost(w1, w2 + h, b) - c) / h;
        float db = (cost(w1, w2, b + h) - c) / h;

        w1 -= learning_rate * dw1;
        w2 -= learning_rate * dw2;
        b -= learning_rate * db;

        //printf("Cost = %f, w1 = %f, w2 = %f, b = %f\n", cost(w1, w2, b), w1, w2, b);
    }
    printf("Cost = %f, w1 = %f, w2 = %f, b = %f\n", cost(w1, w2, b), w1, w2, b);

    for (size_t i = 0; i < train_count; i++) {
        printf("%1.0f | %1.0f = %f\n", train[i][0], train[i][1], sigmoidf(train[i][0] * w1 + train[i][1] * w2 + b));
    }
    
}
