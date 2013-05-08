TEMPLATE        =       app
CONFIG          +=      console
CONFIG          -=      app_bundle
CONFIG          -=      qt

SOURCES         += \
    md5.cpp \
    testmd5.cpp \

HEADERS += \
    md5.h \
    constants.h
