#ifndef __tick_h
#define __tick_h


void ftick1(void);
void ftick2(void);
void ftick3(void);
void ftick4(void);
void ftick5(void);
void ftick6(void);
void ftick7(void);
void ftick8(void);
void ftick9(void);
void ftick10(void);

void (*ftick[])(void)={

ftick1,
ftick2,
ftick3,
ftick4,
ftick5,
ftick6,
ftick7,
ftick8,
ftick9,
ftick10	
	
};


enum tickCode{

tick1,
tick2,
tick3,
tick4,
tick5,
tick6,
tick7,
tick8,
tick9,
tick10	

};


void cs_handle_tick1(void);
void cs_handle_tick2(void);
void cs_handle_tick3(void);
void cs_handle_tick4(void);

void spectra_tick1(void);
void spectra_tick2(void);
void spectra_tick3(void);


void fc50_all(void);
void fc51_all(void);
void fc50N_all(void);
void fc51N_all(void);
void fc27_all(void);
void fc59_all(void);
void fc46_all(void);
void fc49_all(void);
void fcBF_all(void);
void fc37_all(void);
void fcUNB_all(void);
void fcPVP_all(void);
void boardIO(void);

void fcUNB_initial_dt(void);
void pick_up_handles(void);

void pushDataToMaster(void);



#endif






