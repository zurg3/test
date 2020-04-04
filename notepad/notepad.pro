TEMPLATE = app
TARGET = notepad

QT += widgets

SOURCES += \
  main.cpp\
  notepad.cpp

HEADERS += \
  notepad.h\
  config.h\
  version.h

FORMS += notepad.ui

RESOURCES += \
  notepad.qrc

RC_FILE = notepad.rc
