@echo off
setlocal
cd /d "%~dp0.."
cmake --preset win-amd64-relwithdebinfo
cmake --build --preset win-amd64-relwithdebinfo
pause