//Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i,
//return true if you can visit all the rooms, or false otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** rooms, int* roomSizes, int* visited, int room) {
    visited[room] = 1;

    for (int i = 0; i < roomSizes[room]; i++) {
        int nextRoom = rooms[room][i];

        if (visited[nextRoom] == 0) {
            dfs(rooms, roomSizes, visited, nextRoom);
        }
    }
}

bool canVisitAllRooms(int** rooms, int n, int* roomSizes) {
    int* visited = (int*)calloc(n, sizeof(int));

    dfs(rooms, roomSizes, visited, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomSizes[i]);

        rooms[i] = (int*)malloc(roomSizes[i] * sizeof(int));

        if (roomSizes[i] > 0) {
            printf("Enter keys in room %d: ", i);

            for (int j = 0; j < roomSizes[i]; j++) {
                scanf("%d", &rooms[i][j]);
            }
        }
    }

    if (canVisitAllRooms(rooms, n, roomSizes)) {
        printf("Output: true\n");
    }
    else {
        printf("Output: false\n");
    }

    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }

    free(rooms);
    free(roomSizes);

    return 0;
}