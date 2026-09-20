#include <stdio.h>

#define MAX 100

void displayArray(int arr[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtEnd(int arr[], int *n, int value)
{
    if (*n >= MAX)
    {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    arr[*n] = value;
    (*n)++;
    printf("Inserted %d at end.\n", value);
}

void insertAtPosition(int arr[], int *n, int value, int position)
{
    int i;

    if (*n >= MAX)
    {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (position < 0 || position > *n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (i = *n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*n)++;
    printf("Inserted %d at position %d.\n", value, position);
}

void deleteAtPosition(int arr[], int *n, int position)
{
    int i;

    if (*n == 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    if (position < 0 || position >= *n)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Deleted element: %d\n", arr[position]);

    for (i = position; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main()
{
    int arr[MAX];
    int n = 5;
    int choice, value, position;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    printf("1D Array Operations Demo\n");
    printf("----------------------\n");

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Traverse / Display array\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from specific position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(arr, n);
            break;

        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(arr, &n, value);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(arr, &n, value, position);
            break;

        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(arr, &n, position);
            break;

        case 5:
            printf("Program ended.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
