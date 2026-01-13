#include <stdio.h>

int main(int argc, char **argv) {
    int value = 0;
    float value_2 = 0.0;
    int a = 5;
    int b = 8;

    value = b / a;           // truncated
    printf("%d\n", value);
    value_2 = b / a;         // truncated then coersed
    printf("%f\n", value_2);
    value_2 = b / (float)a;  // b is coersed to match the less restricted a
    printf("%f\n", value_2);
    value_2 = (float)b / a;  // same as before.
    printf("%f\n", value_2);
}
