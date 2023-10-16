from PIL import Image

# .ppm dosyasını açın
ppm_image = Image.open("output.ppm")

# .png olarak kaydedin
ppm_image.save("output.png")

# .png dosyasını görüntüleyin
ppm_image.show()