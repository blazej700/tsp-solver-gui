#include <wx/wxprec.h>
#include <wx/gbsizer.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include "gui.hpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class TspSolver: public wxApp
{
public:
    virtual bool OnInit();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)

wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(TspSolver);


bool TspSolver::OnInit()
{
    MyFrame *frame = new MyFrame( "Tsp solver", wxPoint(50, 50), wxSize(300, 400));
    frame->Show( true );
    return true;
}