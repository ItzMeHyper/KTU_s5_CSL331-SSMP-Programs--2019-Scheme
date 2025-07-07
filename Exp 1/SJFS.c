#include<stdio.h>

int main() {
    float wAvg = 0, tAvg = 0;
    int n, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bTime[n], wTime[n], tTime[n], pID[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bTime[i]);
        pID[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bTime[i] > bTime[j]) {
                int temp = bTime[i];
                bTime[i] = bTime[j];
                bTime[j] = temp;

                temp = pID[i];
                pID[i] = pID[j];
                pID[j] = temp;
            }
        }
    }

    wTime[0] = 0;
    for (int i = 1; i < n; i++) {
        wTime[i] = wTime[i - 1] + bTime[i - 1];
        wAvg += wTime[i];
    }

    for (int i = 0; i < n; i++) {
        tTime[i] = bTime[i] + wTime[i];
        tAvg += tTime[i];
    }

    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("\n P[%d]\t\t %d\t\t %d\t\t %d", pID[i], bTime[i], wTime[i], tTime[i]);
    }
    printf("\n");

    printf("\nAverage Turnaround Time = %.2f ms", tAvg / (float)n);
    printf("\nAverage Waiting Time = %.2f ms\n", wAvg / (float)n);

    printf("\nGANTT CHART: \n");
    printf("\t ");
    for (int i = 0; i < n; i++) {
        printf("-------- ");
    }
    printf("\n\t|");
    for (int i = 0; i < n; i++) {
        printf("  P[%d]  |", pID[i]);
    }
    printf("\n\t ");
    for (int i = 0; i < n; i++) {
        printf("-------- ");
    }

    printf("\n\t0");
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += bTime[i];
        printf("\t%d", temp);
    }
    printf("\n");
}