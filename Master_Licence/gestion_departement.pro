QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addlicencestudent.cpp \
    addprof.cpp \
    addsoutenance.cpp \
    addstudentpage.cpp \
    ajoutermaster.cpp \
    ajoutermasteretudaintes.cpp \
    alerte.cpp \
    deletestudentpage.cpp \
    echec.cpp \
    loginpage.cpp \
    main.cpp \
    suppression.cpp \
    supprimerlicence.cpp \
    supprimermastereude.cpp \
    supprimermasterprof.cpp \
    supprimerprof.cpp \
    welcomewindow.cpp

HEADERS += \
    addlicencestudent.h \
    addprof.h \
    addsoutenance.h \
    addstudentpage.h \
    ajoutermaster.h \
    ajoutermasteretudaintes.h \
    alerte.h \
    database.h \
    deletestudentpage.h \
    echec.h \
    loginpage.h \
    suppression.h \
    supprimerlicence.h \
    supprimermastereude.h \
    supprimermasterprof.h \
    supprimerprof.h \
    welcomewindow.h

FORMS += \
    addlicencestudent.ui \
    addprof.ui \
    addsoutenance.ui \
    addstudentpage.ui \
    ajoutermaster.ui \
    ajoutermasteretudaintes.ui \
    alerte.ui \
    deletestudentpage.ui \
    echec.ui \
    loginpage.ui \
    suppression.ui \
    supprimerlicence.ui \
    supprimermastereude.ui \
    supprimermasterprof.ui \
    supprimerprof.ui \
    welcomewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
