cmake_minimum_required(VERSION 3.13)
project(PasteAndElaste)

set(CMAKE_CXX_STANDARD 14)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "C:\\Dev\\Qt\\5.12.2\\mingw73_64\\lib\\cmake")

# Find QT packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Sql REQUIRED)

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Tell CMake to create the executable
set(SOURCE_FILES src/main.cpp src/ui/main-window/UiMainWindow.h src/ui/main-window/MainWindow.h src/ui/main-window/MainWindow.cpp src/model/ClipboardEntryModel.cpp src/model/ClipboardEntryModel.h src/model/ClipboardEntry.cpp src/model/ClipboardEntry.h src/consts.h)
add_executable(PasteAndElaste ${SOURCE_FILES})

# Link the executable to the Qt 5 libraries
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core)
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Quick)
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Sql)