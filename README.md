# Box2D demo
 
This is simple demo of Box2D physics engine.

## Compilation
### Linux
You should install SFML (https://www.sfml-dev.org/tutorials/2.5/start-linux.php) and download and build Box2D (https://github.com/erincatto/box2d). In `Makefile` edit `BOX2DINCPATH` to path to Box2D include/box2d folder (where all .h files are located) and `BOX2DLIBPATH` to path to `libbox2d.a` file. After that compile project with `make` command. You can also remove .o files with `make clear`.
### Windows
Currently `Makefile` is designed for Linux systems, but since both SFML and Box2D are cross-platform libraries, you can try to rewrite it to work on Windows systems.
