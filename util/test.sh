#!/bin/bash

check_arguments() {
	if [ "$#" -ne 1 ]; then
		echo "Usage: $0 <number>"
		exit 1
	fi
}

check_arguments $@
NUMBER=$1
DIR="./problem/$NUMBER"
EXE="$DIR/a.out"
SRC="$DIR/main.cpp"

check_compilation() {
	c++ -std=c++17 -Wall -Werror -Wextra -o $EXE $SRC
	if [ "$?" -ne 0 ]; then
		exit 1
	fi
}

check_compilation

INPUT_FILE="$DIR/input"
create_inputfile() {
	cat << EOF > $INPUT_FILE


# Enter your input for problem number $NUMBER here. Lines starting
# with '#' will be ignored. The file will be opened in your default
# editor. Save and close the file to run the program with the input.
EOF
	
	move_filepointer() {
		exec 3<> $INPUT_FILE
		cat $INPUT_FILE >&3
		exec 3>&-
	}
	move_filepointer

	wait_for_editor() {
		clear
		printf "hint: Waiting for your editor to close the file... "
		code --wait $INPUT_FILE
		printf "\n"
	}
	wait_for_editor

	remove_comments() {
		sed -i '' '/^#/d' $INPUT_FILE
		sed -i '' '/^$/d' $INPUT_FILE
	}
	remove_comments
}

create_inputfile
$EXE < $INPUT_FILE
rm -f $EXE