#include <stdio.h>
#include <string.h>

typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;

void displayJobSequence(Job jobs[], int dmax, int timeslot[], int maxprofit) {
    printf("\nRequired Jobs: ");
    for (int i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1) {
            printf("%s", jobs[timeslot[i]].id);
            if (i < dmax) {
                printf(" --> ");
            }
        }
    }
    printf("\nMax Profit: %d\n", maxprofit);
}

int minValue(int x, int y) {
    return (x < y) ? x : y;
}

void sort(Job jobs[], int n) {
    int i, j;
    Job temp;

    // Sort the jobs profit-wise in descending order
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (jobs[j + 1].profit > jobs[j].profit) {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("Sorted jobs\n");
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++) {
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
}

void jobSequencingWithDeadline(Job jobs[], int n) {
    int i, j, k, maxprofit = 0;
    int filledTimeSlot = 0;
    int dmax = 0;

    // Sort the jobs profit-wise in descending order
    sort(jobs, n);

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }
    int timeslot[dmax + 1];

    // Free time slots initially set to -1 (EMPTY)
    for (i = 1; i <= dmax; i++) {
        timeslot[i] = -1;
    }

    printf("Maximum deadline: %d\n", dmax);

    for (i = 0; i < n; i++) {
        k = minValue(dmax, jobs[i].deadline);
        while (k >= 1) {
            if (timeslot[k] == -1) {
                timeslot[k] = i;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        // If all time slots are filled, then stop
        if (filledTimeSlot == dmax) {
            break;
        }
    }

    // Calculate the required profit
    for (i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1) {
            maxprofit += jobs[timeslot[i]].profit;
        }
    }

    displayJobSequence(jobs, dmax, timeslot, maxprofit);
}

int main(void) {
    int i, n;
    

    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];

    printf("\nEnter the job id, deadline, and profit for each job:\n");
    for (i = 0; i < n; i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencingWithDeadline(jobs, n);

    return 0;
}
