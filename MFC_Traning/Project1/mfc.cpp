#include"mfc.h"
app a;
BOOL app::InitInstance() {
	frame *f = new frame;
	f->ShowWindow(SW_SHOWNORMAL);//��ʾ
	f->UpdateWindow();//����
	m_pMainWnd = f;//ָ�������ڵ�ָ��
	return TRUE;
};
frame::frame() {
	Create(NULL,TEXT("mfc"));
}