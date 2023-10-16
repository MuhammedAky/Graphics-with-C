#ifndef CRAFTIX_H
#define CRAFTIX_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h> // size_t için ekledik

void craftix_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);
bool save_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path);

#endif // CRAFTIX_H