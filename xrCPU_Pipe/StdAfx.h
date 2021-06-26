#pragma once

#pragma warning(disable:4995)
#include <d3d9.h>
#pragma warning(default:4995)

#include "../xrCore/xrCore.h"

// you must define ENGINE_BUILD then building the engine itself
// and not define it if you are about to build DLL
#ifndef NO_ENGINE_API
	#ifdef ENGINE_BUILD
		#define DLL_API			__declspec(dllimport)
		#define ENGINE_API		__declspec(dllexport)
	#else
		#define DLL_API			__declspec(dllexport)
		#define ENGINE_API		__declspec(dllimport)
	#endif
#else
	#define ENGINE_API
	#define DLL_API
#endif // NO_ENGINE_API

#define ECORE_API

// Our headers
#include "engine.h"
#include "defines.h"
#include "device.h"

#pragma warning(disable:4995)
#include <xmmintrin.h>
#pragma warning(default:4995)