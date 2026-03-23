#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void star(unsigned int size);

unsigned int convert(char *st) {
    char *x;
    for (x = st; *x; x++) {
        if (!isdigit(*x)) {
            return 1;
        }
    }
    return (strtoul(st, 0L, 10));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Usage: ./star <start_number>\n", 29);
        write(2, "Example: ./star 5\n", 18);
        return 1;
    }

    star(convert(argv[1]));

    return 0;
}

void star(unsigned int size) {
    if (size == 0) {
        return;
    }

    // Set the pre-defined dimensions
    int rows = (size * 6) - 1;
    int cols = (size * 4) + 1;

    if (size == 1) {
        rows = 7;
        cols = 5;
    }

    char canva[cols][rows];

    // Initialize the canvas with spaces
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            canva[i][j] = ' ';
        }
    }

    // Top and bottom tips of the star
    int center = (rows - 1) / 2;

    if (size == 1) {
        canva[0][3] = '*';
        canva[cols - 1][3] = '*';
    } else {
        canva[0][center] = '*';
        canva[cols - 1][center] = '*';
    }

    for (int i = 0; i < (int)size; i++) {
        canva[i][center + i] = '*';
        canva[i][center - i] = '*';
    }

    for (int i = size - 1; i > 0; i--) {
        canva[cols - 1 - i][center + i] = '*';
        canva[cols - 1 - i][center - i] = '*';
    }

    // Sides of the star
    for (int i = 0; i < (int)size - 1; i++) {
        canva[size + i + 1][i + 1] = '*';
        canva[size + i + 1][rows - 2 - i] = '*';
    }

    for (int i = size - 1; i > 0; i--) {
        canva[(size * 2) + i][size - i] = '*';
        canva[(size * 2) + i][rows - size + i - 1] = '*';
    }

    canva[(size * 2)][size] = '*';
    canva[(size * 2)][rows - size - 1] = '*';

    // Horizontal lines of the star
    if (size == 1) {
        for (int i = 0; i < 3; i++) {
            canva[size][i] = '*';
            canva[size][rows - i - 1] = '*';
        }
    } else {
        for (int i = 0; i < (int)(size * 2) + 1; i++) {
            canva[size][i] = '*';
            canva[size][rows - 1 - i] = '*';
        }
    }

    for (int i = (size * 2) + 1; i > 0; i--) {
        canva[cols - size - 1][i - 1] = '*';
        canva[cols - size - 1][rows - i] = '*';
    }

    // Render canvas and trim trailing spaces
    for (int i = 0; i < cols; i++) {
        int last_star_index = -1;

        for (int j = 0; j < rows; j++) {
            if (canva[i][j] == '*') {
                last_star_index = j;
            }
        }

        if (last_star_index != -1) {
            for (int j = 0; j <= last_star_index; j++) {
                write(1, &(canva[i][j]), 1);
            }
        }
        write(1, "\n", 1);
    }
}