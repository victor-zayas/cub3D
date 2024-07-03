# cub3D

## Overview

`cub3D` is a project developed as part of the 42 School curriculum. It involves creating a 3D game engine inspired by the classic game Wolfenstein 3D. The main objective is to understand the basics of ray-casting and how a 2D world can be rendered in 3D.

## Features

- **Ray-casting Engine**: A basic ray-casting engine to render 3D graphics from a 2D map.
- **Textures**: Apply textures to walls for more realistic graphics.
- **Player Movement**: Basic movement controls for the player (forward, backward, left, right).
- **Basic Collision Detection**: Prevent the player from walking through walls.

### Prerequisites

- A macOS operating system (Linux will be implemented in the future).
- Make sure you have the following dependencies installed:
  - `gcc` or any other C compiler
  - `make`

### Clone the Repository

```bash
git clone https://github.com/your-username/cub3D.git
cd cub3D
```
### Usage

```bash
make
./cub3D <path_to_the_selected_map>
```
### Project structure

cub3D/
├── includes/ # Header files\n
├── libft/ # Library created by us
├── mlx/ # Campus's graphic library
├── src/ # Source files
├── texture/ # Texture files
├── maps/ # Example map files
├── Makefile # Makefile for building the project
└── README.md # This README file

### Controls

- W: move forward
- S: move backward
- A: move left
- D: move right
- Left Arrow: Turn left
- Right Arrow: Turn right
- ESC: Exit the game

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- The 42 School for providing the project framework.
- The developers of the MiniLibX library.
- Inspiration from classic games like Wolfenstein 3D.

## Contributors
- [Larrain Gonzalez](https://github.com/lagonzal)
- [Victor Zayas](https://github.com/victor-zayas)
