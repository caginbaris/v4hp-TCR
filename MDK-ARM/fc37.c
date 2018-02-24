#include "plib_definitions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "boardIO.h"


struct fc37_inputParameters fc37_obj1_L1_in;
struct fc37_inputParameters fc37_obj2_L1_in;

struct fc37_outputParameters fc37_obj1_L1_out_a={0};
struct fc37_outputParameters fc37_obj1_L1_out_b={0};
struct fc37_outputParameters fc37_obj1_L1_out_c={0};

struct fc37_outputParameters fc37_obj2_L1_out_a={0};
struct fc37_outputParameters fc37_obj2_L1_out_b={0};
struct fc37_outputParameters fc37_obj2_L1_out_c={0};




/*


*/


void fc37_init(){

			struct fc37_inputParameters fc37_initStruct={	1.0f, /*level*/
																								0.9f, /*DropOutRatio*/
																								0.05f,/*Delay*/};
	
		fc37_obj1_L1_in=fc37_initStruct;
		fc37_obj2_L1_in=fc37_initStruct;
		


}






void fc37_all(){
	
	float pick_current=0;
	uint8_t cb_pos=1;
	
	static long pick_current_counter=0;
	static long inhibit_counter=0;
	
	static uint8_t current_checked=0;
	static uint8_t inhibit_enabled=0;
	
	

	
 /*************inhibit part-start**********/
	
	pick_current=maxSelector_3p(fRMS.Ia,fRMS.Ib,fRMS.Ic);
	
	cb_pos=DI.bit.Q1_cb_pos;  //cau counditionally compiled wrt card ID and corresponding CBs
 
	current_checked	=	on_delay(	 (pick_current>(Sys.I_Nom_obj1*0.5f)),
															 current_checked,
															 fs*0.026f,
															 &pick_current_counter);
	
	if(current_checked){inhibit_enabled =1;}
	if(DO.bits.inhibit){inhibit_enabled =0;}
	
	//DO.bits.inhibit=off_delay((inhibit_enabled==1 && current_checked==0),DO.bits.inhibit,fs*30,&inhibit_counter); 
	
	/*************inhibit part-end**********/
		
																	

	fc37(fRMS.ITCR_ab,cb_pos,fc37_obj1_L1_in,&fc37_obj1_L1_out_a,EN.bits.fc37_obj1);
	fc37(fRMS.ITCR_bc,cb_pos,fc37_obj1_L1_in,&fc37_obj1_L1_out_b,EN.bits.fc37_obj1);
	fc37(fRMS.ITCR_ca,cb_pos,fc37_obj1_L1_in,&fc37_obj1_L1_out_c,EN.bits.fc37_obj1);
	

	

	


}






