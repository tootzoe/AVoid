




UE_ROOT = D:/UE5/UE_5.4

INCLUDEPATH += $$UE_ROOT/Engine/Source \
                           $$UE_ROOT/Engine/Intermediate/Build/Win64/UE4Editor/Inc \
                           $$UE_ROOT/Engine/Intermediate/Build/Win64/UE4Editor/Inc/Engine/UHT \
                           $$UE_ROOT/Engine/Source/Runtime \
                           $$UE_ROOT/Engine/Source/Runtime/Engine/Classes \
                           $$UE_ROOT/Engine/Source/Runtime/Engine/Public \
                           $$UE_ROOT/Engine/Source/Runtime/TraceLog/Public \
                           $$UE_ROOT/Engine/Source/Runtime/Core/Public \
                           $$UE_ROOT/Engine/Source/Runtime/CoreUObject/Public \
                           $$UE_ROOT/Engine/Source/Runtime/UMG/Public \
                           $$UE_ROOT/Engine/Source/Runtime/Experimental/Chaos/Public \
                           $$UE_ROOT/Engine/Source/Runtime/AIModule/Classes \
                           $$UE_ROOT/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public

######  Project reletived
INCLUDEPATH += ./../Intermediate/Build/Win64/UnrealEditor/Inc/AVoid/UHT

INCLUDEPATH += ./AVoid













DEFINES += "USE_QTCREATOR"
DEFINES += "AVOID_API=  "

DEFINES += "BlueprintCallable" \
           "BlueprintImplementableEvent" \
           "BlueprintNativeEvent" \
           "_Implementation" "VisibleAnywhere" \
            "EditAnywhere" "BlueprintReadWrite" \
            "Category" "BlueprintReadOnly" \
            "Transient" "VisibleDefaultsOnly" \
            "EditDefaultsOnly" "EditInstanceOnly" \
            "AllowPrivateAccess"


#####

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







