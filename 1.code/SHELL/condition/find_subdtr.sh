#!/bin/bash
str="abcdefghijklmnopqrstuvwxyz"
keyword="ghi"

if echo $str|grep $keyword ; then 
    echo "$str includes $keyword"
else
    echo "$str does not include $keyword"
fi