#ifndef _APPCONFIG_H
#define _APPCONFIG_H


#include "compiler.h"

#define DEV_BUILD_KEY_IF        0x44564946 
#define DEV_BUILD_KEY_BL        0x4456424C  

#if defined (_LOADER)
COMPILER_ASSERT(DEV_BUILD_KEY == DEV_BUILD_KEY_BL);
#else
COMPILER_ASSERT(DEV_BUILD_KEY == DEV_BUILD_KEY_IF);
#endif


/*****************************************************************************
*	软件版本
*/
struct _tag_SOFTVER
{
	unsigned int softver;	        /*软件版本*/
	unsigned int hardware;		/*硬件类型*/
	const char * dev;
};

//extern const struct _tag_SOFTVER SoftVer;
unsigned int getSoftVer(void);

#if 0
#define DEV_COMPILEVER			1
#define DEVICE_VERSION			DEV_VERSION(1, 0, 0)
#define DEV_VERSION(first,second,third)	(((first&0xff)<<24)|((second&0xff)<<16)|((third&0xff)<<8)|(DEV_COMPILEVER&0xff))
#endif

//extern void SoftVersion(void);

#endif
