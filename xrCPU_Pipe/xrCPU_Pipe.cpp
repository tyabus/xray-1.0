// xrCPU_Pipe.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
//#include "../stdafx.h"
#pragma hdrstop

#pragma comment(lib,"xr_3DA")

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

extern xrSkin1W			xrSkin1W_x86;
extern xrSkin2W			xrSkin2W_x86;
extern xrM44_Mul		xrM44_Mul_x86;
extern xrTransfer		xrTransfer_x86;
extern xrMemCopy_8b		xrMemCopy_x86;
extern xrMemCopy_8b		xrMemCopy_MMX;
extern xrMemFill_32b	xrMemFill32_x86;
extern xrMemFill_32b	xrMemFill32_MMX;

extern "C" {
	__declspec(dllexport) void	__cdecl	xrBind_PSGP	(xrDispatchTable* T, DWORD dwFeatures)
	{
		if(strstr(strlwr(GetCommandLine()),"-x86"))	dwFeatures &= ~(_CPU_FEATURE_SSE+_CPU_FEATURE_MMX);

		// generic
		T->skin1W	= xrSkin1W_x86;
		T->skin2W	= xrSkin2W_x86;
		T->m44_mul	= xrM44_Mul_x86;
		T->transfer = xrTransfer_x86;
		T->memCopy	= xrMemCopy_x86;
		T->memFill	= NULL;
		T->memFill32= xrMemFill32_x86;

		// mmx
		if (dwFeatures & _CPU_FEATURE_MMX) {
			T->memCopy = xrMemCopy_MMX;
			T->memFill32 = xrMemFill32_MMX;
		}
	}
};
