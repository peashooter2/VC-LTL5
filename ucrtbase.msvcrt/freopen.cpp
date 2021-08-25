﻿#include <stdio.h>
#include <internal_shared.h>

#if WindowsTargetPlatformMinVersion < WindowsTargetPlatformWindows6
extern "C" errno_t __cdecl freopen_s(
	_Outptr_result_maybenull_ FILE** _Stream,
	_In_z_                    char const* _FileName,
	_In_z_                    char const* _Mode,
	_Inout_                   FILE* _OldStream
)
{
	_VALIDATE_RETURN_ERRCODE(_Stream != nullptr, EINVAL);

	return (*_Stream = freopen(_FileName, _Mode, _OldStream)) ? 0 : errno;
}

_LCRT_DEFINE_IAT_SYMBOL(freopen_s);
#endif

#if WindowsTargetPlatformMinVersion < WindowsTargetPlatformWindows6
extern "C" errno_t __cdecl _wfreopen_s(
	_Outptr_result_maybenull_ FILE** _Stream,
	_In_z_                    wchar_t const* _FileName,
	_In_z_                    wchar_t const* _Mode,
	_Inout_                   FILE* _OldStream
)
{
	_VALIDATE_RETURN_ERRCODE(_Stream != nullptr, EINVAL);

	return (*_Stream = _wfreopen(_FileName, _Mode, _OldStream)) ? 0 : errno;
}

_LCRT_DEFINE_IAT_SYMBOL(_wfreopen_s);
#endif
