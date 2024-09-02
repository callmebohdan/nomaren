@echo off

setlocal

pushd %~dp0
cd ..
set PROJECT_DIR=%cd%
popd

set BUILD_DIR=%PROJECT_DIR%\build
set BIN_DIR=%PROJECT_DIR%\bin
set OUT_DIR=%PROJECT_DIR%\out
set QT_PATH=C:\Qt\6.7.2\mingw_64
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
    echo Generating ui_mainwindow.h from mainwindow.ui...
    "%QT_PATH%\bin\uic.exe" -o "%SRC_DIR%\ui_mainwindow.h" "%SRC_DIR%\mainwindow.ui"
)

echo Configuring the project with CMake...
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="%QT_PATH%" "%PROJECT_DIR%"

echo Building the project...
mingw32-make

if exist "%QT_PATH%\bin\windeployqt.exe" (
    echo Deploying Qt libraries...
    "%QT_PATH%\bin\windeployqt.exe" --release --compiler-runtime "%BUILD_DIR%\src\nomaren.exe"
)

if exist "%BUILD_DIR%\src\nomaren.exe" (
    echo Copying the application into the bin/ directory...
    mkdir "%BIN_DIR%"
    xcopy /s /e /y "%BUILD_DIR%\src\nomaren.exe" "%BIN_DIR%"
    xcopy /s /e /y "%BUILD_DIR%\src\*.dll" "%BIN_DIR%"
    xcopy /s /e /y "%BUILD_DIR%\src\generic" "%BIN_DIR%\generic"
    xcopy /s /e /y "%BUILD_DIR%\src\iconengines" "%BIN_DIR%\iconengines"
    xcopy /s /e /y "%BUILD_DIR%\src\imageformats" "%BIN_DIR%\imageformats"
    xcopy /s /e /y "%BUILD_DIR%\src\multimedia" "%BIN_DIR%\multimedia"
    xcopy /s /e /y "%BUILD_DIR%\src\networkinformation" "%BIN_DIR%\networkinformation"
    xcopy /s /e /y "%BUILD_DIR%\src\platforms" "%BIN_DIR%\platforms"
    xcopy /s /e /y "%BUILD_DIR%\src\styles" "%BIN_DIR%\styles"
    xcopy /s /e /y "%BUILD_DIR%\src\tls" "%BIN_DIR%\tls"
) else (
    echo Error: nomaren.exe was not created.
)

endlocal

pause
