#!/bin/bash



if id|grep "root">/dev/null; then
    echo "you are root!"
else
    echo "you are not root!"
fi

