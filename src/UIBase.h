///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __UIBASE_H__
#define __UIBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CMainFrameBase
///////////////////////////////////////////////////////////////////////////////
class CMainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxBoxSizer* m_bSizer;
		wxButton* m_button;
		wxMenuBar* m_menubar1;
		wxMenu* MainMenu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonReDrawClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectFont( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CMainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxFontBitmap"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 656,659 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~CMainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CTestFontBitmapDlgBase
///////////////////////////////////////////////////////////////////////////////
class CTestFontBitmapDlgBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlString;
		wxButton* m_buttonDraw;
		wxButton* m_button7;
		wxTextCtrl* m_textCtrlResult;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnBtnDraw( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectFont( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxBoxSizer* bSizer2;
		
		CTestFontBitmapDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 705,597 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX ); 
		~CTestFontBitmapDlgBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CPaintPanelBase
///////////////////////////////////////////////////////////////////////////////
class CPaintPanelBase : public wxPanel 
{
	private:
	
	protected:
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPaintPanelPaint( wxPaintEvent& event ) { event.Skip(); }
		
	
	public:
		
		CPaintPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~CPaintPanelBase();
	
};

#endif //__UIBASE_H__
