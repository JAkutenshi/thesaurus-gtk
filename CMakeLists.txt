# Set the name and the supported language of the project
PROJECT(Thesaurus-gtk)
# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(SQLITE REQUIRED sqlite3)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
ADD_LINK_OPTIONS(-rdynamic)

INCLUDE_DIRECTORIES(${SQLITE_INCLUDE_DIRS})
LINK_DIRECTORIES(${SQLITE_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from hello.c
SET(SOURCE_FILES src/main.c src/config.h)
ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES} src/model/lit_entry.h)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTK3_LIBRARIES} ${SQLITE_LIBRARIES})
