# 🌌 fract-ol

## Description
**fract-ol** is a project focused on exploring and visualizing fractals. It allows users to generate and manipulate various fractal patterns using different parameters and rendering techniques.

## Usage
1. Clone the repo on your Linux machine;
2. Run `make`, this will also clone the mini-libx for Linux;
3. To start the program, run `./fractol Mandelbrot` or `./fractol Julia -0.8 0.156`
	- Note: these values for Julia are just an example;
	- Julia will render differently based on the values you give it.

Once the window opens, you can use the following controls:

| Input | Action |
|-|-|
| `↑` `↓` `←` `→` | Move the fractal around |
| `I` `O` `mouseWheel` | Zoom in and zoom out |
| `+` `-` | Increase and lower the definition, affects performance |
| `❌` `ESC` | Close the window |
| `mouseRightClick` | **Only for Julia**: as long as it's pressed, the fractal dynamically changes based on the position of the cursor on the window taking the x and the y as the two values for the render |

Note: the `+` and `-` buttons are set to work with the numpad ones. If you wish to use the "normal ones" then go inside of `events_handler.c`, then read the comment above the function `keyboard_handler()`.\
I can't just add it myself because then Norminette either says "line too long" or "function exceeds 25 lines".

## Grade
I didn't do the Bonus part so I got **100**.
