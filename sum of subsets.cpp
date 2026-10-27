/*Read a set of distinct positive integers and the target sum.
Start with an empty subset and sum zero.
At each element, consider two choices:
- Include the element.
- Exclude the element.
If the current sum equals the target, display the selected subset.
If the current sum exceeds the target, stop exploring that branch.
If all elements are processed without reaching the target, return.
Continue until all valid subsets have been found.*/ 

#include <stdio.h>
int a[100], subset[100];
int n, target;
void sumOfSubsets(int index, int sum, int count) 
{
    int i;
    if (sum == target) 
	{
        printf("{ ");
        for (i = 0; i < count; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }
    if (index == n || sum > target)
        return;
    /* Include the current element */
    subset[count] = a[index];
    sumOfSubsets(index + 1,sum + a[index], count + 1);
    /* Exclude the current element */
    sumOfSubsets(index + 1, sum, count);
}
int main() 
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter distinct positive integers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);
    printf("Subsets with the given sum:\n");
    sumOfSubsets(0, 0, 0);
    return 0;
}

