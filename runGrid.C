{
  TString gridMode="full";
  Bool_t iAODAnalysis =kTRUE;
  Bool_t useMC =kFALSE;
  Bool_t frun2=kTRUE;
  Bool_t root6=kTRUE;
  //Load common libraries
  gSystem->Load("libCore.so");
  gSystem->Load("libTree.so");
  gSystem->Load("libGeom.so");
  gSystem->Load("libVMC.so");
  gSystem->Load("libPhysics");
  gSystem->Load("libSTEERBase");
  gSystem->Load("libSTEER");
  gSystem->Load("libRAWDatabase");
  gSystem->Load("libRAWDatarec");
  gSystem->Load("libHist");
  gSystem->Load("libRIO");
  //gSystem->Load("libEveDet");
  //gSystem->Load("libCDB");
  //gSystem->Load("libESDfilter");
  gSystem->Load("libAOD");
  gSystem->Load("libESD");
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice");
  gSystem->Load("libCORRFW");
  gSystem->Load("libADbase");
  gSystem->Load("libADrec");
  gSystem->Load("libADsim");
  gSystem->Load("libOADB");

  //ANALYSIS
  gSystem->Load("libVZERObase.so");
  gSystem->Load("libVZEROrec.so");
  gSystem->Load("libVZEROsim.so");
  gSystem->Load("libANALYSIScalib.so");
  gSystem->Load("libEventMixing.so");
  gSystem->Load("libTender.so");
  gSystem->Load("libTenderSupplies.so");

  // PWG
  gSystem->Load("libPWGTools.so");
  gSystem->Load("libPWGGlauber.so");
  gSystem->Load("libPWGflowBase.so");
  gSystem->Load("libPWGflowTasks.so");
  gSystem->Load("libPWGmuon.so");
  gSystem->Load("libPWGmuondep.so");
  gSystem->Load("libPWGCaloTrackCorrBase.so");
  //PWGCF
  gSystem->Load("libPWGCFCorrelationsBase.so");
  gSystem->Load("libPWGCFCorrelationsDPhi.so");
  //gSystem->Load("libPWGCFCorrelationsJCORRAN.so");
  gSystem->Load("libPWGCFChaoticity.so");
  //  gSystem->Load("libPWGCFFEMTOSCOPYAOD.so");
  // gSystem->Load("libPWGCFfemtoscopy.so");

  gSystem->Load("libPWGCFfemtoscopyUser.so");

  gSystem->Load("libPWGCFunicor.so");
  gSystem->Load("libPWGCFebye.so");
  gSystem->Load("libPWGCFflowCME.so");
  gSystem->Load("libPWGCFK0Analysis.so");
  gSystem->Load("libPWGCFflowBW.so");

  gSystem->Load("libPWGflowBase");
  gSystem->Load("libPWGflowTasks");

  gSystem->Load("libTPCbase.so");
  gSystem->Load("libTPCrec.so");
  gSystem->Load("libTPCsim.so");
  gSystem->Load("libTPCupgrade.so");
  gSystem->Load("libTPCutil.so");

  gSystem->Load("libACORDEbase.so");

  gSystem->Load("libPWGCFFlowForward.so");
  
  //gSystem->Load("libESD.so");
  //gSystem->Load("libMinuit");
  
  // Use AliRoot includes to compile our task
  gROOT->ProcessLine(".include $ROOTSYS/include");
  gROOT->ProcessLine(".include $ALICE_ROOT/include");
  gROOT->ProcessLine(".include $ALICE_PHYSICS");
  gROOT->ProcessLine(".include $ALICE_PHYSICS/lib");
  gROOT->ProcessLine(".include $ALICE_ROOT/lib");

  //gSystem->SetIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include  -I$ALICE_ROOT/ITS -I$ALICE_ROOT/TPC -I$ALICE_ROOT/CONTAINERS -I$ALICE_ROOT/STEER/STEER -I$ALICE_ROOT/STEER/STEERBase -I$ALICE_ROOT/STEER/ESD -I$ALICE_ROOT/STEER/AOD -I$ALICE_ROOT/TRD -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS  -I$ALICE_ROOT/OADB -I$ALICE_PHYSICS/OADB -I$ALICE_PHYSICS/PWG -I$ALICE_PHYSICS/PWGCF -I$ALICE_ROOT/PWGHF -I$ALICE_ROOT/PWGHF/base -I$ALICE_ROOT/PWGHF/vertexingHF -I$ALICE_ROOT/PWG/FLOW/Base -I$ALICE_ROOT/PWG/FLOW/Tasks -I$ALICE_ROOT/PWGDQ/dielectron -I$ALICE_ROOT/AD/macros -I/$ALICE_ROOT/STAT/Macros -I$ALICE_ROOT/VZERO -I$ALICE_PHYSICS/OADB -g");
  gSystem->SetIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include  -I$ALICE_ROOT/ITS -I$ALICE_ROOT/TPC -I$ALICE_ROOT/CONTAINERS -I$ALICE_ROOT/STEER/STEER -I$ALICE_ROOT/STEER/STEERBase -I$ALICE_ROOT/STEER/ESD -I$ALICE_ROOT/STEER/AOD -I$ALICE_ROOT/TRD -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS  -I$ALICE_ROOT/OADB -I$ALICE_PHYSICS/OADB -I$ALICE_PHYSICS/PWG -I$ALICE_PHYSICS/PWGCF -I$ALICE_ROOT/PWGHF -I$ALICE_ROOT/PWGHF/base -I$ALICE_ROOT/PWGHF/vertexingHF -I$ALICE_ROOT/PWG/FLOW/Base -I$ALICE_ROOT/PWG/FLOW/Tasks -I$ALICE_ROOT/PWGDQ/dielectron -I$ALICE_ROOT/AD/macros -I/$ALICE_ROOT/STAT/Macros -I$ALICE_ROOT/VZERO -I$ALICE_PHYSICS/OADB -g");

  
  
  AliAnalysisManager *mgr = new AliAnalysisManager("testAnalysis");
  TChain*chain;
  // Create and configure the alien handler plugin
  if(gridMode!=""){
    if(root6) gROOT->ProcessLine(".L CreateAlienHandler.C");
    else gROOT->LoadMacro("CreateAlienHandler.C");
    AliAnalysisGrid *alienHandler = CreateAlienHandler(useMC,iAODAnalysis);
    mgr->SetGridHandler(alienHandler);
    //  if (!alienHandler) return;
  }else{
    if(useMC){
      if(iAODAnalysis){
	chain=new TChain("aodTree");
        chain->Add("/Users/yuko/alicework/alice_data/2017/LHC17f2b_fast/265309/001/AliAOD.root");//DPMJET
        chain1 = new TChain("TE");
        chain1->Add("/Users/yuko/alicework/alice_data/2017/LHC17f2b_fast/265309/001/files/galice.root");//DPMJET
      }else{
        TChain* chain=new TChain("esdTree");
        chain->Add("/Users/yuko/alicework/alice_data/2017/LHC17f2b_fast/265309/001/AliESDs.root");//DPMJET
      }

    }else{
      if(!iAODAnalysis){
        chain =new TChain("esdTree");
        //	chain->Add("../testdata/AliESDs_12g_pass2_188359.root");
	//    chain->Add("input/2012/LHC12g/000188359/ESDs/pass2/12000188359001.10/AliESDs.root");
	//	chain->Add("../../tmp/AliESDs.root");
	//chain->Add("$HOME/alicework/alice_data/2013/LHC13c/000195529/ESDs/pass2/13000195529000.10/AliESDs.root");
        chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_CENT_wSDD/16000265309019.100/AliESDs.root");
      }
      else{
	chain =new TChain("aodTree");
	//chain->Add("../../alice_data/2013/LHC13c/000195529/ESDs/pass2/AOD/001/AliAOD.root");/Users/yuko/alicework/alice_data/2017/LHC17f2b_fast/265309/001/AliAOD.root does
	//chain->Add("../../alice_data/2013/LHC13b/000195344/ESDs/pass3/AOD/001/AliAOD.root");
	//		chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_CENT_wSDD/AOD/001/AliAOD.root");
	//	chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_CENT_wSDD/16000265309019.100/AliAOD.root");
	//
	//	///chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_FAST/001/AliAOD.root");
	
	//chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_FAST/001/AliAOD.root");
       	chain->Add("~/workalice/alice_data/2016/LHC16q/000265309/pass1_FAST/002/AliAOD.root");

	//chain->Add("~/workalice/alice_data/2016/LHC16q/000265309/pass1_FAST/001/AliAOD.root");
	//			chain->Add("~/workalice/alice_data/2017/LHC17o/000281961/pass1/AOD208/0001/AliAOD.root");
	
	/*
	chain->Add("~/workalice/alice_data/2018/LHC18f/AliAOD_1.root");
	
	chain->Add("~/workalice/alice_data/2018/LHC18f/AliAOD_2.root");
	chain->Add("~/workalice/alice_data/2018/LHC18f/AliAOD_3.root");
	chain->Add("~/workalice/alice_data/2018/LHC18f/AliAOD_4.root");
	*/
	//chain->Add("~/workalice/alice_data/2015/LHC15o/246276/AOD194/0001/AliAOD.root");// LHC15o
	//	chain->Add("~/workalice/alice_data/2015/LHC15o/245683/pass1/AOD194/0001/AliAOD.root");// LHC15o
	
	//	chain->Add("$HOME/alicework/alice_data/2015/LHC15n/000244340/pass4/AOD/001/AliAOD.root");
   //	chain->Add("~/Downloads/AliAOD.root");
      }
    }

  }

  //  gSystem->Exec("alien_cp alien:///alice/cern.ch/user/y/ysekiguc/correction.root .");



//  Create the analysis manager
  // if AOD , AliMCEventHander is not necessary
    // if (useMC && !iAODAnalysis) {
  if(useMC){
    AliMCEventHandler* mcHandler = new AliMCEventHandler();
     mgr->SetMCtruthEventHandler(mcHandler);
     mcHandler->SetReadTR(useMC);
    }

   if(!iAODAnalysis){
     AliESDInputHandler* esdH = new AliESDInputHandler();
     mgr->SetInputEventHandler(esdH);
   }else{
     AliAODInputHandler *aodHandler = new AliAODInputHandler();
     mgr->SetInputEventHandler(aodHandler);
   }
   
//   if(!TGrid
   //::Connect("alien://","ysekiguc","","-domain=cern.ch")){cout<<"TGrid connection failed"<<endl;return ;}
   if(frun2){
     if(root6) gROOT->ProcessLine(".L $ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
     else gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
     AddTaskPhysicsSelection(useMC,true);
     

     if(root6) gROOT->ProcessLine(".L $ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
     else gROOT->LoadMacro("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
	 AddTaskMultSelection();
	 //AliMultSelectionTask *multSelTask=AddTaskMultSelection();
	 //	 multSelTask->SetAlternateOADBFullManualBypassMC("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/data/OADB-LHC16q.root");
   }
   if(root6) gROOT->ProcessLine(".L $ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C");
   else gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C");
   //   AliAnalysisTaskPIDResponse *taskPID=AddTaskPIDResponse(kFALSE,kFALSE,kTRUE,1);
   AddTaskPIDResponse(useMC);
   //
   //   gROOT->ProcessLine(".x AliForwardTaskValidationYS.cxx++g");
   //   gROOT->ProcessLine(".x AliForwardTaskValidationYS.h");
   gROOT->ProcessLine(".L $ALICE_PHYSICS/PWGCF/FLOW/macros/AddTaskForwardValidation.C");
   AddTaskForwardValidation(false,false,false,"PbPb");
   //gROOT->ProcessLine(".L AddTaskForwardValidationYS.C");
   //AddTaskForwardValidationYS(false,false,false,"PbPb");
   //   AddTaskForwardValidation();
   
   
   gROOT->ProcessLine(".x AliAnalysisTaskSEpPbCorrelationsForward.cxx++g");
   gROOT->ProcessLine(".x AddTaskpPbCorrelationsForward.C");
   //   gROOT->ProcessLine(".x AddTaskFlowValidation.C");
   
   //   AliAnalysisTaskSEpPbCorrelationsForward* ana =AddTaskpPbCorrelationsForward();
   
   // Enable debug printouts
   
   mgr->SetDebugLevel(0);

   if (!mgr->InitAnalysis()) return;

   mgr->PrintStatus();
   // Start analysis in grid.
   if(gridMode!=""){
     mgr->StartAnalysis("grid");
   }
   else{
     mgr->StartAnalysis("local",chain);
   }
};
