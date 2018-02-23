#include "plib_definitions.h"
#include "nfbm.h"



struct fc59_inputParameters fc59_obj1_L1_in;
struct fc59_inputParameters fc59_obj1_L2_in;


struct fc59_outputParameters fc59_obj1_L1_out_a={0};
struct fc59_outputParameters fc59_obj1_L1_out_b={0};
struct fc59_outputParameters fc59_obj1_L1_out_c={0};

struct fc59_outputParameters fc59_obj1_L2_out_a={0};
struct fc59_outputParameters fc59_obj1_L2_out_b={0};
struct fc59_outputParameters fc59_obj1_L2_out_c={0};



void fc59_init(){

	struct fc59_inputParameters fc59_initStruct={	1.0f, /*level*/
																								0.04f,/*Delay*/
																								0.9f, /*DropOutRatio*/
																								
																								};
	
	fc59_obj1_L1_in=fc59_initStruct;
	fc59_obj1_L1_in=fc59_initStruct;																								
																								

}



void fc59_all(){
	
	
	
	fc59(tRMS.AB_synth,fc59_obj1_L1_in,&fc59_obj1_L1_out_a,EN.bits.fc59_obj1_L1);
	fc59(tRMS.BC_synth,fc59_obj1_L1_in,&fc59_obj1_L1_out_b,EN.bits.fc59_obj1_L1);
	fc59(tRMS.CA_synth,fc59_obj1_L1_in,&fc59_obj1_L1_out_c,EN.bits.fc59_obj1_L1);
	
	fc59(tRMS.AB_synth,fc59_obj1_L2_in,&fc59_obj1_L2_out_a,EN.bits.fc59_obj1_L2);
	fc59(tRMS.BC_synth,fc59_obj1_L2_in,&fc59_obj1_L2_out_b,EN.bits.fc59_obj1_L2);
	fc59(tRMS.CA_synth,fc59_obj1_L2_in,&fc59_obj1_L2_out_c,EN.bits.fc59_obj1_L2);
	
	

}

