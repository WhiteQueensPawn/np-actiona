include(../common.pri)
unix:!mac:QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN -Wl,--rpath=$${PREFIX}/$${LIBDIR}/actiona
QT += xml \
	network \
	script \
	scripttools
equals(QT_MAJOR_VERSION, 5) {
unix:QT += x11extras
QT += widgets
}
CONFIG += mobility
contains(DEFINES, ACT_PROFILE) {
CONFIG += console
}
MOBILITY += systeminfo
TARGET = actiona
VERSION = $$ACTIONA_VERSION
DESTDIR = ..
SOURCES += main.cpp \
	mainwindow.cpp \
	scriptmodel.cpp \
	deleteactionpushbutton.cpp \
	actiondialog.cpp \
	aboutdialog.cpp \
	scriptparametersdialog.cpp \
	settingsdialog.cpp \
	settingskeyedit.cpp \
	newactiontreewidget.cpp \
	scripttableview.cpp \
	scriptmodelundocommands.cpp \
	newactiondialog.cpp \
	global.cpp \
	scriptcontentdialog.cpp \
    sfxscriptdialog.cpp \
    progresssplashscreen.cpp \
    scriptsettingsdialog.cpp \
    resourcedialog.cpp \
    filetypeguesser.cpp \
    resourcetablewidget.cpp \
    resourcetypedelegate.cpp \
    resourcenamedelegate.cpp
HEADERS += mainwindow.h \
	global.h \
	scriptmodel.h \
	deleteactionpushbutton.h \
	actiondialog.h \
	aboutdialog.h \
	scriptparametersdialog.h \
	settingsdialog.h \
	settingskeyedit.h \
	newactiontreewidget.h \
	scripttableview.h \
	scriptmodelundocommands.h \
	newactiondialog.h \
	scriptcontentdialog.h \
    sfxscriptdialog.h \
    progresssplashscreen.h \
    scriptsettingsdialog.h \
    resourcedialog.h \
    filetypeguesser.h \
    resourcetablewidget.h \
    resourcetypedelegate.h \
    resourcesizeitem.h \
    resourcenamedelegate.h
!contains(DEFINES, ACT_NO_UPDATER) {
	SOURCES += changelogdialog.cpp
	HEADERS += changelogdialog.h
}
INCLUDEPATH += . \
	src \
	../tools \
	../actiontools \
	../executer
FORMS += mainwindow.ui \
	actiondialog.ui \
	aboutdialog.ui \
	scriptparametersdialog.ui \
	settingsdialog.ui \
	newactiondialog.ui \
	changelogdialog.ui \
	scriptcontentdialog.ui \
    sfxscriptdialog.ui \
    scriptsettingsdialog.ui \
    resourcedialog.ui
win32:LIBS += -luser32 \
	-ladvapi32 \
	-lole32 \
	-lshlwapi \
	-lshell32
unix:LIBS += -lXtst
LIBS += -L.. \
	-ltools \
	-lactiontools \
	-lexecuter
RESOURCES += gui.qrc
win32:RC_FILE = gui.rc
TRANSLATIONS = ../locale/gui_fr_FR.ts \
                ../locale/gui_de_DE.ts
win32:system(lrelease ../locale/qt_fr_FR.ts) #For Windows we need to copy the qt translation files
win32:system(lrelease ../locale/qt_de_DE.ts)
unix:!mac:CONFIG += link_pkgconfig
unix:!mac:PKGCONFIG += libnotify

unix {
	target.path = $${PREFIX}/bin

        locales.path = $${PREFIX}/share/actiona/locale
        locales.files = ../locale/gui_fr_FR.qm \
                        ../locale/gui_de_DE.qm
	locales.CONFIG = no_check_exist

	icon.path = $${PREFIX}/share/pixmaps
        icon.files = icons/actiona.png

	desktopicon.path = $${PREFIX}/share/icons/hicolor/48x48/apps
        desktopicon.files = icons/actiona.png

	desktopfile.path = $${PREFIX}/share/applications
        desktopfile.files = ../actiona.desktop

	manfile.path = $${PREFIX}/share/man/man1
        manfile.files = ../docs/actiona.1

	mimefile.path = $${PREFIX}/share/mime/packages/
        mimefile.files = ../docs/actiona.xml

	INSTALLS += target locales icon desktopicon desktopfile manfile mimefile
}
