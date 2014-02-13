@ECHO OFF

SET USEGCC=1
FOR /F "delims=" %%G IN ('WHERE cl 2^>NUL') DO (
    SET USEGCC=0
)

RMDIR /S /Q bin 2>NUL
MKDIR bin 2>NUL

IF [%USEGCC%] == [1] (
    ECHO Using GNU toolchain
    g++ -O3 -static-libgcc -static-libstdc++ -o bin/tmp.exe cmdcolor.cpp >bin\build.log
    strip bin/tmp.exe >>bin\build.log
) ELSE (
    ECHO Using Microsoft toolchain
    cl /EHsc /O2 /Fe:bin\ /Fo:bin\tmp.obj cmdcolor.cpp >bin\build.log 2>NUL
)

upx -9 -obin/cmdcolor.exe bin/tmp.exe >bin\upx.log
