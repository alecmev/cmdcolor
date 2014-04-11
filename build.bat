@ECHO OFF

SET USEGCC=1
FOR /F "delims=" %%G IN ('WHERE cl 2^>NUL') DO (
    SET USEGCC=0
)

RMDIR /S /Q bin 2>NUL
MKDIR bin 2>NUL

IF [%USEGCC%] == [1] (
    CALL :GNU
) ELSE (
    CALL :MS
)

GOTO :UPX

:GNU
ECHO Using GNU toolchain
g++ -O3 -static-libgcc -static-libstdc++ -o bin/tmp.exe cmdcolor.cpp ^
 >bin\build.log
strip bin/tmp.exe >>bin\build.log
GOTO :EOF

:MS
ECHO Using Microsoft toolchain
CALL vcvars32
CALL cl /Zi /nologo /W3 /WX- /sdl /O2 /Oi /Oy- /GL /Gm- /EHsc /MD /GS /Gy ^
 /fp:precise /Zc:wchar_t /Zc:forScope /Gd /TP /analyze- /Fe:bin\ ^
 /Fo:bin\tmp.obj /Fd:bin\tmp.pdb cmdcolor.cpp >bin\build.log 2>NUL
GOTO :EOF

:UPX
upx -9 -obin/cmdcolor.exe bin/tmp.exe >bin\upx.log
