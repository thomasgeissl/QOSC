#!/bin/bash
set -ev

for dir in examples/example*/
do
    dir=${dir%*/}
    cd examples/${dir##*/}
    mkdir -p build
    cd build
    touch test
done
