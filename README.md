# Pong-SDL2
A poorly written Pong port to SDL2

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
mkdir build && cd build
cmake ..
make -j4
```
* 3 . Run the program
```bash
./Pong
```