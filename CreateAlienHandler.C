AliAnalysisGrid* CreateAlienHandler(Bool_t isMC,Bool_t fAOD)
{
  //  char *data     = "LHC17f2b_fast";
  //  TString data     = "LHC17o";
  //  TString data     = "LHC16q";

  //  TString data     = "LHC15o_HIR";
  //    TString data     = "LHC15o_LIR";
  TString data     = "LHC17j";

  //TString data     = "LHC18f";
  
  TString datatype = "FAST"  ;//Fast,wSDD,woSDD
  Int_t method   =  1;
  // Check if user has a valid token, otherwise make one. This has limitations.
  // One can always follow the standard procedure of calling alien-token-init then
  // source /tmp/gclient_env_$UID in the current shell.
  
  // if (!AliAnalysisGrid::CreateToken()) return NULL;
  AliAnalysisAlien *plugin = new AliAnalysisAlien();
  plugin->SetOverwriteMode();
  plugin->SetMergeViaJDL(1);


  plugin->SetRunMode("full");
  //   plugin->SetRunMode("terminate");
  //plugin->SetRunMode("test");
  
  //Set versions of used packages
  plugin->SetAPIVersion("V1.1x");
  //  plugin->SetAliPhysicsVersion("vAN-20170628-1");
  //plugin->SetAliPhysicsVersion("vAN-20170722-1");//have issuse to deal with primary particle so it is removed
  //  plugin->SetAliPhysicsVersion("vAN-20180407-1");
  //  plugin->SetAliPhysicsVersion("vAN-20190709-1");
  //  plugin->SetRootVersion("v5-34-30");
  //  plugin->SetAliRootVersion("v5-09-49");
  //plugin->SetAliPhysicsVersion("vAN-20190731_ROOT6-1");
  //  plugin->SetAliPhysicsVersion("vAN-20190909_ROOT6-1");
  plugin->SetAliPhysicsVersion("vAN-20190919_ROOT6-1");
    
  // Declare input data to be processed.
  // Method 1: Create automatically XML collections using alien 'find' command.
  // Define production directory LFN
  
  if(!isMC){
    plugin->SetRunPrefix("000"); // IMPORTANT!
  }

  
  plugin->SetCheckCopy(kFALSE);
  if(!isMC){
    if(method==1){
      if(data=="LHC15o_HIR"){//PbPb run2
		plugin->SetGridDataDir("/alice/data/2015/LHC15o");
		plugin->SetDataPattern("*pass1/AOD194/*/AliAOD.root");
		//		plugin->SetDataPattern("*pass1/AOD194/*/AliAOD.root");
		//Good runs according to Freja's note
		plugin->AddRunNumber(246276);
		plugin->AddRunNumber(246275);
		plugin->AddRunNumber(246185);
		plugin->AddRunNumber(246153);
		plugin->AddRunNumber(246089);
		//		plugin->AddRunNumber(245963);
		plugin->AddRunNumber(245954);
		plugin->AddRunNumber(245833);
		plugin->AddRunNumber(245705);
		plugin->AddRunNumber(245683);

      }else if(data=="LHC15o_LIR"){//PbPb run2
		plugin->SetGridDataDir("/alice/data/2015/LHC15o");
		//		plugin->SetDataPattern("*pass5_lowIR/AOD194/*/AliAOD.root");
		plugin->SetDataPattern("*pass3_lowIR_pidfix/AOD194/*/AliAOD.root");
		//Good runs according to Freja's note
		//		plugin->AddRunNumber(244917);
		plugin->AddRunNumber(244918);
		plugin->AddRunNumber(244975);
		plugin->AddRunNumber(244980);
		plugin->AddRunNumber(244982);
		plugin->AddRunNumber(244983);
		plugin->AddRunNumber(245064);
		plugin->AddRunNumber(245066);
		plugin->AddRunNumber(245068);
		plugin->AddRunNumber(246390);
		plugin->AddRunNumber(246391);
		plugin->AddRunNumber(246392);
		
      }else if(data=="LHC16q"){
		plugin->SetGridDataDir("/alice/data/2016/LHC16q");
		if(datatype=="wSDD")plugin->SetDataPattern("*pass1_CENT_wSDD/AOD/*/AliAOD.root");
		else if(datatype=="woSDD")plugin->SetDataPattern("*pass1_CENT_woSDD/AOD190/*/AliAOD.root");
		else if(datatype=="FAST")plugin->SetDataPattern("*pass1_FAST/AOD190/*/AliAOD.root");
		//plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265305); // remove because no ZDC
		//		plugin->AddRunNumber(265308);  // remove because no ZDC

		//		part1
		
		plugin->AddRunNumber(265309);
		/*
		plugin->AddRunNumber(265332);
		plugin->AddRunNumber(265334);
		plugin->AddRunNumber(265335); // remove because of no TOF in data taking
		plugin->AddRunNumber(265336);
		*/

		/*
		//part2
		plugin->AddRunNumber(265338);
		plugin->AddRunNumber(265339);
		plugin->AddRunNumber(265342);
		plugin->AddRunNumber(265343);
		plugin->AddRunNumber(265344);
		plugin->AddRunNumber(265377);
		plugin->AddRunNumber(265378);
		plugin->AddRunNumber(265381);
		plugin->AddRunNumber(265383);
		plugin->AddRunNumber(265384);
		plugin->AddRunNumber(265385);
		*/
		/*
		//part3
		plugin->AddRunNumber(265387);
		plugin->AddRunNumber(265388);
		plugin->AddRunNumber(265419);
		plugin->AddRunNumber(265420);
		plugin->AddRunNumber(265421);
		plugin->AddRunNumber(265422);
		plugin->AddRunNumber(265424);
		plugin->AddRunNumber(265425);
		plugin->AddRunNumber(265426);
		plugin->AddRunNumber(265427);
		plugin->AddRunNumber(265435);
		plugin->AddRunNumber(265499);
		plugin->AddRunNumber(265500);
		plugin->AddRunNumber(265501);
		plugin->AddRunNumber(265521);
		plugin->AddRunNumber(265525);
		*/
	  }else if(data=="LHC15n"){
		plugin->SetGridDataDir("/alice/data/2015/LHC15n");
		plugin->SetDataPattern("*pass4/AOD/*/AliAOD.root");
		plugin->AddRunNumber(244340);
		plugin->AddRunNumber(244343);
		plugin->AddRunNumber(244351);
		plugin->AddRunNumber(244355);
		plugin->AddRunNumber(244359);
		plugin->AddRunNumber(244364);
		plugin->AddRunNumber(244377);
		plugin->AddRunNumber(244411);
		plugin->AddRunNumber(244416);
		plugin->AddRunNumber(244418);
		plugin->AddRunNumber(244421);
		plugin->AddRunNumber(244453);
		plugin->AddRunNumber(244456);
		plugin->AddRunNumber(244480);
		plugin->AddRunNumber(244481);
		plugin->AddRunNumber(244482);
		plugin->AddRunNumber(244483);
		plugin->AddRunNumber(244484);
		plugin->AddRunNumber(244531);
		plugin->AddRunNumber(244540);
		plugin->AddRunNumber(244542);
		plugin->AddRunNumber(244617);
		plugin->AddRunNumber(244618);
		plugin->AddRunNumber(244619);
		plugin->AddRunNumber(244626);
		plugin->AddRunNumber(244627);
		plugin->AddRunNumber(244628);
    }else if(data=="LHC13b2_p1"){
		plugin->SetGridDataDir("/alice/sim/2013/LHC13b2_efix_p1");
		plugin->SetDataPattern("*/AOD/AliAOD.root");
		plugin->AddRunNumber(195344);
		plugin->AddRunNumber(195346);
		plugin->AddRunNumber(195351);
		plugin->AddRunNumber(195389);
		plugin->AddRunNumber(195390);
		plugin->AddRunNumber(195391);
		plugin->AddRunNumber(195478);
		plugin->AddRunNumber(195479);
		plugin->AddRunNumber(195480);
		plugin->AddRunNumber(195481);
		plugin->AddRunNumber(195482);
		plugin->AddRunNumber(195483);
		plugin->AddRunNumber(195529);
		plugin->AddRunNumber(195531);
		plugin->AddRunNumber(195566);
		plugin->AddRunNumber(195567);
		plugin->AddRunNumber(195568);
		plugin->AddRunNumber(195592);
		plugin->AddRunNumber(195593);
		plugin->AddRunNumber(195596);
		plugin->AddRunNumber(195633);
		plugin->AddRunNumber(195635);
		plugin->AddRunNumber(195644);
		plugin->AddRunNumber(195673);
		plugin->AddRunNumber(195675);
		plugin->AddRunNumber(195677);
	  }else if(data=="LHC18f"){
		plugin->SetGridDataDir("/alice/data/2018/LHC18f");
		plugin->SetDataPattern("*pass1/AOD208/*/AliAOD.root");
		plugin->AddRunNumber(287000);
		plugin->AddRunNumber(287021);
		plugin->AddRunNumber(287063);
		plugin->AddRunNumber(287064);
		plugin->AddRunNumber(287072);
		plugin->AddRunNumber(287077);
		plugin->AddRunNumber(287137);
		plugin->AddRunNumber(287185);
      }else if(data=="LHC17j"){
	plugin->SetGridDataDir("/alice/data/2017/LHC17j");
	plugin->SetDataPattern("*pass1/AOD208/*/AliAOD.root");
	plugin->AddRunNumber(274667);
	plugin->AddRunNumber(274653);
	
	
	
      }else if(data=="LHC17o"){
	plugin->SetGridDataDir("/alice/data/2017/LHC17o");
	plugin->SetDataPattern("*pass1/AOD208/*/AliAOD.root");

		/*
		plugin->AddRunNumber(281961);
		plugin->AddRunNumber(281959);
		plugin->AddRunNumber(281953);
		plugin->AddRunNumber(281940);
		plugin->AddRunNumber(281939);
		plugin->AddRunNumber(281932);
		plugin->AddRunNumber(281931);
		plugin->AddRunNumber(281928);
		plugin->AddRunNumber(281920);
		plugin->AddRunNumber(281918);
		//	  plugin->AddRunNumber(281916);//SPD
		//	  plugin->AddRunNumber(281915);
		//	  plugin->AddRunNumber(281895);
		//	  plugin->AddRunNumber(281894);
		//	  plugin->AddRunNumber(281893);
		//	  plugin->AddRunNumber(281892);

		//		plugin->AddRunNumber(281756); //badTPCtrack
		//		plugin->AddRunNumber(281755); //badTPCtrack
		//		plugin->AddRunNumber(281754); //bad TPC
		//		plugin->AddRunNumber(281753); //bad tpc
		///		plugin->AddRunNumber(281751); //bad tpc
		//		plugin->AddRunNumber(281750); //bad tpc
		//		plugin->AddRunNumber(281741); //bad tpc
		//	  plugin->AddRunNumber(281713); //bad FMD
		//		plugin->AddRunNumber(281709);  //badtpc
		//	  plugin->AddRunNumber(281707); //bad FMD
		//	  plugin->AddRunNumber(281706); //bad FMD
		//	  plugin->AddRunNumber(281705); //bad FMD
		plugin->AddRunNumber(281633);
		//	  plugin->AddRunNumber(281592); // bad FMDa
		plugin->AddRunNumber(281583);
		plugin->AddRunNumber(281581);
		plugin->AddRunNumber(281580);

		plugin->AddRunNumber(281574);
		plugin->AddRunNumber(281569);
		plugin->AddRunNumber(281568);
		//		plugin->AddRunNumber(281563);  //but FMD
		plugin->AddRunNumber(281562);
		plugin->AddRunNumber(281557);
		plugin->AddRunNumber(281511);
		plugin->AddRunNumber(281509);
		plugin->AddRunNumber(281477);
		plugin->AddRunNumber(281475);
		plugin->AddRunNumber(281450);
		plugin->AddRunNumber(281449);
		//		plugin->AddRunNumber(281446); //but FMD
		plugin->AddRunNumber(281444);
		plugin->AddRunNumber(281443);
		plugin->AddRunNumber(281441);
		plugin->AddRunNumber(281415);
		plugin->AddRunNumber(281321);
		plugin->AddRunNumber(281301);
		plugin->AddRunNumber(281277);
		plugin->AddRunNumber(281275);
		plugin->AddRunNumber(281273);
		plugin->AddRunNumber(281271);
		//		plugin->AddRunNumber(281244); // but FMD
		plugin->AddRunNumber(281243);
		plugin->AddRunNumber(281242);
		plugin->AddRunNumber(281241);
		plugin->AddRunNumber(281240);
		plugin->AddRunNumber(281213);
		plugin->AddRunNumber(281212);
		plugin->AddRunNumber(281191);
		plugin->AddRunNumber(281190);
		plugin->AddRunNumber(281189);
		plugin->AddRunNumber(281181);
		plugin->AddRunNumber(281179);
		plugin->AddRunNumber(281081);
		plugin->AddRunNumber(281080);
		plugin->AddRunNumber(281062);
		plugin->AddRunNumber(281061);
		
		plugin->AddRunNumber(281060);
		
		//		plugin->AddRunNumber(281036); //but FMD
		//plugin->AddRunNumber(281035); //bad FMD
		//		plugin->AddRunNumber(281033); //bud FMD
		//		plugin->AddRunNumber(281032);// bad FMD
		plugin->AddRunNumber(280999);
		plugin->AddRunNumber(280998);
		plugin->AddRunNumber(280997);
		//		plugin->AddRunNumber(280996); //bad FMD
		plugin->AddRunNumber(280994);
		plugin->AddRunNumber(280990);
		plugin->AddRunNumber(280947);
		//		plugin->AddRunNumber(280943); //bad FMD
		plugin->AddRunNumber(280940);
		plugin->AddRunNumber(280936);
		plugin->AddRunNumber(280897);
		plugin->AddRunNumber(280880);
		plugin->AddRunNumber(280856);
		//		plugin->AddRunNumber(280854); //bad FMD
		plugin->AddRunNumber(280849);
		plugin->AddRunNumber(280848);
		plugin->AddRunNumber(280847);
		plugin->AddRunNumber(280844);
		plugin->AddRunNumber(280842);
		plugin->AddRunNumber(280793);
		plugin->AddRunNumber(280792);
		plugin->AddRunNumber(280787);
		plugin->AddRunNumber(280786);
		plugin->AddRunNumber(280768);
		plugin->AddRunNumber(280767);
		plugin->AddRunNumber(280766);
		plugin->AddRunNumber(280765);
		plugin->AddRunNumber(280764);
		plugin->AddRunNumber(280763);
		plugin->AddRunNumber(280762);
		plugin->AddRunNumber(280761);
		plugin->AddRunNumber(280757);
		plugin->AddRunNumber(280756);
		plugin->AddRunNumber(280755);
		plugin->AddRunNumber(280754);
		plugin->AddRunNumber(280753);
		
		
		plugin->AddRunNumber(280729);
		plugin->AddRunNumber(280706);
		plugin->AddRunNumber(280705);
		plugin->AddRunNumber(280681);

		//91below
		plugin->AddRunNumber(280679);
		plugin->AddRunNumber(280676);
		plugin->AddRunNumber(280673);
		plugin->AddRunNumber(280671);
		plugin->AddRunNumber(280650);
		plugin->AddRunNumber(280648);
		plugin->AddRunNumber(280647);
		plugin->AddRunNumber(280645);
		plugin->AddRunNumber(280639);
		plugin->AddRunNumber(280637);
		plugin->AddRunNumber(280636);
		plugin->AddRunNumber(280634);
		plugin->AddRunNumber(280613);
		plugin->AddRunNumber(280583);
		plugin->AddRunNumber(280581);
		plugin->AddRunNumber(280574);
		plugin->AddRunNumber(280551);
		plugin->AddRunNumber(280550);
		plugin->AddRunNumber(280547);
		plugin->AddRunNumber(280546);
		plugin->AddRunNumber(280519);
		plugin->AddRunNumber(280518);
		plugin->AddRunNumber(280499);
		//		plugin->AddRunNumber(280490); //bad FMD
		plugin->AddRunNumber(280448);
		plugin->AddRunNumber(280447);
		plugin->AddRunNumber(280446);
		plugin->AddRunNumber(280445);
		plugin->AddRunNumber(280443);		
		plugin->AddRunNumber(280419);
		plugin->AddRunNumber(280415);
		//		plugin->AddRunNumber(280412); // bad FMD
		plugin->AddRunNumber(280406);
		plugin->AddRunNumber(280405);
		plugin->AddRunNumber(280403);
		plugin->AddRunNumber(280375);
		plugin->AddRunNumber(280374);
		plugin->AddRunNumber(280352);
		plugin->AddRunNumber(280351);
		plugin->AddRunNumber(280350);
		plugin->AddRunNumber(280349);
		plugin->AddRunNumber(280348);
		plugin->AddRunNumber(280312);
		plugin->AddRunNumber(280310);
		plugin->AddRunNumber(280290);
		plugin->AddRunNumber(280286);
		plugin->AddRunNumber(280285);
		plugin->AddRunNumber(280284);
		plugin->AddRunNumber(280282);
		*/

	plugin->AddRunNumber(281961);
	//     plugin->AddRunNumber(281959 : return 1;
	plugin->AddRunNumber(281956);
	plugin->AddRunNumber(281953); //2;
     plugin->AddRunNumber(281940);// 3;
     plugin->AddRunNumber(281939);// 4;
     plugin->AddRunNumber(281932);// 5;
     plugin->AddRunNumber(281931);// 6;
     plugin->AddRunNumber(281928);// 7;
     plugin->AddRunNumber(281920);// 8;
     plugin->AddRunNumber(281918);// 9;
     plugin->AddRunNumber(281915);// 10;//
     plugin->AddRunNumber(281895);// 11;//
     plugin->AddRunNumber(281894);// 12;//
     plugin->AddRunNumber(281892);// 13;//
     plugin->AddRunNumber(281633);// 14;//
     plugin->AddRunNumber(281583);// 15;
       //     plugin->AddRunNumber(281581);// 12;
       //     plugin->AddRunNumber(281580);// 13;
     /*
     plugin->AddRunNumber(281574);// 16;
     plugin->AddRunNumber(281569);// 17;
     plugin->AddRunNumber(281568);// 18;
     plugin->AddRunNumber(281562);// 19;
     plugin->AddRunNumber(281557);// 20;
     plugin->AddRunNumber(281511);// 21;
     plugin->AddRunNumber(281509);// 22;
     plugin->AddRunNumber(281477);// 23;
     plugin->AddRunNumber(281475);// 24;
     plugin->AddRunNumber(281450);// 25;
     plugin->AddRunNumber(281449);// 26;
     plugin->AddRunNumber(281444);// 27;
     plugin->AddRunNumber(281443);// 28;
     plugin->AddRunNumber(281441);// 29;
     plugin->AddRunNumber(281415);// 30;
     plugin->AddRunNumber(281321);// 31;
     plugin->AddRunNumber(281301);// 32;
     plugin->AddRunNumber(281277);// 33;
     plugin->AddRunNumber(281275);// 34;
     plugin->AddRunNumber(281273);// 35;
     plugin->AddRunNumber(281271);// 36;
     plugin->AddRunNumber(281243);// 37;
     plugin->AddRunNumber(281242);// 38;
     plugin->AddRunNumber(281241);// 39;
     plugin->AddRunNumber(281240);// 40;
     plugin->AddRunNumber(281213);// 41;
     plugin->AddRunNumber(281212);// 42;
     plugin->AddRunNumber(281191);// 43;
     plugin->AddRunNumber(281190);// 44;
     plugin->AddRunNumber(281189);// 45;
     plugin->AddRunNumber(281181);// 46;
     plugin->AddRunNumber(281180);// 47;//
     plugin->AddRunNumber(281179);// 48;
     plugin->AddRunNumber(281081);// 49;
     plugin->AddRunNumber(281080);// 50;
     plugin->AddRunNumber(281062);// 51;
     plugin->AddRunNumber(281061);// 52;
     plugin->AddRunNumber(281060);// 53;
     plugin->AddRunNumber(280999);// 54;
     plugin->AddRunNumber(280998);// 55;
     plugin->AddRunNumber(280997);// 56;
     plugin->AddRunNumber(280994);// 57;
     plugin->AddRunNumber(280990);// 58;
     plugin->AddRunNumber(280947);// 59;
     plugin->AddRunNumber(280940);// 60;
     plugin->AddRunNumber(280936);// 61;
     plugin->AddRunNumber(280897);// 62;
     plugin->AddRunNumber(280890);// 63;//
     plugin->AddRunNumber(280881);// 64;//
     plugin->AddRunNumber(280880);// 65;
     plugin->AddRunNumber(280856);// 66;
     plugin->AddRunNumber(280849);// 67;
     plugin->AddRunNumber(280848);// 68;
     plugin->AddRunNumber(280847);// 69;
     plugin->AddRunNumber(280845);// 70;//
     plugin->AddRunNumber(280844);// 71;
     plugin->AddRunNumber(280842);// 72;
     plugin->AddRunNumber(280793);// 73;
     plugin->AddRunNumber(280792);// 74;
     plugin->AddRunNumber(280787);// 75;
     plugin->AddRunNumber(280786);// 76;
     plugin->AddRunNumber(280768);// 77;
     plugin->AddRunNumber(280767);// 78;
     plugin->AddRunNumber(280766);// 79;
     plugin->AddRunNumber(280765);// 80;
     plugin->AddRunNumber(280764);// 81;
     plugin->AddRunNumber(280763);// 82;
     plugin->AddRunNumber(280762);// 83;
     plugin->AddRunNumber(280761);// 84;
     plugin->AddRunNumber(280757);// 85;
     plugin->AddRunNumber(280756);// 86;
     plugin->AddRunNumber(280755);// 87;
     plugin->AddRunNumber(280754);// 88;
     plugin->AddRunNumber(280753);// 89;
     plugin->AddRunNumber(280729);// 90;
     plugin->AddRunNumber(280706);// 91;
     plugin->AddRunNumber(280705);// 92;
     plugin->AddRunNumber(280681);// 93;
     plugin->AddRunNumber(280679);// 94;
       //     plugin->AddRunNumber(280676);// 88;
       //     plugin->AddRunNumber(280673);// 89;
     plugin->AddRunNumber(280671);// 95;
       //     plugin->AddRunNumber(280650);// 91;
       //     plugin->AddRunNumber(280648);// 92;
     plugin->AddRunNumber(280647);// 96;
     plugin->AddRunNumber(280645);// 97;
     plugin->AddRunNumber(280639);// 98;
     plugin->AddRunNumber(280637);// 99;
     plugin->AddRunNumber(280636);// 100;
     plugin->AddRunNumber(280634);// 101;
     plugin->AddRunNumber(280613);// 102;
     plugin->AddRunNumber(280583);// 103;
     plugin->AddRunNumber(280581);// 104;
     plugin->AddRunNumber(280576);// 105;//
     plugin->AddRunNumber(280575);// 106;//
     plugin->AddRunNumber(280574);// 107;
     plugin->AddRunNumber(280551);// 108;
     plugin->AddRunNumber(280550);// 109;
     plugin->AddRunNumber(280547);// 110;
     plugin->AddRunNumber(280546);// 111;
     plugin->AddRunNumber(280519);// 112;
     plugin->AddRunNumber(280518);// 113;
     plugin->AddRunNumber(280499);// 114;
     plugin->AddRunNumber(280448);// 115;
     plugin->AddRunNumber(280447);// 116;
     plugin->AddRunNumber(280446);// 117;
     plugin->AddRunNumber(280445);// 118;
     plugin->AddRunNumber(280443);// 119;
     plugin->AddRunNumber(280419);// 120;
     plugin->AddRunNumber(280415);// 121;
     plugin->AddRunNumber(280413);// 122;//
     plugin->AddRunNumber(280406);// 123;
     plugin->AddRunNumber(280405);// 124;
     plugin->AddRunNumber(280403);// 125;
     plugin->AddRunNumber(280375);// 126;
     plugin->AddRunNumber(280374);// 127;
       //     plugin->AddRunNumber(280352);// 122;
     plugin->AddRunNumber(280351);// 128;
     plugin->AddRunNumber(280350);// 129;
     plugin->AddRunNumber(280349);// 130;
     plugin->AddRunNumber(280348);// 131;
     plugin->AddRunNumber(280312);// 132;
     plugin->AddRunNumber(280310);// 133;
     plugin->AddRunNumber(280290);// 134;
     plugin->AddRunNumber(280286);// 135;
     plugin->AddRunNumber(280285);// 136;
     plugin->AddRunNumber(280284);// 137;
     plugin->AddRunNumber(280283);// 138;
     plugin->AddRunNumber(280282);// 139;

     */
      }
      
      
      //else if(data=="LHC17j"){
      
      //	plugin->SetGridDataDir("/alice/data/2017/LHC17j");

      //	plugin->SetDataPattern("*pass1/AOD208/*/AliAOD.root");
      //	plugin->AddRunNumber(274671);
      //	plugin->AddRunNumber(274669);
      //	plugin->AddRunNumber(274667);

      //	plugin->AddRunNumber(274653);
      //	//plugin->AddRunNumber(274657);
      //      }


	}else{
	  //   plugin->SetOutputSingleFolder("output");
	  //   plugin->SetOutputToRunNo();
	  //   Method 2: Declare existing data files (raw collections, xml collections, root file)
	  //   If no path mentioned data is supposed to be in the work directory (see SetGridWorkingDir())
	  //   XML collections added via this method can be combined with the first method if
	  //   the content is compatible (using or not tags)
	  //    if(data=="LHC16q" && datatype=="wSDD") plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/xml/pass1_CENT_wSDD/000265305_000265525.xml");//old good run list
	  if(data=="LHC16q" && datatype=="wSDD") plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/xml/pass1_CENT_wSDD/000265309_000265525.xml");//32 runs
	  if(data=="LHC16q" && datatype=="woSDD") plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/xml/pass1_CENT_woSDD/000265309_000265525.xml");//32 runs
	  if(data=="LHC16q" && datatype=="FAST") plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/xml/pass1_FAST/000265309_000265525.xml");//32 runs
	  if(data=="LHC15n") plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/xml/LHC15n/pass4/000244340_000244628.xml");
	  //   plugin->AddDataFile("/alice/data/2008/LHC08c/000057657/raw/Run57657.Merged.RAW.tag.root");
	  //   Define alien work directory where all files will be copied. Relative to alien $HOME.
	}
  }else{
	  if(method==1){
		if(data=="LHC17f2b_fast"){
		  plugin->SetGridDataDir("/alice/sim/2017/LHC17f2b_fast");
		  plugin->SetDataPattern("AOD/*/AliAOD.root");
		  plugin->AddRunNumber(265309);
		  /*
			plugin->AddRunNumber(265332);
			plugin->AddRunNumber(265334);
			//      plugin->AddRunNumber(265335); // remove because of no TOF in data taking
			plugin->AddRunNumber(265336);
			plugin->AddRunNumber(265338);
			plugin->AddRunNumber(265339);
			plugin->AddRunNumber(265342);
			plugin->AddRunNumber(265343);
			plugin->AddRunNumber(265344);
			plugin->AddRunNumber(265377);
			plugin->AddRunNumber(265378);
			plugin->AddRunNumber(265381);
			plugin->AddRunNumber(265383);
			plugin->AddRunNumber(265384);
			plugin->AddRunNumber(265385);
			plugin->AddRunNumber(265387);
			plugin->AddRunNumber(265388);
			plugin->AddRunNumber(265419);
			plugin->AddRunNumber(265420);
			plugin->AddRunNumber(265421);
			plugin->AddRunNumber(265422);
			plugin->AddRunNumber(265424);
			plugin->AddRunNumber(265425);
			plugin->AddRunNumber(265426);
			plugin->AddRunNumber(265427);
			plugin->AddRunNumber(265435);
			plugin->AddRunNumber(265499);
			plugin->AddRunNumber(265500);
			plugin->AddRunNumber(265501);
			plugin->AddRunNumber(265521);
			plugin->AddRunNumber(265525);
		  */
		}
	  }else if(method==2){
		
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265309.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265332.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265334.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265336.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265338.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265339.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265342.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265343.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265344.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265377.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265378.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265381.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265383.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265384.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265385.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265387.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265388.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265419.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265420.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265421.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265422.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265424.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265425.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265426.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265427.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265435.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265499.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265500.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265501.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265521.xml");
		plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265525.xml");
	  }
	}

  //  plugin->SetGridWorkingDir("TPCFMD_LHC16qfast_part1_fmdcut5");
  //  plugin->SetGridWorkingDir("TPCFMD_LHC16qfast_part2_fmdcut5");
  //  plugin->SetGridWorkingDir("20112019_TPCTPC_LHC16qfast_part1");
  //    plugin->SetGridWorkingDir("20112019_TPCTPC_LHC16qfast_part1_tpctrackonly");
  //  plugin->SetGridWorkingDir("05122019_TPCTPC_LHC16qfast_part1_tpctrackonly");
  //  plugin->SetGridWorkingDir("HI_PBPB_20200127_TPCFMD_part1");
  //  plugin->SetGridWorkingDir("HI_PBPB_20200128_TPCFMD");
  //  plugin->SetGridWorkingDir("HI_PBPB_Goodruns_20200128_TPCFMD");

  //  plugin->SetGridWorkingDir("HIR_PBPB_Goodruns_20200226");
  //  plugin->SetGridWorkingDir("LIR_PBPB_Goodruns_20200226");
  //  plugin->SetGridWorkingDir("hogehoge_ppdata");
  plugin->SetGridWorkingDir("LHC17j_lowrateppdata");




  // Declare alien output directory. Relative to working directory.
  plugin->SetGridOutputDir("output"); // In this case will be $HOME/work/output
  plugin->SetUser("ysekiguc");
  // Declare the analysis source files names separated by blancs. To be compiled runtime
  // using ACLiC on the worker nodes.

  plugin->SetAnalysisSource("AliAnalysisTaskSEpPbCorrelationsForward.cxx");
  // Declare all libraries (other than the default ones for the framework. These will be
  // loaded by the generated analysis macro. Add all extra files (task .cxx/.h) here.

  plugin->AddIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include  -I$ALICE_ROOT/ITS -I$ALICE_ROOT/TPC -I$ALICE_ROOT/CONTAINERS -I$ALICE_ROOT/STEER/STEER -I$ALICE_ROOT/STEER/STEERBase -I$ALICE_ROOT/STEER/ESD -I$ALICE_ROOT/STEER/AOD -I$ALICE_ROOT/TRD -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS  -I$ALICE_ROOT/OADB -I/$ALICE_PHYSICS/OADB -I$ALICE_ROOT/PWGHF -I$ALICE_ROOT/PWGHF/base -I$ALICE_ROOT/PWGHF/vertexingHF -I$ALICE_ROOT/PWG/FLOW/Base -I$ALICE_ROOT/PWG/FLOW/Tasks -I$ALICE_ROOT/PWGDQ/dielectron -I$ALICE_ROOT/PWGCF/Correlations/macros/underlyingevent -I$ALICE_ROOT/VZERO -I$ALICE_ROOT/PWG/Tools -I$ALICE_ROOT/PWGCF/Correlations/Base -I$ALICE_ROOT/PWGCF/Correlations/DPhi -I$ALICE_ROOT/PWGLF/FORWARD/analysis2  -I$ALICE_ROOT/OADB/COMMON    -g");

   plugin->SetAdditionalLibs("libCore.so  libTree.so  libGeom.so  libVMC.so  libPhysics.so libSTEERBase.so libESD.so  libAOD.so  libANALYSIS.so  libANALYSISalice.so libCORRFW.so  libPWGTools.so  libPWGGlauber.so libPWGflowBase.so libPWGCFCorrelationsBase.so libPWGCFCorrelationsDPhi.so  libPWGCFCorrelationsJCORRAN.so libPWGLFforward2.so  libOADB.so  libADbase.so libADrec.so libADsim.so libVZERObase.so libVZEROrec.so  libVZEROsim.so AliAnalysisTaskSEpPbCorrelationsForward.h  AliAnalysisTaskSEpPbCorrelationsForward.cxx");
   
   // Declare the output file names separated by blancs.
   // (can be like: file.root or file.root@ALICE::Niham::File)

   plugin->SetDefaultOutputs("");

   // Optionally define the files to be archived.
   //   plugin->SetOutputArchive("log_archive.zip:stdout,stderr@ALICE::NIHAM::File root_archive.zip:*.root@ALICE::NIHAM::File");
   //   plugin->SetOutputArchive("log_archive.zip:stdout,stderr");

   // Optionally set a name for the generated analysis macro (default MyAnalysis.C)
   plugin->SetAnalysisMacro("TaskPt.C");

   // Optionally set maximum number of input files/subjob (default 100, put 0 to ignore)
   //   if(data=="LHC16q" )plugin->SetNrunsPerMaster(35);
   if(data=="LHC16q" )plugin->SetNrunsPerMaster(1);
   else if(data=="LHC15n")plugin->SetNrunsPerMaster(35);
   else if(  data=="LHC17f2b_fast")plugin->SetNrunsPerMaster(1);
   //   else if(data.Contains("LHC17o")plugin->SetNrunsPerMaster(160);
   else plugin->SetNrunsPerMaster(1);
   
   if(isMC){
     plugin->SetSplitMaxInputFileNumber(700);
   }else{
     if(fAOD){
       plugin->SetSplitMaxInputFileNumber(50);
       //       plugin->SetSplitMaxInputFileNumber(15);
	 }else{
       plugin->SetSplitMaxInputFileNumber(100);
     }
   }

   // Optionally modify the executable name (default analysis.sh)
   plugin->SetExecutable("TaskPt.sh");

   // Optionally set number of failed jobs that will trigger killing waiting sub-jobs.
   //   plugin->SetMaxInitFailed(5);

   // Optionally resubmit threshold.
   //   plugin->SetMasterResubmitThreshold(90);

   // Optionally set time to live (default 30000 sec)
   plugin->SetTTL(30000);

   // Optionally set input format (default xml-single)
   plugin->SetInputFormat("xml-single");

   // Optionally modify the name of the generated JDL (default analysis.jdl)
   plugin->SetJDLName("TaskPt.jdl");

   // Optionally modify job price (default 1)
   plugin->SetPrice(1);

   // Optionally modify split mode (default 'se')
   plugin->SetSplitMode("se");


   //   plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/correction.root");
   return plugin;
}
