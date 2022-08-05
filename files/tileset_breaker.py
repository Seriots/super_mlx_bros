
from PIL import Image


def crop(path, height, width):
    k = 0
    im = Image.open(path)
    imgwidth, imgheight = im.size
    for i in range(0, imgheight, height):
        for j in range(0, imgwidth, width):
            box = (j, i, j+width, i+height)
            a = im.crop(box)
            a.save(f"tiles/tile_{k}.png")
            k += 1

# crop("grass_tileset.png", 16, 16)
