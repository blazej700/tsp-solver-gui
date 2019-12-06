#ifndef gui_hpp
#define gui_hpp
#include <wx/wxprec.h>
#include <wx/gbsizer.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/busyinfo.h>
#include <wx/richtext/richtextbuffer.h>
#include <wx/numdlg.h> 
#include <wx/event.h>
#include <iostream>
#include <chrono>

#include "graph.hpp"
#include "path.hpp"
#include "bf.hpp"
#include "bb.hpp"
#include "dp.hpp"
#include "sa.hpp"
#include "ts.hpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class MyFrame: public wxFrame
{

	Graph graph;
	SimAnnealing sa;
	TabuSearch ts;

	wxButton *but5;

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
	wxStaticText *errValText;

	wxChoice *mChoice;
    wxChoice *sChoice;

    wxFrame *frame3;
    wxChoice *pChoice;
    wxTextCtrl *start_tInput;
    wxTextCtrl *end_tInput;
    wxTextCtrl *coolingInput;
    wxTextCtrl *run_timeInput;

    wxFrame *frame4;
    wxChoice *tChoice;
    wxTextCtrl *iterationsInput;
    wxTextCtrl *reset_thresholdInput;
    wxTextCtrl *stop_thresholdInput;
    wxTextCtrl *Trun_timeInput;

	void OnExit(wxCommandEvent& event);
    void a1(wxCommandEvent& event);
    void Load(wxCommandEvent& event);
    void Solver(wxCommandEvent& event);
    void ShowGraph(wxCommandEvent& event);
    void RandomMap(wxCommandEvent& event);
    void ChangeSolver(wxCommandEvent& event);
    void Param(wxCommandEvent& event);
    void SaParam();
    void SaParamHandler(wxCommandEvent& event);
    void TsParam();
    void TsParamHandler(wxCommandEvent& event);
    void SaParamColse(wxCloseEvent &event);
    void TsParamColse(wxCloseEvent &event);

    wxDECLARE_EVENT_TABLE();



    std::string file_names[15] = {"tsp_6.txt", "tsp_10.txt", "tsp_12.txt", "tsp_13.txt", 
					"tsp_14.txt", "tsp_15.txt", "tsp_17.txt", "tsp_17_2.txt", "tsp_21.txt",
					 "tsp_24.txt", "tsp_26.txt", "tsp_29.txt", "tsp_42.txt", "tsp_58.txt",
					 "tsp_120.txt"};

public:
	
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};



#endif //gui_hpp