#!/bin/bash

set -e

export QT_QPA_PLATFORM=xcb

SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd "$SCRIPT_DIR/.."
PROJECT_DIR=$(pwd)

BIN_DIR="$PROJECT_DIR/bin"
BUILD_DIR="$PROJECT_DIR/build"
OUT_DIR="$PROJECT_DIR/out"
SRC_DIR="$PROJECT_DIR/src"

QT_PATH="/usr/lib/x86_64-linux-gnu/cmake/Qt6"
QT_LIB_PATH="/usr/lib/x86_64-linux-gnu"

if [ -d "$BIN_DIR" ]; then
    echo "Cleaning bin/ directory..."
    rm -rf "$BIN_DIR"
fi

if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning build/ directory..."
    rm -rf "$BUILD_DIR"
fi

if [ -d "$OUT_DIR" ]; then
    echo "Cleaning bin/ directory..."
    rm -rf "$BIN_DIR"
fi

echo "Creating build/ directory..."
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "Running CMake configuration..."
cmake -G "Unix Makefiles" -DCMAKE_PREFIX_PATH="$QT_PATH" "$PROJECT_DIR"

echo "Generate ui_nomaren.h"
uic "$SRC_DIR/nomaren.ui" -o "$SRC_DIR/ui_nomaren.h"

echo "Building the project..."
make

if [ -f "$BUILD_DIR/nomaren" ]; then
    mkdir -p "$BIN_DIR"
    echo "Copying the application into the bin/ directory..."
    cp "$BUILD_DIR/nomaren" "$BIN_DIR"
    cp "$QT_LIB_PATH/libQt6Core.so.6" "$BIN_DIR"
    cp "$QT_LIB_PATH/libQt6Gui.so.6" "$BIN_DIR"
    cp "$QT_LIB_PATH/libQt6Widgets.so.6" "$BIN_DIR"
else
    echo "Error: nomaren was not created."
    exit 1
fi
