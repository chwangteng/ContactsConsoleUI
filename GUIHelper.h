#ifndef _GUIHELPER_H
#define _GUIHELPER_H
#include<Windows.h>
extern CONSOLE_CURSOR_INFO cci;                                //定义光标信息
extern COORD pos;                                              //定义光标坐标
extern HANDLE outPutHandle;                                    //定义获并得标准输出句柄
extern HANDLE inPutHandle;                                     //定义并获得标准输入句柄
extern INPUT_RECORD Input_Record;                              //定义输入事件结构体
extern DWORD res;                                              //定义返回记录
#endif