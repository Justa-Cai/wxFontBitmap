///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UIBase.h"

///////////////////////////////////////////////////////////////////////////

CMainFrameBase::CMainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_bSizer = new wxBoxSizer( wxVERTICAL );
	
	m_button = new wxButton( this, wxID_ANY, wxT("ReDraw"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bSizer->Add( m_button, 0, wxALL, 5 );
	
	this->SetSizer( m_bSizer );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	MainMenu = new wxMenu();
	wxMenuItem* m_menuItemSelectFont;
	m_menuItemSelectFont = new wxMenuItem( MainMenu, wxID_ANY, wxString( wxT("Select Font") ) , wxEmptyString, wxITEM_NORMAL );
	MainMenu->Append( m_menuItemSelectFont );
	
	m_menubar1->Append( MainMenu, wxT("TOOLS") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnButtonReDrawClick ), NULL, this );
	this->Connect( m_menuItemSelectFont->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CMainFrameBase::OnSelectFont ) );
}

CMainFrameBase::~CMainFrameBase()
{
	// Disconnect Events
	m_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnButtonReDrawClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CMainFrameBase::OnSelectFont ) );
	
}

CTestFontBitmapDlgBase::CTestFontBitmapDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("String:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText1->Wrap( -1 );
	bSizer21->Add( m_staticText1, 0, wxALL, 5 );
	
	m_textCtrlString = new wxTextCtrl( this, wxID_ANY, wxT("L"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_textCtrlString, 1, wxALL, 5 );
	
	m_buttonDraw = new wxButton( this, wxID_ANY, wxT("Draw"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_buttonDraw, 0, wxALL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Select Font"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_button7, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer21, 0, wxEXPAND, 5 );
	
	m_textCtrlResult = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer2->Add( m_textCtrlResult, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( CTestFontBitmapDlgBase::OnPaint ) );
	m_buttonDraw->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CTestFontBitmapDlgBase::OnBtnDraw ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CTestFontBitmapDlgBase::OnSelectFont ), NULL, this );
}

CTestFontBitmapDlgBase::~CTestFontBitmapDlgBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( CTestFontBitmapDlgBase::OnPaint ) );
	m_buttonDraw->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CTestFontBitmapDlgBase::OnBtnDraw ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CTestFontBitmapDlgBase::OnSelectFont ), NULL, this );
	
}

CPaintPanelBase::CPaintPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	
	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( CPaintPanelBase::OnPaintPanelPaint ) );
}

CPaintPanelBase::~CPaintPanelBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( CPaintPanelBase::OnPaintPanelPaint ) );
	
}
