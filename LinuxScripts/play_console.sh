#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/.."

echo "Copying retip to root..."
cp -f out/build/linux-amd64-relwithdebinfo/retip .

echo "Starting retip with console logging..."
./retip --gpu_allow_invalid_fetch_constants=true --enable_console=true --scribble_heap=true --vsync=off --fullscreen=true --video_mode_refresh_rate=164 --log_file=logs/retip.log
