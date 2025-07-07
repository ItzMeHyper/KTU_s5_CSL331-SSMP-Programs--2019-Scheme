#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, r, i, j, k = 0, c = 0, flag = 0, exec = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int visit[n];
    int a[n];

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], avail[r], need[n][r];

    printf("\nEnter the available resources: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    printf("\nEnter the allocation of processess: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter the max resources of processess: \n");
    for (i = 0; i < n; i++) {
        visit[i] = 0;
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < r; j++) printf("%d ", alloc[i][j]);
        printf("\t\t");
        for (j = 0; j < r; j++) printf("%d ", max[i][j]);
        printf("\t\t");
        for (j = 0; j < r; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    while (c < n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            exec = 0;

            for (j = 0; j < r; j++) {
                if (need[i][j] <= avail[j]) {
                    exec++;
                }
            }

            if (exec == r && visit[i] == 0) {
                for (j = 0; j < r; j++) {
                    avail[j] += alloc[i][j];
                }
                flag = 1;
                visit[i] = 1;
                c++;
                a[k++] = i;
            }
        }

        if (flag == 0) {
            printf("No safe sequence found!\n");
            exit(0);
        }
    }

    printf("\nSafe Sequence: \n");
    printf("<");
    for (i = 0; i < n; i++) {
        printf("P%d ", a[i]);
    }
    printf(">\n");
}