
#include "main.h"





union digitalInputs{


struct{
	
	/*--------MRB naming----Board Naming*/
	
	uint32_t start_stop:1; 	//DI-1
	uint32_t Q1_cb_pos:1;  	//DI-2
	uint32_t Q2_cb_pos:1;  	//DI-3
	uint32_t Q3_cb_pos:1;  	//DI-4
	uint32_t DI5:1;  				//DI-5
	uint32_t DI6:1;  				//DI-6
	uint32_t DI7:1;  				//DI-7
	uint32_t DI8:1;  				//DI-8
	uint32_t DI9:1;  				//DI-9
	uint32_t SVC_trip:1; 		//DI-10
	uint32_t DI11:1;  			//DI-11
	uint32_t Q1_open:1; 		//DI-12
	uint32_t Q1_trip:1; 		//DI-13
	uint32_t Q2_open:1; 		//DI-14
	uint32_t Q2_trip:1; 		//DI-15
	uint32_t Q3_open:1; 		//DI-16
	uint32_t Q3_trip:1; 		//DI-17
	uint32_t _51:1; 				//DI-18
	uint32_t _52:1; 				//DI-19
	uint32_t _53:1; 				//DI-20
	uint32_t _54:1; 				//DI-21
	uint32_t cold_test:1; 	//DI-22
	uint32_t _56:1; 				//DI-23
	uint32_t tfr_trig:1; 	  //DI-24
	uint32_t plb_sp2:1; 		//DI-25
	uint32_t plb_sp1:1; 		//DI-26
	uint32_t plb_sp4:1; 		//DI-27
	uint32_t plb_sp3:1; 		//DI-28
	uint32_t plb_sp6:1; 		//DI-29
	uint32_t plb_sp5:1; 		//DI-30
	uint32_t reset:1; 			//reset.... 24th

	
	
	
}bit;



uint32_t all; 


}; 



union digitalOutputs{


struct{
	
	/*--------MRB naming----Board Naming*/
	
	uint8_t trip:1; 		//DO-1
	uint8_t alarm:1;  	//DO-2
	uint8_t inhibit:1;  //DO-3
	uint8_t BF:1;  			//DO-4
	uint8_t IBF:1;			//DO-5
	uint8_t spare:1;		//DO-6
	uint32_t boardSPARE:10;	// DO-7...16	
	
	uint32_t LD_IBF:1;		// Board Ind. Output Upper
	uint32_t LD_TRIP:1;		// Board Ind. Output Mid
	uint32_t LD_ALARM:1;	// Board Ind. Output Bot
	
	
}bits;



uint8_t all; 





};


extern union digitalInputs  DI;
extern union digitalOutputs DO;



