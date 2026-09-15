
// winnavigator64.h: winnavigator64 uygulaması için ana üst bilgi dosyası
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH için bu dosyayı eklemeden önce 'pch.h' öğesini ekle"
#endif

#include "resource.h"       // ana semboller


// Cwinnavigator64App:
// Bu sınıfın uygulaması için bkz. winnavigator64.cpp
//

class Cwinnavigator64App : public CWinAppEx
{
public:
	Cwinnavigator64App() noexcept;


// Geçersiz Kılar
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Uygulama
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cwinnavigator64App theApp;
