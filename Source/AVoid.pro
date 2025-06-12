




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

HEADERS += \
    AVoid/AVoid.h \
    AVoid/Character/AVoidCamera.h \
    AVoid/Character/AVoidCharacter.h \
    AVoid/Character/CharacterLight.h \
    AVoid/Character/Locomotion.h \
    AVoid/Character/Mechanics.h \
    AVoid/General/AVoidGameModeBase.h \
    AVoid/General/AVoidPlayerController.h \
    AVoid/Level/LevelDirector.h \
    AVoid/Level/ObstacleSpawner.h \
    AVoid/UI/AVoidHUD.h \
    AVoid/Utils/Debug.h

SOURCES += \
    AVoid/AVoid.cpp \
    AVoid/Character/AVoidCamera.cpp \
    AVoid/Character/AVoidCharacter.cpp \
    AVoid/Character/CharacterLight.cpp \
    AVoid/Character/Locomotion.cpp \
    AVoid/Character/Mechanics.cpp \
    AVoid/General/AVoidGameModeBase.cpp \
    AVoid/General/AVoidPlayerController.cpp \
    AVoid/Level/LevelDirector.cpp \
    AVoid/Level/ObstacleSpawner.cpp \
    AVoid/UI/AVoidHUD.cpp

DISTFILES += \
    AVoid.Target.cs \
    AVoid/AVoid.Build.cs \
    AVoidEditor.Target.cs
