#include "craftix.h"

#define WIDTH 250
#define HEIGHT 250

int main(void) {

    uint32_t pixels[WIDTH * HEIGHT];
    
    craftix_fill(pixels, WIDTH, HEIGHT, 0x000000);

    craftix_draw_rect(pixels, WIDTH, HEIGHT, 0, 0, 80, 40, 0x808080);

    craftix_draw_circle(pixels, WIDTH, HEIGHT, 75, 75, 15, 0xFF0000);
    
    craftix_draw_line(pixels, WIDTH, HEIGHT, 10, 150, 70, 220, 0x202020);
    
    save_ppm_file(pixels, WIDTH, HEIGHT, "output.ppm");
    
    
    return 0;
}