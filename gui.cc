#include "gui.hpp"


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){

    wxPanel *panel = new wxPanel(this);

    mainSizer = new wxBoxSizer(wxVERTICAL);

    sizer2N  = new wxStaticBoxSizer(wxVERTICAL, panel, "-");
    sizer3N  = new wxStaticBoxSizer(wxVERTICAL, panel, "Result");
    wxGridBagSizer *sizer1 = new wxGridBagSizer(10,10);
    wxGridBagSizer *sizer2 = new wxGridBagSizer(10,10);
    wxGridBagSizer *sizer3 = new wxGridBagSizer(10,10);

    wxButton *but1 = new wxButton(panel, wxID_ANY, "Load");
    wxButton *but2 = new wxButton(panel, wxID_ANY, "Solve");
    wxButton *but3 = new wxButton(panel, wxID_ANY, "Show");
    wxButton *but4 = new wxButton(panel, wxID_ANY, "Random");

    wxStaticText *mText = new wxStaticText(panel, wxID_ANY, "Map");
    wxStaticText *sText = new wxStaticText(panel, wxID_ANY, "Solver");

    wxStaticText *citiesText = new wxStaticText(panel, wxID_ANY, "Cities:");
    citiesValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *odmText = new wxStaticText(panel, wxID_ANY, "Optimal distance:");
    odmValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *opmText = new wxStaticText(panel, wxID_ANY, "Optimal path:");
    opmValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *odsText = new wxStaticText(panel, wxID_ANY, "Optimal distance:");
    odsValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *opsText = new wxStaticText(panel, wxID_ANY, "Optimal path:");
    opsValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *timeText = new wxStaticText(panel, wxID_ANY, "Time:");
    timeValText = new wxStaticText(panel, wxID_ANY, "0");

    wxStaticText *itrText = new wxStaticText(panel, wxID_ANY, "Iterations:");
    itrValText = new wxStaticText(panel, wxID_ANY, "0");

    wxArrayString maps;
    maps.Add("6 cities");
    maps.Add("10 cities");
    maps.Add("12 cities");
    maps.Add("13 cities");
    maps.Add("14 cities");
    maps.Add("15 cities");
    maps.Add("17 cities");
    maps.Add("gr17");
    maps.Add("gr21");
    maps.Add("gr24");
    maps.Add("fri26");
    maps.Add("bayg29");
    mChoice  = new wxChoice(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize,maps);

    wxArrayString tsp;
    tsp.Add("Brute force");
    tsp.Add("Branch and bound");
    tsp.Add("Dynamic programming");
    sChoice  = new wxChoice(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize,tsp);

    wxStaticLine *line1 = new wxStaticLine(panel, wxID_ANY);

    but1->Bind(wxEVT_BUTTON, &MyFrame::Load, this);
    mChoice->Bind(wxEVT_CHOICE, &MyFrame::Load, this);
    but2->Bind(wxEVT_BUTTON, &MyFrame::Solver, this);
    but3->Bind(wxEVT_BUTTON, &MyFrame::ShowGraph, this);
    but4->Bind(wxEVT_BUTTON, &MyFrame::RandomMap, this);

    sizer1->Add(mText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(mChoice, wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but1, wxGBPosition(0,2), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but3, wxGBPosition(0,3), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but4, wxGBPosition(0,4), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer1->Add(sText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(sChoice, wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but2, wxGBPosition(1,2), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    
    sizer1->Add(line1, wxGBPosition(2,0), wxGBSpan(1,5), wxEXPAND | wxALL, 0);

    sizer2->Add(citiesText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(citiesValText , wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2->Add(odmText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(odmValText , wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2->Add(opmText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(opmValText , wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(odsText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(odsValText , wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(opsText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(opsValText , wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(timeText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(timeValText , wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(itrText, wxGBPosition(3,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(itrValText , wxGBPosition(3,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2N->Add(sizer2, 0, wxALL, 10);
    sizer3N->Add(sizer3, 0, wxALL, 10);

    mainSizer->Add(sizer1, 0, wxALL, 10);
    mainSizer->Add(sizer2N, 0, wxALL, 10);
    mainSizer->Add(sizer3N, 0, wxALL, 10);

    panel->SetSizer(mainSizer);

    mainSizer->Fit(this);

    this->Show(true);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::Load(wxCommandEvent& event){

	if(mChoice->GetSelection()==wxNOT_FOUND){
		wxMessageBox( "Please choose a map", "Error", wxICON_HAND );
		return;
	}

	try{
		graph.read(file_names[mChoice->GetSelection()]);
	}
	catch(std::string ex){
		wxMessageBox( ex, "Error", wxICON_ERROR );
		return;
	}

    graph.read(file_names[mChoice->GetSelection()]);
    citiesValText->SetLabel(std::to_string(graph.get_cities()));
    opmValText->SetLabel(graph.get_best_path());
	odmValText->SetLabel(graph.get_best_dist());

	sizer2N->Fit(this);
	sizer3N->Fit(this);
	mainSizer->Fit(this);

	sizer2N->GetStaticBox()->SetLabel(mChoice->GetString(mChoice->GetSelection()));
}

void MyFrame::RandomMap(wxCommandEvent& event){
	int i = wxGetNumberFromUser("", "Numer of cities:","Random map", 2, 2, 300);
	if(i>1){
		graph.random(i);
		citiesValText->SetLabel(std::to_string(graph.get_cities()));
	    opmValText->SetLabel(graph.get_best_path());
		odmValText->SetLabel(graph.get_best_dist());


		sizer2N->GetStaticBox()->SetLabel(wxT("Random " + std::to_string(graph.get_cities()) + " cities"));
		sizer2N->Fit(this);
		sizer3N->Fit(this);
		mainSizer->Fit(this);
		return;
	}
	else{
		wxMessageBox("Numer of cities must be greater than 1", "Error", wxICON_ERROR );
		return;
	}
}

void MyFrame::Solver(wxCommandEvent& event){


	int n = sChoice->GetSelection();
	Path p1(graph);

	if(graph.get_cities()==0){
		wxMessageBox( "Please load a map", "Error", wxICON_ERROR );
		return;
	}

	std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

	wxBeginBusyCursor();
	if(n==0){
		BruteForce bf;
		timeStart = std::chrono::high_resolution_clock::now();
		p1 = bf.solve(graph);
		timeStop = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);
		itrValText->SetLabel(std::to_string(p1.get_ad_info()));
	}
	else if(n==1){
		BranchnBound bb;
		timeStart = std::chrono::high_resolution_clock::now();
		p1 = bb.solve(graph);
		timeStop = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);
		itrValText->SetLabel(std::to_string(p1.get_ad_info()));
	}
	else if(n==2){
		DynamicProgramming dp;
		timeStart = std::chrono::high_resolution_clock::now();
		p1 = dp.solve(graph);
		timeStop = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);
		itrValText->SetLabel("N/A");
	}
	else{
		wxEndBusyCursor();
		wxMessageBox( "Please choose a solver", "Error", wxICON_ERROR );
		return;

	}
	wxEndBusyCursor();

	odsValText->SetLabel(std::to_string(p1.path_distance()));
	opsValText->SetLabel(p1.to_string());
	timeValText->SetLabel(std::to_string(time.count())+"s");

	sizer2N->Fit(this);
	sizer3N->Fit(this);
	mainSizer->Fit(this);

}


void MyFrame::ShowGraph(wxCommandEvent& event){

	wxFrame *frame2 = new wxFrame(this,  wxID_ANY, "Graph", wxPoint(50, 50), wxSize(400, 400));
	wxPanel *panel2 = new wxPanel(frame2);

	wxBoxSizer *ShowSizer = new wxBoxSizer(wxVERTICAL);

	wxTextCtrl *rTable = new wxTextCtrl(panel2, wxID_ANY,"",wxDefaultPosition, wxDefaultSize, wxEXPAND | wxTE_MULTILINE | wxTE_READONLY);

	(*rTable)<<graph.to_string();

	ShowSizer->Add(rTable, 1, wxEXPAND, 5 );
	panel2->SetSizer(ShowSizer);


    frame2->Show(true);

}