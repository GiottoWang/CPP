#include"mfc.h"
app a;
BOOL app::InitInstance() {
	frame *f = new frame;
	f->ShowWindow(SW_SHOWNORMAL);//显示
	f->UpdateWindow();//更新
	m_pMainWnd = f;//指向主窗口的指针
	return TRUE;
};
frame::frame() {
	Create(NULL,TEXT("mfc"));
}