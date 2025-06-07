




#TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#
# below one line project name need to be lowercaes
PRJNAMETOOT = AVoid
DEFINES += "AVOID_API="
DEFINES += "AVOID_API(...)="
#
DEFINES += "UCLASS()=AVOID_API"
DEFINES += "UCLASS(...)=AVOID_API"
#
# this is true during development with unreal-editor...

DEFINES += "WITH_EDITORONLY_DATA=1"

## this project only
DEFINES += PLATFORM_ANDROID
##


INCLUDEPATH += ../Intermediate/Build/Win64/UnrealEditor/Inc/$$PRJNAMETOOT/UHT
INCLUDEPATH += $$PRJNAMETOOT $$PRJNAMETOOT/Public $$PRJNAMETOOT/Private
#INCLUDEPATH += ../Plugins/NNEPostProcessing/Source/NNEPostProcessing/Public
# we should follow UE project struct to include files, start from prj.Build.cs folder
#
#  The Thirdparty libs
#
#
#
include(defs.pri)
include(inc.pri)
#
## this project only
# INCLUDEPATH += $$UESRCROOT/Runtime/Renderer/Private
##
#
#

DISTFILES += \
    AVoid.Target.cs \
    AVoid/AVoid.Build.cs \
    AVoidEditor.Target.cs

HEADERS += \
    AVoid/AVoid.h \
    AVoid/Charactor/AVoidCamera.h \
    AVoid/Charactor/AVoidCharacter.h \
    AVoid/Charactor/CharacterLight.h \
    AVoid/Charactor/Locomotion.h \
    AVoid/Charactor/Mechanics.h \
    AVoid/General/AVoidGameModeBase.h \
    AVoid/General/AVoidPlayerController.h \
    AVoid/Level/LevelDirector.h \
    AVoid/Level/ObstacleSpawner.h \
    AVoid/UI/AVoidHUD.h \
    AVoid/Utils/Debug.h

SOURCES += \
    AVoid/AVoid.cpp \
    AVoid/Charactor/AVoidCamera.cpp \
    AVoid/Charactor/AVoidCharacter.cpp \
    AVoid/Charactor/CharacterLight.cpp \
    AVoid/Charactor/Locomotion.cpp \
    AVoid/Charactor/Mechanics.cpp \
    AVoid/General/AVoidGameModeBase.cpp \
    AVoid/General/AVoidPlayerController.cpp \
    AVoid/Level/LevelDirector.cpp \
    AVoid/Level/ObstacleSpawner.cpp \
    AVoid/UI/AVoidHUD.cpp
