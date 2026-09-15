
// winnavigator64Doc.cpp: Cwinnavigator64Doc sınıfının uygulaması
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS; önizleme, küçük resim ve arama filtresi işleyicilerini uygulayan
// bir ATL projesinde tanımlanabilir ve belge kodunun o projeyle paylaşılmasına olanak sağlar.
#ifndef SHARED_HANDLERS
#include "winnavigator64.h"
#endif

#include "winnavigator64Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cwinnavigator64Doc

IMPLEMENT_DYNCREATE(Cwinnavigator64Doc, CDocument)

BEGIN_MESSAGE_MAP(Cwinnavigator64Doc, CDocument)
END_MESSAGE_MAP()


// Cwinnavigator64Doc oluşturma/yok etme

Cwinnavigator64Doc::Cwinnavigator64Doc() noexcept
{
	// TODO: Buraya bir defalık oluşturma kodunu ekleyin

}

Cwinnavigator64Doc::~Cwinnavigator64Doc()
{
}

BOOL Cwinnavigator64Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: Buraya yeniden başlatma kodunu ekleyin
	// (SDI belgeleri bu belgeyi yeniden kullanacak)

	return TRUE;
}




// Cwinnavigator64Doc serileştirmesi

void Cwinnavigator64Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: Depolama kodunu buraya ekle
	}
	else
	{
		// TODO: Yükleme kodunu buraya ekle
	}
}

#ifdef SHARED_HANDLERS

// Küçük resim desteği
void Cwinnavigator64Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Belgenin verilerini çizmek için bu kodu değiştirin
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Arama İşleyicileri desteği
void Cwinnavigator64Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Belgenin verilerinden arama içeriklerini ayarlayın.
	// İçerik parçaları ";" ile ayrılmalıdır

	// Örneğin: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cwinnavigator64Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cwinnavigator64Doc tanılama

#ifdef _DEBUG
void Cwinnavigator64Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cwinnavigator64Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cwinnavigator64Doc komutları
