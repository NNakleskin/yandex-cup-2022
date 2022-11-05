#include <stdio.h>
#include <stdlib.h>


int main(void) {
    long long n = 0, k = 0;
    scanf("%lld%lld", &n, &k);
    int **board = malloc(n * sizeof(int));
    long long colour_count = n * n / k;
    int **colours = malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) {
        colours[i] = malloc(3 * sizeof(int));
        colours[i][0] = i + 1;
        colours[i][1] = 0;
    }
    for(int i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(int));
    }
    int index = 0;

    for(int i = 0; i < n; i++) {
        index = i % k;
        for(int j = 0; j < n; j++) {
            if(index >= k) {
                index = 0;
            }
            board[i][j] = colours[index][0];
            colours[index][1] += 1;
            if(colours[index][1] > colour_count) {
                printf("No\n");
                return 0;
            }
            index++;
        }
    }

    
    printf("Yes\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        putchar(10);
    }
    
    
    for(int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    for(int i = 0; i < k; i++) {
        free(colours[i]);
    }
    free(colours);
    return 0;
}
