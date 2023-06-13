#!/bin/bash
for f in ./*comp; 
    do echo "Processing $f...";
    halcompile --install $f;
done
