
// winnavigator64View.h: Cwinnavigator64View sınıfının arabirimi
//

#pragma once
#include <afxshelllistctrl.h>


class Cwinnavigator64View : public CView
{
protected: // yalnızca serileştirmeden oluştur
	Cwinnavigator64View() noexcept;
	DECLARE_DYNCREATE(Cwinnavigator64View)

// Öznitelikler
public:
	Cwinnavigator64Doc* GetDocument() const;

// İşlemler
public:

// Geçersiz Kılar
public:
	virtual void OnDraw(CDC* pDC);  // bu görünümü çizmek için geçersiz kılındı
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Uygulama
public:
	virtual ~Cwinnavigator64View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);

// Oluşturulan ileti eşlemesi işlevleri
private:
	CMFCShellListCtrl m_wndList;
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // winnavigator64View.cpp içinde hata ayıklama sürümü
inline Cwinnavigator64Doc* Cwinnavigator64View::GetDocument() const
   { return reinterpret_cast<Cwinnavigator64Doc*>(m_pDocument); }
#endif

