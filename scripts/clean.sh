#!/bin/bash

SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd "$SCRIPT_DIR/.."
PROJECT_DIR=$(pwd)

BIN_DIR="$PROJECT_DIR/bin"
BUILD_DIR="$PROJECT_DIR/build"
OUT_DIR="$PROJECT_DIR/out"
SRC_DIR="$PROJECT_DIR/src"

if [ -d "$BIN_DIR" ]; then
    echo "Cleaning bin/ directory..."
    rm -rf "$BIN_DIR"
fi

if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning build/ directory..."
    rm -rf "$BUILD_DIR"
fi

if [ -d "$OUT_DIR" ]; then
    echo "Cleaning out/ directory..."
    rm -rf "$OUT_DIR"
fi

if [ -d "$SRC_DIR/ui_nomaren.h" ]; then
    echo "Deleting ui_nomaren.h..."
    rm -f "$BIN_DIR/ui_nomaren.h"
fi
