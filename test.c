#include "craftix.h"

#define WIDTH 250
#define HEIGHT 250

int main(void) {
    uint32_t pixels[WIDTH * HEIGHT];
    craftix_fill(pixels, WIDTH, HEIGHT, 0xFF8080FF);
    save_ppm_file(pixels, WIDTH, HEIGHT, "output.ppm");
    return 0;
}