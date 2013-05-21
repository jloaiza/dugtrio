TEMPLATE        =       app
CONFIG          +=      console
CONFIG          -=      app_bundle
CONFIG          -=      qt

SOURCES         += \     
    dugtrio.cpp \
    LSS/lss.cpp \
    LSS/lssmanager.cpp \
    LSS/lssxml.cpp

HEADERS += \
    LSS/lss.h \
    LSS/lssmanager.h \
    LSS/lssxml.h \
    observer.h \
    observable.h

OTHER_FILES += \
    LSS/lssconfig.xml

