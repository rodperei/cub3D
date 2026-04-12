*This project has been created as part of the 42 curriculum by frnicola and rodperei.*

## Description
This project challenges us to make our own simple first-person perspective game, using the raycasting technique. This technique consists of building the perspective by calculating the distance between the point of origin of the ray and a collision element, and then printing it on the window using the MinilibX library.

## Instructions
First of all, you need to download the project from the Intra, as well as the MinilibX library. Then, extract the library to the project's `lib/` directory.

**Makefile available rules:**
* `all`: Compiles the project and the library.
* `clean`: Removes the build directory (along with `.o` and `.d` files).
* `fclean`: Removes the created binary and cleans the library.
* `re`: Recompiles the entire project from scratch.
* `bonus`: Compiles the project for bonus evaluation.

After you have compiled the project, execute the program with the following command:

`./cub3D defs.cub`

Where `defs.cub` is a mandatory argument specifying the path to a `.cub` file containing the configuration for the program to run properly. 

**The configuration file has the following format:**
* An option starting with `NO`, specifying the path to the texture file for the North wall face.
* An option starting with `SO`, specifying the path to the texture file for the South wall face.
* An option starting with `WE`, specifying the path to the texture file for the West wall face.
* An option starting with `EA`, specifying the path to the texture file for the East wall face.
* An option starting with `F`, specifying the RGB color code of the floor (range 0 to 255 for each color channel).
* An option starting with `C`, specifying the RGB color code of the ceiling (range 0 to 255 for each color channel).

These options can be provided in any order and separated by any number of empty lines. 
*Note: The texture files must be in `.xpm` format, as that is the format supported by our program.*

Always at the very end of the file, there must be a map. The map must be composed of only 6 valid characters: `0` for an empty space, `1` for a wall, and `N`, `S`, `E`, or `W` for the player's starting position and spawning orientation. Additionally, the map must be completely surrounded by walls.

## Resources
* [Lode's Computer Graphics Tutorial (Raycasting)](https://lodev.org/cgtutor/raycasting.html)
* [Interactive DDA Algorithm](https://aaaa.sh/creatures/dda-algorithm-interactive/) 
* [Bresenham's Line Algorithm](https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html) 

*AI was used to proofread this README file.*
