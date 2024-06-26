#include <stdio.h>

float t_profit = 0;
float x[50];

void display(int n)
{
    int i;
    printf("\nMaximum profit is:- %f\n", t_profit);
}

void sort_Descending(int n, float *weight, float *profit, float *ratio)
{
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
}

void Greedy_fract_knapsack(int n, float *weight, float *profit, float capacity)
{
    int i;
    float ratio[n];
    float u = capacity;

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    sort_Descending(n, weight, profit, ratio);

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            float x = u / weight[i];
            t_profit = t_profit + (x * profit[i]);
            break;
        }
        else
        {
            t_profit = t_profit + profit[i];
            u = u - weight[i];
        }
    }


    display(n);
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i;

    printf("\nEnter the number of items: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each item:\n");
    for (i = 0; i < num; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    Greedy_fract_knapsack(num, weight, profit, capacity);

    return 0;
}
