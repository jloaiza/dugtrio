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
    structures/ntreenode.cpp \
    LSS/testerlss.cpp \
    LSS/lssoperations.cpp \
    LSS/lssmain.cpp \
    LSS/lssdirection.cpp

HEADERS += \
    LSS/lss.h \
    LSS/lssmanager.h \
    LSS/lssxml.h \
    observer.h \
    observable.h \
    LSS/regsisterspace.h \
    LSS/registerbuffer.h \
    structures/ntree.h \
    structures/ntreenode.h \
    LSS/lssoperations.h \
    LSS/info.h

OTHER_FILES += \
    LSS/lssconfig.xml \
    LSS/disk1

