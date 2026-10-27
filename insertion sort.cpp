/*Read n and the array.
Start from the second element, i = 1.
Store A[i] in key.
Compare key with the elements before it.
Shift every element greater than key one position to the right.
Insert key into the empty position.
Repeat for all elements.
Display the sorted array.*/

#include<stdio.h>
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) 
	{
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) 
		{
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void display(int a[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main() 
{
    int a[100], n, i, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    printf("Insertion Sort: ");
    display(a, n);
    return 0;
}

