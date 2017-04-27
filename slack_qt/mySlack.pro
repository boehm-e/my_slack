TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    socket.cpp

RESOURCES += qml.qrc

QT_LABS_CONTROLS_STYLE=material
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    socket.h
