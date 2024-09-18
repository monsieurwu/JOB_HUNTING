#!/bin/bash
echo "input filename"
read filename

case $filename in
    *.c)
    echo "C"
    ;;
    *.cpp)
    echo "C++"
    ;;
    *.h)
    echo "C/C++ Header"
    ;;
    *.html)
    echo "HTML"
    ;;
    *.css)
    echo "CSS"
    ;;
    *.js)
    echo "JavaScript"
    ;;
    *.sh)
    echo "Shell"
    ;;
    *.txt)
    echo "TXT"
    ;;
    *)
    echo "Unknown file type"
    ;;
esac