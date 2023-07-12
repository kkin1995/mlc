#!/bin/sh

set -xe

clang -Wall -Wextra -o main $1 -lm
