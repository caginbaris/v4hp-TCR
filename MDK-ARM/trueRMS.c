#include "measurement_functions.h"
#include "nfbm.h"

#define rmsChannelNo 15
#define bufferLength 50

struct AdcData tRMS={0};
union uAdc  backRMS={0};
float bufferRMS[rmsChannelNo][bufferLength]={0};


void trueRMS(void){

	static uint8_t counter=0; 
	

	
	backRMS.sAdc.AB_synth=true_rms(fAdc.sAdc.AB_synth ,&bufferRMS[Vab][0],counter,bufferLength);
	backRMS.sAdc.BC_synth=true_rms(fAdc.sAdc.BC_synth ,&bufferRMS[Vbc][0],counter,bufferLength);
	backRMS.sAdc.CA_synth=true_rms(fAdc.sAdc.CA_synth ,&bufferRMS[Vca][0],counter,bufferLength);

	backRMS.sAdc.Ia=true_rms(fAdc.sAdc.Ia,&bufferRMS[Ia][0],counter,bufferLength);
	backRMS.sAdc.Ib=true_rms(fAdc.sAdc.Ib,&bufferRMS[Ib][0],counter,bufferLength);
	backRMS.sAdc.Ic=true_rms(fAdc.sAdc.Ic,&bufferRMS[Ic][0],counter,bufferLength);
	backRMS.sAdc.In=true_rms(fAdc.sAdc.In,&bufferRMS[In][0],counter,bufferLength);
	
	backRMS.sAdc.IRESa=true_rms(fAdc.sAdc.IRESa,&bufferRMS[IRESa][0],counter,bufferLength);
	backRMS.sAdc.IRESb=true_rms(fAdc.sAdc.IRESb,&bufferRMS[IRESb][0],counter,bufferLength);
	backRMS.sAdc.IRESc=true_rms(fAdc.sAdc.IRESc,&bufferRMS[IRESc][0],counter,bufferLength);
	
	backRMS.sAdc.IUNBa =true_rms(fAdc.sAdc.IUNBa,&bufferRMS[IUNBa][0],counter,bufferLength);
	backRMS.sAdc.IUNBb =true_rms(fAdc.sAdc.IUNBb,&bufferRMS[IUNBb][0],counter,bufferLength);
	
	
	if(++counter==bufferLength){counter=0;}
	
	tRMS=backRMS.sAdc;
		
	
}



