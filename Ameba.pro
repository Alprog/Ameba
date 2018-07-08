
# DEFINES

win32|win64:CONFIG += win
unix:!macx:!android:CONFIG += linux
macx:CONFIG += osx
android:CONFIG += android

win:DEFINES += WIN
linux:DEFINES += LINUX
osx:DEFINES += OSX
android:DEFINES += ANDROID

# PROJECT

TEMPLATE = app

CONFIG += qt c++11
CONFIG -= debug_and_release debug_and_release_target
QT += widgets

HEADERS += $$files(Source/*.h, true)
SOURCES += $$files(Source/*.cpp, true)
INCLUDEPATH += Source

RESOURCES = ameba.qrc

# OPTIONS

win|osx {
    QMAKE_CXXFLAGS += /wd4250 /wd4800 /wd5030
}

linux|android {
    QMAKE_CXXFLAGS += -std=c++0x -fpermissive -Wno-attribute
}

DISTFILES += \
    Android/AndroidManifest.xml \
    Android/gradle/wrapper/gradle-wrapper.jar \
    Android/gradlew \
    Android/res/values/libs.xml \
    Android/build.gradle \
    Android/gradle/wrapper/gradle-wrapper.properties \
    Android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/Android
