#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "measurement_functions.h"
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

extern uint32_t adc_values[15];

float calc_offset=0;
enum AdcChannel ch=Van;


float averager();
void main_flow(void);


struct prefilt pf_data[15]={0};


void init_conversion(){
	
	//Offset
	
	offset.Ia=2064.0f;//CTB4 2051.129f; 
	offset.Ib=2064.0f;//CTB4 2050.04f;
	offset.Ic=2064.0f;//CTB4 2050.65f;
	
	offset.In=2051.270f;
	
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
	
	scale.In=0.005482456140351f;


	
	scale.ITCR_bc=0.005507f;
	scale.ITCR_ca=0.005507f;
	
	scale.Van=0.10699f;
	scale.Vbn=0.10699f;
	scale.Vcn=0.10699f;
	
	scale.Vb_synch=0.005502f; 
	scale.Vc_synch=0.005502f; 
	scale.ITCR_ab=0.005502f; 
	
}





void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	

	

if(hadc->Instance==ADC1){ 
	
	
	rawAdc.sAdc.Van=	prefilter((adc_values[Van] -	offset.Van),&pf_data[Van])*scale.Van;
	rawAdc.sAdc.Ia=		prefilter((adc_values[Ia] -	offset.Ia),&pf_data[Ia])*scale.Ia;
	rawAdc.sAdc.ITCR_bc=prefilter((adc_values[ITCR_bc] -	offset.Van),&pf_data[ITCR_bc])*scale.ITCR_bc;
	
	rawAdc.sAdc.Vbn=	prefilter((adc_values[Vbn] -	offset.Vbn),&pf_data[Vbn])*scale.Vbn;
	rawAdc.sAdc.Ib=		prefilter((adc_values[Ib] -	offset.Ib),&pf_data[Ib])*scale.Ib;
	rawAdc.sAdc.ITCR_ca=prefilter((adc_values[ITCR_ca] -	offset.ITCR_ca),&pf_data[ITCR_ca])*scale.ITCR_ca;
	
	rawAdc.sAdc.Vcn=	prefilter((adc_values[Vcn] -	offset.Vcn),&pf_data[Vcn])*scale.Vcn;
	rawAdc.sAdc.Ic=		prefilter((adc_values[Ic] -	offset.Ic),&pf_data[Ic])*scale.Ic;
	
	rawAdc.sAdc.Vb_synch=prefilter((adc_values[Vb_synch] -	offset.Vb_synch),&pf_data[Vb_synch])*scale.Vb_synch;
	rawAdc.sAdc.In=		prefilter((adc_values[In] -	offset.In),&pf_data[In])*scale.In;
	
	rawAdc.sAdc.Vc_synch=prefilter((adc_values[Vc_synch] -	offset.Vc_synch),&pf_data[Vc_synch])*scale.Vc_synch;
	rawAdc.sAdc.ITCR_ab=prefilter((adc_values[ITCR_ab] -	offset.ITCR_ab),&pf_data[ITCR_ab])*scale.ITCR_ab;
	
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
	rawAdc.sAdc.In=				(adc_values[In]-offset.In)						*scale.In;
	
	rawAdc.sAdc.Vc_synch=		(adc_values[Vc_synch]-offset.Vc_synch)			*scale.Vc_synch;
	rawAdc.sAdc.ITCR_ab=		(adc_values[ITCR_ab]-offset.ITCR_ab)			*scale.ITCR_ab;
	
	#endif	
	
	
	
	fAdc.sAdc.Ia=rawAdc.sAdc.Ia*TR.CT;
	fAdc.sAdc.Ib=rawAdc.sAdc.Ib*TR.CT;
	fAdc.sAdc.Ic=rawAdc.sAdc.Ic*TR.CT;
	fAdc.sAdc.In=rawAdc.sAdc.In*TR.CT;
	
	fAdc.sAdc.Vb_synch=rawAdc.sAdc.Vb_synch*TR.RES;
  fAdc.sAdc.Vc_synch=rawAdc.sAdc.Vc_synch*TR.RES;
	fAdc.sAdc.ITCR_ab=rawAdc.sAdc.ITCR_ab*TR.RES;
	
	fAdc.sAdc.Van=rawAdc.sAdc.Van*TR.VT;
	fAdc.sAdc.Vbn=rawAdc.sAdc.Vbn*TR.VT;
	fAdc.sAdc.Vcn=rawAdc.sAdc.Vcn*TR.VT;
	
	fAdc.sAdc.ITCR_bc=rawAdc.sAdc.ITCR_bc*TR.UNB;
	fAdc.sAdc.ITCR_ca=rawAdc.sAdc.ITCR_ca*TR.UNB; 	
	
	fAdc.sAdc.AB_synth=(fAdc.sAdc.Van-fAdc.sAdc.Vbn);
	fAdc.sAdc.BC_synth=(fAdc.sAdc.Vbn-fAdc.sAdc.Vcn);
	fAdc.sAdc.CA_synth=(fAdc.sAdc.Vcn-fAdc.sAdc.Van);
	

	
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


