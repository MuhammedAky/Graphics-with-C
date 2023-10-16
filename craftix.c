#include "craftix.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Save pixel data to a PPM file
bool save_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path) {
    // Open the file for writing in binary mode
    FILE *f = fopen(file_path, "wb");

    if (!f) {
        perror("File opening error");
        return false;
    }

    // Write the PPM header with the image dimensions and maximum color value
    fprintf(f, "P6\n%zu %zu\n255\n", width, height);

    // Iterate through the pixel array and write RGB values to the file
    for (size_t i = 0; i < width * height; ++i) {
        uint32_t pixel = pixels[i];
        uint8_t bytes[3] = {
            (pixel >> 16) & 0xFF,  // Red
            (pixel >> 8) & 0xFF,   // Green
            pixel & 0xFF           // Blue
        };

        // Write the RGB values as binary data
        fwrite(bytes, sizeof(bytes), 1, f);

        if (ferror(f)) {
            perror("Data writing error");
            fclose(f);
            return false;
        }
    }

    // Close the file and return success
    fclose(f);
    return true;
}

// Fill the pixel array with a specified color and save it to a default file
void craftix_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color) {
    // Fill the pixel array with the specified color
    for (size_t i = 0; i < width * height; ++i) {
        pixels[i] = color;
    }
}

void craftix_draw_rect(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
    int x1, int y1, int w, int h,
    uint32_t color) {

    int x2 = x1 + w;
    int y2 = y1 + h;
        
    for (int y = y1; y <= y2; ++y) {
        if (0 <= y && y < (int)pixels_height) {
            for (int x = x1; x <= x2; ++x) {
                if (0 <= x && x < (int)pixels_width) {
                    pixels[y * pixels_width + x] = color;
                }
            }
        }
    }
}

void craftix_draw_circle(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
    int cx, int cy, int r,
    uint32_t color) {
        if (r == 0) return;

        int x1 = cx - r;
        int x2 = cx + r;

        int y1 = cy - r;
        int y2 = cy + r;

        for (int y = y1; y <= y2; ++y) {
        if (0 <= y && y < (int) pixels_height) {
            for (int x = x1; x <= x2; ++x) {
                if (0 <= x && x < (int) pixels_width) {
                    int dx = x - cx;
                    int dy = y - cy;
                    if (dx*dx + dy*dy <= r*r) {
                        pixels[y*pixels_width + x] = color;
                    }
                }
            }
        }
    }
}