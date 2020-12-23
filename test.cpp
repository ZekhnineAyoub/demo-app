// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
//
//
#include <wx/button.h>
// create application 
class Myapp : public wxApp
{

public:
   
    virtual bool  OnInit();

};


class MyFrame : public wxFrame
{

public: 
//
     MyFrame(const wxString& title , const wxPoint& pos , const wxSize & size);

private:

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1(wxCommandEvent& event);
    void OnButton2(wxCommandEvent& event);
    

    wxDECLARE_EVENT_TABLE();

};

enum 
{
  ID_Hello=1,
  wxID_BUTTON1=2,
  wxID_BUTTON2=3

};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(wxID_BUTTON1, MyFrame::OnButton1)
    EVT_BUTTON(wxID_BUTTON2, MyFrame::OnButton2)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(Myapp);

bool Myapp :: OnInit()
{
    
    MyFrame *frame = new MyFrame("EFS Application",wxPoint(100,100), wxSize(500,500) );
    frame->Show( true );
    return true;
    
}



MyFrame :: MyFrame(const wxString& title, const wxPoint& pos , const wxSize& size)
         : wxFrame(NULL, wxID_ANY , title , pos , size)

{

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "Bonjour","c'est une nouvelle fenetre ");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&Fichier" );
    menuBar->Append( menuHelp, "&Aide" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    wxButton * button = new wxButton(this, wxID_BUTTON1,"Mon button",wxPoint(0,0),wxDefaultSize,0, wxDefaultValidator,wxButtonNameStr);
    wxButton * button2 = new wxButton(this, wxID_BUTTON2,"Mon button",wxPoint(100,100),wxDefaultSize,0, wxDefaultValidator,wxButtonNameStr);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "c'est nune fenetre","Application help", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Bienvenue !");
}
void MyFrame::OnButton1(wxCommandEvent& event)
{
    wxLogMessage("Bienvenue !");
}
void MyFrame::OnButton2(wxCommandEvent& event)
{
    wxLogMessage("Bienvenue !");
}


