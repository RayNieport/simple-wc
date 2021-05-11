# simple-wc
>A barebones implementation of the wc command, written to practice C.

[RepoSize](https://img.shields.io/github/repo-size/RayNieport/simple-wc)
[![License](https://img.shields.io/github/license/RayNieport/simple-wc)](https://github.com/RayNieport/simple-wc/blob/main/LICENSE)

## Usage: 
```
simple-wc [OPTION]... [FILE]...
```
## Description:
Prints line, word, and character counts for each FILE, and totals if more than one FILE is given.
When no FILE is provided, or FILE is -, reads from standard input.

Three options are implemented:
```
-m : print character counts
-w : print word counts
-l : print line counts
```
If no arguments are provided, simple-wc defaults to printing all three counts.

## Installation:
This program is not meant to replace the version of wc on your system. It was simply a short personal exercise to practice and brush up on my C skills. That said, if you would like to use it or modify it for your own purposes, here are the steps to do so:

__First__, clone the git respository:
```
git clone https://github.com/RayNieport/simple-wc.git
```

__Second__, navigate into the cloned repository and compile with gcc:
```
gcc simple-wc.c -o simple-wc
```

__Finally__, run the command:
```
./simple-wc LICENSE README.md
```

## License and Copyright
If you're interested in modifying or using my work for your own project, please see the LICENSE for up to date copyright and license information regarding simple-wc. 
