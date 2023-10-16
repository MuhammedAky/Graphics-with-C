#include "craftix.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool save_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path) {
    FILE *f = fopen(file_path, "wb");

    if (!f) {
        perror("Dosya açma hatasi");
        return false;
    }

    fprintf(f, "P6\n%zu %zu 255\n", width, height);

    for (size_t i = 0; i < width * height; ++i) {
        uint32_t pixel = pixels[i];
        uint8_t bytes[3] = {
            (pixel >> 16) & 0xFF,
            (pixel >> 8) & 0xFF,
            pixel & 0xFF
        };

        fwrite(bytes, sizeof(bytes), 1, f);

        if (ferror(f)) {
            perror("Veri yazma hatasi");
            fclose(f);
            return false;
        }
    }

    fclose(f);
    return true;
}

void craftix_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color) {
    for (size_t i = 0; i < width*height; ++i) {
        pixels[i] = color;
    }

    save_ppm_file(pixels, width, height, "./output.ppm");
}