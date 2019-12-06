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
    but5 = new wxButton(panel, wxID_ANY, "Option");

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

    wxStaticText *errText = new wxStaticText(panel, wxID_ANY, "Error:");
    errValText = new wxStaticText(panel, wxID_ANY, "0");

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
    maps.Add("dantzig42");
    maps.Add("brazil58");
    maps.Add("gr120");
    mChoice  = new wxChoice(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize,maps);

    wxArrayString tsp;
    tsp.Add("Brute force");
    tsp.Add("Branch and bound");
    tsp.Add("Dynamic programming");
    tsp.Add("Simulating annealing");
    tsp.Add("Tabu search");
    sChoice  = new wxChoice(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize,tsp);

    wxStaticLine *line1 = new wxStaticLine(panel, wxID_ANY);

    but1->Bind(wxEVT_BUTTON, &MyFrame::Load, this);
    mChoice->Bind(wxEVT_CHOICE, &MyFrame::Load, this);
    but2->Bind(wxEVT_BUTTON, &MyFrame::Solver, this);
    but3->Bind(wxEVT_BUTTON, &MyFrame::ShowGraph, this);
    but4->Bind(wxEVT_BUTTON, &MyFrame::RandomMap, this);
    sChoice->Bind(wxEVT_CHOICE, &MyFrame::ChangeSolver, this);
    but5->Bind(wxEVT_BUTTON, &MyFrame::Param, this);

    sizer1->Add(mText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(mChoice, wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but1, wxGBPosition(0,2), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but3, wxGBPosition(0,3), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but4, wxGBPosition(0,4), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer1->Add(sText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(sChoice, wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but2, wxGBPosition(1,2), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer1->Add(but5, wxGBPosition(1,3), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    
    sizer1->Add(line1, wxGBPosition(2,0), wxGBSpan(1,5), wxEXPAND | wxALL, 0);

    sizer2->Add(citiesText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(citiesValText , wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2->Add(odmText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(odmValText , wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2->Add(opmText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer2->Add(opmValText , wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(odsText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(odsValText , wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(errText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(errValText , wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(opsText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(opsValText , wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(timeText, wxGBPosition(3,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(timeValText , wxGBPosition(3,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer3->Add(itrText, wxGBPosition(4,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    sizer3->Add(itrValText , wxGBPosition(4,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    sizer2N->Add(sizer2, 0, wxALL, 10);
    sizer3N->Add(sizer3, 0, wxALL, 10);

    mainSizer->Add(sizer1, 0, wxALL, 10);
    mainSizer->Add(sizer2N, 0, wxALL, 10);
    mainSizer->Add(sizer3N, 0, wxALL, 10);

    but5->Disable();

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

void MyFrame::ChangeSolver(wxCommandEvent& event){

    if(sChoice->GetSelection() == 3 || sChoice->GetSelection() == 4)
        but5->Enable(true);
    else
        but5->Disable();
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
    else if(n==3){
        
        timeStart = std::chrono::high_resolution_clock::now();
        p1 = sa.solve(graph);
        timeStop = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);
        itrValText->SetLabel("N/A");
    }
    else if(n==4){
        timeStart = std::chrono::high_resolution_clock::now();
        p1 = ts.solve(graph);
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
    if(p1.size()<30)
	   opsValText->SetLabel(p1.to_string());
    else
        opsValText->SetLabel("Path too long");
    
	timeValText->SetLabel(std::to_string(time.count())+"s");

    float distance = p1.path_distance();
    float optimal_distance = (float)std::stoi(graph.get_best_dist());
    errValText->SetLabel(std::to_string( ((distance-optimal_distance)/optimal_distance)*100)+"%");

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

void MyFrame::Param(wxCommandEvent& event){

    but5->Disable();

    
    if(frame3!=nullptr){
        //frame3->Close(true);
        frame3=nullptr;
    }
    if(frame4!=nullptr){
        //frame4->Close(true);
        frame4=nullptr;
    }
    if(sChoice->GetSelection()==3 && (frame3==nullptr))
        SaParam();
    else if(sChoice->GetSelection()==4 && (frame4==nullptr))
        TsParam();

    return;
}

void MyFrame::SaParam(){

    frame3 = new wxFrame(this,  wxID_ANY, "Options", wxPoint(50, 50), wxSize(200, 200));
    wxPanel *panel3 = new wxPanel(frame3);

    wxBoxSizer *SaSizer = new wxBoxSizer(wxVERTICAL);
    wxGridBagSizer *SaSizer1 = new wxGridBagSizer(10,10);

    wxArrayString neib;
    neib.Add("Swap");
    neib.Add("Insert");
    neib.Add("Invert");

    

    wxStaticText *pChoiceText = new wxStaticText(panel3, wxID_ANY, "Neighborhood metode:");
    pChoice = new wxChoice(panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize,neib);
    
    wxStaticText *start_tText = new wxStaticText(panel3, wxID_ANY, "Initail temperature:");
    start_tInput = new wxTextCtrl(panel3, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *end_tText = new wxStaticText(panel3, wxID_ANY, "Ending temperature:");
    end_tInput = new wxTextCtrl(panel3, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *coolingText = new wxStaticText(panel3, wxID_ANY, "Cooling ratio:");
    coolingInput = new wxTextCtrl(panel3, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *run_timeText = new wxStaticText(panel3, wxID_ANY, "Maximal time:");
    run_timeInput = new wxTextCtrl(panel3, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxButton *buts1 = new wxButton(panel3, wxID_ANY, "Save and close");

    SaSizer1->Add(pChoiceText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    SaSizer1->Add(pChoice, wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    SaSizer1->Add(start_tText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    SaSizer1->Add(start_tInput, wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    SaSizer1->Add(end_tText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    SaSizer1->Add(end_tInput, wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    SaSizer1->Add(coolingText, wxGBPosition(3,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    SaSizer1->Add(coolingInput, wxGBPosition(3,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    SaSizer1->Add(run_timeText, wxGBPosition(4,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    SaSizer1->Add(run_timeInput, wxGBPosition(4,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    SaSizer1->Add(buts1, wxGBPosition(5,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    buts1->Bind(wxEVT_BUTTON, &MyFrame::SaParamHandler, this);
    //frame3->Bind(wxEVT_CLOSE_WINDOW, &MyFrame::SaParamHandler, wxID_EXIT);

    pChoice->SetSelection(sa.get_nei());

    (*start_tInput)<<std::to_string(sa.get_start_t());
    (*end_tInput)<<std::to_string(sa.get_end_t());
    (*coolingInput)<<std::to_string(sa.get_cooling());
    (*run_timeInput)<<std::to_string(sa.get_run_time());

    SaSizer->Add(SaSizer1, 0, wxALL, 10);
    panel3->SetSizer(SaSizer);

    SaSizer->Fit(frame3);
    frame3->Show(true);
}

void MyFrame::SaParamHandler(wxCommandEvent& event){

    try {
    sa.set_param(std::stoi(start_tInput->GetLineText(0).ToStdString()), 
                    std::stof(end_tInput->GetLineText(0).ToStdString()), 
                    std::stof(coolingInput->GetLineText(0).ToStdString()), 
                    std::stoi(run_timeInput->GetLineText(0).ToStdString()), 
                    pChoice->GetSelection());
    }
    catch (const std::invalid_argument& ia) {
        wxMessageBox( "Invalid argument", "Error", wxICON_ERROR );
        return;
    }

    frame3->Close(true);
    frame3=nullptr;
    but5->Enable(true);
}

void MyFrame::TsParam(){

    frame4 = new wxFrame(this,  wxID_ANY, "Options", wxPoint(50, 50), wxSize(200, 200));
    wxPanel *panel4 = new wxPanel(frame4);

    wxBoxSizer *TsSizer = new wxBoxSizer(wxVERTICAL);
    wxGridBagSizer *TsSizer1 = new wxGridBagSizer(10,10);

    wxArrayString neib;
    neib.Add("Swap");
    neib.Add("Insert");
    neib.Add("Invert");

    

    wxStaticText *tChoiceText = new wxStaticText(panel4, wxID_ANY, "Neighborhood metode:");
    tChoice = new wxChoice(panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize,neib);
    
    wxStaticText *iterationsText = new wxStaticText(panel4, wxID_ANY, "iterations:");
    iterationsInput = new wxTextCtrl(panel4, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *reset_thresholdText = new wxStaticText(panel4, wxID_ANY, "reset_threshold:");
    reset_thresholdInput = new wxTextCtrl(panel4, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *stop_thresholdText = new wxStaticText(panel4, wxID_ANY, "stop_threshold:");
    stop_thresholdInput = new wxTextCtrl(panel4, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxStaticText *Trun_timeText = new wxStaticText(panel4, wxID_ANY, "Maximal time:");
    Trun_timeInput = new wxTextCtrl(panel4, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

    wxButton *butt1 = new wxButton(panel4, wxID_ANY, "Save and close");

    TsSizer1->Add(tChoiceText, wxGBPosition(0,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    TsSizer1->Add(tChoice, wxGBPosition(0,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    TsSizer1->Add(iterationsText, wxGBPosition(1,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    TsSizer1->Add(iterationsInput, wxGBPosition(1,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    TsSizer1->Add(reset_thresholdText, wxGBPosition(2,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    TsSizer1->Add(reset_thresholdInput, wxGBPosition(2,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    TsSizer1->Add(stop_thresholdText, wxGBPosition(3,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    TsSizer1->Add(stop_thresholdInput, wxGBPosition(3,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    TsSizer1->Add(Trun_timeText, wxGBPosition(4,0), wxGBSpan(1,1), wxEXPAND | wxALL, 2);
    TsSizer1->Add(Trun_timeInput, wxGBPosition(4,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    TsSizer1->Add(butt1, wxGBPosition(5,1), wxGBSpan(1,1), wxEXPAND | wxALL, 2);

    butt1->Bind(wxEVT_BUTTON, &MyFrame::TsParamHandler, this);
    //frame4->Bind(wxEVT_CLOSE_WINDOW, &MyFrame::TsParamHandler, wxID_EXIT);

    tChoice->SetSelection(ts.get_nei());

    (*iterationsInput)<<std::to_string(ts.get_iterations());
    (*reset_thresholdInput)<<std::to_string(ts.get_reset_threshold());
    (*stop_thresholdInput)<<std::to_string(ts.get_stop_threshold());
    (*Trun_timeInput)<<std::to_string(ts.get_run_time());

    TsSizer->Add(TsSizer1, 0, wxALL, 10);
    panel4->SetSizer(TsSizer);

    TsSizer->Fit(frame4);
    frame4->Show(true);
}


void MyFrame::TsParamHandler(wxCommandEvent& event){

    try {
    ts.set_param(std::stoi(iterationsInput->GetLineText(0).ToStdString()), 
                 std::stoi(reset_thresholdInput->GetLineText(0).ToStdString()), 
                 std::stoi(stop_thresholdInput->GetLineText(0).ToStdString()), 
                 std::stoi(Trun_timeInput->GetLineText(0).ToStdString()), 
                 tChoice->GetSelection());
    }
    catch (const std::invalid_argument& ia) {
        wxMessageBox( "Invalid argument", "Error", wxICON_ERROR );
        return;
    }

    frame4->Close(true);
    frame4=nullptr;
    but5->Enable(true);
}

void MyFrame::TsParamColse(wxCloseEvent &event)
{
    frame4->Close(true);
    frame4=nullptr;
    but5->Enable(true);
}

void MyFrame::SaParamColse(wxCloseEvent &event)
{
    frame3->Close(true);
    frame3=nullptr;
    but5->Enable(true);
}

