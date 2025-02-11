#!/bin/bash

if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <number>"
	exit 1
fi

NUMBER=$1
DIR="./problem/$NUMBER"

if [ ! -d "$DIR" ]; then
	mkdir -p $DIR

	cat << EOF > $DIR/main.cpp
#include <iostream>



int init() {
	return (0);
}

int solve() {
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (0);
	}

	if (solve() != 0) {
		return (0);
	}

	return (0);
}
EOF
fi

# `code` is an alias for Visual Studio Code
code -g $DIR/main.cpp:3
