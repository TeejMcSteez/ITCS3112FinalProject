Write-Host "Building for C++17 in dist"

clang src/main.cpp -o dist/out --std="c++23"
