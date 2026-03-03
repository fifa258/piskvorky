#include <stdio.h>

#define SIZE 15
#define MIN 1
#define WIN_COUNT 5

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
    } while (character != 0 || number < MIN || number > SIZE);

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

int checkWin(char table[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char symbol = table[i][j];
            if (symbol == 0) continue;

            // horizontalni
            if (j + WIN_COUNT <= SIZE) {
                int count = 0;
                for (int k = 0; k < WIN_COUNT; k++)
                    if (table[i][j + k] == symbol) count++;

                if (count == WIN_COUNT) return 1;
            }

            // vertikalni
            if (i + WIN_COUNT <= SIZE) {
                int count = 0;
                for (int k = 0; k < WIN_COUNT; k++)
                    if (table[i + k][j] == symbol) count++;

                if (count == WIN_COUNT) return 1;
            }

            // diagonalni
            if (i + WIN_COUNT <= SIZE && j + WIN_COUNT <= SIZE) {
                int count = 0;
                for (int k = 0; k < WIN_COUNT; k++)
                    if (table[i + k][j + k] == symbol) count++;

                if (count == WIN_COUNT) return 1;
            }

            // diagonalni druhy smer
            if (i + WIN_COUNT <= SIZE && j - WIN_COUNT >= -1) {
                int count = 0;
                for (int k = 0; k < WIN_COUNT; k++)
                    if (table[i + k][j - k] == symbol) count++;

                if (count == WIN_COUNT) return 1;
            }
        }
    }

    return 0;
}

int checkChar(char table[SIZE][SIZE], COORDINATES coor) {
    return table[coor.row - 1][coor.column - 1] != 0;
}

int main(void) {
    char table[SIZE][SIZE] = {0};
    COORDINATES coordinates;


    header();
    tablePrinter(table);

    do {
        do {
            coordinates.row = input("Cross", "row");
            coordinates.column = input("Cross", "column");

            if (checkChar(table, coordinates)) {
                printf("This position is already taken!\n");
            }
        } while (checkChar(table, coordinates));

        table[coordinates.row - 1][coordinates.column - 1] = 'X';

        header();
        tablePrinter(table);

        if (checkWin(table)) {
            printf("Cross is the winner!\n");
            return 0;
        }

        do {
            coordinates.row = input("Nought", "row");
            coordinates.column = input("Nought", "column");

            if (checkChar(table, coordinates)) {
                printf("This position is already taken!\n");
            }
        } while (checkChar(table, coordinates));

        table[coordinates.row - 1][coordinates.column - 1] = 'O';

        header();
        tablePrinter(table);

        if (checkWin(table)) {
            printf("Nought is the winner!\n");
            return 0;
        }
    } while (checkWin(table) == 0);

    return 0;
}
