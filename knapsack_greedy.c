#include<stdio.h>
#define MAX 10

struct fruits {
    int num;
    float value;
    float weight;
    float ratio;
};

int main() {
    struct fruits f[MAX], temp;
    int n, M, i, j; 
    float remaining, max_nutri_value = 0.0f;
    printf("PARNA MISHRA\t 60009220201\n");
    printf("ENTER THE NUMBER OF FRUITS: \n");
    scanf("%d", &n);
    printf("\nEnter the max capacity of the bag: \n");
    scanf("%d", &M);

    printf("\nFRUIT DETAILS:\n");
    for (i = 0; i < n; i++) {
        printf("\nEnter the sr no., value, weight of the fruit: ");
        scanf("%d %f %f", &f[i].num, &f[i].value, &f[i].weight);
        f[i].ratio = f[i].value / f[i].weight;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (f[j].ratio < f[j + 1].ratio) {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }

    remaining = M;
    printf("\nTHE OPTIMAL SOLUTION IS:\n");
    for (i = 0; i < n; i++) {
        if (f[i].weight <= remaining) {
            max_nutri_value += f[i].value;
            remaining -= f[i].weight;
            printf("fruit %d , ", f[i].num); 
        } else {
            max_nutri_value += f[i].value * (remaining / f[i].weight); 
            printf("fruit %d* %.2f\t",f[i].num, (remaining / f[i].weight)); 
            break; 
        }
    }
    printf("\nMaximum nutritional value: %.2f\n", max_nutri_value);

    return 0;
}