#include "measurement_functions.h"
#include "mlib_constants.h"
#include "plib_definitions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "cs_handles.h"
#include <math.h>




struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
struct fcUNBi_inputParameters fcUNBi_obj1_L1_in;


struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_a={0};
struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_b={0};

struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_a={0};
struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_b={0};

float UNBpcorrection=0.062831853071796; //half deg @fs

uint8_t detect=0;
uint8_t comp=0;
uint8_t dmy_phase=0;

float UNBa_rms=0;
float UNBb_rms=0;


float nucArray[4]={0};


void fcUNB_initial_dt(){
	
	static long time_out_counter=0;
	static uint8_t  passed=0;
	
	if(Sys.UNBdetect && passed==0){
		
		passed=off_delay(1,passed,12500,&time_out_counter);

	//	fcUNBd_obj1_L1_out_a.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBa.c,UNBa.s)+pi-UNBpcorrection);
	//	fcUNBd_obj1_L1_out_b.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBb.c,UNBb.s)+pi-UNBpcorrection);
		
		fcUNBd_obj1_L1_out_a.Nmag=fRMS.ITCR_bc*sqrt2;
		fcUNBd_obj1_L1_out_b.Nmag=fRMS.ITCR_ca*sqrt2; 
		

	}
	
	if(!Sys.UNBdetect){passed=0;}
	
	
	
}



void fcUNB_init(){
	
		struct fcUNBd_inputParameters fUNBd_initStruct={	0.0f, 						/*level*/
																										  0.0f, 						/*delay*/
																										  0.02f 						/*dropout ratio*/};
		
		struct fcUNBi_inputParameters fUNBi_initStruct={	0.0f, 						/*level*/
																										  0.02f 						/*time Multiplier*/};
		
		
		
		fcUNBd_obj1_L1_in=fUNBd_initStruct;
		fcUNBi_obj1_L1_in=fUNBi_initStruct;																										



}



void fcUNB_all(){
	
	static uint8_t counter=0;
	
	static float UNBa_buffer[25];
	static float UNBb_buffer[25];
	
	float UNBa_synth=0;
	float UNBb_synth=0;
	

	
	fcUNB_initial_dt();
	
	
	if(Sys.UNBcompFlag){
	
	//cau cs_handles part is not used
	
	UNBa_synth=(fcUNBd_obj1_L1_out_a.Nmag*sin(phase_cs_A_out.phase_I-fcUNBd_obj1_L1_out_a.Nphase));
	UNBb_synth=(fcUNBd_obj1_L1_out_b.Nmag*sin(phase_cs_A_out.phase_I-fcUNBd_obj1_L1_out_a.Nphase));	
	
	UNBa_rms=true_rms((fAdc.sAdc.ITCR_bc -UNBa_synth),&UNBa_buffer[0],counter,25);
	UNBb_rms=true_rms((fAdc.sAdc.ITCR_ca-UNBb_synth),&UNBb_buffer[0],counter,25);	
		
	
		
	}else{
		
	
	UNBa_rms=fRMS.ITCR_bc;
	UNBb_rms=fRMS.ITCR_ca;
	
	
	}
	
	if(++counter==25){counter=0;}	
	
	
	fcUNBd(UNBa_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_a,EN.bits.fcUNBd_obj1);
	fcUNBd(UNBb_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_b,EN.bits.fcUNBd_obj1);
	
	fcUNBi(UNBa_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_a,EN.bits.fcUNBi_obj1);
	fcUNBi(UNBb_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_b,EN.bits.fcUNBi_obj1);
	

}


