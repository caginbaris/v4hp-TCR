#include "measurement_functions.h"
#include "nfbm.h"

#define rmsChannelNo 20
#define bufferLength 50

struct AdcData tRMS={0};
union uAdc  backRMS={0};
float bufferRMS[rmsChannelNo][bufferLength]={0};


void trueRMS(void){

	static uint8_t counter=0; 
	

	backRMS.sAdc.Van=true_rms(fAdc.sAdc.Van ,&bufferRMS[Van][0],counter,bufferLength);
	backRMS.sAdc.Vbn=true_rms(fAdc.sAdc.Vbn ,&bufferRMS[Vbn][0],counter,bufferLength);
	backRMS.sAdc.Vcn=true_rms(fAdc.sAdc.Vcn ,&bufferRMS[Vcn][0],counter,bufferLength);
	
	backRMS.sAdc.AB_synth=true_rms(fAdc.sAdc.AB_synth ,&bufferRMS[Vab][0],counter,bufferLength);
	backRMS.sAdc.BC_synth=true_rms(fAdc.sAdc.BC_synth ,&bufferRMS[Vbc][0],counter,bufferLength);
	backRMS.sAdc.CA_synth=true_rms(fAdc.sAdc.CA_synth ,&bufferRMS[Vca][0],counter,bufferLength);

	backRMS.sAdc.Ia=true_rms(fAdc.sAdc.Ia,&bufferRMS[Ia][0],counter,bufferLength);
	backRMS.sAdc.Ib=true_rms(fAdc.sAdc.Ib,&bufferRMS[Ib][0],counter,bufferLength);
	backRMS.sAdc.Ic=true_rms(fAdc.sAdc.Ic,&bufferRMS[Ic][0],counter,bufferLength);
	
	backRMS.sAdc.Va_synch=true_rms(fAdc.sAdc.Va_synch,&bufferRMS[Va_synch][0],counter,bufferLength);
	backRMS.sAdc.Vb_synch=true_rms(fAdc.sAdc.Vb_synch,&bufferRMS[Vb_synch][0],counter,bufferLength);
	backRMS.sAdc.Vc_synch=true_rms(fAdc.sAdc.Vc_synch,&bufferRMS[Vc_synch][0],counter,bufferLength);
	
	backRMS.sAdc.ITCR_ab=true_rms(fAdc.sAdc.ITCR_ab,&bufferRMS[ITCR_ab][0],counter,bufferLength);
	backRMS.sAdc.ITCR_bc=true_rms(fAdc.sAdc.ITCR_bc,&bufferRMS[ITCR_bc][0],counter,bufferLength);
	backRMS.sAdc.ITCR_ca=true_rms(fAdc.sAdc.ITCR_ca,&bufferRMS[ITCR_ca][0],counter,bufferLength);
	
	backRMS.sAdc.ITCR_a=true_rms(fAdc.sAdc.ITCR_a,&bufferRMS[ITCR_a][0],counter,bufferLength);
	backRMS.sAdc.ITCR_b=true_rms(fAdc.sAdc.ITCR_b,&bufferRMS[ITCR_b][0],counter,bufferLength);
	backRMS.sAdc.ITCR_c=true_rms(fAdc.sAdc.ITCR_c,&bufferRMS[ITCR_c][0],counter,bufferLength);
	
	backRMS.sAdc.ITCR_N=true_rms(fAdc.sAdc.ITCR_N,&bufferRMS[ITCR_N][0],counter,bufferLength);
	
	
	if(++counter==bufferLength){counter=0;}
	
	tRMS=backRMS.sAdc;
		
	
}



