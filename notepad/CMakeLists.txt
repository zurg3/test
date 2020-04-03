cmake_minimum_required(VERSION 3.10)

project(notepad)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)
find_package(Qt5 COMPONENTS PrintSupport)

add_executable(notepad
  main.cpp
  notepad.cpp
  notepad.h
  notepad.ui
  notepad.qrc
  config.h
  version.h
)

target_link_libraries(notepad
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::PrintSupport
)
