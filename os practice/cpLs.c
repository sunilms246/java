#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    FILE *fps, *fpd;
    char sours[20], destination[20], buff;
    printf("\nEnter sorce file name : ");
    scanf("%s", sours);
    printf("\nEnter destination file name :");
    scanf("%s", destination);
    fps = fopen(sours, "r");
    fpd = fopen (destination, "w");
    if(fps == NULL || fpd == NULL){
        printf("Error in opening file\n");
        exit(1);
    }
    while((buff = fgetc(fps)) != EOF){
        fputc(buff, fpd);
    }
    fclose(fps);
    fclose(fpd);
    printf("cp sucessfully complete");
    return 0;
}