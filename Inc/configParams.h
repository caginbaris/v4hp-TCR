#ifndef __configParams_h
#define __configParams_h

#include "stdint.h"



//---------------DW0
union pFuncEnable{

	struct{
		
		uint32_t obj1_OverCurrentProteciton:1; 				//50-51-N
		uint32_t obj1_VoltageProtection:1;  					//27-59
		uint32_t obj1_NegativeSequenceProtection:1;  	//46
		uint32_t obj1_ThermalProtection:1;						//49
		uint32_t obj1_BreakerFailureProtection:1;			//BF
		uint32_t obj1_UnbalanceProtection:1;					//UNB
		uint32_t obj1_CapBankOverloadProtection:1;		//PVP
		uint32_t obj1_UnderCurrentProtection:1;				//37
		uint32_t obj1_DefiniteTimeOCProtection:1;			//50
		uint32_t obj1_InverseTimeOProtectionC:1;			//51
		uint32_t obj1_DefiniteTimeOCNProtection:1;		//50N
		uint32_t obj1_InverseTimeOCNProtection:1;			//51N
		uint32_t obj1_UnderVoltageProtection:1;				//27
		uint32_t obj1_OverVoltageProtection:1;				//59
		
		uint32_t spare1:1;															//
		uint32_t spare2:1;															//
		
		uint32_t obj2_OverCurrentProteciton:1; 				//50-51-N
		uint32_t obj2_VoltageProtection:1;  					//27-59
		uint32_t obj2_NegativeSequenceProtection:1;  	//46
		uint32_t obj2_ThermalProtection:1;						//49
		uint32_t obj2_BreakerFailureProtection:1;			//BF
		uint32_t obj2_UnbalanceProtection:1;					//UNB
		uint32_t obj2_CapBankOverloadProtection:1;		//PVP
		uint32_t obj2_UnderCurrentProtection:1;				//37
		uint32_t obj2_DefiniteTimeOCProtection:1;			//50
		uint32_t obj2_InverseTimeOProtectionC:1;			//51
		uint32_t obj2_DefiniteTimeOCNProtection:1;		//50N
		uint32_t obj2_InverseTimeOCNProtection:1;			//51N
		uint32_t obj2_UnderVoltageProtection:1;				//27
		uint32_t obj2_OverVoltageProtection:1;				//59
		
		uint32_t spare3:1;															//
		uint32_t spare4:1;															//
		
	
	}bit;
	
	uint32_t all;	


};



//0->true RMS
//---------------DW1
union mSelection{

	struct{
		
		uint32_t obj1_fc50_L1:1; 												//0
		uint32_t obj1_fc50_L2:1; 												//1
		uint32_t obj1_fc50_L3:1; 												//2
		
		uint32_t obj1_fc51:1; 													//3
		
		uint32_t obj1_fc50N_L1:1; 											//4
		uint32_t obj1_fc50N_L2:1; 											//5
		uint32_t obj1_fc50N_L3:1; 											//6
		
		uint32_t obj1_fc51N:1; 													//7
		
		uint32_t spare1:1;															//
		uint32_t spare2:1;															//
		uint32_t spare3:1;															//
		uint32_t spare4:1;															//
		uint32_t spare5:1;															//

		
		uint32_t obj2_fc50_L1:1; 												//Don't Care
		uint32_t obj2_fc50_L2:1; 												//..
		uint32_t obj2_fc50_L3:1; 												//..
		
		uint32_t obj2_fc51:1; 													//..
		
		uint32_t obj2_fc50N_L1:1; 											//..
		uint32_t obj2_fc50N_L2:1; 											//..
		uint32_t obj2_fc50N_L3:1; 											//..
		
	
		
	
		
	
	}bit;
	
	uint32_t all;	


};


//---------------DW2
union cSelection1{

	struct{
		
		//51
		
		uint32_t obj1_fc51_IEC_NormalInverse:1;
		uint32_t obj1_fc51_IEC_VeryInverse:1;
		uint32_t obj1_fc51_IEC_ExtremelyInverse:1;
		uint32_t obj1_fc51_IEC_LongInverse:1;
		
		uint32_t obj1_fc51_ANSI_NormalInverse:1;
		uint32_t obj1_fc51_ANSI_VeryInverse:1;
		uint32_t obj1_fc51_ANSI_ExtremelyInverse:1;
		uint32_t obj1_fc51_ANSI_LongInverse:1;
		
		//51N
		
		uint32_t obj1_fc51N_IEC_NormalInverse:1;
		uint32_t obj1_fc51N_IEC_VeryInverse:1;
		uint32_t obj1_fc51N_IEC_ExtremelyInverse:1;
		uint32_t obj1_fc51N_IEC_LongInverse:1;
		
		uint32_t obj1_fc51N_ANSI_NormalInverse:1;
		uint32_t obj1_fc51N_ANSI_VeryInverse:1;
		uint32_t obj1_fc51N_ANSI_ExtremelyInverse:1;
		uint32_t obj1_fc51N_ANSI_LongInverse:1;
		
		//46
		
		uint32_t obj1_fc46_IEC_NormalInverse:1;
		uint32_t obj1_fc46_IEC_VeryInverse:1;
		uint32_t obj1_fc46_IEC_ExtremelyInverse:1;
		uint32_t obj1_fc46_IEC_LongInverse:1;
		
		uint32_t obj1_fc46_ANSI_NormalInverse:1;
		uint32_t obj1_fc46_ANSI_VeryInverse:1;
		uint32_t obj1_fc46_ANSI_ExtremelyInverse:1;
		uint32_t obj1_fc46_ANSI_LongInverse:1;
		
		//UNB dont care
		
		uint32_t obj1_fcUNB_IEC_NormalInverse:1;
		uint32_t obj1_fcUNB_IEC_VeryInverse:1;
		uint32_t obj1_fcUNB_IEC_ExtremelyInverse:1;
		uint32_t obj1_fcUNB_IEC_LongInverse:1;
		
		uint32_t obj1_fcUNB_ANSI_NormalInverse:1;
		uint32_t obj1_fcUNB_ANSI_VeryInverse:1;
		uint32_t obj1_fcUNB_ANSI_ExtremelyInverse:1;
		uint32_t obj1_fcUNB_ANSI_LongInverse:1;
		
	
	}bit;
	
	uint32_t all;	
};

//---------------DW3
union cSelection2{

	struct{
		
		//PVP
		
		uint32_t obj1_fcPVP_IEC_NormalInverse:1;
		uint32_t obj1_fcPVP_IEC_VeryInverse:1;
		uint32_t obj1_fcPVP_IEC_ExtremelyInverse:1;
		uint32_t obj1_fcPVP_IEC_LongInverse:1;
		
		uint32_t obj1_fcPVP_ANSI_NormalInverse:1;
		uint32_t obj1_fcPVP_ANSI_VeryInverse:1;
		uint32_t obj1_fcPVP_ANSI_ExtremelyInverse:1;
		uint32_t obj1_fcPVP_ANSI_LongInverse:1;
		
		//51
		
		uint32_t obj2_fc51_IEC_NormalInverse:1;
		uint32_t obj2_fc51_IEC_VeryInverse:1;
		uint32_t obj2_fc51_IEC_ExtremelyInverse:1;
		uint32_t obj2_fc51_IEC_LongInverse:1;
		
		uint32_t obj2_fc51_ANSI_NormalInverse:1;
		uint32_t obj2_fc51_ANSI_VeryInverse:1;
		uint32_t obj2_fc51_ANSI_ExtremelyInverse:1;
		uint32_t obj2_fc51_ANSI_LongInverse:1;
		
		//51N
		
		uint32_t obj2_fc51N_IEC_NormalInverse:1;
		uint32_t obj2_fc51N_IEC_VeryInverse:1;
		uint32_t obj2_fc51N_IEC_ExtremelyInverse:1;
		uint32_t obj2_fc51N_IEC_LongInverse:1;
		
		uint32_t obj2_fc51N_ANSI_NormalInverse:1;
		uint32_t obj2_fc51N_ANSI_VeryInverse:1;
		uint32_t obj2_fc51N_ANSI_ExtremelyInverse:1;
		uint32_t obj2_fc51N_ANSI_LongInverse:1;
		

		uint32_t spare1:1;
		uint32_t spare2:1;
		uint32_t spare3:1;
		uint32_t spare4:1;
		uint32_t spare5:1;
		uint32_t spare6:1;
		uint32_t spare7:1;
		uint32_t spare8:1;

	
	}bit;
	
	uint32_t all;	
};


//---------------DW4
union pFlags{

	struct{
		
		
		
		uint32_t phaseRotation:1;
		uint32_t fc27_currentSupervision:1;
		uint32_t fcBF_cbSupervision:1;
		uint32_t spare1:1;
		uint32_t naturalUNBdetect:1;
		uint32_t naturalUNBcomp:1;
		uint32_t spare2:26;
	
	}bit;
	
	uint32_t all;	
};













#endif