#include "nfbm.h"
#include "SPI_MasterSlave.h"

#include "UART_MasterSlave.h"
#include "mlib_definitions.h"
#include "plib_handles.h"
#include "protection_functions.h"
#include "boardIO.h"
#include "externalData.h"
#include "pDataConfigs.h"
#include "powerSysData.h"
#include "bit_expansion.h"

#include "test_commParams.h"

//****test Parameters For Register Read****//

enum commTestDW testParamDW=DW_0;
enum commTestF testParamF=F_0;


uint32_t testDW[READ_TOTAL_REGISTER_SIZE + 1]={0};
uint32_t testEntryDW=0;

uint32_t testF[READ_TOTAL_REGISTER_SIZE + 1]={0};
uint32_t testEntryF=0;

//****test Parameters For Register Read****//




void pushDataToMaster(void){
	
	
	
	#if  COMM_testEnable 
	
	int i;
	
	/*testDW[testParamDW]=testEntryDW;
	comParams.pushDataBufferDW[testParamDW]=testDW[testParamDW];
	
	testF[testParamF]=testEntryF;
	comParams.pushDataBufferDW[testParamF]=testDW[testParamF];*/
	
	for(i=0;i<80;i++){
	comParams.pushDataBufferF[i+166]=comParams_uart.recDataBufferF[i];
	}
	
	#else
	
	
	//MEM AREA-1
	
	
	//Integer Parameters
	
	/*2*/comParams.pushDataBufferDW[0]=pick_words.w_arr[0];
	/*4*/comParams.pushDataBufferDW[1]=pick_words.w_arr[1];
	/*6*/comParams.pushDataBufferDW[2]=pick_words.w_arr[2];
	
	/*8*/ comParams.pushDataBufferDW[3]=trip_words.w_arr[0];
	/*10*/comParams.pushDataBufferDW[4]=trip_words.w_arr[1];
	/*12*/comParams.pushDataBufferDW[5]=trip_words.w_arr[2];
	
	/*14*/comParams.pushDataBufferDW[6]=fault_code;//tripping hist enerterd 1 or more seq
	
	/*16*/comParams.pushDataBufferDW[7]=0; 				// Board Status
	
	/*18*/comParams.pushDataBufferDW[8]=DI.all; 	// Input Status
	/*20*/comParams.pushDataBufferDW[9]=DO.all; 	// Output Status
	
	/*22*/comParams.pushDataBufferDW[10]=0; 			// Spare
	/*24*/comParams.pushDataBufferDW[11]=0; 			// Spare
	/*26*/comParams.pushDataBufferDW[12]=0; 			// Spare
	/*28*/comParams.pushDataBufferDW[13]=0; 			// Spare
	
	//Real Parameters
	
	/*30*/comParams.pushDataBufferF[0]=tRMS.Ia; 	// Ia true RMS
	/*32*/comParams.pushDataBufferF[1]=tRMS.Ib; 	// Ib true RMS
	/*34*/comParams.pushDataBufferF[2]=tRMS.Ic; 	// Ic true RMS
	
	/*36*/comParams.pushDataBufferF[3]=fRMS.Ia; 	// Ia fund RMS
	/*38*/comParams.pushDataBufferF[4]=fRMS.Ib; 	// Ib fund RMS
	/*40*/comParams.pushDataBufferF[5]=fRMS.Ic; 	// Ic fund RMS
	
	/*42*/comParams.pushDataBufferF[6]=P.total; 	// Ptotal
	
	/*44*/comParams.pushDataBufferF[7]=Q.ab; 			// Qab
	/*46*/comParams.pushDataBufferF[8]=Q.bc; 			// Qbc
	/*48*/comParams.pushDataBufferF[9]=Q.ca; 			// Qca
	/*50*/comParams.pushDataBufferF[10]=Q.total;	// Qca
	
	/*52*/comParams.pushDataBufferF[11]=spect_Ia.foutMag[2]; 	// H2-A
	/*54*/comParams.pushDataBufferF[12]=spect_Ib.foutMag[2]; 	// H2-B
	/*56*/comParams.pushDataBufferF[13]=spect_Ic.foutMag[2]; 	// H2-C
	
	/*58*/comParams.pushDataBufferF[14]=spect_Ia.foutMag[3];	// H3-A
	/*60*/comParams.pushDataBufferF[15]=spect_Ib.foutMag[3]; 	// H3-B
	/*62*/comParams.pushDataBufferF[16]=spect_Ic.foutMag[3]; 	// H3-C
	
	/*64*/comParams.pushDataBufferF[17]=spect_Ia.foutMag[4]; 	// H4-A
	/*66*/comParams.pushDataBufferF[18]=spect_Ib.foutMag[4]; 	// H4-B
	/*68*/comParams.pushDataBufferF[19]=spect_Ic.foutMag[4]; 	// H4-C
	
	/*70*/comParams.pushDataBufferF[20]=spect_Ia.foutMag[5]; 	// H5-A
	/*72*/comParams.pushDataBufferF[21]=spect_Ib.foutMag[5]; 	// H5-B
	/*74*/comParams.pushDataBufferF[22]=spect_Ic.foutMag[5]; 	// H5-C
	
	/*76*/comParams.pushDataBufferF[23]=spect_Ia.foutMag[6]; 	// H6-A
	/*78*/comParams.pushDataBufferF[24]=spect_Ib.foutMag[6]; 	// H6-B
	/*80*/comParams.pushDataBufferF[25]=spect_Ic.foutMag[6]; 	// H6-C
	
	/*82*/comParams.pushDataBufferF[26]=spect_Ia.foutMag[7]; 	// H7-A
	/*84*/comParams.pushDataBufferF[27]=spect_Ib.foutMag[7]; 	// H7-B
	/*86*/comParams.pushDataBufferF[28]=spect_Ic.foutMag[7]; 	// H7-C
	
	/*88*/comParams.pushDataBufferF[29]=spect_Ia.foutMag[8]; 	// H8-A
	/*90*/comParams.pushDataBufferF[30]=spect_Ib.foutMag[8]; 	// H8-B
	/*92*/comParams.pushDataBufferF[31]=spect_Ic.foutMag[8]; 	// H8-C
	
	/*94*/comParams.pushDataBufferF[32]=spect_Ia.foutMag[9]; 	// H9-A
	/*96*/comParams.pushDataBufferF[33]=spect_Ib.foutMag[9]; 	// H9-B
	/*98*/comParams.pushDataBufferF[34]=spect_Ic.foutMag[9];	// H9-C
	
	/*100*/comParams.pushDataBufferF[35]=spect_Ia.foutMag[10]; 	// H10-A
	/*102*/comParams.pushDataBufferF[36]=spect_Ib.foutMag[10]; 	// H10-B
	/*104*/comParams.pushDataBufferF[37]=spect_Ic.foutMag[10]; 	// H10-C
	
	/*106*/comParams.pushDataBufferF[38]=spect_Ia.foutMag[11]; // H11-A
	/*108*/comParams.pushDataBufferF[39]=spect_Ib.foutMag[11]; // H11-B
	/*110*/comParams.pushDataBufferF[40]=spect_Ic.foutMag[11]; // H11-C
	
	/*112*/comParams.pushDataBufferF[41]=spect_Ia.foutMag[12]; // H12-A
	/*114*/comParams.pushDataBufferF[42]=spect_Ib.foutMag[12]; // H12-B
	/*116*/comParams.pushDataBufferF[43]=spect_Ic.foutMag[12]; // H12-C
	
	/*118*/comParams.pushDataBufferF[44]=spect_Ia.foutMag[13]; // H13-A
	/*120*/comParams.pushDataBufferF[45]=spect_Ib.foutMag[13]; // H13-B
	/*122*/comParams.pushDataBufferF[46]=spect_Ic.foutMag[13]; // H13-C
	
	//MEM AREA-2
	
	/*126*/comParams.pushDataBufferF[47]=thd.a; 			//thd Ia
	/*128*/comParams.pushDataBufferF[48]=thd.b;				//thd Ib
	/*130*/comParams.pushDataBufferF[49]=thd.c;				//thd Ic
	
	/*132*/comParams.pushDataBufferF[50]=mag_sym.V1; 	//Vpos
	/*134*/comParams.pushDataBufferF[51]=mag_sym.V2; 	//Vneg
	
	/*136*/comParams.pushDataBufferF[52]=mag_sym.I1; 	//Ipos
	/*138*/comParams.pushDataBufferF[53]=mag_sym.I2;	//Ineg
	
	/*140*/comParams.pushDataBufferF[54]=(mag_sym.V1>1.0f) ? (100.0f*mag_sym.V2/mag_sym.V1):0.0f ; //UNB Ratio V
	/*142*/comParams.pushDataBufferF[55]=(mag_sym.I1>1.0f) ? (100.0f*mag_sym.I2/mag_sym.I1):0.0f ; //UNB Ratio I
	
	/*144*/comParams.pushDataBufferF[56]=0.0f ; //Spare
	
	/*146*/comParams.pushDataBufferF[57]=fRMS.Van; 		//RMS Van
	/*148*/comParams.pushDataBufferF[58]=fRMS.Vbn;		//RMS Vbn
	/*150*/comParams.pushDataBufferF[59]=fRMS.Vcn;		//RMS Vcn
	
	/*152*/comParams.pushDataBufferF[60]=fRMS.AB_synth;//RMS Vab
	/*154*/comParams.pushDataBufferF[61]=fRMS.BC_synth;//RMS Vbc
	/*156*/comParams.pushDataBufferF[62]=fRMS.CA_synth;//RMS Vca
	
	/*158*/comParams.pushDataBufferF[63]=tRMS.Vb_synch; // true RMS IresA
	/*160*/comParams.pushDataBufferF[64]=tRMS.Vc_synch; // true RMS IresB
	/*162*/comParams.pushDataBufferF[65]=tRMS.ITCR_ab; // true RMS IresC
	
	/*164*/comParams.pushDataBufferF[66]=tRMS.Vb_synch*tRMS.Vb_synch*Sys.Rvalue; // PresA 
	/*166*/comParams.pushDataBufferF[67]=tRMS.Vc_synch*tRMS.Vc_synch*Sys.Rvalue; // PresB 
	/*168*/comParams.pushDataBufferF[68]=tRMS.ITCR_ab*tRMS.ITCR_ab*Sys.Rvalue; // PresC 
	
	/*170*/comParams.pushDataBufferF[69]=comParams.pushDataBufferF[63]+comParams.pushDataBufferF[64]+comParams.pushDataBufferF[65]; // P Res Total
	
	/*172*/comParams.pushDataBufferF[70]=fRMS.ITCR_bc; // UNBa fund RMS
	/*174*/comParams.pushDataBufferF[71]=tRMS.ITCR_bc; // UNBa true RMS
	
	/*176*/comParams.pushDataBufferF[72]=fRMS.ITCR_ca; // UNBa fund RMS
	/*178*/comParams.pushDataBufferF[73]=tRMS.ITCR_ca; // UNBa true RMS
	
	/*180*/comParams.pushDataBufferF[74]=0.0f ; //Spare
	/*182*/comParams.pushDataBufferF[75]=0.0f ; //Spare

	/*184*/comParams.pushDataBufferF[76]=phase_cs_A_out.X ; // imp. A
	/*186*/comParams.pushDataBufferF[77]=phase_cs_B_out.X ;	// imp. B
	/*188*/comParams.pushDataBufferF[78]=phase_cs_C_out.X ;	// imp. C
	
	/*190*/comParams.pushDataBufferF[79]=phase_cs_A_out.phase_disp ;  // phase. disp.A
	/*192*/comParams.pushDataBufferF[80]=phase_cs_B_out.phase_disp ;	// phase. disp.B
	/*194*/comParams.pushDataBufferF[81]=phase_cs_C_out.phase_disp ;	// phase. disp.C
	
	/*196*/comParams.pushDataBufferF[82]=0.0f ; //Spare
	/*198*/comParams.pushDataBufferF[83]=0.0f ; //Spare
	/*200*/comParams.pushDataBufferF[84]=0.0f ; //Spare
	/*202*/comParams.pushDataBufferF[85]=0.0f ; //Spare
	/*204*/comParams.pushDataBufferF[86]=0.0f ; //Spare
	
	/*Spare->206-248*/
	
	
	/*Mem Area-3*/
	
	/*252*/comParams.pushDataBufferDW[14]=pEN.all;
	/*254*/comParams.pushDataBufferDW[15]=mSelect.all;
	/*256*/comParams.pushDataBufferDW[16]=cSelect1.all;
  /*258*/comParams.pushDataBufferDW[17]=cSelect2.all;
	/*260*/comParams.pushDataBufferDW[18]=pFlag.all; 
	
	
	/*262*/comParams.pushDataBufferF[109]=fc50_obj1_L1_in.dropout_ratio;
	/*264*/comParams.pushDataBufferF[110]=fc50_obj1_L1_in.dropout_time;
	
	
	/*266*/comParams.pushDataBufferF[111]=fc50_obj1_L1_in.level;
	/*268*/comParams.pushDataBufferF[112]=fc50_obj1_L1_in.delay;
	
	/*270*/comParams.pushDataBufferF[113]=fc50_obj1_L2_in.level;
	/*272*/comParams.pushDataBufferF[114]=fc50_obj1_L2_in.delay;
	
	/*274*/comParams.pushDataBufferF[115]=fc50_obj1_L3_in.level;
	/*276*/comParams.pushDataBufferF[116]=fc50_obj1_L3_in.delay;
	
	//discard
	//discard
	
	/*282*/comParams.pushDataBufferF[119]=fc51_obj1_in.level;
	/*284*/comParams.pushDataBufferF[120]=fc51_obj1_in.time_multiplier;
	
	
	/*286*/comParams.pushDataBufferF[121]=fc50N_obj1_L1_in.dropout_ratio;
	/*288*/comParams.pushDataBufferF[122]=fc50N_obj1_L1_in.dropout_time;
	
	/*290*/comParams.pushDataBufferF[123]=fc50N_obj1_L1_in.level;
	/*292*/comParams.pushDataBufferF[124]=fc50N_obj1_L1_in.delay;
	
	/*294*/comParams.pushDataBufferF[125]=fc50N_obj1_L2_in.level;
	/*296*/comParams.pushDataBufferF[126]=fc50N_obj1_L2_in.delay;
	
	/*298*/comParams.pushDataBufferF[127]=fc50N_obj1_L3_in.level;
	/*300*/comParams.pushDataBufferF[128]=fc50N_obj1_L3_in.delay;
	
	//discard
	//discard
	
	/*306*/comParams.pushDataBufferF[131]=fc51N_obj1_in.level;
	/*308*/comParams.pushDataBufferF[132]=fc51N_obj1_in.time_multiplier;
	
	/*310*/comParams.pushDataBufferF[133]=fc59_obj1_L1_in.dropout_ratio;
	//discard
	
	/*314*/comParams.pushDataBufferF[135]=fc59_obj1_L1_in.level;
	/*316*/comParams.pushDataBufferF[136]=fc59_obj1_L1_in.delay;
	
	/*318*/comParams.pushDataBufferF[137]=fc59_obj1_L2_in.level;
	/*320*/comParams.pushDataBufferF[138]=fc59_obj1_L2_in.delay;
	
	
	/*322*/comParams.pushDataBufferF[139]=fc27_obj1_L1_in.dropout_ratio;
	
	//discard
	
	/*326*/comParams.pushDataBufferF[141]=fc27_obj1_L1_in.level;
	/*328*/comParams.pushDataBufferF[142]=fc27_obj1_L1_in.delay;
	
	/*330*/comParams.pushDataBufferF[143]=fc27_obj1_L2_in.level;
	/*332*/comParams.pushDataBufferF[144]=fc27_obj1_L2_in.delay;
	
	/*334*/comParams.pushDataBufferF[145]=fc46d_obj1_L1_in.dropout_ratio;
	/*336*/comParams.pushDataBufferF[146]=fc46d_obj1_L1_in.dropout_time;
	
	/*338*/comParams.pushDataBufferF[147]=fc46d_obj1_L1_in.level;
	/*340*/comParams.pushDataBufferF[148]=fc46d_obj1_L1_in.delay;
	
	/*342*/comParams.pushDataBufferF[149]=fc46i_obj1_L1_in.level;
	/*344*/comParams.pushDataBufferF[150]=fc46i_obj1_L1_in.time_multiplier;
	
	/*346*/comParams.pushDataBufferF[151]=fc49_obj1_therm.k;
	/*348*/comParams.pushDataBufferF[152]=fc49_obj1_therm.tau;
	/*350*/comParams.pushDataBufferF[153]=fc49_obj1_L1_in.alarm_level;
	/*352*/comParams.pushDataBufferF[154]=fc49_obj1_therm.Inom;
	
	//discard
	//discard
	
	//discard
	/*360*/comParams.pushDataBufferF[158]=fcBF_in.delay;
	/*362*/comParams.pushDataBufferF[159]=fcBF_in.threshold;
	
	//discard
	//discard
	//discard
	//discard
	//discard
	//discard
	
	
	/*MEM-4*/
	
	
	/*378*/comParams.pushDataBufferF[166]=fc37_obj1_L1_in.dropout_ratio;
	//discard
	/*382*/comParams.pushDataBufferF[168]=fc37_obj1_L1_in.level;
	/*384*/comParams.pushDataBufferF[169]=fc37_obj1_L1_in.delay;
	
	/*386*/comParams.pushDataBufferF[170]=fcUNBd_obj1_L1_in.dropout_ratio;
	//discard
	/*390*/comParams.pushDataBufferF[172]=fcUNBd_obj1_L1_in.level;
	/*392*/comParams.pushDataBufferF[173]=fcUNBd_obj1_L1_in.delay;
	//discard
	
	
	//discard
	//discard
	/*400*/comParams.pushDataBufferF[177]=fcUNBi_obj1_L1_in.level;
	/*402*/comParams.pushDataBufferF[178]=fcUNBi_obj1_L1_in.time_multiplier;
	
	
	/*404*/comParams.pushDataBufferF[179]=fcPVPd_obj1_L1_in.dropout_ratio;
	//discard
	/*408*/comParams.pushDataBufferF[181]=fcPVPd_obj1_L1_in.level;
	/*410*/comParams.pushDataBufferF[182]=fcPVPd_obj1_L1_in.delay;
	
	
	//discard
	//discard
	/*416*/comParams.pushDataBufferF[185]=fcPVPi_obj1_L1_in.level;
	/*418*/comParams.pushDataBufferF[186]=fcPVPi_obj1_L1_in.time_multiplier;
	//discard
	
	/*422*/comParams.pushDataBufferF[188]=fc50_obj2_L1_in.dropout_ratio;
	/*424*/comParams.pushDataBufferF[189]=fc50_obj2_L1_in.dropout_time;
	
	
	/*426*/comParams.pushDataBufferF[190]=fc50_obj2_L1_in.level;
	/*428*/comParams.pushDataBufferF[191]=fc50_obj2_L1_in.delay;
	
	/*430*/comParams.pushDataBufferF[192]=fc50_obj2_L2_in.level;
	/*432*/comParams.pushDataBufferF[193]=fc50_obj2_L2_in.delay;
	
	/*434*/comParams.pushDataBufferF[194]=fc50_obj2_L3_in.level;
	/*436*/comParams.pushDataBufferF[195]=fc50_obj2_L3_in.delay;
	
	
	//discard
	//discard
	
	/*442*/comParams.pushDataBufferF[198]=fc51_obj2_in.level;
	/*444*/comParams.pushDataBufferF[199]=fc51_obj2_in.time_multiplier;
	
	
	/*446*/comParams.pushDataBufferF[200]=fc49_obj2_therm.k;
	/*448*/comParams.pushDataBufferF[201]=fc49_obj2_therm.tau;
	/*450*/comParams.pushDataBufferF[202]=fc49_obj2_L1_in.alarm_level;
	/*452*/comParams.pushDataBufferF[203]=fc49_obj2_therm.Inom;
	//discard
	//discard
	
	
	/*458*/comParams.pushDataBufferF[206]=fc37_obj2_L1_in.dropout_ratio;
	//discard
	/*462*/comParams.pushDataBufferF[208]=fc37_obj2_L1_in.level;
	/*464*/comParams.pushDataBufferF[209]=fc37_obj2_L1_in.delay;
	
	/*466*/comParams.pushDataBufferF[210]=Sys.Q_TCR; //cau im MVar
	/*468*/comParams.pushDataBufferF[211]=Sys.Q_HF2;
	/*470*/comParams.pushDataBufferF[212]=Sys.Q_HF3;
	/*472*/comParams.pushDataBufferF[213]=Sys.Q_HF4;
	
	/*474*/comParams.pushDataBufferF[214]=Sys.I_Nom_obj1;
	/*476*/comParams.pushDataBufferF[215]=Sys.I_Nom_obj2;
	/*478*/comParams.pushDataBufferF[216]=Sys.I_BreakerClosed_MIN;
	/*480*/comParams.pushDataBufferF[217]=Sys.Rvalue;
	
	/*474*/comParams.pushDataBufferF[218]=TR.VT_MV_Primary;
	/*476*/comParams.pushDataBufferF[219]=TR.VT_MV_Secondary;
	/*478*/comParams.pushDataBufferF[220]=TR.CT_Primary;
	/*480*/comParams.pushDataBufferF[221]=TR.CT_Secondary  ;
	/*478*/comParams.pushDataBufferF[222]=TR.TCR_Primary;
	/*480*/comParams.pushDataBufferF[223]=TR.TCR_Secondary;
	/*478*/comParams.pushDataBufferF[224]=0;
	/*480*/comParams.pushDataBufferF[225]=0;
	
	//discard
	//discard
	
	#endif
	
}







