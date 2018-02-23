
#ifndef POWERSYSDATA_H
#define POWERSYSDATA_H

#include <stdint.h>

struct PowerSysData{
	
	
	float I_Nom_obj1;          
	float I_Nom_obj2;		 
  float I_BreakerClosed_MIN;            //fc27,fcBF
	float Q_TCR;
	float Q_HF2;
	float Q_HF3;
	float Q_HF4;		
	float Rvalue;
	
	uint32_t phaseRotation:1;	
	uint32_t fc27_currentSupervision:1;				//fc27
	uint32_t fcBF_CBSupervision:1;							//fcBF

	uint32_t spare:1;	
	
	uint32_t UNBdetect:1;
	uint32_t UNBcompFlag:1;
	
	

	


};

extern struct PowerSysData Sys;







#endif


