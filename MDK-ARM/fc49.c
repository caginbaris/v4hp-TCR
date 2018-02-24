#include "nfbm.h"
#include "plib_definitions.h"
#include "measurement_functions.h"
#include "powerSysData.h"


struct thermal_parameters fc49_obj1_therm;
struct thermal_parameters fc49_obj2_therm;

struct fc49_inputParameters fc49_obj1_L1_in;
struct fc49_inputParameters fc49_obj1_L2_in; // cau-omitted

struct fc49_inputParameters fc49_obj2_L1_in;
struct fc49_inputParameters fc49_obj2_L2_in; // cau-omitted


struct fc49_outputParameters fc49_obj1_L1_out_a={0};
struct fc49_outputParameters fc49_obj1_L1_out_b={0};
struct fc49_outputParameters fc49_obj1_L1_out_c={0};

//struct fc49_outputParameters fc49_obj1_L2_out_a={0};
//struct fc49_outputParameters fc49_obj1_L2_out_b={0};
//struct fc49_outputParameters fc49_obj1_L2_out_c={0};

struct fc49_outputParameters fc49_obj2_L1_out_a={0};
struct fc49_outputParameters fc49_obj2_L1_out_b={0};
struct fc49_outputParameters fc49_obj2_L1_out_c={0};

//struct fc49_outputParameters fc49_obj2_L2_out_a={0};
//struct fc49_outputParameters fc49_obj2_L2_out_b={0};
//struct fc49_outputParameters fc49_obj2_L2_out_c={0};


float therm_a_obj1=0;
float therm_b_obj1=0;
float therm_c_obj1=0;
	
float therm_a_obj2=0;
float therm_b_obj2=0;
float therm_c_obj2=0;




void fc49_init(){
	
	struct thermal_parameters fc49_therm_initStruct={ 1.0f,/*Inom*/
																										1.1, /*k*/	
																										10.0f,/*tau in*/
																										0.0004f,/*ts*/				
																										0 /*freeze*/	};
	
	struct fc49_inputParameters fc49_initStruct={ 0.777f,/*alarm level*/		};
	
	fc49_obj1_therm=fc49_therm_initStruct;
	fc49_obj2_therm=fc49_therm_initStruct;	
																								

	fc49_obj1_therm.Inom=Sys.I_Nom_obj1;
	fc49_obj2_therm.Inom=Sys.I_Nom_obj2;
																								
																								
	fc49_obj1_L1_in=fc49_initStruct;
	//fc49_obj1_L2_in=fc49_initStruct;
																								
	fc49_obj2_L1_in=fc49_initStruct;
	//fc49_obj2_L2_in=fc49_initStruct;
																								
																																												
						

}



void fc49_all(){
	

	
	
	therm_a_obj1=thermal_status(tRMS.ITCR_ab,fc49_obj1_therm,therm_a_obj1);
	therm_b_obj1=thermal_status(tRMS.ITCR_bc,fc49_obj1_therm,therm_b_obj1);
	therm_c_obj1=thermal_status(tRMS.ITCR_ca,fc49_obj1_therm,therm_c_obj1);
	
	
	//obj1
	
	fc49(therm_a_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_a,EN.bits.fc49_obj1_L1);
	fc49(therm_b_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_b,EN.bits.fc49_obj1_L1);
	fc49(therm_c_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_c,EN.bits.fc49_obj1_L1);
	



}


