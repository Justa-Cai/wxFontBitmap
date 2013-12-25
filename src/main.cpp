#include "UIBase.h"
#include <wx/wx.h>
#include <wx/fontenum.h>
#include <wx/fontmap.h>
#include <wx/fontdlg.h>

#include <ft2build.h>
#include FT_FREETYPE_H


static wxFont g_font;

class CPaintPanel:public CPaintPanelBase
{
public:
	CPaintPanel( wxWindow* parent )
		:CPaintPanelBase(parent)
	{
		srand(time(NULL));

	}

	virtual void OnPaintPanelPaint( wxPaintEvent& event ) 
	{
		wxPaintDC dc(this);
		PrepareDC(dc);
		wxMemoryDC memdc;

		wxString str;
		wxFont m_font = g_font;
		//m_font.SetFamily("")
		// the current text origin
		wxCoord x = 5,
			y = 5;

		// output the font name/info
		wxString fontInfo;

		fontInfo.Printf(wxT("Face name: %s, family: %s"),
			m_font.GetFaceName().c_str(),
			m_font.GetFamilyString().c_str());

		dc.DrawText(fontInfo, x, y);
		y=20;
		for (int i=10; i<30; i++) {
			y += i + 3;
			m_font.SetPointSize(i);
			dc.SetFont(m_font);
			str.Printf(wxT("Font Size:%d 你好WX！！"), i);
			dc.DrawText(str, 5, y);

		}
	}
};

class MyEncodingEnumerator : public wxFontEnumerator
{
public:
	MyEncodingEnumerator()
	{ m_n = 0; }

	const wxString& GetText() const
	{ return m_text; }

protected:
	virtual bool OnFontEncoding(const wxString& facename,
		const wxString& encoding)
	{
		wxString text;
		text.Printf(wxT("Encoding %u: %s (available in facename '%s')\n"),
			(unsigned int) ++m_n, encoding.c_str(), facename.c_str());
		m_text += text;
		return true;
	}

	virtual bool OnFacename( const wxString& facename )
	{
		wxString text;
		text.Printf(wxT("Encoding %u:  facename:'%s')\n"),
			(unsigned int) ++m_n, facename.c_str());
		m_text += text;
		return true;
	}

private:
	size_t m_n;
	wxString m_text;
};

class CTestFontBitmapDlg: public CTestFontBitmapDlgBase
{
public:
	CTestFontBitmapDlg(wxWindow *parent):
	  CTestFontBitmapDlgBase(parent)
	  {
		  wxLogWindow *pLogWin = new wxLogWindow(this, "LOG");
		  wxLog::SetActiveTarget(pLogWin);
		  m_textCtrlString->SetLabel("LOVE 我爱你!");
	//	  m_textCtrlString->SetLabel("L");
		  g_font = *wxNORMAL_FONT;
		  g_font.SetPointSize(20);
		  wxFont font;
		  font.SetFaceName("Courier New");
		  font.SetPointSize(8);
		  m_textCtrlResult->SetFont(font);
		  Maximize();
	  }

	  virtual void OnBtnDraw( wxCommandEvent& event ) 
	  {
		  Draw();
	  }

	  void Draw()
	  {
		  FT_Library  library;
		  FT_Error error;
		  FT_Face     face;
		  FT_UInt glyph_index;
		  FT_UInt font_size = 32;
		  FT_ULong char_code = 0x6211;//"我";
		  wxString str = "我们";
		  char_code = str.GetChar(1);

		  error = FT_Init_FreeType( &library );
		  if (error)
		  {
			  wxLogDebug("error!!!\n");
			  return;
		  }

		  error = FT_New_Face( library,
			  "d:\\tmp\\font\\simkai.ttf",
			  0,
			  &face );
		  if ( error == FT_Err_Unknown_File_Format )
		  {
			  wxLogDebug("UnSupport font file");
			  return;
		  }
		  else if ( error )
		  {
			  wxLogDebug("Unknow errror");
			  return;
		  }

		  error = FT_Set_Pixel_Sizes(
			  face,   /* handle to face object */
			  0,      /* pixel_width           */
			  font_size );   /* pixel_height          */

		   error = FT_Load_Char( face, char_code, FT_LOAD_RENDER);

		   FT_GlyphSlot  slot = face->glyph;
		   FT_Bitmap *pBitmap = &slot->bitmap;

		   wxString strResult;
		   for (int i=0; i<pBitmap->rows; i++)
		   {
			   for (int j=0; j<pBitmap->width; j++)
			   {
				   if (pBitmap->buffer[i*pBitmap->pitch + j]==0)
					   strResult += " ";
				   else
					   strResult += "*";
			   }
			   strResult += "\n";
		   }

		   m_textCtrlResult->Clear();
		   m_textCtrlResult->AppendText(strResult);
	  }

	  void Draw1()
	  {
		  wxFont font = g_font;
		  int font_size = font.GetPointSize();
		  font_size = 16;
		  font.SetPointSize(font_size);


		  wxBitmap bmp(500, 500, 1);
		  wxMemoryDC dc(bmp);
		  dc.SetFont(font);
		  dc.SetBackground(*wxWHITE_BRUSH);
		  dc.Clear();
		  dc.SetBackgroundMode(wxSOLID);
		  dc.SetTextForeground(*wxWHITE);
		  dc.SetTextBackground(*wxBLACK);
		  dc.DrawText(m_textCtrlString->GetValue(), 0, 0);

		  wxFontMetrics metrics =  dc.GetFontMetrics();
		  wxLogDebug("height:%d ascent:%d descent:%d\n", metrics.height, metrics.ascent, metrics.descent);

		  wxString strResult;
		  wxColour color;

		  int font_width=0, font_height=0;
		  while(1) {
			  dc.GetPixel(++font_width, 0, &color);
			  if (color.GetRGB()!=wxBLACK->GetRGB())
				  break;
		  }

		  while(1) {
			  dc.GetPixel(0, ++font_height, &color);
			  if (color.GetRGB()!=wxBLACK->GetRGB())
				  break;
		  }
		  wxLogDebug("width:%d height:%d\n", font_width, font_height);

		  m_textCtrlResult->Clear();
		  for (int h=0; h<font_height; h++) {
			  for (int w=0; w<font_width; w++) {
				  wxUint32 rgb;
				  dc.GetPixel(w, h, &color);
				  rgb = color.GetRGB();

				  if ( rgb == wxBLACK->GetRGB())
					  strResult += " ";
				  else 
					  strResult += "*";
			  }
			  strResult += "\n";
		  }
		  m_textCtrlResult->Clear();
		  m_textCtrlResult->AppendText(strResult);
		  dc.SelectObject(wxNullBitmap);
		  bmp.SaveFile("d:\\bitmpmap.bmp",wxBITMAP_TYPE_BMP);
	  }

	  virtual void OnSelectFont( wxCommandEvent& event ) 
	  {
#if 0
		  wxFontDialog dlg;
		  dlg.Create(this);
		  if (dlg.ShowModal() == wxID_OK) {
			  g_font = dlg.GetFontData().GetChosenFont();
			  Draw();
		  }
#else
		  wxFileDialog dlg(this, _("Open Font file"), "", "", "True Type(*.ttf)|*.ttf;OTF(*.otf)", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
		  if (dlg.ShowModal() == wxID_OK) {
			  m_strFontPath = dlg.GetPath();
		  }
#endif
	  }


protected:
	wxString m_strFontPath;
};

class CMainFrame: public CMainFrameBase
{
public:
	CMainFrame( wxWindow* parent)
		:CMainFrameBase(parent)
	{
		m_paintPanel = new CPaintPanel(this);
		m_bSizer->Add( m_paintPanel, 1, wxALL|wxEXPAND, 5 );
		wxLogWindow *pLogWin = new wxLogWindow(this, "LOG");
		wxLog::SetActiveTarget(pLogWin);
		g_font = *wxNORMAL_FONT;
	}

	virtual void OnButtonReDrawClick( wxCommandEvent& event ) 
	{
		wxString str;
#if 0
		const size_t count = wxFontMapper::GetSupportedEncodingsCount();

		for ( size_t n = 0; n < count; n++ )
		{
			wxFontEncoding enc = wxFontMapper::GetEncoding(n);
			str = str + wxFontMapper::GetEncodingName(enc) + "\n";
		}
		wxLogDebug(str);

		return;
#endif
		

#if 0
		MyEncodingEnumerator fontEnumerator;
		wxArrayString arrayStrs = fontEnumerator.GetEncodings("WINDOWS-936");

		
		for (int i=0; i<arrayStrs.GetCount(); i++)
			str = str + arrayStrs[i] + "\n";
		wxLogDebug(str);
		return;
		fontEnumerator.EnumerateEncodings("GB2312");

		wxLogMessage(wxT("Enumerating all available encodings:\n%s"),
			fontEnumerator.GetText().c_str());
#endif

#if 0
		//列举出系统中 支持某种codepage的字体
		MyEncodingEnumerator fontEnumerator;
		fontEnumerator.EnumerateFacenames (wxFONTENCODING_CP936);
		wxArrayString arrayStrs = fontEnumerator.GetFacenames(wxFONTENCODING_CP936);
		for (int i=0; i<arrayStrs.GetCount(); i++)
			str = str + arrayStrs[i] + "\n";
		wxLogDebug(str);
		return;
#endif
		m_paintPanel->Refresh();
	}

	virtual void OnSelectFont( wxCommandEvent& event ) 
	{
		wxFontDialog dlg;
		dlg.Create(this);
		if (dlg.ShowModal() == wxID_OK) {
			g_font = dlg.GetFontData().GetChosenFont();
			m_paintPanel->Refresh();
		}
	}

public:
	CPaintPanel *m_paintPanel;
};





// MAIN APP
class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};
wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	CTestFontBitmapDlg *pdlg = new CTestFontBitmapDlg(NULL);
	pdlg->ShowModal();

	return true;
	CMainFrame *frame = new CMainFrame(NULL);
	frame->Show( true );
	return true;
}
