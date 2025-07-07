#include<stdio.h>

int main(){
    float wAvg=0, tAvg=0;
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bTime[n], wTime[n], tTime[n];
    
    for(int i=0; i<n; i++){
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &bTime[i]);
    }
    
    wTime[0] = 0;
    for(int i=1; i<n; i++){
        wTime[i] = wTime[i-1] + bTime[i-1];
        wAvg += wTime[i];
    }
    
    for(int i=0; i<n; i++){
        tTime[i] = bTime[i] + wTime[i];
        tAvg += tTime[i];
    }
    
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0; i<n; i++){
        printf("\n P[%d]\t\t %d\t\t %d\t\t %d", i+1, bTime[i], wTime[i], tTime[i]);
    }
    printf("\n");
    
    printf("\nAverage Turnaround Time = %.2f", tAvg / (float)n);
    printf("\nAverage Waiting Time = %.2f\n", wAvg / (float)n);
    
    printf("\nGANTT CHART: \n");
    printf("\t ");
    for(int i=0; i<n; i++){
        printf("-------- ");
    }
    printf("\n\t|");
    for(int i=0; i<n; i++){
        printf("  P[%d]  |", i+1);
    }
    printf("\n\t ");
    for(int i=0; i<n; i++){
        printf("-------- ");
    }
    
    printf("\n\t0");
    int temp = 0;
    for(int i=0; i<n; i++){
        temp += bTime[i];
        printf("\t%d", temp);
    }
    printf("\n");
}