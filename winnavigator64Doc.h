
// winnavigator64Doc.h: Cwinnavigator64Doc sınıfının arabirimi
//


#pragma once


class Cwinnavigator64Doc : public CDocument
{
protected: // yalnızca serileştirmeden oluştur
	Cwinnavigator64Doc() noexcept;
	DECLARE_DYNCREATE(Cwinnavigator64Doc)

// Öznitelikler
public:

// İşlemler
public:

// Geçersiz Kılar
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Uygulama
public:
	virtual ~Cwinnavigator64Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Oluşturulan ileti eşlemesi işlevleri
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Arama İşleyicisi için arama içeriğini ayarlayan yardımcı işlevi
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
