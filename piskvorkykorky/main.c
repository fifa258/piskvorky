#include <stdio.h>

#define SIZE 15
#define MIN 1

typedef struct {
    int row;
    int column;
} COORDINATES;

int buffer() {
    int character = 0;
    while (getchar() != '\n') {
        character++;
    }
    return character;
}

int input(const char *text1, const char *text2) {
    int number = 0;
    int character;

    printf("%s is playing\n", text1);
    do {
        printf("Enter %s:\n", text2);
        scanf("%d", &number);
        character = buffer();
        if (character != 0 || number < MIN || number > SIZE) {
            printf("You entered the wrong input.\n");
        }

    } while (character != 0 || number < MIN ||number > SIZE);

    return number;
}

void header() {
    printf("               N O U G T S  A N D  C R O S S E S\n");
    printf("--|------------------------------------------------------------\n");
    printf("--|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10| 11| 12| 13| 14| 15|\n");
    printf("--|------------------------------------------------------------\n");
}

void tablePrinter(const char p[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%2c |", p[i][j]);
        }
        printf("\n");
        printf("--|------------------------------------------------------------\n");
    }
}

int main(void) {
    char table[SIZE][SIZE] = {0};
    COORDINATES coordinates;

    coordinates.row = input("Cross", "row");
    coordinates.column = input("Cross", "column");

    table[coordinates.row - 1][coordinates.column - 1] = 'X';

    header();
    tablePrinter(table);
    return 0;
}
