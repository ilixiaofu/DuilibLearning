#pragma once

#include "meta.h"

// 从 ui::ListContainerElement 中继承所有可用功能
class CItem : public ui::ListContainerElement
{
public:
	CItem();
	~CItem();

	// 提供外部调用来初始化 item 数据
	void InitSubControls(const std::wstring& img, const std::wstring& title);

private:
	bool OnRemove(ui::EventArgs* args);

private:
	ui::ListBox* list_box_;

	ui::Control* control_img_;
	ui::Label* label_title_;
	ui::Progress* progress_;
	ui::Button* btn_del_;
};
