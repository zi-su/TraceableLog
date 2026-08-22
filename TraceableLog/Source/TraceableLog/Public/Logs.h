// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Usage is the same as UE_LOG
// The source file and line number are appended to the end of the message.
#define TRACEABLE_LOG(Category, Verbosity, Format, ...) \
	do \
	{ \
		const FStringView FileName = FPathViews::GetCleanFilename(TEXT(__FILE__)); \
		UE_LOG(Category, Verbosity, Format TEXT(" [%.*s:%d]"), \
			##__VA_ARGS__, FileName.Len(), FileName.GetData(), __LINE__); \
	} while (false)
