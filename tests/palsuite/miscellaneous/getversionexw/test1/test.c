/*============================================================
**
** Source : test.c
**
** Purpose: Test for GetVersionExW() function
**
** 
**  Copyright (c) 2006 Microsoft Corporation.  All rights reserved.
** 
**  The use and distribution terms for this software are contained in the file
**  named license.txt, which can be found in the root of this distribution.
**  By using this software in any fashion, you are agreeing to be bound by the
**  terms of this license.
** 
**  You must not remove this notice, or any other, from this software.
** 
**
**=========================================================*/

#define UNICODE

#include <palsuite.h>

int __cdecl main(int argc, char *argv[]) 
{
	
    OSVERSIONINFO TheVersionInfo;
    OSVERSIONINFO* pVersionInfo = &TheVersionInfo;
 
    /*
     * Initialize the PAL and return FAILURE if this fails
     */

    if(0 != (PAL_Initialize(argc, argv)))
    {
        return FAIL;
    }

    /* This needs to be done before using GetVersionEx */
    pVersionInfo->dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
  
    /* If GetVersionEx fails, then the test fails */
    if(GetVersionEx(pVersionInfo) == 0) 
    {
        Fail("ERROR: The GetVersionEx function returned 0, which indicates " 
             "failure.");
    }
  
    /* These values are fixed, ensure they're set properly */
    if(pVersionInfo->dwMajorVersion != 5) 
    {
        Fail("ERROR: The fixed value of dwMajorVersion shoud be 5, but is "
             " really %d.",pVersionInfo->dwMajorVersion);
    }

    /* The minor version values for Win2k and XP are different 
       for Win2k minor version equals 0 and for XP minor version
       equals 1.  Both values are excepted here. */
    if((pVersionInfo->dwMinorVersion != 0) && 
       (pVersionInfo->dwMinorVersion != 1)) 
    {
        Fail("ERROR: The fixed value of dwMinorVersion shoud be 0 or 1, "
             "but is really %d.",pVersionInfo->dwMinorVersion);
    }

    if(pVersionInfo->dwBuildNumber_PAL_Undefined < 0) 
    {
        Fail("ERROR: The value of dwBuildNumber shoud be at least 0, but is "
             "really %d.",pVersionInfo->dwBuildNumber_PAL_Undefined);
    }

#if !WIN32


    /* Under BSD, the PlatformID should be UNIX and the Service Pack
       version should be set to "".
    */

    if(pVersionInfo->dwPlatformId != VER_PLATFORM_UNIX ||
       pVersionInfo->szCSDVersion_PAL_Undefined[0] != 0) 
    {
        Fail("ERROR: The dwPlatformId should be %d but is really %d.  And the "
             "szCSDVerion should be NULL.",VER_PLATFORM_UNIX,
             pVersionInfo->dwPlatformId);
    }
#endif
  
    
    PAL_Terminate();
    return PASS;
}



