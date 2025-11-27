Write-Host "Building for C++17 in dist"

if (!(Test-Path -Path ./dist)) {
  New-Item -Path ./dist -ItemType Directory  
}

Set-Location ./dist/

clang ../src/main.cpp --std="c++17"

Set-Location ../
