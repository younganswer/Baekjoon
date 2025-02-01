#!/bin/bash

find . -type f -name "*.cpp" -exec chmod -x {} +

find . -path "./.git" -prune -o -type f -perm +111 -exec rm -f {} +
