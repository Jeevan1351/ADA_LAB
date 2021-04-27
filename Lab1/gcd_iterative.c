#include <stdio.h>



int euclid(int a, int b)
{

    while (a != b)
    {

        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }

    return a;
}


int main()
{
    int a, b;
	printf("Enter the values of a and b:\t");
	scanf("%d %d", &a, &b);
    printf("\nGCD(%d, %d) = %d", a, b, euclid(a, b));
    return 0;
}

