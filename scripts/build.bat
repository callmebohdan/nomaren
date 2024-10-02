@echo off

setlocal

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

pushd %~dp0
cd ..
set PROJECT_DIR=%cd%
popd

set BUILD_DIR=%PROJECT_DIR%\build
set BIN_DIR=%PROJECT_DIR%\bin
set OUT_DIR=%PROJECT_DIR%\out
set QT_PATH=C:\Qt\6.7.2\msvc2019_64
set SRC_DIR=%PROJECT_DIR%\src

if exist "%BIN_DIR%" (
    echo Cleaning bin directory...
    rd /s /q "%BIN_DIR%"
)

if exist "%BUILD_DIR%" (
    echo Cleaning build directory...
    rd /s /q "%BUILD_DIR%"
)

if exist "%OUT_DIR%" (
    echo Cleaning out directory...
    rd /s /q "%OUT_DIR%"
)

echo Creating build directory...
mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

if exist "%QT_PATH%\bin\uic.exe" (
    echo Generating ui_nomaren.h from nomaren.ui...
    "%QT_PATH%\bin\uic.exe" -o "%SRC_DIR%\ui_nomaren.h" "%SRC_DIR%\nomaren.ui"
)

echo Configuring the project with CMake...
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="%QT_PATH%" "%PROJECT_DIR%"

echo Building the project with MSBuild...
msbuild "%BUILD_DIR%\nomaren.sln" /p:Configuration=Release

if exist "%QT_PATH%\bin\windeployqt.exe" (
    echo Deploying Qt libraries...
    "%QT_PATH%\bin\windeployqt.exe" --release --compiler-runtime "%BUILD_DIR%\src\Release\nomaren.exe"
)

if exist "%BUILD_DIR%\src\Release\nomaren.exe" (
    echo Copying the application into the bin/ directory...
    mkdir "%BIN_DIR%"
    xcopy /s /e /y /I "%BUILD_DIR%\src\Release" "%BIN_DIR%"
) else (
    echo Error: nomaren.exe was not created.
)

endlocal
