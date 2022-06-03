#include <stdio.h>

float tocelsius(float fahren);

int main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d%8.2f\n", fahr, tocelsius(fahr));
    }
    return 0;
}

float tocelsius(float fahren)
{
    return (5.0/9.0)*(fahren-32);
}
