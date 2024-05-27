#include <stdio.h>
#include <stdlib.h>

#define SIZE 45

int arr[SIZE];
int size;
int choice;

int hash_division(int key) {
    return key % size;
}

int hash_multiplication(int key) {
    float A = 0.618033;
    return (int)(size * (key * A - (int)(key * A)));
}

int hash_mid_square(int key) {
    int square = key * key;
    int digits = 0;
    int temp = square;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    int middle = square;
    for (int i = 0; i < (digits / 2); i++) {
        middle /= 10;
    }
    middle %= size;

    return middle;
}

void create() {
    printf("ENTER TABLE SIZE (<45) : ");
    scanf("%d", &size);

    int temp_size = size;

    for (int i = 0; i < temp_size; i++) {
        if (i > 0.7 * size) {
            size = size * 2;
            int cnt = 0;
            do {
                cnt = 0;
                for (i = 2; i <= size / 2; i++) {
                    if (size % i == 0) {
                        cnt++;
                    }
                }
                size++;
            } while (cnt != 0);
            size--;
        }

        int val;
        scanf("%d", &val);
        int idx;

        switch (choice) {
            case 1:
                idx = hash_division(val);
                break;
            case 2:
                idx = hash_multiplication(val);
                break;
            case 3:
                idx = hash_mid_square(val);
                break;
            default:
                printf("Invalid choice.\n");
                return;
        }

        if (arr[idx] == 0) {
            arr[idx] = val;
        } else {
            int k = 1;
            while (arr[idx] != 0) {
                idx = (idx + k) % size;
                k++;
            }
            arr[idx] = val;
        }
    }

    printf("Hash table using the selected hash function:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", i, arr[i]);
    }
}

int main() {
    printf("Choose a hash function:\n");
    printf("1. Division Method\n");
    printf("2. Multiplication Method\n");
    printf("3. Mid-Square Method\n");

    scanf("%d", &choice);

    create();

    return 0;
}
