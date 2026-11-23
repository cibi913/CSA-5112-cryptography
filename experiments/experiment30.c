
#include <stdio.h>

int main()
{
    int X, T, secondBlock, result;

    printf("Enter one-block message X: ");
    scanf("%d",&X);

    printf("Enter CBC-MAC value T: ");
    scanf("%d",&T);

    secondBlock = X ^ T;

    printf("\nFirst block X = %d\n",X);
    printf("MAC value T = %d\n",T);

    printf("Second block (X XOR T) = %d\n",secondBlock);

    printf("\nThe two-block message can produce the same CBC-MAC.\n");

    return 0;
}
