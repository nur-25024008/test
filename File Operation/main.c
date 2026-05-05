#include <stdio.h>
int main()
{
    FILE *file;
    char data[255],coded[225];
    printf("Open A file\n");
    file=fopen("text.txt","a+");
    while(fscanf(file,"%s", data)!=EOF)
    {
        printf("%s",data);
    }
    fprintf(file,"\n 2nd line printed by code \n 3nd line printed by code in the same function");
    fscanf(file,"%s", coded);
    printf("Printed output : \n %s",coded);
    fclose(file);
    return 0;
}
