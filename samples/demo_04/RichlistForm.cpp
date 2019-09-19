#include "RichlistForm.h"
#include "Item.h"

const std::wstring CRichlistForm::kClassName = L"Basic";

CRichlistForm::CRichlistForm()
{
}


CRichlistForm::~CRichlistForm()
{
}

std::wstring CRichlistForm::GetSkinFolder()
{
	return L"richlist";
}

std::wstring CRichlistForm::GetSkinFile()
{
	return L"richlist.xml";
}

std::wstring CRichlistForm::GetWindowClassName() const
{
	return kClassName;
}

void CRichlistForm::InitWindow()
{
	list_ = dynamic_cast<ui::ListBox*>(FindControl(L"list"));

	for (auto i = 0; i < 100; i++)
	{
		CItem* item = new CItem;
		ui::GlobalManager::FillBoxWithCache(item, L"richlist/item.xml");

		std::wstring img = L"icon.png";
		std::wstring title = nbase::StringPrintf(L"�������� [%02d]", i + 1);

		item->InitSubControls(img, title);
		list_->Add(item);
	}

	// �����б��е��ѡ��������¼�
	list_->AttachSelect(nbase::Bind(&CRichlistForm::OnSelected, this, std::placeholders::_1));
}


bool CRichlistForm::OnSelected(ui::EventArgs* args)
{
	int current = args->wParam;
	int old = args->lParam;


	auto message = nbase::StringPrintf(L"��ѡ��������Ϊ %d �������һ��ѡ����������Ϊ %d", current, old);
	ShowMsgBox(GetHWND(), MsgboxCallback(), message, false, L"��ʾ", false);

	return true;
}

LRESULT CRichlistForm::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	PostQuitMessage(0L);
	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}