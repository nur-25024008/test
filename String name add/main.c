#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[10],str2[10],str3[10],str4[10];
    str1[0]=' ';
    str2[0]=' ';
    str3[0]=' ';
    str4[0]=' ';
    int length;
    printf("Enter Tittle or designation : \n");
    scanf("%s",&str1);
    printf("Enter first name : \n");
    scanf("%s",&str2);
    printf("Enter middle name : \n");
    scanf("%s",&str3);
    printf("Enter surname : \n");
    scanf("%s",&str4);
    strcat(str3, str4);
    strcat(str2, str3);
    strcat(str1, str2);
    length=strlen(str1);
    printf("Full \v name \r[size %d] : ",length);
    puts(str1);

    return 0;
}
