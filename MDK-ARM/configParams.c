#include "nfbm.h"
#include "UART_MasterSlave.h"
#include "measurement_functions.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"
#include "powerSysData.h"


union protectionEnableData pEN;

union mSelection mSelect={0};
union pFlags pFlag={0};

void init_protection(void);

void checkDataFromMaster(){
	
	


}

void pullDataFromMaster(){
	
	
	// DW data
	
	// processed @ last
	
	pEN.all=comParams_uart.recDataBufferDW[0];
	mSelect.all=comParams_uart.recDataBufferDW[1];
	cSelect1.all=comParams_uart.recDataBufferDW[2];
	cSelect2.all=comParams_uart.recDataBufferDW[3];
	pFlag.all=comParams_uart.recDataBufferDW[4];
	
	init_protection();
	
	
	Sys.phaseRotation=pFlag.bit.phaseRotation;
	Sys.fc27_currentSupervision= pFlag.bit.fc27_currentSupervision;
	//Sys.fcBF_CBSupervision=pFlag.bit.fcBF_cbSupervision;
	
	//spare
	
	//Sys.UNBdetect=pFlag.bit.naturalUNBdetect;
	//Sys.UNBcompFlag=pFlag.bit.naturalUNBcomp;
	
	
	//F data
	
	fc50_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	fc50_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L2_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	fc50_obj1_L3_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L3_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	
	fc50_obj1_L1_in.level=comParams_uart.recDataBufferF[2];
	fc50_obj1_L1_in.delay=comParams_uart.recDataBufferF[3];
	
	fc50_obj1_L2_in.level=comParams_uart.recDataBufferF[4];
	fc50_obj1_L2_in.delay=comParams_uart.recDataBufferF[5];
	
	fc50_obj1_L3_in.level=comParams_uart.recDataBufferF[6];
	fc50_obj1_L3_in.delay=comParams_uart.recDataBufferF[7];
	
	//discard
	//discard
	
	fc51_obj1_in.level=comParams_uart.recDataBufferF[10];
	fc51_obj1_in.time_multiplier=comParams_uart.recDataBufferF[11];
	
	
	fc50N_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	fc50N_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L2_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	fc50N_obj1_L3_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L3_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	
	fc50N_obj1_L1_in.level=comParams_uart.recDataBufferF[14];
	fc50N_obj1_L1_in.delay=comParams_uart.recDataBufferF[15];
	
	fc50N_obj1_L2_in.level=comParams_uart.recDataBufferF[16];
	fc50N_obj1_L2_in.delay=comParams_uart.recDataBufferF[17];
	
	fc50N_obj1_L3_in.level=comParams_uart.recDataBufferF[18];
	fc50N_obj1_L3_in.delay=comParams_uart.recDataBufferF[19];
	
	
	//discard
	//discard
	
	fc51N_obj1_in.level=comParams_uart.recDataBufferF[22];
	fc51N_obj1_in.time_multiplier=comParams_uart.recDataBufferF[23];
	
	
	
	fc59_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[24];
	fc59_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[24];
	//discard
	
	fc59_obj1_L1_in.level=comParams_uart.recDataBufferF[26];
	fc59_obj1_L1_in.delay=comParams_uart.recDataBufferF[27];
	
	fc59_obj1_L2_in.level=comParams_uart.recDataBufferF[28];
	fc59_obj1_L2_in.delay=comParams_uart.recDataBufferF[29];
	
	
	
	fc27_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[30];
	fc27_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[30];
	//discard
	
	fc27_obj1_L1_in.level=comParams_uart.recDataBufferF[32];
	fc27_obj1_L1_in.delay=comParams_uart.recDataBufferF[33];
	
	fc27_obj1_L2_in.level=comParams_uart.recDataBufferF[34];
	fc27_obj1_L2_in.delay=comParams_uart.recDataBufferF[35];
	
	

	
	
	fc49_obj1_therm.k=comParams_uart.recDataBufferF[42];
	fc49_obj1_therm.tau=comParams_uart.recDataBufferF[43]*60;
	fc49_obj1_L1_in.alarm_level=comParams_uart.recDataBufferF[44];
	fc49_obj1_therm.Inom=comParams_uart.recDataBufferF[104];
	
	
	fc49_obj2_therm.k=comParams_uart.recDataBufferF[45];
	fc49_obj2_therm.tau=comParams_uart.recDataBufferF[46]*60;
	fc49_obj2_L1_in.alarm_level=comParams_uart.recDataBufferF[47];
	fc49_obj2_therm.Inom=comParams_uart.recDataBufferF[104];
	

	
	fc37_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[56];
	//discard
	fc37_obj1_L1_in.level=comParams_uart.recDataBufferF[58];
	fc37_obj1_L1_in.delay=comParams_uart.recDataBufferF[59];
	
	

	
	Sys.Q_TCR=comParams_uart.recDataBufferF[100];
	Sys.Q_HF2=comParams_uart.recDataBufferF[101];
	Sys.Q_HF3=comParams_uart.recDataBufferF[102];
	Sys.Q_HF4=comParams_uart.recDataBufferF[103];

	Sys.I_Nom_obj1=comParams_uart.recDataBufferF[104];
	Sys.I_Nom_obj2=comParams_uart.recDataBufferF[104];
	
	Sys.I_BreakerClosed_MIN=comParams_uart.recDataBufferF[106];
	
	
	
	TR.VT_MV_Primary  =comParams_uart.recDataBufferF[108];
	TR.VT_MV_Secondary=comParams_uart.recDataBufferF[109];
	
	TR.VT_HV_Primary  =comParams_uart.recDataBufferF[110];
	TR.VT_HV_Secondary=comParams_uart.recDataBufferF[111];
	
	TR.CT_Primary  =comParams_uart.recDataBufferF[112];
	TR.CT_Secondary=comParams_uart.recDataBufferF[113];
	
	TR.TCR_Primary  =comParams_uart.recDataBufferF[114];
	TR.TCR_Secondary=comParams_uart.recDataBufferF[115];
	

	
	
	//cau final TR value must considered
	
	
	TR.VT_MV=	(TR.VT_MV_Secondary>eps) 	? 	(TR.VT_MV_Primary/TR.VT_MV_Secondary) : 0.0f;
	TR.VT_HV=	(TR.VT_HV_Secondary>eps) 	? 	(TR.VT_HV_Primary/TR.VT_HV_Secondary) : 0.0f;
	
	TR.CT=	(TR.CT_Secondary>eps) 	? 	(TR.CT_Primary/TR.CT_Secondary) : 0.0f;
	TR.TCR=	(TR.TCR_Secondary >eps) 	? 	(TR.TCR_Primary/TR.TCR_Secondary) : 0.0f;

								 
												 
	


	
	

	
											
											
												
												
													
	
	 
	
	
	
	
	
	
	
	
	
	


}

