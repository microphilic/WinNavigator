
// ChildFrm.h: CChildFrame sınıfının arabirimi
//

#pragma once

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame() noexcept;

// Öznitelikler
protected:
	CSplitterWndEx m_wndSplitter;
public:

// İşlemler
public:

// Geçersiz Kılar
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Uygulama
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Oluşturulan ileti eşlemesi işlevleri
protected:
	DECLARE_MESSAGE_MAP()
};
