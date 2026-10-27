/*Read the number of items, their profits, weights, and knapsack capacity W.
Calculate the ratio profit / weight for each item.
Sort items in descending order of this ratio.
Set total profit to zero.
Examine items in sorted order:
- If the entire item fits, take it and reduce the remaining capacity.
- Otherwise, take the fraction that fits and calculate its proportional profit.
Stop when the capacity becomes zero or no items remain.
Display the maximum total profit.*/


#include <stdio.h>
int main()
{
    int n, i, j;
    float k;
    float w[100], p[100], pw[100];
    float temp;
    float totalProfit = 0;
    printf("Enter the knapsack capacity: ");
    scanf("%f", &k);
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("\nEnter the weights:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &w[i]);
    }
    printf("\nEnter the profits:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &p[i]);
    }
    // Calculate profit/weight ratio
    for(i = 0; i < n; i++)
    {
        pw[i] = p[i] / w[i];
    }
    // Sort according to ratio in descending order
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pw[i] < pw[j])
            {
                // Swap ratio
                temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;
                // Swap weights
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
	            // Swap profits
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nObjects after sorting:\n");
    printf("Weight\tProfit\tP/W Ratio\n");
    for(i = 0; i < n; i++)
    {
        printf("%.2f\t%.2f\t%.2f\n", w[i], p[i], pw[i]);
    }
    printf("\nSelected Objects:\n");
    // Fractional Knapsack
    for(i = 0; i < n; i++)
    {
        if(k >= w[i])
        {
            printf("Take object %d completely\n", i + 1);
            k -= w[i];
            totalProfit += p[i];
        }
        else
        {
            float fraction = k / w[i];
            printf("Take %.2f fraction of object %d\n", fraction, i + 1);
            totalProfit += fraction * p[i];
            k = 0;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}

