#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "mlib_definitions.h"
#include "pDataConfigs.h"
#include "conversion.h"

volatile uint8_t conversion_completed=0;

volatile uint32_t cycle_count_1=0;
volatile uint32_t cycle_count_2=0;

union uAdc rawAdc={0};
union uAdc fAdc={0};



struct AdcData offset={0};
struct AdcData scale={0};

struct TurnRatios TR;

struct prefilter_oc_parameters oc[15]={0};

extern uint32_t adc_values[15];

float calc_offset=0;
enum AdcChannel ch=Van;


float averager();
void main_flow(void);





void init_conversion(){
	
	//Offset
	
	offset.Ia=2064.0f;//CTB4 2051.129f; 
	offset.Ib=2064.0f;//CTB4 2050.04f;
	offset.Ic=2064.0f;//CTB4 2050.65f;
	
	offset.Va_synch=2051.270f;
	
	offset.Vb_synch=2050.0f;
	offset.Vc_synch=2050.0f;
	offset.ITCR_ab=2050.0f;
	
	offset.ITCR_bc=2050.0f;
	offset.ITCR_ca=2050.0f;
	
	offset.Van=2048.936f;
	offset.Vbn=2050.661f;
	offset.Vcn=2050.0f;
	
	
	
	// Scale
	
	scale.Ia=0.055470985603544f;//0.055411955626188f;
	scale.Ib=0.055493895671476f;//0.055411955626188f;
	scale.Ic=0.055470985603544f;//0.055411955626188f;
	
	scale.Va_synch=0.005482456140351f;


	
	scale.ITCR_bc=0.055470985603544f;
	scale.ITCR_ca=0.055470985603544f;
	
	scale.Van=0.10699f;
	scale.Vbn=0.10699f;
	scale.Vcn=0.10699f;
	
	scale.Vb_synch=0.005502f; 
	scale.Vc_synch=0.005502f; 
	scale.ITCR_ab=0.055470985603544f; 
	
	
	TR.TCR=1000.0f;
	TR.VT_MV=345;
	TR.VT_HV=345;
	TR.CT=1000.0f;
	
}





void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	

	

if(hadc->Instance==ADC1){ 
	
	
	rawAdc.sAdc.Van=			prefilter_oc((adc_values[Van] -	offset.Van),&oc[Van])*scale.Van;
	rawAdc.sAdc.Ia=				prefilter_oc((adc_values[Ia] -	offset.Ia),&oc[Ia])*scale.Ia;
	rawAdc.sAdc.ITCR_bc=	prefilter_oc((adc_values[ITCR_bc] -	offset.Van),&oc[ITCR_bc])*scale.ITCR_bc;
	
	rawAdc.sAdc.Vbn=			prefilter_oc((adc_values[Vbn] -	offset.Vbn),&oc[Vbn])*scale.Vbn;
	rawAdc.sAdc.Ib=				prefilter_oc((adc_values[Ib] -	offset.Ib),&oc[Ib])*scale.Ib;
	rawAdc.sAdc.ITCR_ca=	prefilter_oc((adc_values[ITCR_ca] -	offset.ITCR_ca),&oc[ITCR_ca])*scale.ITCR_ca;
	
	rawAdc.sAdc.Vcn=			prefilter_oc((adc_values[Vcn] -	offset.Vcn),&oc[Vcn])*scale.Vcn;
	rawAdc.sAdc.Ic=				prefilter_oc((adc_values[Ic] -	offset.Ic),&oc[Ic])*scale.Ic;
	
	rawAdc.sAdc.Vb_synch=	prefilter_oc((adc_values[Vb_synch] -	offset.Vb_synch),&oc[Vb_synch])*scale.Vb_synch;
	rawAdc.sAdc.Va_synch=	prefilter_oc((adc_values[Va_synch] -	offset.Va_synch),&oc[Va_synch])*scale.Va_synch;
	
	rawAdc.sAdc.Vc_synch=	prefilter_oc((adc_values[Vc_synch] -	offset.Vc_synch),&oc[Vc_synch])*scale.Vc_synch;
	rawAdc.sAdc.ITCR_ab=	prefilter_oc((adc_values[ITCR_ab] -	offset.ITCR_ab),&oc[ITCR_ab])*scale.ITCR_ab;
	
	#if 0
	rawAdc.sAdc.Van=			(adc_values[Van]		-	offset.Van)			*scale.Van;
	rawAdc.sAdc.Ia=				(adc_values[Ia]			-	offset.Ia)			*scale.Ia;
	rawAdc.sAdc.ITCR_bc=		(adc_values[ITCR_bc]	-	offset.ITCR_bc)		*scale.ITCR_bc;
	
	rawAdc.sAdc.Vbn=			(adc_values[Vbn]-offset.Vbn)					*scale.Vbn;
	rawAdc.sAdc.Ib=				(adc_values[Ib]-offset.Ib)						*scale.Ib;
	rawAdc.sAdc.ITCR_ca=		(adc_values[ITCR_ca]-offset.ITCR_ca)			*scale.ITCR_ca;
	
	rawAdc.sAdc.Vcn=			(adc_values[Vcn]-offset.Vcn)					*scale.Vcn;
	rawAdc.sAdc.Ic=				(adc_values[Ic]-offset.Ic)						*scale.Ic;
	
	rawAdc.sAdc.Vb_synch=		(adc_values[Vb_synch]-offset.Vb_synch)			*scale.Vb_synch;
	rawAdc.sAdc.Va_synch=				(adc_values[In]-offset.Va_synch)						*scale.Va_synch;
	
	rawAdc.sAdc.Vc_synch=		(adc_values[Vc_synch]-offset.Vc_synch)			*scale.Vc_synch;
	rawAdc.sAdc.ITCR_ab=		(adc_values[ITCR_ab]-offset.ITCR_ab)			*scale.ITCR_ab;
	
	#endif	
	
	
	
	
	
	fAdc.sAdc.Ia=rawAdc.sAdc.Ia*TR.CT;
	fAdc.sAdc.Ib=rawAdc.sAdc.Ib*TR.CT;
	fAdc.sAdc.Ic=rawAdc.sAdc.Ic*TR.CT;
	
	fAdc.sAdc.Va_synch=rawAdc.sAdc.Va_synch*TR.VT_HV;
	fAdc.sAdc.Vb_synch=rawAdc.sAdc.Vb_synch*TR.VT_HV;
  fAdc.sAdc.Vc_synch=rawAdc.sAdc.Vc_synch*TR.VT_HV;
	
	fAdc.sAdc.ITCR_ab=rawAdc.sAdc.ITCR_ab*TR.TCR;
	fAdc.sAdc.ITCR_bc=rawAdc.sAdc.ITCR_bc*TR.TCR;
	fAdc.sAdc.ITCR_ca=rawAdc.sAdc.ITCR_ca*TR.TCR; 
	
	fAdc.sAdc.Van=rawAdc.sAdc.Van*TR.VT_MV;
	fAdc.sAdc.Vbn=rawAdc.sAdc.Vbn*TR.VT_MV;
	fAdc.sAdc.Vcn=rawAdc.sAdc.Vcn*TR.VT_MV;
	

	fAdc.sAdc.AB_synth=(fAdc.sAdc.Van-fAdc.sAdc.Vbn);
	fAdc.sAdc.BC_synth=(fAdc.sAdc.Vbn-fAdc.sAdc.Vcn);
	fAdc.sAdc.CA_synth=(fAdc.sAdc.Vcn-fAdc.sAdc.Van);
	
	fAdc.sAdc.ITCR_a=(fAdc.sAdc.ITCR_ab-fAdc.sAdc.ITCR_ca);
	fAdc.sAdc.ITCR_b=(fAdc.sAdc.ITCR_bc-fAdc.sAdc.ITCR_ab);
	fAdc.sAdc.ITCR_c=(fAdc.sAdc.ITCR_ca-fAdc.sAdc.ITCR_bc);
	
	fAdc.sAdc.ITCR_N=(fAdc.sAdc.ITCR_a+fAdc.sAdc.ITCR_b+fAdc.sAdc.ITCR_c);
	

	
	//fAdc=rawAdc;
	
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_SET);
	main_flow();
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_RESET);
	conversion_completed=1;	

	
	//HAL_GPIO_TogglePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin);	
	
	cycle_count_1++;
	
	//calc_offset= averager();
	
	
	}


}



float averager(){
	
	
	static uint32_t count=0;
	static float sum=0;
	static float x=0;
	
	sum+=fAdc.bufferAdc[ch];
	
	if(++count==12500){
	
		x=sum/12500.0f;
		sum=0;
		count=0;
	}
	
	return x;

}


