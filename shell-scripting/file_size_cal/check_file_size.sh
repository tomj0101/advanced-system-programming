#!/bin/bash
size=$(wc -c < sample.xml)
if (($size >= 400000 )); then
        echo "File have the GOOD size :)"
else
        echo "Oh-oh WRONG size :("

fi
