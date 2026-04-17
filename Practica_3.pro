TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ARCHIVOS.cpp \
        ENCRI_DESIN.cpp \
        LZ78_ALL.cpp \
        RLE_ALL.cpp \
        main.cpp

HEADERS += \
    ARCHIVOS.h \
    ENCRI_DESIN.h \
    Entry.h \
    LZ78_ALL.h \
    RLE_ALL.h
