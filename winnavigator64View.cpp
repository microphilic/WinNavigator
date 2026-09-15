
// winnavigator64View.cpp: Cwinnavigator64View sınıfının uygulaması
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS; önizleme, küçük resim ve arama filtresi işleyicilerini uygulayan
// bir ATL projesinde tanımlanabilir ve belge kodunun o projeyle paylaşılmasına olanak sağlar.
#ifndef SHARED_HANDLERS
#include "winnavigator64.h"
#endif

#include "winnavigator64Doc.h"
#include "winnavigator64View.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cwinnavigator64View

IMPLEMENT_DYNCREATE(Cwinnavigator64View, CView)

BEGIN_MESSAGE_MAP(Cwinnavigator64View, CView)
	// Standart yazdırma komutları
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cwinnavigator64View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// Cwinnavigator64View oluşturma/yok etme

Cwinnavigator64View::Cwinnavigator64View() noexcept
{
	// TODO: Buraya oluşturma kodunu ekleyin

}

Cwinnavigator64View::~Cwinnavigator64View()
{
}

BOOL Cwinnavigator64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Burada, CREATESTRUCT cs'yi değiştirerek Window sınıfını veya
	//  stillerini değiştirin

	return CView::PreCreateWindow(cs);
}

// Cwinnavigator64View çizimi

void Cwinnavigator64View::OnDraw(CDC* /*pDC*/)
{
	Cwinnavigator64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Buraya yerel veriler için çizim kodunu ekleyin
}


// Cwinnavigator64View yazdırma


void Cwinnavigator64View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cwinnavigator64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// varsayılan hazırlık
	return DoPreparePrinting(pInfo);
}

void Cwinnavigator64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Yazdırmadan önce ek başlatma ekleyin
}

void Cwinnavigator64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Yazdırdıktan sonra temizleme ekleyin
}

void Cwinnavigator64View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cwinnavigator64View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cwinnavigator64View tanılama

#ifdef _DEBUG
void Cwinnavigator64View::AssertValid() const
{
	CView::AssertValid();
}

void Cwinnavigator64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cwinnavigator64Doc* Cwinnavigator64View::GetDocument() const // hata ayıklama dışı sürüm satır içidir
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cwinnavigator64Doc)));
	return (Cwinnavigator64Doc*)m_pDocument;
}
#endif //_DEBUG


// Cwinnavigator64View ileti işleyicileri

int Cwinnavigator64View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Özelleşmiş oluşumun kodunu buraya ekleyin
	CRect rectDummy(0, 0, 0, 0);

	m_wndList.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, rectDummy, this, 1);

	return 0;
}

void Cwinnavigator64View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: İleti işleyicinizin kodunu buraya ekleyin
	m_wndList.SetWindowPos(nullptr, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void Cwinnavigator64View::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	if (bActivate && AfxGetMainWnd() != nullptr)
	{
		((CMainFrame*)AfxGetMainWnd())->GetShellTreeCtrl().SetRelatedList(&m_wndList);
	}

	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}