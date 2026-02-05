//Problem: A system receives two separate logs of user arrival times from two different servers.
//Each log is already sorted in ascending order.
//Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {

    int p, q;

    printf("Number of entries in server log 1 --> ");
    scanf("%d", &p);
    int log1[p];

    printf("Enter %d entries: ", p);
    for(int i = 0; i < p; i++){
        scanf("%d", &log1[i]);
    }

    printf("Number of entries in server log 2 --> ");
    scanf("%d", &q);
    int log2[q];

    printf("Enter %d entries: ", q);
    for(int j = 0; j < q; j++){
        scanf("%d", &log2[j]);
    }

    int log[p + q];
    int i = 0, j = 0, k = 0;

    while(i < p && j < q){
        if(log1[i] <= log2[j]){
            log[k++] = log1[i++];
        }
        else{
            log[k++] = log2[j++];
        }
    }

    while(i < p){
        log[k++] = log1[i++];
    }

    while(j < q){
        log[k++] = log2[j++];
    }

    printf("Merged chronological log: ");
    for(int i = 0; i < p + q; i++){
        printf("%d ", log[i]);
    }

    return 0;
}