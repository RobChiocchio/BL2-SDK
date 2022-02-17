#pragma once
#ifndef CSIMPLEDETOUR_H
#define CSIMPLEDETOUR_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "detours/detours.h"

class CSimpleDetour
{
public:
	CSimpleDetour(void** old, void* replacement);

	void Attach();
	void Detach();
private:
	void** m_fnOld;
	void* m_fnReplacement;

	bool m_bAttached;
};

#define SETUP_SIMPLE_DETOUR(name, old, replacement) \
	CSimpleDetour name(&(PVOID&)old, (void *)(&(void * &)replacement))

#define SETUP_DETOUR_FUNCTION( ret, conv, name, params ) \
	ret conv name##_H params; \
	ret ( conv *name##_T ) params = name; \
	CSimpleDetour *Detour_##name = new CSimpleDetour( &(void * &)name##_T, (void *)(&(void * &)name##_H) ); \
	ret conv name##_H params

#define SETUP_DETOUR_FUNCTION_LATE( ret, conv, name, params ) \
	ret conv name##_H params; \
	ret ( conv *name##_T ) params = NULL; \
	CSimpleDetour *Detour_##name = NULL; \
	ret conv name##_H params

#define SETUP_DETOUR_LATE( name ) \
	Detour_##name = new CSimpleDetour( &(void * &)name##_T, (void *)(&(void * &)name##_H) )

#define SETUP_DETOUR_EXTERN( ret, conv, name, params ) \
	extern ret ( conv *name##_T ) params; \
	extern CSimpleDetour *Detour_##name

#define SETUP_DETOUR_TRAMP( ret, conv, name, params ) \
	ret ( conv *name##_T ) params = NULL;
#endif // !CSIMPLEDETOUR_H_
