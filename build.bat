@ECHO OFF

RMDIR /S /Q bin 2>NUL
MKDIR bin 2>NUL
g++ -O3 -static-libgcc -static-libstdc++ -o bin/tmp.exe cmdcolor.cpp
strip bin/tmp.exe
upx -9 -obin/cmdcolor.exe bin/tmp.exe >NUL
DEL bin\tmp.exe 2>NUL
