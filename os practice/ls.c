#include<stdlib.h>
#include<stdio.h>

#include<dirent.h>
int main(){
    struct dirent *direntp;
    DIR *dir;
    char name[20];
    printf("Enter directory name ");
    scanf("%s", name);
    dir = opendir(name);
    if(dir == NULL){
        pritnf("No such directory exist");
        exit(1);
    }
    while((direntp = readdir(dir)) != NULL){
        pritnf("\n%s", direntp->d_name);
    }
    closedir(dir);
    return 0;
    
}