#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};

#define train_count (sizeof(train)/sizeof(train[0]))

float cost(float w, float b)
{
   float result = 0.0f;
   for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = (x * w) + b;
    float d = y - train[i][1];
    result += d*d;
   }
   result /= train_count;
   return result;
}   

float rand_float(void)
{
    return (float) rand() / (float) RAND_MAX;
}

int main()
{
    // y = x * w
    srand(time(0)); // seed for rand()
    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;

    float learning_rate = 1e-2;
    float h = 1e-3;
    for (int i = 0; i < 300; i++) {
        float grad_w = (cost(w+h, b) - cost(w, b)) / h;
        float grad_b = (cost(w, b+h) - cost(w, b)) / h;
        w -= learning_rate * grad_w;
        b -= learning_rate * grad_b;
        printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }
    printf("--------------------\n");
    printf("%f\n", w);
    printf("%f\n", b);
    

    return 0;
}
