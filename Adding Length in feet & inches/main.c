#include <stdio.h>
#include <stdlib.h>

struct len
{
    int feet;
    float inch;
} len1,len2,lensum;

int main()
{
    printf("Enter first Length : \n Feet : ");
    scanf("%d",&len1.feet);
    printf(" Inch : ");
    scanf("%f",&len1.inch);
    printf("\nEnter second Length : \n Feet : ");
    scanf("%d",&len2.feet);
    printf(" Inch : ");
    scanf("%f",&len2.inch);
    lensum.feet=len1.feet+len2.feet;
    lensum.inch=len1.inch+len2.inch;
    for ( ;lensum.inch>=12;lensum.inch-=12)
    {
        lensum.feet++;
    }
    printf("Total Length = %d feet %f inches",lensum.feet,lensum.inch);
    return 0;
}
