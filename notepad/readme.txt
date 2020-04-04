Build instructions

Linux (CMake)
mkdir build
cd build
cmake ..
cmake --build .

Windows (CMake)
cmake .
cmake --build . --config Release
windeployqt --no-translations Release
