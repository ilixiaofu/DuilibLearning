#ifndef _META_H_
#define _META_H_

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����
// Windows ͷ�ļ�
#include <windows.h>
// C ����ʱͷ�ļ�
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