#include "plib_definitions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "boardIO.h"



struct fcBF_inputParameters  fcBF_in;
struct fcBF_outputParameters fcBF_out={0};



void fcBF_init(){
	
struct fcBF_inputParameters fcBF_initStruct={
	
	
	0.0f,	/*rmaA*/
	0.0f,	/*rmsB*/
	0.0f,	/*rmsC*/
	
	0.0f,	/*threshold*/
	0.05f,	/*delay*/
	0.0f, 		/*trip inp*/
	0.0f,		/*cb_pos inp*/
	0.0f,		/*CB_pos_check*/

};	

fcBF_in=fcBF_initStruct;



}


void fcBF_all(){
	
	fcBF_in.rmsA=fRMS.Ia;
	fcBF_in.rmsB=fRMS.Ib;
	fcBF_in.rmsC=fRMS.Ic;
	
	fcBF_in.threshold=Sys.I_BreakerClosed_MIN;
	fcBF_in.CB_pos_check=Sys.fcBF_CBSupervision; 
	
	fcBF_in.CB_pos		=DI.bit.Q1_cb_pos;												/*Breaker Input*/
	fcBF_in.trip_input=DI.bit.SVC_trip | DI.bit.Q1_open ;	       /*Trip Input*/
	// cau related cb position should conditionally compiled
	
	fcBF(fcBF_in,&fcBF_out,EN.bits.fcBF_obj1);
	
	
	if(fcBF_out.trip){

		DO.bits.BF=0;

	}else{
	
		DO.bits.BF=1;
	
	}
	


}








