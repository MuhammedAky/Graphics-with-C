#include <stdio.h>
// #include <stdlib.h>

#define WIDTH 25
#define HEIGHT 25

int main() {
  // Dosyayı aç
    FILE *fp = fopen("test.ppm", "wb");
 
    if (!fp) {
        perror("File creation");
        return -1;
    }
 
  // Başlık bilgisini yaz
  fprintf(fp,"P3\n%d %d\n255\n", WIDTH, HEIGHT);
  // Pikselleri yaz
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      fprintf(fp, "%d %d %d ", 255, 0, 255);
    }
    fprintf(fp, "\n");
  }
  // Dosyayı kapat
  fclose(fp);
  return 0;
}