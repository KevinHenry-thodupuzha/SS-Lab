#include <stdio.h>
#define MAX 20

int main() {
    int numP, numR;
    int max[MAX][MAX], alloc[MAX][MAX], need[MAX][MAX];
    int aval[MAX], finish[MAX], safeSeq[MAX], work[MAX];
    int i, j, k, count = 0, ind = 0;

    // Input number of processes and resources
    printf("Enter the number of processes and resources:\n");
    scanf("%d %d", &numP, &numR);

    // Input Max matrix
    printf("\nEnter Max matrix (%d rows with %d values each):\n", numP, numR);
    for (i = 0; i < numP; i++)
        for (j = 0; j < numR; j++)
            scanf("%d", &max[i][j]);

    // Input Allocation matrix
    printf("\nEnter Allocation matrix (%d rows with %d values each):\n", numP, numR);
    for (i = 0; i < numP; i++)
        for (j = 0; j < numR; j++)
            scanf("%d", &alloc[i][j]);

    // Input Available resources
    printf("\nEnter Available resources (%d values):\n", numR);
    for (j = 0; j < numR; j++)
        scanf("%d", &aval[j]);

    // Calculate Need matrix = Max - Allocation
    for (i = 0; i < numP; i++)
        for (j = 0; j < numR; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize work and finish arrays
    for (j = 0; j < numR; j++)
        work[j] = aval[j];

    for (i = 0; i < numP; i++)
        finish[i] = 0;

    // Banker's Algorithm
    while (count < numP) {
        int found = 0;
        for (i = 0; i < numP; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (j = 0; j < numR; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (k = 0; k < numR; k++)
                        work[k] += alloc[i][k];
                    safeSeq[ind++] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is in an unsafe state.\n");
            return 0;
        }
    }

    // Output safe sequence
    printf("\nSystem is in a safe state.\nSafe sequence: ");
    for (i = 0; i < numP; i++) {
        printf("P%d", safeSeq[i]);
        if (i != numP - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}

