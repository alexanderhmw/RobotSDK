QT += core xml opengl widgets gui

CONFIG += qt
TEMPLATE = lib

PROJNAME = KITTI
INSTALLTYPE = MOD

unix:INCLUDEPATH += \
	/home/alexanderhmw/SDK/GLViewer/include	\
	/usr/include	\
	/usr/include/eigen3	\
	$$(HOME)/Git/RobotSDK/RobotSDK_Mod

unix{
	CONFIG(debug, debug|release){
	   LIBS += -L/home/alexanderhmw/SDK/GLViewer/lib/Debug -lGLViewer
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_core
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_highgui
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_features2d
	}
	else {
	   LIBS += -L/home/alexanderhmw/SDK/GLViewer/lib/Release -lGLViewer
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_core
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_highgui
	   LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_features2d
	}
}

include(RobotSDK.pri)


