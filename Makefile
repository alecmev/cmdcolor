all: cmdcolor.exe

cmdcolor.exe: cmdcolor.cpp
	cl /MT cmdcolor.cpp
