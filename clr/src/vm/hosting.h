// ==++==
// 
//   
//    Copyright (c) 2006 Microsoft Corporation.  All rights reserved.
//   
//    The use and distribution terms for this software are contained in the file
//    named license.txt, which can be found in the root of this distribution.
//    By using this software in any fashion, you are agreeing to be bound by the
//    terms of this license.
//   
//    You must not remove this notice, or any other, from this software.
//   
// 
// ==--==

#ifndef __HOSTING_H__
#define __HOSTING_H__

#include "clrhost.h"

#define ClrVirtualAlloc                 EEVirtualAlloc
#define ClrVirtualFree                  EEVirtualFree
#define ClrVirtualQuery                 EEVirtualQuery
#define ClrVirtualProtect               EEVirtualProtect
#define ClrHeapCreate                   EEHeapCreate
#define ClrHeapDestroy                  EEHeapDestroy
#define ClrHeapAlloc                    EEHeapAlloc
#define ClrHeapFree                     EEHeapFree
#define ClrHeapValidate                 EEHeapValidate
#define ClrCreateCriticalSection        EECreateCriticalSection
#define ClrDestroyCriticalSection       EEDestroyCriticalSection
#define ClrEnterCriticalSection         EEEnterCriticalSection
#define ClrLeaveCriticalSection         EELeaveCriticalSection
#define ClrSleepEx                      EESleepEx
#define ClrTlsSetValue                  EETlsSetValue
#define ClrTlsGetValue                  EETlsGetValue

#define ClrAllocationDisallowed         EEAllocationDisallowed

// memory management function
LPVOID EEVirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL EEVirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
SIZE_T EEVirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
BOOL EEVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
HANDLE EEGetProcessHeap();
HANDLE EEHeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
BOOL EEHeapDestroy(HANDLE hHeap);
LPVOID EEHeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
BOOL EEHeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
BOOL EEHeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);

BOOL EEAllocationDisallowed();
HANDLE EEGetProcessExecutableHeap();

// critical section functions
CRITSEC_COOKIE EECreateCriticalSection(LPCSTR szTag, LPCSTR level, CrstFlags flags);
void EEDeleteCriticalSection(CRITSEC_COOKIE cookie);
void EEEnterCriticalSection(CRITSEC_COOKIE cookie);
void EELeaveCriticalSection(CRITSEC_COOKIE cookie);

DWORD EESleepEx(DWORD dwMilliseconds, BOOL bAlertable);

// TLS functions
LPVOID EETlsGetValue(DWORD slot);
BOOL EETlsCheckValue(DWORD slot, LPVOID * pValue);
VOID EETlsSetValue(DWORD slot, LPVOID pData);



#endif
    
