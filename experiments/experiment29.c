
#include <stdio.h>

int main()
{
    int blockSize = 1024;
    int stateSize = 1600;
    int capacity = stateSize - blockSize;

    int lanes = 64;
    int capacityLanes = capacity / lanes;

    printf("SHA-3 State Size = %d bits\n",stateSize);
    printf("Block Size = %d bits\n",blockSize);
    printf("Capacity = %d bits\n",capacity);

    printf("Lane Size = %d bits\n",lanes);
    printf("Capacity Lanes = %d\n",capacityLanes);

    printf("\nInitially all capacity lanes are zero.\n");
    printf("Without applying the permutation, absorption does not\n");
    printf("change the capacity lanes.\n");
    printf("Therefore, they remain zero indefinitely.\n");

    return 0;
}
