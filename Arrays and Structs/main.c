#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define VARNAME(x) (#x)


int main() {
    void displayArray(int arr[], int size);

    int nums[5] = {4, 3, 2, 5, 1};
    displayArray(nums, 5);

    int grades[2][2] = {1,2,3,4};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("grades[%d][%d]=%d\n", i, j, grades[i][j]);
        }
    }

    return 0;
}

void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i != size - 1)
            printf("%d, ", arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("]\n");
}

