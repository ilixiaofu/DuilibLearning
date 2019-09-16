#include "WinMain.h"
#include "ControlsForm.h"

void MainThread::Init()
{
	nbase::ThreadManager::RegisterThread(kThreadUI);

	// 启动杂事处理线程
	misc_thread_.reset(new MiscThread(kThreadGlobalMisc, "Global Misc Thread"));
	misc_thread_->Start();

	// 获取资源路径，初始化全局参数
	std::wstring app_dir = QPath::GetAppPath();
	ui::GlobalManager::Startup(app_dir + L"resources\\", ui::CreateControlCallback(), false);

	// 创建一个默认带有阴影的居中窗口
	ControlForm* window = new ControlForm();
	window->Create(NULL, ControlForm::kClassName.c_str(), WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, 0);
	window->CenterWindow();
	window->ShowWindow();
}

void MainThread::Cleanup()
{
	ui::GlobalManager::Shutdown();

	misc_thread_->Stop();
	misc_thread_.reset(nullptr);

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

	// TODO: 在此处放置代码。
	// 创建主线程
	MainThread thread;

	// 执行主线程循环
	thread.RunOnCurrentThreadWithLoop(nbase::MessageLoop::kUIMessageLoop);

	return 0;
}