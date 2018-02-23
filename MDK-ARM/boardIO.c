
#include "stm32f7xx_hal.h"
#include "protection_functions.h"
#include "boardIO.h"




union digitalInputs  DI={0};
union digitalOutputs DO={0};



void boardIO(){
	
	
	/*Input stage*/
	
	DI.bit.start_stop=HAL_GPIO_ReadPin(START_STOP_DI_1_GPIO_Port,START_STOP_DI_1_Pin);
	//DI.bit.Q1_cb_pos=HAL_GPIO_ReadPin (Q1_CB_POS_DI_2_GPIO_Port ,Q1_CB_POS_DI_2_Pin);
	//DI.bit.Q2_cb_pos=HAL_GPIO_ReadPin (Q2_CB_POS_DI_3_GPIO_Port ,Q2_CB_POS_DI_3_Pin);
	//DI.bit.Q3_cb_pos=HAL_GPIO_ReadPin (Q3_CB_POS_DI_4_GPIO_Port ,Q3_CB_POS_DI_4_Pin);
	
	//DI.bit.SVC_trip=HAL_GPIO_ReadPin  (SVC_TRIP_DI_10_GPIO_Port ,SVC_TRIP_DI_10_Pin);
	
	
	//DI.bit.Q1_open=HAL_GPIO_ReadPin (Q1_CB_OPEN_DI_12_GPIO_Port ,Q1_CB_OPEN_DI_12_Pin);
	DI.bit.Q2_open=HAL_GPIO_ReadPin (Q2_CB_OPEN_DI_14_GPIO_Port ,Q2_CB_OPEN_DI_14_Pin);
	DI.bit.Q3_open=HAL_GPIO_ReadPin (Q3_CB_OPEN_DI_16_GPIO_Port ,Q3_CB_OPEN_DI_16_Pin);
	
	
	DI.bit.Q1_trip=HAL_GPIO_ReadPin (Q1_CB_TRIP_DI_13_GPIO_Port ,Q1_CB_TRIP_DI_13_Pin);
	DI.bit.Q2_trip=HAL_GPIO_ReadPin (Q2_CB_TRIP_DI_15_GPIO_Port ,Q2_CB_TRIP_DI_15_Pin);
	DI.bit.Q3_trip=HAL_GPIO_ReadPin (Q3_CB_TRIP_DI_17_GPIO_Port ,Q3_CB_TRIP_DI_17_Pin);
	
	
	DI.bit._51=HAL_GPIO_ReadPin (DI_51_DI_18_GPIO_Port, DI_51_DI_18_Pin);
	DI.bit._53=HAL_GPIO_ReadPin (DI_53_DI_20_GPIO_Port, DI_53_DI_20_Pin);
	DI.bit._52=HAL_GPIO_ReadPin (DI_52_DI_19_GPIO_Port, DI_52_DI_19_Pin);
	DI.bit._54=HAL_GPIO_ReadPin (DI_54_DI_21_GPIO_Port, DI_54_DI_21_Pin);
	DI.bit._56=HAL_GPIO_ReadPin (DI_56_DI_23_GPIO_Port, DI_56_DI_23_Pin);
	
	
	DI.bit.cold_test=HAL_GPIO_ReadPin(COLD_TEST_DI_22_GPIO_Port,COLD_TEST_DI_22_Pin);
	DI.bit.tfr_trig =HAL_GPIO_ReadPin(TFR_TRIGGER_DI_24_GPIO_Port,TFR_TRIGGER_DI_24_Pin);
	
	DI.bit.plb_sp1=HAL_GPIO_ReadPin(PLB_INT_DI_SP1_DI_26_GPIO_Port,PLB_INT_DI_SP1_DI_26_Pin);
	DI.bit.plb_sp2=HAL_GPIO_ReadPin(PLB_INT_DI_SP2_DI_25_GPIO_Port,PLB_INT_DI_SP2_DI_25_Pin);
	DI.bit.plb_sp3=HAL_GPIO_ReadPin(PLB_INT_DI_SP3_DI_28_GPIO_Port,PLB_INT_DI_SP3_DI_28_Pin);
	DI.bit.plb_sp4=HAL_GPIO_ReadPin(PLB_INT_DI_SP4_DI_27_GPIO_Port,PLB_INT_DI_SP4_DI_27_Pin);
	DI.bit.plb_sp6=HAL_GPIO_ReadPin(PLB_INT_DI_SP6_DI_29_GPIO_Port,PLB_INT_DI_SP6_DI_29_Pin);
	
	DI.bit.reset=HAL_GPIO_ReadPin(DI_RESET_GPIO_Port,DI_RESET_Pin);
	
	/*Output stage*/
	
	//DO.bits.trip=1;
	//DO.bits.inhibit=0;
	DO.bits.IBF=1;
	DO.bits.LD_IBF=1;
	//DO.bits.BF=1;
	
	HAL_GPIO_WritePin(BOARD_TRIP_DO_1_GPIO_Port,BOARD_TRIP_DO_1_Pin,(GPIO_PinState)DO.bits.trip); 
	HAL_GPIO_WritePin(BOARD_ALARM_DO_2_GPIO_Port,BOARD_ALARM_DO_2_Pin,(GPIO_PinState)DO.bits.alarm);
	HAL_GPIO_WritePin(BOARD_INHIBIT_DO_3_GPIO_Port,BOARD_INHIBIT_DO_3_Pin,(GPIO_PinState)DO.bits.inhibit);
	HAL_GPIO_WritePin(BOARD_BF_DO_4_GPIO_Port,BOARD_BF_DO_4_Pin,(GPIO_PinState)DO.bits.BF);
	HAL_GPIO_WritePin(BOARD_IBF_DO_5_GPIO_Port,BOARD_IBF_DO_5_Pin,(GPIO_PinState)DO.bits.IBF);
	HAL_GPIO_WritePin(BOARD_SP_DO_6_GPIO_Port,BOARD_SP_DO_6_Pin,(GPIO_PinState)DO.bits.spare);
	
	
	HAL_GPIO_WritePin(LD_TRIP_GPIO_Port ,LD_TRIP_Pin,(GPIO_PinState)DO.bits.LD_TRIP);
	HAL_GPIO_WritePin(LD_ALARM_GPIO_Port ,LD_ALARM_Pin,(GPIO_PinState)DO.bits.LD_ALARM);
	HAL_GPIO_WritePin(LD_IBF_GPIO_Port,LD_IBF_Pin,(GPIO_PinState)DO.bits.LD_IBF);

	
	
	

}











