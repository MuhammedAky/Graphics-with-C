#ifndef CRAFTIX_H
#define CRAFTIX_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h> // for size_t

void craftix_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);

void craftix_draw_rect(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
    int x1, int y1, int w, int h,
    uint32_t color);

void craftix_draw_circle(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
    int cx, int cy, int r,
    uint32_t color);

bool save_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path);

#endif // CRAFTIX_H