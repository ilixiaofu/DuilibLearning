#ifndef _META_H_
#define _META_H_

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// base header
#include "base/base.h"

// shared project
#include "shared/shared.h"

// duilib
#include "duilib/UIlib.h"
//using namespace DuiLib;
//using namespace ui;


#ifdef _DEBUG
#pragma comment(lib, "base_d.lib")
#pragma comment(lib, "duilib_d.lib")
#pragma comment(lib, "shared_d.lib")
#else
#pragma comment(lib, "base.lib")
#pragma comment(lib, "duilib.lib")
#pragma comment(lib, "shared.lib")
//#ifdef _UNICODE
//#pragma comment(lib, "DuiLib_u.lib")
//#else
//#pragma comment(lib, "DuiLib.lib")
#endif

#endif