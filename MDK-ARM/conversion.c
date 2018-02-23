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
	
	offset.IRESa=2050.0f;
	offset.IRESb=2050.0f;
	offset.IRESc=2050.0f;
	
	offset.IUNBa=2050.0f;
	offset.IUNBb=2050.0f;
	
	offset.Van=2048.936f;
	offset.Vbn=2050.661f;
	offset.Vcn=2050.0f;
	
	
	
	// Scale
	
	scale.Ia=0.055470985603544f;//0.055411955626188f;
	scale.Ib=0.055493895671476f;//0.055411955626188f;
	scale.Ic=0.055470985603544f;//0.055411955626188f;
	
	scale.In=0.005482456140351f;


	
	scale.IUNBa=0.005507f;
	scale.IUNBb=0.005507f;
	
	scale.Van=0.10699f;
	scale.Vbn=0.10699f;
	scale.Vcn=0.10699f;
	
	scale.IRESa=0.005502f; 
	scale.IRESb=0.005502f; 
	scale.IRESc=0.005502f; 
	
}





void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	

	

if(hadc->Instance==ADC1){ 
	
	
	rawAdc.sAdc.Van=	prefilter((adc_values[Van] -	offset.Van),&pf_data[Van])*scale.Van;
	rawAdc.sAdc.Ia=		prefilter((adc_values[Ia] -	offset.Ia),&pf_data[Ia])*scale.Ia;
	rawAdc.sAdc.IUNBa=prefilter((adc_values[IUNBa] -	offset.Van),&pf_data[IUNBa])*scale.IUNBa;
	
	rawAdc.sAdc.Vbn=	prefilter((adc_values[Vbn] -	offset.Vbn),&pf_data[Vbn])*scale.Vbn;
	rawAdc.sAdc.Ib=		prefilter((adc_values[Ib] -	offset.Ib),&pf_data[Ib])*scale.Ib;
	rawAdc.sAdc.IUNBb=prefilter((adc_values[IUNBb] -	offset.IUNBb),&pf_data[IUNBb])*scale.IUNBb;
	
	rawAdc.sAdc.Vcn=	prefilter((adc_values[Vcn] -	offset.Vcn),&pf_data[Vcn])*scale.Vcn;
	rawAdc.sAdc.Ic=		prefilter((adc_values[Ic] -	offset.Ic),&pf_data[Ic])*scale.Ic;
	
	rawAdc.sAdc.IRESa=prefilter((adc_values[IRESa] -	offset.IRESa),&pf_data[IRESa])*scale.IRESa;
	rawAdc.sAdc.In=		prefilter((adc_values[In] -	offset.In),&pf_data[In])*scale.In;
	
	rawAdc.sAdc.IRESb=prefilter((adc_values[IRESb] -	offset.IRESb),&pf_data[IRESb])*scale.IRESb;
	rawAdc.sAdc.IRESc=prefilter((adc_values[IRESc] -	offset.IRESc),&pf_data[IRESc])*scale.IRESc;
	
	#if 0
	rawAdc.sAdc.Van=			(adc_values[Van]		-	offset.Van)			*scale.Van;
	rawAdc.sAdc.Ia=				(adc_values[Ia]			-	offset.Ia)			*scale.Ia;
	rawAdc.sAdc.IUNBa=		(adc_values[IUNBa]	-	offset.IUNBa)		*scale.IUNBa;
	
	rawAdc.sAdc.Vbn=			(adc_values[Vbn]-offset.Vbn)					*scale.Vbn;
	rawAdc.sAdc.Ib=				(adc_values[Ib]-offset.Ib)						*scale.Ib;
	rawAdc.sAdc.IUNBb=		(adc_values[IUNBb]-offset.IUNBb)			*scale.IUNBb;
	
	rawAdc.sAdc.Vcn=			(adc_values[Vcn]-offset.Vcn)					*scale.Vcn;
	rawAdc.sAdc.Ic=				(adc_values[Ic]-offset.Ic)						*scale.Ic;
	
	rawAdc.sAdc.IRESa=		(adc_values[IRESa]-offset.IRESa)			*scale.IRESa;
	rawAdc.sAdc.In=				(adc_values[In]-offset.In)						*scale.In;
	
	rawAdc.sAdc.IRESb=		(adc_values[IRESb]-offset.IRESb)			*scale.IRESb;
	rawAdc.sAdc.IRESc=		(adc_values[IRESc]-offset.IRESc)			*scale.IRESc;
	
	#endif	
	
	
	
	fAdc.sAdc.Ia=rawAdc.sAdc.Ia*TR.CT;
	fAdc.sAdc.Ib=rawAdc.sAdc.Ib*TR.CT;
	fAdc.sAdc.Ic=rawAdc.sAdc.Ic*TR.CT;
	fAdc.sAdc.In=rawAdc.sAdc.In*TR.CT;
	
	fAdc.sAdc.IRESa=rawAdc.sAdc.IRESa*TR.RES;
  fAdc.sAdc.IRESb=rawAdc.sAdc.IRESb*TR.RES;
	fAdc.sAdc.IRESc=rawAdc.sAdc.IRESc*TR.RES;
	
	fAdc.sAdc.Van=rawAdc.sAdc.Van*TR.VT;
	fAdc.sAdc.Vbn=rawAdc.sAdc.Vbn*TR.VT;
	fAdc.sAdc.Vcn=rawAdc.sAdc.Vcn*TR.VT;
	
	fAdc.sAdc.IUNBa=rawAdc.sAdc.IUNBa*TR.UNB;
	fAdc.sAdc.IUNBb=rawAdc.sAdc.IUNBb*TR.UNB; 	
	
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


