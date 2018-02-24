#include "nfbm.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"

struct fc50_inputParameters fc50N_obj1_L1_in;
struct fc50_inputParameters fc50N_obj1_L2_in;
struct fc50_inputParameters fc50N_obj1_L3_in;


struct fc50_outputParameters fc50N_obj1_L1_out={0};
struct fc50_outputParameters fc50N_obj1_L2_out={0};
struct fc50_outputParameters fc50N_obj1_L3_out={0};


void fc50N_init(){
	
	
		struct fc50_inputParameters fc50_initStruct={	1.0f, /*level*/
																								0.9f, /*DropOutRatio*/
																								0.05f,/*Delay*/
																								0.02f /*DropOutTime*/};
	
		fc50N_obj1_L1_in=fc50_initStruct;
		fc50N_obj1_L2_in=fc50_initStruct;
		fc50N_obj1_L3_in=fc50_initStruct;	





}


void fc50N_all(){
	
	
	float fc50N_rms=0;

	
		// fc50N L1****************
	
		if(mSelect.bit.obj1_fc50N_L1){
		
		fc50N_rms=fRMS.ITCR_N;

		}else{
		
		fc50N_rms=tRMS.ITCR_N;
			
		}
		
		
		fc50(fc50N_rms,fc50N_obj1_L1_in,&fc50N_obj1_L1_out,EN.bits.fc50N_obj1_L1);
		
		
		// fc50N L2*****************
		
		if(mSelect.bit.obj1_fc50N_L2){
		
		fc50N_rms=fRMS.ITCR_N;

		}else{
		
		fc50N_rms=tRMS.ITCR_N;
			
		}
		
		
		
		
		fc50(fc50N_rms,fc50N_obj1_L2_in,&fc50N_obj1_L2_out,EN.bits.fc50N_obj1_L2);
		
		
		
		if(mSelect.bit.obj1_fc50N_L3){
		
		fc50N_rms=fRMS.ITCR_N;

		}else{
		
		fc50N_rms=tRMS.ITCR_N;
			
		}
		
		
		
		fc50(fc50N_rms,fc50N_obj1_L3_in,&fc50N_obj1_L3_out,EN.bits.fc50N_obj1_L3);



}
