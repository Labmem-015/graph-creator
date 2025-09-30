# About the project

This project is used for creating and visualizing graphs. Short name: Gratòr.

# How to build

You need to generate a project buildsystem and then build project. You can use this to build release version:

```
cmake --workflow release
```

Or this command to build debug:

```
cmake --workflow debug
```

# What is happening in the code

`Node` class is used for rendering a single Node.

`Graph` is used for managing `Node`s.

`Matrix` is used for parsing and giving a transition matrix of Markov Chain.

# TODO

1. Implement simple graph rendering
2. Implement parsing data
3. Implement building graph
4. Implement graph shared library runtime loading in main executable to debug without restarting app.
5. Implement physics of graph (make it interactive like in obsidian)
6. Implement optimizations to handle larger graphs
7. Make it crossplatform (build on Windows also).