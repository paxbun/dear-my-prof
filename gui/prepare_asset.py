from PIL import Image

with Image.open('./Asset/Icon.png') as img:
    img.save('./Asset/Icon.ico')