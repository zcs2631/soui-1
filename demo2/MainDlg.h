// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <valueAnimator\ValueAnimator.h>

class CMainDlg : public SHostWnd, IAnimation::IAnimationListener, IValueAnimator::IAnimatorListener, IValueAnimator::IAnimatorUpdateListener
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

protected:
	//IAnimation::IAnimationListener
	virtual void onAnimationStart(IAnimation * animation);

	virtual void onAnimationEnd(IAnimation * animation);

	virtual void onAnimationRepeat(IAnimation * animation);

	// 通过 IAnimatorListener 继承
	virtual void onAnimationStart(IValueAnimator * pAnimator) override;
	virtual void onAnimationEnd(IValueAnimator * pAnimator) override;
	virtual void onAnimationRepeat(IValueAnimator * pAnimator) override;

	// 通过 IAnimatorUpdateListener 继承
	virtual void onAnimationUpdate(IValueAnimator * pAnimator) override;

protected:
	void onBtnTest();
	void onBtnShow();
	void onBtnHide();
	void onBtnAnimator();
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_test",onBtnTest)
		EVENT_NAME_COMMAND(L"btn_show",onBtnShow)
		EVENT_NAME_COMMAND(L"btn_hide",onBtnHide)
		EVENT_NAME_COMMAND(L"btn_animator",onBtnAnimator)
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()


private:
	BOOL			m_bLayoutInited;	

};
