# Pong-SDL2
A poorly written port of Pong to SDL2

## Todo
* Sound effects
* Build instructions for Windows and/or MacOS
* Actual builds for Windows and/or MacOS

## Building (Linux)
* 1 . Install the dependencies
```bash
sudo apt install cmake make build-essential gcc libsdl2-dev libsdl2-gfx-dev
```
* 2 . Build
```bash
git clone https://github.com/KrasnotR/Pong-SDL2.git
cd Pong-SDL2
git submodule update --init --recursive
./build.sh
```
* 3 . Run the program
```bash
./Pong
```
