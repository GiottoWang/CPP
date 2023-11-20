#pragma once
#include<afxwin.h>
class app :public CWinApp {//应用程序类
	virtual BOOL InitInstance();
};
class frame :public CFrameWnd {//框架类
public:
	frame();
};