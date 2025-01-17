﻿// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#define DEBUG_LOG(Message) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,  FString(__FUNCTION__) + "(" + FString::FromInt(__LINE__) + ") " + Message);
#define DEBUG_LOG_TICK(Message) GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Yellow,  FString(__FUNCTION__) + "(" + FString::FromInt(__LINE__) + ") " + Message);
#define DEBUG_LOG_NUMBER(Message, Number) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,  FString(__FUNCTION__) + "(" + FString::FromInt(__LINE__) + ") " + Message + FString::SanitizeFloat(Number));
#define DEBUG_LOG_NUMBER_TICK(Message, Number) GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan,  FString(__FUNCTION__) + "(" + FString::FromInt(__LINE__) + ") " + Message + FString::SanitizeFloat(Number));
#define DEBUG_LOG_ERROR(Message) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red,  FString(__FUNCTION__) + "(" + FString::FromInt(__LINE__) + ") " + Message);
