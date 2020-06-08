TEMPLATE = app
CONFIG += console c++11


INCLUDEPATH += . \
               ./../Admiral/SquidStatDLL/include/    \
               ./../Admiral/QtDLL/include/QtCore    \
               ./../Admiral/QtDLL/include/QtSerialPort    \
               ./../Admiral/QtDLL/include/QtWidgets    \
               ./../Admiral/QtDLL/include/QtGui    \
               ./../Admiral/QtDLL/include

win32{
    CONFIG -= app_bundle
    CONFIG -= qt
    CONFIG(debug, debug|release){
        #debug
        LIBS += -L"./../Admiral/SquidStatDLL/Debug/"   \
            "./../Admiral/SquidStatDLL/Debug/libSquidstatLibrary.1.dll" \
            "./../Admiral/SquidStatDLL/Debug/libSquidStat_DLL.1.dll" \
            "./../Admiral/QtDLL/Debug/libQt5Core.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5DBus.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5EglFSDeviceIntegration.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5Gui.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5Network.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5SerialPort.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5Svg.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5WaylandClient.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5Widgets.5.dll" \
            "./../Admiral/QtDLL/Debug/libQt5XcbQpa.5.dll" \
            "./../Admiral/QtDLL/Debug/libicudata.56.dll" \
            "./../Admiral/QtDLL/Debug/libicui18n.56.dll" \
            "./../Admiral/QtDLL/Debug/libicuuc.56.dll" \
             -lpthread
    }else {
        #release
        LIBS += -L"./../Admiral/SquidStatDLL/Release/"   \
            "./../Admiral/SquidStatDLL/Release/libSquidstatLibrary.1.dll" \
            "./../Admiral/SquidStatDLL/Release/libSquidStat_DLL.1.dll" \
            "./../Admiral/QtDLL/Release/libQt5Core.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5DBus.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5EglFSDeviceIntegration.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5Gui.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5Network.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5SerialPort.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5Svg.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5WaylandClient.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5Widgets.5.dll" \
            "./../Admiral/QtDLL/Release/libQt5XcbQpa.5.dll" \
            "./../Admiral/QtDLL/Release/libicudata.56.dll" \
            "./../Admiral/QtDLL/Release/libicui18n.56.dll" \
            "./../Admiral/QtDLL/Release/libicuuc.56.dll" \
            -lpthread
    }
}


macx{
    QT += core
    CONFIG(debug, debug|release){
        #debug
        LIBS += -L"./../Admiral/SquidStatDLL/Debug/"   \
            "./../Admiral/SquidStatDLL/Debug/libSquidstatLibrary.1.dylib" \
            "./../Admiral/SquidStatDLL/Debug/libSquidStat_DLL.1.dylib" \
             -lpthread
    }else {
        #release
        LIBS += -L"./../Admiral/SquidStatDLL/Release/"   \
            "./../Admiral/SquidStatDLL/Release/libSquidstatLibrary.1.dylib" \
            "./../Admiral/SquidStatDLL/Release/libSquidStat_DLL.1.dylib" \
            -lpthread
    }
}

unix:!macx {
    CONFIG -= app_bundle
    CONFIG -= qt
    CONFIG(debug, debug|release){
        #debug
        LIBS += -L"./../Admiral/SquidStatDLL/Debug/"   \
            "./../Admiral/SquidStatDLL/Debug/libSquidstatLibrary.so.1" \
            "./../Admiral/SquidStatDLL/Debug/libSquidStat_DLL.so.1" \
            "./../Admiral/QtDLL/Debug/libQt5Core.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5DBus.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5EglFSDeviceIntegration.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5Gui.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5Network.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5SerialPort.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5Svg.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5WaylandClient.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5Widgets.so.5" \
            "./../Admiral/QtDLL/Debug/libQt5XcbQpa.so.5" \
            "./../Admiral/QtDLL/Debug/libicudata.so.56" \
            "./../Admiral/QtDLL/Debug/libicui18n.so.56" \
            "./../Admiral/QtDLL/Debug/libicuuc.so.56" \
             -lpthread
    }else {
        #release
        LIBS += -L"./../Admiral/SquidStatDLL/Release/"   \
            "./../Admiral/SquidStatDLL/Release/libSquidstatLibrary.so.1" \
            "./../Admiral/SquidStatDLL/Release/libSquidStat_DLL.so.1" \
            "./../Admiral/QtDLL/Release/libQt5Core.so.5" \
            "./../Admiral/QtDLL/Release/libQt5DBus.so.5" \
            "./../Admiral/QtDLL/Release/libQt5EglFSDeviceIntegration.so.5" \
            "./../Admiral/QtDLL/Release/libQt5Gui.so.5" \
            "./../Admiral/QtDLL/Release/libQt5Network.so.5" \
            "./../Admiral/QtDLL/Release/libQt5SerialPort.so.5" \
            "./../Admiral/QtDLL/Release/libQt5Svg.so.5" \
            "./../Admiral/QtDLL/Release/libQt5WaylandClient.so.5" \
            "./../Admiral/QtDLL/Release/libQt5Widgets.so.5" \
            "./../Admiral/QtDLL/Release/libQt5XcbQpa.so.5" \
            "./../Admiral/QtDLL/Release/libicudata.so.56" \
            "./../Admiral/QtDLL/Release/libicui18n.so.56" \
            "./../Admiral/QtDLL/Release/libicuuc.so.56" \
            -lpthread
    }
}


SOURCES += \
         AppThread.cpp \
         CsvFileWriter.cpp \
         ExpDataNotifier.cpp \
         Experiment.cpp \
         ExperimentSelector.cpp \
         SquidStateHandler.cpp \
         TimerClass.cpp \
         main.cpp

HEADERS += \
        AppThread.h \
        CsvFileWriter.h \
        ExpDataNotifier.h \
        Experiment.h \
        ExperimentSelector.h \
        SquidStateHandler.h \
        TimerClass.h
