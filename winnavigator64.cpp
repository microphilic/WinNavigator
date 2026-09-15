
// winnavigator64.cpp: Uygulamanın sınıf davranışlarını tanımlar.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "winnavigator64.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "winnavigator64Doc.h"
#include "winnavigator64View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cwinnavigator64App

BEGIN_MESSAGE_MAP(Cwinnavigator64App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &Cwinnavigator64App::OnAppAbout)
	// Standart dosya tabanlı belge komutları
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standart yazdırma ayarları komutu
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// Cwinnavigator64App oluşturma

Cwinnavigator64App::Cwinnavigator64App() noexcept
{
	m_bHiColorIcons = TRUE;


	m_nAppLook = 0;
	// Yeniden Başlatma Yöneticisini destekle
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Uygulama, Ortak Dil Çalışma Zamanı desteği kullanılarak derlendiyse (/clr):
	//     1) Yeniden Başlatma Yöneticisi desteğinin düzgün çalışması için bu ek ayar gerekir.
	//     2) Projenizde, derlemek üzere System.Windows.Forms başvurusu eklemeniz gerekir.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: Aşağıdaki uygulama kimliği dizesini benzersiz kimlik dizesiyle değiştirin; dize için
	// önerilen biçim: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("winnavigator64.AppID.NoVersion"));

	// TODO: Oluşturma kodunu buraya ekleyin,
	// Tüm önemli başlatmaları InitInstance'a yerleştir
}

// Tek Cwinnavigator64App nesnesi

Cwinnavigator64App theApp;


// Cwinnavigator64App başlatma

BOOL Cwinnavigator64App::InitInstance()
{
	// Bir uygulama bildirimi, görsel stilleri etkinleştirmek için
	// ComCtl32.dll sürüm 6 veya sonraki sürümlerin kullanılmasını belirtiyorsa
	// Windows XP'de InitCommonControlsEx() gerekir. Aksi takdirde pencere oluşturulamaz.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Uygulamanızda kullanmak istediğiniz tüm ortak denetim sınıflarını
	// dahil etmek için bunu ayarlayın.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE kitaplıklarını başlat
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// RichEdit denetimini kullanmak için AfxInitRichEdit2() gerekir
	// AfxInitRichEdit2();

	// Standart başlatma
	// Bu özellikleri kullanmıyorsanız ve son yürütülebilir dosyanızın boyutunu
	// azaltmak istiyorsanız, aşağıdan ihtiyacınız olmayan belirli başlatma
	// yordamlarını kaldırmanız gerekir
	// Ayarlarımızın depolandığı kayıt defteri anahtarını değiştirin
	// TODO: Bu dizeyi, şirketinizin veya kuruluşunuzun adı gibi
	// uygun bir dize olarak değiştirmeniz gerekir
	SetRegistryKey(_T("Yerel AppWizard Tarafından Oluşturulan Uygulamalar"));
	LoadStdProfileSettings(4);  // Standart INI dosyası seçeneklerini yükleyin (MRU dahil)


	InitContextMenuManager();
	InitShellManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Uygulamanın belge şablonlarını kaydedin. Belge şablonları,
	//  belgeler, çerçeve pencereleri ve görünümler arasında bağlantı görevi görür
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_winnavigator64TYPE,
		RUNTIME_CLASS(Cwinnavigator64Doc),
		RUNTIME_CLASS(CChildFrame), // özel MDI alt çerçevesi
		RUNTIME_CLASS(Cwinnavigator64View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ana MDI Çerçevesi penceresi oluştur
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Standart kabuk komutları, DDE, dosya açma için komut satırını ayrıştır
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Komut satırında belirtilen komutları dağıtın. Uygulama /RegServer, /Register,
	// /Unregserver veya /Unregister ile başlatıldıysa FALSE değerini döndürür.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Ana pencere başlatıldı, gösterip güncelleştirin
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int Cwinnavigator64App::ExitInstance()
{
	//TODO: Eklemiş olabileceğiniz ek kaynakları işleyin
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// Cwinnavigator64App ileti işleyicileri


// Uygulamanın Hakkında bölümü için kullanılan CAboutDlg iletişim kutusu

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// İletişim Kutusu Verileri
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV desteği

// Uygulama
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// İletişim kutusunu çalıştırmak için uygulama komutu
void Cwinnavigator64App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Cwinnavigator64App özelleştirme yükleme/kaydetme metotları

void Cwinnavigator64App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void Cwinnavigator64App::LoadCustomState()
{
}

void Cwinnavigator64App::SaveCustomState()
{
}

// Cwinnavigator64App ileti işleyicileri



