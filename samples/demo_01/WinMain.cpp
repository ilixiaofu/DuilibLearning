#include "WinMain.h"
#include "BasicForm.h"

void MainThread::Init()
{
	nbase::ThreadManager::RegisterThread(kThreadUI);

	// ��ȡ��Դ·������ʼ��ȫ�ֲ���
	std::wstring theme_dir = QPath::GetAppPath();
#ifdef _DEBUG
	// Debug ģʽ��ʹ�ñ����ļ�����Ϊ��Դ
	// Ĭ��Ƥ��ʹ�� resources\\themes\\default
	// Ĭ������ʹ�� resources\\lang\\zh_CN
	// �����޸���ָ�� Startup �����������
	ui::GlobalManager::Startup(theme_dir + L"resources\\", ui::CreateControlCallback(), false);
#else
	// Release ģʽ��ʹ����Դ�е�ѹ������Ϊ��Դ
	// ��Դ�����뵽��Դ�б����Ϊ THEME����Դ����Ϊ IDR_THEME
	// �����Դʹ�õ��Ǳ��ص� zip �ļ�������Դ�е� zip ѹ����
	// ����ʹ�� OpenResZip ��һ�����غ����򿪱��ص���Դѹ����
	ui::GlobalManager::OpenResZip(MAKEINTRESOURCE(IDR_ZIP2), L"THEME", "");
	// ui::GlobalManager::OpenResZip(L"resources.zip", "");
	ui::GlobalManager::Startup(L"resources\\", ui::CreateControlCallback(), false);
#endif

	// ����һ��Ĭ�ϴ�����Ӱ�ľ��д���
	BasicForm* window = new BasicForm();
	window->Create(NULL, BasicForm::kClassName.c_str(), WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, 0);
	window->CenterWindow();
	window->ShowWindow();
}

void MainThread::Cleanup()
{
	ui::GlobalManager::Shutdown();
	SetThreadWasQuitProperly(true);
	nbase::ThreadManager::UnregisterThread();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: �ڴ˴����ô��롣
	// �������߳�
	MainThread thread;

	// ִ�����߳�ѭ��
	thread.RunOnCurrentThreadWithLoop(nbase::MessageLoop::kUIMessageLoop);

	return 0;
}
