
    {
        arr[i] = 0;
    }
    for (int i = count; i < size; i++)
    {
        arr[i] = 1;
    }
}

int main()
{
    int arr[11] = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    func(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

