#!/usr/bin/env bash
set -e

# Go to repo root
cd "$(dirname "$0")/.."

echo "================================"
echo "Step 1 Running rexglue migrate"
echo "================================"
rexglue migrate --app_root .

echo "================================"
echo "Step 2 Configure"
echo "================================"
cmake --preset linux-amd64-relwithdebinfo

echo "================================"
echo "Step 3 Run codegen"
echo "================================"
cmake --build --preset linux-amd64-relwithdebinfo --target retip_codegen

echo "================================"
echo "Step 4 Restore original files"
echo "================================"
if [ -f CMakeLists.txt.bak ]; then
    cp -f CMakeLists.txt.bak CMakeLists.txt
else
    echo "WARNING: CMakeLists.txt.bak not found"
fi

if [ -f src/main.cpp.bak ]; then
    cp -f src/main.cpp.bak src/main.cpp
else
    echo "WARNING: src/main.cpp.bak not found"
fi

echo "================================"
echo "Step 5 Reconfigure"
echo "================================"
cmake --preset linux-amd64-relwithdebinfo

echo "================================"
echo "Step 6 Final build"
echo "================================"
cmake --build --preset linux-amd64-relwithdebinfo

echo "================================"
echo "Build completed successfully"
echo "================================"
