#include "nfbm.h"
#include "plib_definitions.h"
#include "pDataConfigs.h"


union pFunctionEnable EN;
union cSelection1 cSelect1;
union cSelection2 cSelect2;
enum  curve_entry curve=IEC_normal_inverse;

float curve_data[8][3]={
	
	{ 0.14f, 0.02f , 0.0f}, 					// IEC Normal Inverse
	{13.5f,  1.0f  , 0.0f},						// IEC Very Inverse
	{80.0f,  2.0f  , 0.0f},						// IEC Extremely Inverse
	{120.0f, 1.0f  , 0.0f},						// IEC Long IInverse
	
	{ 8.9341f, 2.02938f , 0.17966f}, 	// ANSI Normal Inverse
	{ 3.922f,  2.0f 		, 0.0982f}, 	// ANSI Very Inverse
	{ 5.64f,   2.0f 		, 0.02434f}, 	// ANSI Extremely Inverse	
	{ 5.6143f, 1.0f 		, 2.18592f}, 	// ANSI Long Inverse
	
};


void init_protection(void){
	
	
	/*Enable Handling*/
	
	// cau EN all is not changing acc. to bit value 
	
	// fc50 
	
		EN.bits.fc50_obj1_L1= pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50s &
												(fc50_obj1_L1_in.level>eps) &
												(fc50_obj1_L1_in.delay>eps);
																								
		EN.bits.fc50_obj1_L2= pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50s &
												(fc50_obj1_L2_in.level>eps) &
												(fc50_obj1_L2_in.delay>eps);										
												
		EN.bits.fc50_obj1_L3= pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50s &
												(fc50_obj1_L3_in.level>eps) &
												(fc50_obj1_L3_in.delay>eps);


		EN.bits.fc50_obj2_L1= pEN.bit.obj2_50_51_N &
													pEN.bit.obj2_50s &
												(fc50_obj2_L1_in.level>eps) &
												(fc50_obj2_L1_in.delay>eps);
																								
		EN.bits.fc50_obj2_L2= pEN.bit.obj2_50_51_N &
													pEN.bit.obj2_50s &
												(fc50_obj2_L2_in.level>eps) &
												(fc50_obj2_L2_in.delay>eps);										
												
		EN.bits.fc50_obj2_L3= pEN.bit.obj2_50_51_N &
													pEN.bit.obj2_50s &
												(fc50_obj2_L3_in.level>eps) &
												(fc50_obj2_L3_in.delay>eps);
												
	//fc51	
	
		EN.bits.fc51_obj1= 	  pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_51s &
												(fc51_obj1_in.level>eps) &
												(fc51_obj1_in.time_multiplier>eps);
												
		EN.bits.fc51_obj2= 	  pEN.bit.obj2_50_51_N &
													pEN.bit.obj2_51s &
												(fc51_obj2_in.level>eps) &
												(fc51_obj2_in.time_multiplier>eps);											
												
												
	// fc50N
	
		EN.bits.fc50N_obj1_L1= 	pEN.bit.obj1_50_51_N &
														pEN.bit.obj1_50Ns &
													(fc50N_obj1_L1_in.level>eps) &
													(fc50N_obj1_L1_in.delay>eps);
																								
		EN.bits.fc50N_obj1_L2= 	pEN.bit.obj1_50_51_N &
														pEN.bit.obj1_50Ns &
													(fc50N_obj1_L2_in.level>eps) &
													(fc50N_obj1_L2_in.delay>eps);										
												
		EN.bits.fc50N_obj1_L3= 	pEN.bit.obj1_50_51_N &
														pEN.bit.obj1_50s &
													(fc50N_obj1_L3_in.level>eps) &
													(fc50N_obj1_L3_in.delay>eps);		

	// fc51N
	
		EN.bits.fc51N_obj1= 	  pEN.bit.obj1_50_51_N &
														pEN.bit.obj1_51Ns &
													(fc51N_obj1_in.level>eps) &
													(fc51N_obj1_in.time_multiplier>eps);
	
	
	// fc27
	
		EN.bits.fc27_obj1_L1=   pEN.bit.obj1_27_59 &
														pEN.bit.obj1_27 &
													(fc27_obj1_L1_in.level>eps) &
													(fc27_obj1_L1_in.delay>eps);

		EN.bits.fc27_obj1_L2=   pEN.bit.obj1_27_59 &
														pEN.bit.obj1_27 &
													(fc27_obj1_L2_in.level>eps) &
													(fc27_obj1_L2_in.delay>eps);


	// fc59
	
		EN.bits.fc59_obj1_L1=   pEN.bit.obj1_27_59 &
														pEN.bit.obj1_59 &
													(fc59_obj1_L1_in.level>eps) &
													(fc59_obj1_L1_in.delay>eps);

		EN.bits.fc59_obj1_L2=   pEN.bit.obj1_27_59 &
														pEN.bit.obj1_59 &
													(fc59_obj1_L2_in.level>eps) &
													(fc59_obj1_L2_in.delay>eps);	
													
	// fc46
	
		EN.bits.fc46_obj1_L1=   pEN.bit.obj1_46 &
													(fc46d_obj1_L1_in.level>eps) &
													(fc46d_obj1_L1_in.delay>eps);

		EN.bits.fc46_obj1_L2=    pEN.bit.obj1_46 &
													(fc46i_obj1_L1_in.level>eps) &
													(fc46i_obj1_L1_in.time_multiplier>eps);	

	// fc49
	
		EN.bits.fc49_obj1_L1=  	 pEN.bit.obj1_49 &
													(fc49_obj1_L1_in.alarm_level>eps) 
													;	
												

		EN.bits.fc49_obj2_L1=  	 pEN.bit.obj2_49 &
													(fc49_obj2_L1_in.alarm_level>eps) 
													;	
													
												
												
												
	// fcBF		

		EN.bits.fcBF_obj1 = pEN.bit.obj1_BF &
											(fcBF_in.delay>eps);
											
											
	// fc37
	
		EN.bits.fc37_obj1 =pEN.bit.obj1_37 &
										(fc37_obj1_L1_in.level>eps) &
										(fc37_obj1_L1_in.delay>eps);
										
										
		EN.bits.fc37_obj2 =pEN.bit.obj2_37 &
										(fc37_obj2_L1_in.level>eps) &
										(fc37_obj2_L1_in.delay>eps);
										
										
	// fcUNB

		EN.bits.fcUNBd_obj1 =pEN.bit.obj1_UNB &
											(fcUNBd_obj1_L1_in.level>eps) &
											(fcUNBd_obj1_L1_in.delay>eps);		

		EN.bits.fcUNBi_obj1 =pEN.bit.obj1_UNB &
											(fcUNBi_obj1_L1_in.level>eps);	

	// fcPVP
	
		EN.bits.fcPVPd_obj1= pEN.bit.obj1_PVP &
												 (fcPVPd_obj1_L1_in.level>eps) &
												 (fcPVPd_obj1_L1_in.delay>eps); 
												 
												 
		EN.bits.fcPVPi_obj1= pEN.bit.obj1_PVP &
												 (fcPVPi_obj1_L1_in.level>eps) &
												 (fcPVPi_obj1_L1_in.time_multiplier>eps);
		
		
	/*Enable Handling End*/		

	
	
	curve=cSelect1.all & 0x00FF;
	
	switch (curve)
  {
  	case IEC_normal_inverse: 			fc51_obj1_in.curve_data[0]=curve_data[0][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[0][1] ; 
																	fc51_obj1_in.curve_data[2]=0.0f ; break;
  	 
		case IEC_very_inverse: 				fc51_obj1_in.curve_data[0]=curve_data[1][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[1][1] ;
																	fc51_obj1_in.curve_data[2]=0.0f ; break;
		
		case IEC_extremely_inverse: 	fc51_obj1_in.curve_data[0]=curve_data[2][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[2][1] ; 
																	fc51_obj1_in.curve_data[2]=0.0f ; break;	
		
		case IEC_long_inverse: 				fc51_obj1_in.curve_data[0]=curve_data[3][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[3][1] ;
																	fc51_obj1_in.curve_data[2]=0.0f ; break;	
		
		case ANSI_normal_inverse: 		fc51_obj1_in.curve_data[0]=curve_data[4][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[4][1] ; 
																	fc51_obj1_in.curve_data[2]=curve_data[4][2] ; break;				
  	 
		case ANSI_very_inverse: 			fc51_obj1_in.curve_data[0]=curve_data[5][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[5][1] ; 
																	fc51_obj1_in.curve_data[2]=curve_data[5][2] ; break;	
		
		case ANSI_extremely_inverse: 	fc51_obj1_in.curve_data[0]=curve_data[6][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[6][1] ; 
																	fc51_obj1_in.curve_data[2]=curve_data[6][2] ; break;	
																	
		case ANSI_long_inverse: 			fc51_obj1_in.curve_data[0]=curve_data[7][0] ; 
																	fc51_obj1_in.curve_data[1]=curve_data[7][1] ; 
																	fc51_obj1_in.curve_data[2]=curve_data[7][2] ; break;									
																		
		
  } 
	
	
	
	curve=(cSelect1.all>>8) & 0x00FF;
	
	switch (curve)
  {
  	case IEC_normal_inverse: 			fc51N_obj1_in.curve_data[0]=curve_data[0][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[0][1] ; 
																	fc51N_obj1_in.curve_data[2]=0.0f ; break;
  	 
		case IEC_very_inverse: 				fc51N_obj1_in.curve_data[0]=curve_data[1][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[2][1] ; 	
																	fc51N_obj1_in.curve_data[2]=0.0f ; break;
		
		case IEC_extremely_inverse: 	fc51N_obj1_in.curve_data[0]=curve_data[2][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[2][1] ; 
																	fc51N_obj1_in.curve_data[2]=0.0f ; break;
		
		case IEC_long_inverse: 				fc51N_obj1_in.curve_data[0]=curve_data[3][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[3][1] ; 
																	fc51N_obj1_in.curve_data[2]=0.0f ; break;
		
		case ANSI_normal_inverse: 		fc51N_obj1_in.curve_data[0]=curve_data[4][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[4][1] ; 
																	fc51N_obj1_in.curve_data[2]=curve_data[4][2] ; break;
  	 
		case ANSI_very_inverse: 			fc51N_obj1_in.curve_data[0]=curve_data[5][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[5][1] ;
																	fc51N_obj1_in.curve_data[2]=curve_data[5][2] ; break;
		
		case ANSI_extremely_inverse: 	fc51N_obj1_in.curve_data[0]=curve_data[6][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[6][1] ; 
																	fc51N_obj1_in.curve_data[2]=curve_data[6][2] ; break;	
		
		case ANSI_long_inverse: 			fc51N_obj1_in.curve_data[0]=curve_data[7][0] ; 
																	fc51N_obj1_in.curve_data[1]=curve_data[7][1] ; 
																	fc51N_obj1_in.curve_data[2]=curve_data[7][2] ; break;
  }
	
	
	
	
	curve=(cSelect1.all>>16) & 0x00FF;
	
	switch (curve)
  {
  	case IEC_normal_inverse: 			fc46i_obj1_L1_in.curve_data[0]=curve_data[0][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[0][1] ; 
																	fc46i_obj1_L1_in.curve_data[2]=0 ; break;	
		
		case IEC_very_inverse: 				fc46i_obj1_L1_in.curve_data[0]=curve_data[1][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[1][1] ; 
																	fc46i_obj1_L1_in.curve_data[2]=0.0f ; break;				
		
		case IEC_extremely_inverse: 	fc46i_obj1_L1_in.curve_data[0]=curve_data[2][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[2][1] ; 
																	fc46i_obj1_L1_in.curve_data[2]=0.0f ; break;				
		
		case IEC_long_inverse: 				fc46i_obj1_L1_in.curve_data[0]=curve_data[3][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[3][1] ; 	
																	fc46i_obj1_L1_in.curve_data[2]=0.0f ; break;				
		
		case ANSI_normal_inverse: 		fc46i_obj1_L1_in.curve_data[0]=curve_data[4][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[4][1] ; 
																	fc46i_obj1_L1_in.curve_data[2]=curve_data[4][2] ; break;
  	 
		case ANSI_very_inverse: 			fc46i_obj1_L1_in.curve_data[0]=curve_data[5][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[5][1] ;
																	fc46i_obj1_L1_in.curve_data[2]=curve_data[5][2] ; break;
																	
		case ANSI_extremely_inverse: 	fc46i_obj1_L1_in.curve_data[0]=curve_data[6][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[6][1] ;	
																	fc46i_obj1_L1_in.curve_data[2]=curve_data[6][2] ; break;
		
		case ANSI_long_inverse: 			fc46i_obj1_L1_in.curve_data[0]=curve_data[7][0] ; 
																	fc46i_obj1_L1_in.curve_data[1]=curve_data[7][1] ; 
																	fc46i_obj1_L1_in.curve_data[2]=curve_data[7][2] ; break;
													
																	
		
  }
	
	
	
	// cau for Ib but
	
	curve=(cSelect2.all) & 0x00FF;
	
	switch (curve)
  {
  	case IEC_normal_inverse: 			fcPVPi_obj1_L1_in.curve_data[0]=curve_data[0][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[0][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=0.0f ; break;

		case IEC_very_inverse: 				fcPVPi_obj1_L1_in.curve_data[0]=curve_data[1][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[1][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=0.0f ; break;
		
		case IEC_extremely_inverse: 	fcPVPi_obj1_L1_in.curve_data[0]=curve_data[2][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[2][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=0.0f ; break;

		case IEC_long_inverse: 				fcPVPi_obj1_L1_in.curve_data[0]=curve_data[3][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[3][1] ;
																	fcPVPi_obj1_L1_in.curve_data[2]=0.0f ; break;
		
		case ANSI_normal_inverse: 		fcPVPi_obj1_L1_in.curve_data[0]=curve_data[4][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[4][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=curve_data[4][1] ; break;
  	 
		case ANSI_very_inverse: 			fcPVPi_obj1_L1_in.curve_data[0]=curve_data[5][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[5][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=curve_data[5][1] ; break;																	
		
		case ANSI_extremely_inverse: 	fcPVPi_obj1_L1_in.curve_data[0]=curve_data[6][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[6][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=curve_data[6][2] ; break;
		
		case ANSI_long_inverse: 			fcPVPi_obj1_L1_in.curve_data[0]=curve_data[7][0] ; 
																	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[7][1] ; 
																	fcPVPi_obj1_L1_in.curve_data[2]=curve_data[7][2] ; break;	
		
  }
	
	
	
	curve=(cSelect2.all>>8) & 0x00FF;
	
	switch (curve)
  {
  	case IEC_normal_inverse: 			fc51_obj2_in.curve_data[0]=curve_data[0][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[0][1] ; 
																	fc51_obj2_in.curve_data[2]=0.0f ; break;
  	 
		case IEC_very_inverse: 				fc51_obj2_in.curve_data[0]=curve_data[1][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[1][1] ; 
																	fc51_obj2_in.curve_data[2]=0.0f ; break;
		
		case IEC_extremely_inverse: 	fc51_obj2_in.curve_data[0]=curve_data[2][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[2][1] ; 
																	fc51_obj2_in.curve_data[2]=0.0f ; break;
		
		case IEC_long_inverse: 				fc51_obj2_in.curve_data[0]=curve_data[3][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[3][1] ; 
																	fc51_obj2_in.curve_data[2]=0.0f ; break;
		
		case ANSI_normal_inverse: 		fc51_obj2_in.curve_data[0]=curve_data[4][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[4][1] ; 
																	fc51_obj2_in.curve_data[2]=curve_data[4][0] ; break;
  	 
		case ANSI_very_inverse: 			fc51_obj2_in.curve_data[0]=curve_data[5][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[5][1] ; 	
																	fc51_obj2_in.curve_data[2]=curve_data[5][0] ; break;
		
		case ANSI_extremely_inverse: 	fc51_obj2_in.curve_data[0]=curve_data[6][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[6][1] ; 
																	fc51_obj2_in.curve_data[2]=curve_data[6][0] ; break;
		
		case ANSI_long_inverse: 			fc51_obj2_in.curve_data[0]=curve_data[7][0] ; 
																	fc51_obj2_in.curve_data[1]=curve_data[7][1] ; 
																	fc51_obj2_in.curve_data[2]=curve_data[7][0] ; break;
		
  }
	
	

}





