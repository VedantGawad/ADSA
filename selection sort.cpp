/*Read the number of elements n and the array.
Set i = 0 to n - 2.
Assume the element at index i is the minimum. Set min = i.
Traverse the remaining array from j = i + 1 to n - 1.
If A[j] < A[min], update min = j.
Swap A[i] and A[min].
Repeat until the array is sorted.
Display the sorted array.*/

#include<stdio.h>
void selectionSort(int a[], int n) 
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) 
	{
        min = i;
        for (j = i + 1; j < n; j++) 
		{
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	int a[100], n, i;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter elements: ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    printf("Selection Sort: ");
    display(a, n);
    return 0;
}

