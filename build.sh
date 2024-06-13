#!/bin/bash

git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
cd ..
gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
clear
