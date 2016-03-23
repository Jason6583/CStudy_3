#pragma once


template <typename T>
inline void SAFE_DELETE(T& Pointer)
{
	if (Pointer)
	{
		delete Pointer;
		Pointer = NULL;
	}
}