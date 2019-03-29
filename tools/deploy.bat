SET QT_BIN_DIR=C:\Dev\Qt\5.12.2\mingw73_64\bin
SET PROFILE=debug
SET SOURCE_DIR=cmake-build-debug-mingw-64
SET TARGET_DIR=build

SET PATH=%QT_BIN_DIR%;%PATH%

cd ..
windeployqt --%PROFILE% %SOURCE_DIR%