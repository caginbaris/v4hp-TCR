


#ifndef PLIB_DEFINITIONS_H
#define PLIB_DEFINITIONS_H


#define fs 2500

int on_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count);
int off_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count);
int on_off_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count);


struct fc50_inputParameters {

	
	float level;
	float delay;
	float dropout_ratio;
	float dropout_time;

};

struct fc50_outputParameters {

	long trip_counter;
	long dropout_counter;

	unsigned int initial_pick_up:1;
	unsigned int pick_up:1;
	unsigned int trip:1;
	unsigned int trip_latch:1;
	
	

};

void fc50(float rms,struct fc50_inputParameters fc50_in, struct fc50_outputParameters *fc50_out, int enable);


struct fc51_inputParameters {

	
	float level;
	float curve_data[3];
	float time_multiplier;


};

struct fc51_outputParameters {

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;


};

void fc51(float rms,struct fc51_inputParameters fc51_in, struct fc51_outputParameters *fc51_out,int enable );


struct fc27_inputParameters{

	float level;
	float delay;
	float dropout_ratio;
	

};

struct fc27_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;
	unsigned int cs:1; // caution: externally set by a routine
};

void fc27(float rms, struct fc27_inputParameters fc27_in, struct fc27_outputParameters *fc27_out,int enable );

struct fc59_inputParameters{


	float level;
	float delay;
	float dropout_ratio;
	

};

struct fc59_outputParameters{

	long trip_counter;
	unsigned int pick_up;
	unsigned int trip;

};
void fc59(float rms, struct fc59_inputParameters fc59_in, struct fc59_outputParameters *fc59_out, int enable);


struct fc46d_inputParameters{

	
	float level;
	float delay;
	float dropout_ratio;
	float dropout_time;

};


struct fc46d_outputParameters{

	long pass_counter;
	long trip_counter;
	long dropout_counter;

	unsigned int pass_flag:1;
	unsigned int initial_pick_up:1;
	unsigned int pick_up:1;
	unsigned int trip:1;
	unsigned int trip_latch:1;

};

void fc46d(float rms, float Inom, struct fc46d_inputParameters fc46d_in, struct fc46d_outputParameters *fc46d_out, int enable);



struct fc46i_inputParameters {

	
	float level;
	float curve_data[3];
	float time_multiplier;

};

struct fc46i_outputParameters {

	long pass_counter;
	float time2trip;
	long trip_counter;
	
	
	unsigned int pass_flag:1;
	unsigned int pick_up:1;
	unsigned int trip:1;


};

void fc46i(float rms,float Inom, struct fc46i_inputParameters fc46i_in, struct fc46i_outputParameters *fc46i_out, int enable);


struct fc49_inputParameters{


	float alarm_level; 

};


struct fc49_outputParameters{

	
	unsigned int alarm:1;
	unsigned int trip:1;
	

};

void fc49(float temp,struct fc49_inputParameters fc49_in, struct fc49_outputParameters *fc49_out, int enable);

struct fcBF_inputParameters{

	float rmsA;
	float rmsB;
	float rmsC;

	float threshold;
	float delay;

	

	unsigned int trip_input:1;
	unsigned int CB_pos:1;
	unsigned int CB_pos_check:1;


	

};

struct fcBF_outputParameters{

	
	long trip_counter;
	long pass_flag_counter;

	unsigned int pick_up:1;
	unsigned int current_checked:1;
	unsigned int trip:1;
	unsigned int pass_flag:1;
	unsigned int pass_flag_filtered:1;
	

};

void fcBF(struct fcBF_inputParameters fcBF_in, struct fcBF_outputParameters *fcBF_out, int enable);


struct fc37_inputParameters{

	
	float level;
	float dropout_ratio;
	float delay;
	

};

struct fc37_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};

void fc37(float rms,int cb_pos, struct fc37_inputParameters fc37_in, struct fc37_outputParameters *fc37_out, int enable);


struct fcUNBd_inputParameters{

	
	float level; // vectoral difference will be used
	float delay;
	float dropout_ratio;
	
	

};

struct fcUNBd_outputParameters{
	
	float Nphase;
	float Nmag;

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};



struct fcUNBi_inputParameters {
	
	

	
	float level;
	float time_multiplier;


	
};


struct fcUNBi_outputParameters{
	

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;
};


void fcUNBd(float rms,struct fcUNBd_inputParameters fcUNBd_in, struct fcUNBd_outputParameters *fcUNBd_out, int enable);
void fcUNBi(float rms,struct fcUNBi_inputParameters fcUNBi_in, struct fcUNBi_outputParameters *fcUNBi_out, int enable);


struct fcPVPd_inputParameters{

	
	float level; // vectoral difference will be used
	float delay;
	float dropout_ratio;
	
	

};

struct fcPVPd_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};


struct fcPVPi_inputParameters {

	
	float level;
	float curve_data[3];
	float time_multiplier;


};


struct fcPVPi_outputParameters{

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;
};

void fcPVPd(float rms,struct fcPVPd_inputParameters fcPVPd_in, struct fcPVPd_outputParameters *fcPVPd_out, int enable);
void fcPVPi(float rms,struct fcPVPi_inputParameters fcPVPi_in, struct fcPVPi_outputParameters *fcPVPi_out, int enable);


float minSelector_3p(float a, float b, float c);
float maxSelector_3p(float a, float b, float c);


#endif
