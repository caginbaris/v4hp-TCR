
#include "tick.h"




enum tickCode tick=tick1; 

void tickFunctions(){
	
	
	void (* ftick_thread)(void);
		
	//ftick_thread=ftick[tick1] ;
	//ftick_thread();
	boardIO();
	
	
	if(tick==tick10){tick=tick1;
	
	pushDataToMaster();
	
	}
	

}


void ftick1(){
	
	//cs_handle_tick1();
	//spectra_tick1();
	

};
void ftick2(){

	cs_handle_tick2();
	spectra_tick2();
	
};
void ftick3(){

	cs_handle_tick3();
	spectra_tick3();
	

};
void ftick4(){

	cs_handle_tick4();

};
void ftick5(){};
void ftick6(){};
void ftick7(){

	fc50_all();
	fc51_all();

	fc50N_all();
	fc51N_all();
	
	fc27_all();
	fc59_all();
	fc46_all();	


};
void ftick8(){
	
	
	fc49_all();
	fcBF_all();
	fc37_all();
	fcUNB_all();
	fcPVP_all();



};
void ftick9(){
	
	//pick_up_handles();


};
void ftick10(){
	
fcUNB_initial_dt();

};	



