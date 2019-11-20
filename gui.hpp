#ifndef gui_hpp
#define gui_hpp
#include <wx/wxprec.h>
#include <wx/gbsizer.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/busyinfo.h>
#include <wx/richtext/richtextbuffer.h>
#include <wx/numdlg.h> 
#include <iostream>
#include <chrono>

#include "graph.hpp"
#include "path.hpp"
#include "bf.hpp"
#include "bb.hpp"
#include "dp.hpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class MyFrame: public wxFrame
{

	Graph graph;

	wxBoxSizer *mainSizer;
	wxStaticBoxSizer *sizer2N;
	wxStaticBoxSizer *sizer3N;

	wxStaticText *citiesValText;
	wxStaticText *opmValText;
	wxStaticText *odmValText;
	wxStaticText *odsValText;
	wxStaticText *opsValText;
	wxStaticText *timeValText;
	wxStaticText *itrValText;

	wxChoice *mChoice;
    wxChoice *sChoice;

	void OnExit(wxCommandEvent& event);
    void a1(wxCommandEvent& event);
    void Load(wxCommandEvent& event);
    void Solver(wxCommandEvent& event);
    void ShowGraph(wxCommandEvent& event);
    void RandomMap(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();

    std::string file_names[12] = {"tsp_6.txt", "tsp_10.txt", "tsp_12.txt", "tsp_13.txt", 
					"tsp_14.txt", "tsp_15.txt", "tsp_17.txt", "tsp_17_2.txt", "tsp_21.txt",
					 "tsp_24.txt", "tsp_26.txt", "tsp_29.txt"};

public:
	
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};



#endif //gui_hpp