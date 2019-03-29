SET ARCH=64
SET PROFILE=release
SET QT_BIN_DIR=C:\Dev\Qt\5.12.2\mingw73_%ARCH%\bin
SET SOURCE_DIR=build\cmake-build-%PROFILE%-mingw-%ARCH%\PasteAndElaste.exe
SET TARGET_DIR=bin

SET PATH=%QT_BIN_DIR%;%PATH%

cd ..
windeployqt --%PROFILE% "%SOURCE_DIR%"
cd tools