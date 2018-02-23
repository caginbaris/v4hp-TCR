#include "nfbm.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"


struct fc51_inputParameters 	fc51N_obj1_in;
struct fc51_outputParameters 	fc51N_obj1_out={0};

void fc51N_init(){
	
	
	struct fc51_inputParameters fc51N_initStruct={	1.0f, 					/*level*/
																							 {0.0f,0.0f,0.0f}, 	/*Curve*/
																							 0.02f 							/*TimeMultiplier*/};
		
	fc51N_obj1_in=fc51N_initStruct;
	

	
		
	fc51N_obj1_in.curve_data[0]=curve_data[IEC_normal_inverse][0];
	fc51N_obj1_in.curve_data[1]=curve_data[IEC_normal_inverse][1];
	fc51N_obj1_in.curve_data[2]=curve_data[IEC_normal_inverse][2];	


}

	
	
void fc51N_all(){

	float fc51N_rms=0;

	
	
	// fc51N obj1 Start**************************

	if(mSelect.bit.obj1_fc51N){
		
		fc51N_rms=fRMS.In;

	}else{
		
		fc51N_rms=tRMS.In;

	}
	
	fc51(fc51N_rms,fc51N_obj1_in,&fc51N_obj1_out,EN.bits.fc51N_obj1);
	
	// fc51N obj1 End**************************
	
	
	
	




}


