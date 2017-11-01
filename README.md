# PixelSorting
An implementation in C of the pixel sorting algorithm used to glitch pictures.
<div>
<img src="https://github.com/S-Rey/PixelSorting/blob/master/picture/Moon.jpg" width="350"/>
</div>

## Getting Started
### Prerequisites
In order to run the program, you need to have the following libraries and programs installed:
- libpng
- imagemagick

On Arch Linux
```
sudo pacman -S libpng
sudo pacman -S imagemagick 
```

On ubuntu
```
sudo apt-get install libpng-dev
sudo apt-get install imagemagick
```

On termux (Android)
```
apt install coreutils
apt install imagemagick
```

## Cloning and compiling
After cloning the repo, go to its directory and run
```
make
```
After that, a bin/ directory which contains the executable should have been created.
To run the program, simply do:
./pixelsort [files] [options]
- -i the path of the input file
- -o the path of the output file
- -t the threshold of bondary (integer from 0 to 255)

```
cd bin/
./pixelsort -i input.png -o output.png -t 70
```
