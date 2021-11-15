# img_deg

img_deg is a command-line tool that allows you, as the name suggests, degrade images. This allows for unexpected ways of seeing the image, and may lead to inspiration in any number of art projects.

## Usage
If successfully built, you will now have an executable img_deg in your directory.

While still in the directory, use the program as follows:

```
./img_deg filename.jpg savename.jpg quality blur_amount zoom_amount
```

The **quality** argument is between 1 - 75. The quality argument is essentially how badly you want the processor to output the image. 

The **blur_amount** argument is between 0 - 100. This blurs it.

The **zoom amount** doesn't really matter and I think I'm going to ditch it anyway.

Additionally, the program will output some helpful info on the specifications of the images. It will also, for some reasn, declare a segmentation fault.

## Installation

To use install simply make the repo

```
make
```

## Example

```
./img_deg lena.jpg lena2.jpg 1 100 4
```


![Before](lena.jpg)

![After](lena2.jpg)