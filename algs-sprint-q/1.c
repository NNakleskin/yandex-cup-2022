#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long n, k;
    scanf("%d%d", &n, &k);
    int **board = calloc(n, sizeof(int));
    int colour_count = n * n / k;
    int **colours = calloc(k, sizeof(int));
    for(int i = 0; i < k; i++) {
        colours[i] = calloc(2, sizeof(int));
        colours[i][0] = i + 1;
    }
    for(int i = 0; i < n; i++) {
        board[i] = calloc(n, sizeof(int));
    }
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(index >= k) {
                index = 0;
            }
            board[i][j] = colours[index][0];
        }
    }

    for(int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}