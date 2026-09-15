
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CCalendarBar penceresi

class CCalendarBar : public CWnd
{
// Oluşturma
public:
	CCalendarBar();

// Öznitelikler
protected:
	CMonthCalCtrl m_wndCalendar;
	int m_nMyCalendarsY;
	CImageList m_Images;

// Geçersiz Kılar
public:
	virtual BOOL Create(const RECT& rect, CWnd* pParentWnd, UINT nID = (UINT)-1);
	virtual BOOL PreTranslateMessage(MSG *pMsg);

// Uygulama
public:
	virtual ~CCalendarBar();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd *pOldWnd);

	DECLARE_MESSAGE_MAP()
};
