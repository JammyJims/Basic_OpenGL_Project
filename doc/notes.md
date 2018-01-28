# Notes regarding the project.
## Tutorial to be followed
https://learnopengl.com/#!Introduction 

## Extentions
when dealing with extentions, use an if statement to check for the presence of the extentions.

## State machines
Graphics are drawn with state machines detailing how each state changes from one to another. Functions exist that change from one state to another.

## Objects
OpenGL objects are written in C. This means that it uses structs to represent the settings of various states i.e. the window's settings.

## OpenGL libraries
There are numerous libraries that build off of OpenGL such as: GLUT, SDL, SFML and GLFW. The tutorial I will be following will use GLFW. GLAD is an up to date library that will retrieve function pointers to the driver specific function calls. GLAD will be used in order to create a cross platform

### Libraries used:
* GLFW (https://github.com/glfw/glfw)
* GLAD (http://glad.dav1d.de/#profile=core&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&language=c&loader=on)

## The Graphics Pipeline
The Graphics Pipeline consists of: Vertex, Shape Assembly, Geometry Shader, Rasterisation, Fragment Shader, Tests and Blending.
Triangles require 3 vertices defined in 3D space e.g. vertex = x, y, z and triangles require 3 of these. With 3 vertices, rasterisation can occur by filling in the triangle with pixels which best approximate the area of the triangle and then clip all pixels out of view. From this point onwards, fragment shaders are used to determine the final colour of the pixel based on light, shadows, colour of the light, and so on. 

## Vertex Input
All vertics are in Normalized Device Coordinates (NDC) i.e. all x, y, and z coodinates are bounded between [-1, 1]
