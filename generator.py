import sys
import subprocess
import random

num_of_images = 0
max = 5
input_string = "input/la_jolla.jpg"

while(num_of_images < max):
    output_string="output/la_jolla_"+str(num_of_images)+".jpg"
    print(output_string)
    quality = str(random.randint(1, 75))
    blur = str(random.randint(1,60))
    zoom = str(random.randint(1,5))
    subprocess.run(["./img_deg", input_string, output_string, quality, blur, zoom])
    num_of_images +=1
