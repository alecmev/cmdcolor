# cmdcolor

Colorizes standard output on Windows:
```
your-executable.exe | cmdcolor.exe
cmd /c your-batch.bat | cmdcolor.exe
cscript your-script.js | cmdcolor.exe
```
No guarantees, it just works. Would **not** advise using in production.

### Usage

Expects a subset of bash control sequences:
```
<a>[<b>m<c>

<a>  Escape sequence, either \033 or \e, where  
     \033 is just four plain characters, but
     \e is a single escape character (code 27).
     
<b>  Semicolon (;) delimited list of 8/16 colors,
     in any order. Acceptable numbers:
     [30, 37] U [40, 47] U [90, 97] U [100, 107]
     A zero (0) resets all attributes.
     
<c>  Text.
```
[8/16 color codes](http://misc.flogisoft.com/bash/tip_colors_and_formatting#colors).

### Examples

```
echo \033[31m RED ON DEFAULT | cmdcolor.exe
echo \033[41m DEFAULT ON RED | cmdcolor.exe
echo \033[34;43m BLUE ON YELLOW | cmdcolor.exe
echo \033[34;43;35m MAGENTA ON YELLOW | cmdcolor.exe
echo \033[96m LIGHT CYAN \033[0m DEFAULT | cmdcolor.exe
```

### Binaries

Am I the only one who hates building stuff on his own?  
[Download](https://mega.co.nz/#!kxsmCL6I!rseLDCHK02CKTMfPePwuGSY0sJ-gDpexDxoKWCWpotA).
[Mirror](http://jeremejevs.com/u/cmdcolor.exe).

Doesn't work? Paranoid? Hipster?  
Take a look at `build.bat` to find out what you need to build it yourself.
