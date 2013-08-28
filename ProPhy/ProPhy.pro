SOURCES += \
    main.cpp \
    mainwindow.cpp \
    glwidget.cpp \
    cwidget.cpp \
    gldark.cpp \
    loadwindow.cpp

HEADERS += \
    mainwindow.h \
    glwidget.h \
    cwidget.h \
    gldark.h \
    loadwindow.h
QT           += opengl

OTHER_FILES += \
    icon.rc \
    LOAD.bmp
RC_FILE = icon.rc

RESOURCES += \
    image.qrc
