#include <stdio.h>
#include <stdlib.h>

#define WIDTH 200
#define HEIGHT 300

void createPPMFile() {
    FILE *file = fopen("input.ppm", "wb");
    if (!file) {
        perror("File created");
        return;
    }

    int i, j;
    int imageSize = WIDTH * HEIGHT;
    unsigned char color[3] = {35, 35, 35}; // Color of small black rectangle

    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT); // PPM header information

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if ((i >= (HEIGHT - 35) / 2) && (i < (HEIGHT + 35) / 2) && (j >= (WIDTH - 25) / 2) && (j < (WIDTH + 25) / 2)) {
                fwrite(color, 1, 3, file);
            } else {
                unsigned char bgColor[3] = {110, 135, 27};
                fwrite(bgColor, 1, 3, file);
            }
        }
    }

    fclose(file);
}

int main() {
    createPPMFile();
    printf("Saved in file named 'input.ppm'\n");
    return 0;
}
