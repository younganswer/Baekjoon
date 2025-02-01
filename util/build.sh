#!/bin/bash

if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <number>"
	exit 1
fi

NUMBER=$1

mkdir -p $NUMBER

cat << EOF > $NUMBER/main.cpp
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
		return (-1);
	}

	if (solve() != 0) {
		return (-1);
	}

	return (0);
}
EOF

code $NUMBER/main.cpp
