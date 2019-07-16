#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T14:45:15
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += charts
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Railway
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include/

SOURCES +=\
        mainwindow.cpp \
    datetime.cpp \
    log.cpp \
    serialport.cpp \
    barchart.cpp \
    main.cpp \
    login.cpp \
    typedef.cpp \
    analysis.cpp \
    mysqlmodel.cpp

HEADERS  += \
    mainwindow.h \
    datetime.h \
    serialport.h \
    barchart.h \
    mutexqueue.h \
    include/rapidjson/error/en.h \
    include/rapidjson/error/error.h \
    include/rapidjson/internal/biginteger.h \
    include/rapidjson/internal/diyfp.h \
    include/rapidjson/internal/dtoa.h \
    include/rapidjson/internal/ieee754.h \
    include/rapidjson/internal/itoa.h \
    include/rapidjson/internal/meta.h \
    include/rapidjson/internal/pow10.h \
    include/rapidjson/internal/regex.h \
    include/rapidjson/internal/stack.h \
    include/rapidjson/internal/strfunc.h \
    include/rapidjson/internal/strtod.h \
    include/rapidjson/internal/swap.h \
    include/rapidjson/msinttypes/inttypes.h \
    include/rapidjson/msinttypes/stdint.h \
    include/rapidjson/allocators.h \
    include/rapidjson/cursorstreamwrapper.h \
    include/rapidjson/document.h \
    include/rapidjson/encodedstream.h \
    include/rapidjson/encodings.h \
    include/rapidjson/filereadstream.h \
    include/rapidjson/filewritestream.h \
    include/rapidjson/fwd.h \
    include/rapidjson/istreamwrapper.h \
    include/rapidjson/memorybuffer.h \
    include/rapidjson/memorystream.h \
    include/rapidjson/ostreamwrapper.h \
    include/rapidjson/pointer.h \
    include/rapidjson/prettywriter.h \
    include/rapidjson/rapidjson.h \
    include/rapidjson/reader.h \
    include/rapidjson/schema.h \
    include/rapidjson/stream.h \
    include/rapidjson/stringbuffer.h \
    include/rapidjson/writer.h \
    log.h \
    login.h \
    typedef.h \
    analysis.h \
    mysqlmodel.h

FORMS    += mainwindow.ui \
    datetime.ui \
    barchart.ui \
    login.ui

DISTFILES +=
