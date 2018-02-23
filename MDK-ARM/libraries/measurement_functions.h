
#ifndef MEASUREMENT_FUNCTIONS_H
#define MEASUREMENT_FUNCTIONS_H


float true_rms(float rtInput, float *delayLineArray, unsigned int delayLineCounter, unsigned int arrayLength);
float cs_generation(float rtInput,float *coeff, unsigned int coeffLength, float *zValues);

struct phase_cs_in{

		float Vc;
		float Vs;
		float Ic;
		float Is;
};

struct phase_cs_single{

	float c;
	float s;
};

struct phase_cs_out{

		float rms_V;
		float rms_V2;
		float rms_I;
		float rms_I2;
		float P;
		float Q;
		float X;
		float R;	
		float phase_V;
		float phase_I;
		float phase_disp;

};

void cs_computations(struct phase_cs_in  p_in, struct phase_cs_out *p_out );


struct sym_out{

	
	float V1;
	float V2;
	float V0;

	float I1;
	float I2;
	float I0;

};

extern struct sym_out sym;

void sym_comp(struct phase_cs_in pa, struct phase_cs_in pb,struct phase_cs_in pc,struct sym_out *sym);
void sym_mag(struct sym_out sym, struct sym_out *sym_back, struct sym_out *sym_rms);


struct spectra {

	float qBuffer[50];
	float foutReal[14];
	float foutImag[14];
	float foutMag[14];

};

void signal_spectra(
	
	float rtInput, 
	struct spectra *h,
	unsigned int qBufferLength,	//updated buffer length
	float *twBufferReal,			//twiddle factor Real coeffs
	float *twBufferImag,			//twiddle factor Imag coeffs    
	unsigned int pCounter);
	
	
struct thd_data{

	float a;
	float b;
	float c;

}	;


float signal_thd(struct spectra h);


struct pvp_data{

	float a;
	float b;
	float c;

};

void pvp_filter(struct pvp_data in,struct pvp_data *in_back,struct pvp_data *out, struct pvp_data *out_back,float ts);
float pvp_post_filter(float rtInput,float *coeff, unsigned int coeffLength, float *zValues);


float peak_detect_rms(float rtInput, float *pData,unsigned int pDataCounter, unsigned int dataLength);


struct thermal_parameters{


	float Inom; // 0.1 to 4*Inom- def 1.1 k-factor*Inom_obj
	float k;
	float tau;
	float ts;
	unsigned int freeze;

};

float thermal_status(float rms,struct thermal_parameters therm, float mem);

struct  prefilt{
	
	float x;
	float y;

};

float prefilter(float x,struct prefilt *back);

float minSelector_3p(float a, float b, float c);
float maxSelector_3p(float a, float b, float c);



#endif
