#include "nfbm.h"
#include "plib_definitions.h"
#include "measurement_functions.h"
#include "powerSysData.h"
#include "cs_handles.h"



#define cs_qual_time 0.02f

struct fc27_inputParameters fc27_obj1_L1_in;
struct fc27_inputParameters fc27_obj1_L2_in;


struct fc27_outputParameters fc27_obj1_L1_out={0};
struct fc27_outputParameters fc27_obj1_L2_out={0};;



void fc27_init(){
	
	struct fc27_inputParameters fc27_initStruct={ 1.0f,/*level*/
																								0.04f,/*delay*/
																								1.1,/*dropout*/
																								};
	
	fc27_obj1_L1_in=fc27_initStruct;
	fc27_obj1_L2_in=fc27_initStruct;

}


void fc27_all(){
	
	static uint8_t  cs_qual=0;
	static long 		cs_counter=0;
	
	float rms;
	

	
	if(Sys.fc27_currentSupervision){ //cau assigment check needed
	
	cs_qual=on_off_delay(
		
			(fRMS.Ia<Sys.I_BreakerClosed_MIN &&
			 fRMS.Ib<Sys.I_BreakerClosed_MIN &&
			 fRMS.Ic<Sys.I_BreakerClosed_MIN),
			 cs_qual,
			 fs*cs_qual_time,
			 &cs_counter);
		
	}
	
	
	if(cs_qual){
	
	fc27_obj1_L1_out.cs=1;
	fc27_obj1_L2_out.cs=1;		
	
	}else{
		
	fc27_obj1_L1_out.cs=0;
	fc27_obj1_L2_out.cs=0;			
	
	}
	
	
		rms=minSelector_3p(tRMS.AB_synth,tRMS.BC_synth,tRMS.CA_synth);
	
		//L1
		fc27(rms,fc27_obj1_L1_in,&fc27_obj1_L1_out,EN.bits.fc27_obj1_L1);
		//L2
		fc27(rms,fc27_obj1_L2_in,&fc27_obj1_L2_out,EN.bits.fc27_obj1_L2);

		
}




