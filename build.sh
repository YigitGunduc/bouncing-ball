#!/bin/sh

set -xe

OUTPUT="ball.out"
FLAGS="-Wall -Wextra -Werror -o $OUTPUT"

cc ball.c $FLAGS

./$OUTPUT
