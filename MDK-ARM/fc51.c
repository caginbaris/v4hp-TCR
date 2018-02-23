#include "nfbm.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"





struct fc51_inputParameters fc51_obj1_in;
struct fc51_inputParameters fc51_obj2_in;


struct fc51_outputParameters fc51_obj1_out_a={0};
struct fc51_outputParameters fc51_obj1_out_b={0};
struct fc51_outputParameters fc51_obj1_out_c={0};


struct fc51_outputParameters fc51_obj2_out_a={0};
struct fc51_outputParameters fc51_obj2_out_b={0};
struct fc51_outputParameters fc51_obj2_out_c={0};







void fc51_init(){
	
	struct fc51_inputParameters fc51_initStruct={	1.0f, 						/*level*/
																							{0.0f,0.0f,0.0f}, 	/*Curve*/
																							0.02f 							/*TimeMultiplier*/};
		
	fc51_obj1_in=fc51_initStruct;
	fc51_obj2_in=fc51_initStruct;
																									

	fc51_obj1_in.curve_data[0]=curve_data[IEC_normal_inverse][0];
	fc51_obj1_in.curve_data[1]=curve_data[IEC_normal_inverse][1];
	fc51_obj1_in.curve_data[2]=curve_data[IEC_normal_inverse][2];	
																							
	fc51_obj2_in.curve_data[0]=curve_data[IEC_normal_inverse][0];
	fc51_obj2_in.curve_data[1]=curve_data[IEC_normal_inverse][1];
	fc51_obj2_in.curve_data[2]=curve_data[IEC_normal_inverse][2];																							


}



void fc51_all(){
	
	float fc51_rms_a=0;
	float fc51_rms_b=0;
	float fc51_rms_c=0;
	
	
	// fc51 obj1 Start**************************

	if(mSelect.bit.obj1_fc51){ 
		
		// cau mselec problem fc51
		// cau 12 A ustunde waveform bozuluyor CRB tarafinda
		
		fc51_rms_a=fRMS.Ia;
		fc51_rms_b=fRMS.Ib;
		fc51_rms_c=fRMS.Ic;
		
	}else{
		
		fc51_rms_a=tRMS.Ia;
		fc51_rms_b=tRMS.Ib;
		fc51_rms_c=tRMS.Ic;
		
	}
	
	
	
	fc51(fc51_rms_a,fc51_obj1_in,&fc51_obj1_out_a,EN.bits.fc51_obj1);
	fc51(fc51_rms_b,fc51_obj1_in,&fc51_obj1_out_b,EN.bits.fc51_obj1);
	fc51(fc51_rms_c,fc51_obj1_in,&fc51_obj1_out_c,EN.bits.fc51_obj1);
	
	
	// fc51 obj1 End**************************
	
	
	// fc51 obj2 Start************************
	
	
	fc51(tRMS.Vb_synch,fc51_obj2_in,&fc51_obj2_out_a,EN.bits.fc51_obj2);
	fc51(tRMS.Vc_synch,fc51_obj2_in,&fc51_obj2_out_b,EN.bits.fc51_obj2);
	fc51(tRMS.ITCR_ab,fc51_obj2_in,&fc51_obj2_out_c,EN.bits.fc51_obj2);	
	
	
	// fc51 obj2 End**************************
	



}


