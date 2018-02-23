


#include "main_flow.h"
#include "boardIO.h"

void main_flow(){

  //measurement
	
	
	#if 0		
	spectral_analysis(); //cau comm problem when invoked
	cs_handles();
	trueRMS();
  

	// protection
	
	
		
	
	
	fc50_all();
	fc50N_all();
	
	fc51_all();
	fc51N_all();

	fc27_all();
	fc59_all();
	fc46_all();
	fc49_all();	
	
	
	fc37_all();
	fcBF_all();
	fcUNB_all();
	fcPVP_all();

	
	
	
	
	#endif 
	pick_trip_reset_handles();
	boardIO();
	
	
	
	
	
	
	
	
	
}

