

#include <math.h>
#include "mlib_constants.h"
#include "mlib_definitions.h"


// function-1
// True RMS half cycle
// delayLineArray contains half period circular data of input
// delayLineCounter global counter for true rms calculation
// length of delayLineArray - mult. inverse can be u

float true_rms(float rtInput, float *delayLineArray, unsigned int delayLineCounter, unsigned int arrayLength)
{


	unsigned int i;
	float rms = 0, rms_sum = 0, rms_data=0;

	rms_sum = 0;

	*(delayLineArray+delayLineCounter) = rtInput;

	for (i = 0; i < arrayLength; i++)
	{
			
		rms_data=*delayLineArray ++;
		rms_sum = rms_sum + rms_data*rms_data;
		

	}

	rms = sqrt(rms_sum / arrayLength);

	return rms;

}



// function-2
// cs element generation
//cos->c, sin->s
//fs:2.5/5 e3... and scale value should be considered

float cs_generation(float rtInput,float *coeff, unsigned int coeffLength, float *zValues){

	unsigned int i;
     float *z1_ptr,*z2_ptr,*coeff_ptr;
     float output;

	z1_ptr=zValues; 		//background data
	z2_ptr=z1_ptr; 		//data update
	coeff_ptr=coeff+coeffLength-1;  //last element


	output=(*z1_ptr++) *(*coeff_ptr--);

	for(i=2;i<coeffLength;i++){
	
	*z2_ptr++ =*z1_ptr;
	output+=(*z1_ptr++) *(*coeff_ptr--);

	}


	output+=rtInput *(*coeff_ptr);
	*z2_ptr=rtInput;

	return(output);

}

//function-3
void cs_computations(struct phase_cs_in p_in, struct phase_cs_out *p_out ){

	
   	p_out->rms_V2 =(p_in.Vc)*(p_in.Vc) + (p_in.Vs)*(p_in.Vs);
    p_out->rms_I2 =(p_in.Ic)*(p_in.Ic) + (p_in.Is)*(p_in.Is);

   p_out->rms_V =sqrt((p_in.Vc)*(p_in.Vc) + (p_in.Vs)*(p_in.Vs))*isqrt2;
   p_out->rms_I =sqrt((p_in.Ic)*(p_in.Ic) + (p_in.Is)*(p_in.Is))*isqrt2;

	p_out->P= _i2*((p_in.Vc)*(p_in.Ic) +(p_in.Vs)*(p_in.Is));
	p_out->Q=_i2*((p_in.Vs)*(p_in.Ic) -(p_in.Vc)*(p_in.Is));


	if(p_out->rms_I2>1.0f){

	p_out->X=2.0f*(p_out->Q/p_out->rms_I2);
	p_out->R=2.0f*(p_out->P/p_out->rms_I2);
	
	}


	p_out->phase_V= -atan2(p_in.Vc,p_in.Vs)+pi;
	p_out->phase_I= -atan2(p_in.Ic,p_in.Is)+pi;

	p_out->phase_disp=p_out->phase_I-p_out->phase_V;

	if(p_out->phase_disp<0)	{p_out->phase_disp=p_out->phase_disp+_2pi;}
	if(p_out->phase_disp>pi)	{p_out->phase_disp=p_out->phase_disp-_2pi;}

     
	


}


//function-4


void sym_comp(struct phase_cs_in pa, struct phase_cs_in pb,struct phase_cs_in pc,struct sym_out*sym){

	float temp_r,temp_i;

	temp_r=pa.Vc + pb.Vc*sym_r +   pc.Vc*sym_r;
	temp_i=pb.Vs*sym_i - pc.Vs*sym_i;
	
	sym->V0  =(pa.Vc + pb.Vc + 	pc.Vc)*sym_i3;
	sym->V1  =(temp_r - temp_i)*sym_i3;
	sym->V2 =(temp_r + temp_i)*sym_i3;


	temp_r=pa.Ic + pb.Ic*sym_r +   pc.Ic*sym_r;
	temp_i=pb.Is*sym_i - pc.Is*sym_i;

	sym->I0  =(pa.Ic + pb.Ic + 	pc.Ic)*sym_i3;
	sym->I1  =(temp_r -   temp_i)*sym_i3;
	sym->I2 =(temp_r +   temp_i)*sym_i3;
	
	
	}


//function-5

void sym_mag(struct sym_out sym, struct sym_out *sym_back, struct sym_out *sym_rms  ){

	float temp;

	temp = -(sym.V0-sym_back->V0)*sym_rms_scale;
	sym_rms->V0=sqrtf(temp*temp+sym.V0*sym.V0)*isqrt2;
	sym_back->V0=sym.V0;

	temp = -(sym.V1-sym_back->V1)*sym_rms_scale;
	sym_rms->V1=sqrtf(temp*temp+sym.V1*sym.V1)*isqrt2;
	sym_back->V1=sym.V1;

	temp = -(sym.V2-sym_back->V2)*sym_rms_scale;
	sym_rms->V2=sqrtf(temp*temp+sym.V2*sym.V2)*isqrt2;;
	sym_back->V2=sym.V2;


	temp =- (sym.I0-sym_back->I0)*sym_rms_scale;
	sym_rms->I0=sqrtf(temp*temp+sym.I0*sym.I0)*isqrt2;;
	sym_back->I0=sym.I0;

	temp = -(sym.I1-sym_back->I1)*sym_rms_scale;
	sym_rms->I1=sqrtf(temp*temp+sym.I1*sym.I1)*isqrt2;;
	sym_back->I1=sym.I1;

	temp = -(sym.I2-sym_back->I2)*sym_rms_scale;
	sym_rms->I2=sqrtf(temp*temp+sym.I2*sym.I2)*isqrt2;;
	sym_back->I2=sym.I2;


}


// function-6
//spectral analysis
// caution: input structure has to be initialized and used only once
// external pCounter is needed
//twfactors truncated to 13th
 


void signal_spectra(
	
	float rtInput, 
	struct spectra *h,
	unsigned int qBufferLength,	//updated buffer length
	float *twBufferReal,			//twiddle factor Real coeffs
	float *twBufferImag,			//twiddle factor Imag coeffs    
	unsigned int pCounter)

{

	float x_error;
	float temp_real,temp_imag;
	float out_scale;
	unsigned int i;

	out_scale=sqrt2/(float)qBufferLength;


	x_error=h->qBuffer[pCounter]-rtInput;
	h->qBuffer[pCounter]=rtInput;

	for(i=0;i<14;i++){

	temp_real =twBufferReal[i]* (h->foutReal[i]+x_error)-twBufferImag[i]*h->foutImag[i];
	temp_imag=twBufferImag[i]* (h->foutReal[i]+x_error)+twBufferReal[i]*h->foutImag[i];

	h->foutMag[i]=out_scale*sqrtf(temp_real*temp_real+temp_imag*temp_imag);

	h->foutReal[i]=temp_real;
	h->foutImag[i]=temp_imag;
	
	}


}

// function-7
//thd calculation
float signal_thd(struct spectra h){

	unsigned int i;
	float hsum=0.0f,thd=0.0f;

	thd=0.0f;
	hsum=0.0f;

	if(h.foutMag[1]>1.0f){
	
		for(i=2;i<14;i++){hsum+=h.foutMag[i]*h.foutMag[i];}
		
		thd=100.0f*sqrtf(hsum)/h.foutMag[1];

	}else{

		thd=0.0f;
	
	}

	return thd;

}


//function 7
//pvp filtering

void pvp_filter(struct pvp_data in,struct pvp_data *in_back,struct pvp_data *out, struct pvp_data *out_back,float ts){

out->a=out_back->a + (in.a +in_back->a)*_i2*ts;
in_back->a=in.a;
out_back->a=out->a;

out->b=out_back->b + (in.b +in_back->b)*_i2*ts;
in_back->b=in.b;
out_back->b=out->b;

out->c=out_back->c + (in.c +in_back->c)*_i2*ts;
in_back->c=in.c;
out_back->c=out->c;

}


//function 8
//pvp postfiltering

float pvp_post_filter(float rtInput,float *coeff, unsigned int coeffLength, float *zValues){

	unsigned int i;
     float *z1_ptr,*z2_ptr,*coeff_ptr;
     float output;

	z1_ptr=zValues; 		//background data
	z2_ptr=z1_ptr; 		//data update
	coeff_ptr=coeff+coeffLength-1;  //last element


	output=(*z1_ptr++) *(*coeff_ptr--);

	for(i=2;i<coeffLength;i++){
	
	*z2_ptr++ =*z1_ptr;
	output+=(*z1_ptr++) *(*coeff_ptr--);

	}


	output+=rtInput *(*coeff_ptr);
	*z2_ptr=rtInput;

	return(output);

}


//function 9
//rms from peak detect for pvp

float peak_detect_rms(float rtInput, float *pData,unsigned int pDataCounter, unsigned int dataLength){


	unsigned int i=0;
	float p_peak=0;
	float n_peak=0;


	*(pData+pDataCounter) = rtInput;
	

	for (i=0;i<dataLength;i++){
		
		if(pData[i]>p_peak){p_peak=pData[i];}
		if(pData[i]<n_peak){n_peak=pData[i];}
		
	}

	return (p_peak-n_peak)*pn_rms_scale;

}

//function 10
//thermal comp.

float thermal_status(float rms,struct thermal_parameters therm, float mem)
{

	float temp;
	float t_constant;

	if(therm.tau>1.0f) {t_constant = therm.ts / therm.tau;}else{t_constant=0.0f;}

	if (therm.freeze == 0)
	{
		if(therm.Inom * therm.k>1.0f) {
			
		temp = t_constant * (rms*rms) / (therm.Inom * therm.Inom * therm.k * therm.k) + mem * (1.0f - t_constant);
			
		}
	}
	else{
		
		temp = mem;
	}

	mem = temp;

	return temp;

}



float prefilter(float x,struct prefilt *back){
	
		float y;
	
		y = (x-back->x)*b_pf +back->y*a_pf;
		back->y=y;
		back->x=x;
	
		return y;
	
}














