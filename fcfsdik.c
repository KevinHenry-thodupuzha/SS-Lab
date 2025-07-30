#include <stdio.h>
#include <stdlib.h>

#define MAXREQUEST 100 // Maximum number of disk requests allowed

// Function to calculate total seek time using FCFS (First Come First Serve)
int calculatetotal(int requests[MAXREQUEST], int n, int start) {
    int currenttrack = start;
    int totalseek = 0;
    int i;

    for(i = 0; i < n; i++) {
        int seektrack = abs(currenttrack - requests[i]); // Difference between current and requested track
        currenttrack = requests[i]; // Move head to the requested track
        totalseek += seektrack; // Add seek distance to total
    }

    return totalseek; // Return total distance moved (seek time)
}

int main() {
    int n, start, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAXREQUEST) {
        printf("Error: Invalid number of requests.\n");
        return 1;
    }

    int requests[n]; // Array to hold the track requests

    for(i = 0; i < n; i++) {
        printf("Enter request[%d]: ", i);
        scanf("%d", &requests[i]);
    }

    printf("Enter the starting track position: ");
    scanf("%d", &start);

    int totalseek = calculatetotal(requests, n, start);

    printf("Total Seek Time: %d\n", totalseek);

    return 0;
}

