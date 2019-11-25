from PIL import Image
import os

if os.name == 'nt':
    with Image.open('./Asset/Icon.png') as img:
        img.save('./Asset/Icon.ico')