TEMPLATE        =       app
CONFIG          +=      console
CONFIG          -=      app_bundle
CONFIG          -=      qt

SOURCES         += \     
    dugtrio.cpp \
    LSS/lss.cpp \
    LSS/lssmanager.cpp \
    LSS/lssxml.cpp \
    LSS/regsisterspace.cpp \
    LSS/registerbuffer.cpp \
    structures/ntree.cpp \
    structures/ntreenode.cpp

HEADERS += \
    LSS/lss.h \
    LSS/lssmanager.h \
    LSS/lssxml.h \
    observer.h \
    observable.h \
    LSS/regsisterspace.h \
    LSS/registerbuffer.h \
    structures/ntree.h \
    structures/ntreenode.h

OTHER_FILES += \
    LSS/lssconfig.xml

