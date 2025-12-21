#include<stdio.h>
#include<stdlib.h>
int main(){
    int pnum[20], arr[20], burst[20],start[20], finish[20], wait[20], tat[20], tottat = 0, totwt = 0;
    int n;
    pritnf("Enter number of process ");
    scanf("%d", &n);
    printf("process no , arr , burst\n");
    for (int i=0; i<n; i++){
        scanf("%d %d %d",&pnum[i], &arr[i], &burst[i]);
    }
    for(int i=0; i<n; i++){
        if(i=0){
            start[i] = arr[i];
            wait[i] = start[i] - arr[i];
            finish[i] = start[i] + burst[i];
            tat[i] = finish[i] - arr[i];
        }
        else{
            start[i] = finish[i-1];
            wait[i] = start[i] -arr[i];
            finish[i] = start[i] + burst[i];
            tat[i] = finish[i] - arr[i];

        }
    }

    pintf("\nprocess\tarrival\tburst\tturnaround\twait\n");
    for(int i= 0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pnum[i], arr[i], burst[i], tat[i], wait[i]);
        tottat += tat[i];
        totwt += wait[i];
    }
    printf("\nAverage waiting time = %f", (float) totwt/n);
    printf("\nAverage turnaround time = %f", (float) tottat/n);
    return 0;
}