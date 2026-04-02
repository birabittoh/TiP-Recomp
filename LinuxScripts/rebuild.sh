#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/.."
cmake --preset linux-amd64-relwithdebinfo
cmake --build --preset linux-amd64-relwithdebinfo
