#!/bin/bash

BROWSER_PATH="/Applications/Arc.app/Contents/MacOS/Arc"
PORT=9222

RESULT=$(lsof -i :$PORT)

if [ -n "$RESULT" ]; then
	if [[ $RESULT == *"Arc"* ]]; then
		printf "Arc is already running on port $PORT.\n"
		exit 0
	fi
	printf "Port $PORT is already in use.\n"
	exit 1
fi

#pkill -9 -f "Arc.app" || true

#while pgrep -f "Arc.app" > /dev/null; do
#	printf "Arc is already running. Waiting for it to close...\n"
#	sleep 1
#done

printf "Starting Arc on port $PORT...\n"

nohup /Applications/Arc.app/Contents/MacOS/Arc \
	--remote-debugging-port=$PORT \
	> /dev/null 2>&1 &