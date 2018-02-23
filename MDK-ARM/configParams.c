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
	Sys.fcBF_CBSupervision=pFlag.bit.fcBF_cbSupervision;
	
	//spare
	
	Sys.UNBdetect=pFlag.bit.naturalUNBdetect;
	Sys.UNBcompFlag=pFlag.bit.naturalUNBcomp;
	
	
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
	
	
	fc46d_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[36];
	fc46d_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[37];
	
	fc46d_obj1_L1_in.level=comParams_uart.recDataBufferF[38];
	fc46d_obj1_L1_in.delay=comParams_uart.recDataBufferF[39];
	
	fc46i_obj1_L1_in.level=comParams_uart.recDataBufferF[40];
	fc46i_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[41];
	
	
	fc49_obj1_therm.k=comParams_uart.recDataBufferF[42];
	fc49_obj1_therm.tau=comParams_uart.recDataBufferF[43]*60;
	fc49_obj1_L1_in.alarm_level=comParams_uart.recDataBufferF[44];
	fc49_obj1_therm.Inom=comParams_uart.recDataBufferF[104];
	
	//discard
	//discard
	//discard
	
	fcBF_in.delay=comParams_uart.recDataBufferF[49];
	fcBF_in.threshold=comParams_uart.recDataBufferF[50];
	
	//discard
	//discard
	//discard
	//discard
	//discard
	//discard
	
	fc37_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[56];
	//discard
	fc37_obj1_L1_in.level=comParams_uart.recDataBufferF[58];
	fc37_obj1_L1_in.delay=comParams_uart.recDataBufferF[59];
	
	
	fcUNBd_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[60];
	//discard
	fcUNBd_obj1_L1_in.level=comParams_uart.recDataBufferF[62];
	fcUNBd_obj1_L1_in.delay=comParams_uart.recDataBufferF[63];
	//spare
	
	//discard
	//discard
	fcUNBi_obj1_L1_in.level=comParams_uart.recDataBufferF[67];
	fcUNBi_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[68];
	
	fcPVPd_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[69];
	//discard
	//fcPVPd_obj1_L1_in.level=comParams_uart.recDataBufferF[71]; //cau sould e revised
	fcPVPd_obj1_L1_in.delay=comParams_uart.recDataBufferF[72];
	
	//discard
	//discard
	fcPVPi_obj1_L1_in.level=comParams_uart.recDataBufferF[75];
	fcPVPi_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[76]; // cau-diff curve entered
	
	//spare
	
	
	fc50_obj2_L1_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L1_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	fc50_obj2_L2_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L2_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	fc50_obj2_L3_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L3_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	
	fc50_obj2_L1_in.level=comParams_uart.recDataBufferF[80];
	fc50_obj2_L1_in.delay=comParams_uart.recDataBufferF[81];
	
	fc50_obj2_L2_in.level=comParams_uart.recDataBufferF[82];
	fc50_obj2_L2_in.delay=comParams_uart.recDataBufferF[83];
	
	fc50_obj2_L3_in.level=comParams_uart.recDataBufferF[84];
	fc50_obj2_L3_in.delay=comParams_uart.recDataBufferF[85];
	
	//discard
	//discard
	
	fc51_obj2_in.level=comParams_uart.recDataBufferF[88];
	fc51_obj2_in.time_multiplier=comParams_uart.recDataBufferF[89];
	
	fc49_obj2_therm.k=comParams_uart.recDataBufferF[90];
	fc49_obj2_therm.tau=comParams_uart.recDataBufferF[91]*60;
	fc49_obj2_L1_in.alarm_level=comParams_uart.recDataBufferF[92];
	fc49_obj2_therm.Inom=comParams_uart.recDataBufferF[105];
	
	//spare
	//spare
	
	
	fc37_obj2_L1_in.dropout_ratio=comParams_uart.recDataBufferF[96];
	//discard
	fc37_obj2_L1_in.level=comParams_uart.recDataBufferF[98];
	fc37_obj2_L1_in.delay=comParams_uart.recDataBufferF[99];
	
	Sys.Q_TCR=comParams_uart.recDataBufferF[100];
	Sys.Q_HF2=comParams_uart.recDataBufferF[101];
	Sys.Q_HF3=comParams_uart.recDataBufferF[102];
	Sys.Q_HF4=comParams_uart.recDataBufferF[103];

	Sys.I_Nom_obj1=comParams_uart.recDataBufferF[104];
	Sys.I_Nom_obj2=comParams_uart.recDataBufferF[105];
	
	Sys.I_BreakerClosed_MIN=comParams_uart.recDataBufferF[106];
	Sys.Rvalue=comParams_uart.recDataBufferF[107];
	
	
	TR.VT_Primary  =comParams_uart.recDataBufferF[108];
	TR.VT_Secondary=comParams_uart.recDataBufferF[109];
	
	TR.CT_Primary  =comParams_uart.recDataBufferF[110];
	TR.CT_Secondary=comParams_uart.recDataBufferF[111];
	
	TR.UNB_Primary  =comParams_uart.recDataBufferF[112];
	TR.UNB_Secondary=comParams_uart.recDataBufferF[113];
	
	TR.RES_Primary  =comParams_uart.recDataBufferF[114];
	TR.RES_Secondary=comParams_uart.recDataBufferF[115];
	
	
	//cau final TR value must considered
	
	
	TR.VT=	(TR.VT_Secondary>eps) 	? 	(TR.VT_Primary/TR.VT_Secondary) : 0.0f;
	TR.CT=	(TR.CT_Secondary>eps) 	? 	(TR.CT_Primary/TR.CT_Secondary) : 0.0f;
	TR.RES=	(TR.RES_Secondary>eps) 	? 	(TR.RES_Primary/TR.RES_Secondary) : 0.0f;
	TR.UNB=	(TR.UNB_Secondary>eps) 	? 	(TR.UNB_Primary/TR.RES_Secondary) : 0.0f;
								 
												 
	


	
	

	
											
											
												
												
													
	
	 
	
	
	
	
	
	
	
	
	
	


}

