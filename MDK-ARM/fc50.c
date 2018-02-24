#include "nfbm.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"


// input parameters------------------------------

struct fc50_inputParameters fc50_obj1_L1_in;
struct fc50_inputParameters fc50_obj1_L2_in;
struct fc50_inputParameters fc50_obj1_L3_in;

struct fc50_inputParameters fc50_obj2_L1_in;
struct fc50_inputParameters fc50_obj2_L2_in;
struct fc50_inputParameters fc50_obj2_L3_in;

// output parameters------------------------------

// L1 obj1

struct fc50_outputParameters fc50_obj1_L1_out_a={0};
struct fc50_outputParameters fc50_obj1_L1_out_b={0};
struct fc50_outputParameters fc50_obj1_L1_out_c={0};



// L2 obj1

struct fc50_outputParameters fc50_obj1_L2_out_a={0};
struct fc50_outputParameters fc50_obj1_L2_out_b={0};
struct fc50_outputParameters fc50_obj1_L2_out_c={0};

// L3 obj1 

struct fc50_outputParameters fc50_obj1_L3_out_a={0};
struct fc50_outputParameters fc50_obj1_L3_out_b={0};
struct fc50_outputParameters fc50_obj1_L3_out_c={0};

// L1 obj2

struct fc50_outputParameters fc50_obj2_L1_out_a={0};
struct fc50_outputParameters fc50_obj2_L1_out_b={0};
struct fc50_outputParameters fc50_obj2_L1_out_c={0};

// L2 obj2

struct fc50_outputParameters fc50_obj2_L2_out_a={0};
struct fc50_outputParameters fc50_obj2_L2_out_b={0};
struct fc50_outputParameters fc50_obj2_L2_out_c={0};

// L3 obj2

struct fc50_outputParameters fc50_obj2_L3_out_a={0};
struct fc50_outputParameters fc50_obj2_L3_out_b={0};
struct fc50_outputParameters fc50_obj2_L3_out_c={0};







void fc50_init(){
	
	struct fc50_inputParameters fc50_initStruct={	1.0f, /*level*/
																								0.9f, /*DropOutRatio*/
																								0.05f,/*Delay*/
																								0.02f /*DropOutTime*/};
	
	fc50_obj1_L1_in=fc50_initStruct;
	fc50_obj1_L2_in=fc50_initStruct;
	fc50_obj1_L3_in=fc50_initStruct;

	fc50_obj2_L1_in=fc50_initStruct;
	fc50_obj2_L2_in=fc50_initStruct;
	fc50_obj2_L3_in=fc50_initStruct;																																																
																								
																								
}

void fc50_all(){
	
	float fc50_rms_a=0;
	float fc50_rms_b=0;
	float fc50_rms_c=0;
	
	// fc50 obj1 Start**************************
	
	// fc50 obj1 L1
	
	if(mSelect.bit.obj1_fc50_L1){
		
		fc50_rms_a=fRMS.ITCR_ab;
		fc50_rms_b=fRMS.ITCR_bc;
		fc50_rms_c=fRMS.ITCR_ca;
		
	}else{
		
		fc50_rms_a=tRMS.ITCR_ab;
		fc50_rms_b=tRMS.ITCR_bc;
		fc50_rms_c=tRMS.ITCR_ca;
		
	}
	
	fc50(fc50_rms_a ,fc50_obj1_L1_in,&fc50_obj1_L1_out_a,EN.bits.fc50_obj1_L1);
	fc50(fc50_rms_b,fc50_obj1_L1_in,&fc50_obj1_L1_out_b,EN.bits.fc50_obj1_L1);
	fc50(fc50_rms_c,fc50_obj1_L1_in,&fc50_obj1_L1_out_c,EN.bits.fc50_obj1_L1);
	
	
	
		// fc50 obj1 L2
	
	if(mSelect.bit.obj1_fc50_L2){
		
		fc50_rms_a=fRMS.ITCR_ab;
		fc50_rms_b=fRMS.ITCR_bc;
		fc50_rms_c=fRMS.ITCR_ca;
		
	}else{
		
		fc50_rms_a=tRMS.Ia;
		fc50_rms_b=tRMS.Ib;
		fc50_rms_c=tRMS.Ic;
		
	}
	
	fc50(fc50_rms_a,fc50_obj1_L2_in,&fc50_obj1_L2_out_a,EN.bits.fc50_obj1_L2);
	fc50(fc50_rms_b,fc50_obj1_L2_in,&fc50_obj1_L2_out_b,EN.bits.fc50_obj1_L2);
	fc50(fc50_rms_c,fc50_obj1_L2_in,&fc50_obj1_L2_out_c,EN.bits.fc50_obj1_L2);
	
	
	
		// fc50 obj1 L3
	
	if(mSelect.bit.obj1_fc50_L3){
		
		fc50_rms_a=fRMS.ITCR_ab;
		fc50_rms_b=fRMS.ITCR_bc;
		fc50_rms_c=fRMS.ITCR_ca;
		
	}else{
		
		fc50_rms_a=tRMS.Ia;
		fc50_rms_b=tRMS.Ib;
		fc50_rms_c=tRMS.Ic;
		
	}
	
	fc50(fc50_rms_a,fc50_obj1_L3_in,&fc50_obj1_L3_out_a,EN.bits.fc50_obj1_L3);
	fc50(fc50_rms_b,fc50_obj1_L3_in,&fc50_obj1_L3_out_b,EN.bits.fc50_obj1_L3);
	fc50(fc50_rms_c,fc50_obj1_L3_in,&fc50_obj1_L3_out_c,EN.bits.fc50_obj1_L3);

	// fc50 obj1 End****************************
	

}

