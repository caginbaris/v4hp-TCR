#include "stm32f7xx_hal.h"
#include "flash_api.h"
#include "UART_MasterSlave.h"
#include "boardIO.h"
#include "alarms.h"

#define dataStartAddressD  (ADDR_FLASH_SECTOR_2+4)
#define dataStartAddressF1 (dataStartAddressD+5*4)
#define dataStartAddressF2 (dataStartAddressF1+56*4)
#define dataStartAddressF3 (dataStartAddressF2+61*4)

static FLASH_EraseInitTypeDef EraseInitStruct;

uint32_t SECTORError;

uint8_t eraseError=0;
uint8_t writeError=0;

uint32_t sentinel=0xA5B4C3D2;





uint8_t flashWritePending=0;
extern uint8_t incoming_data_flag;




extern float nucArray[4];




void flashErase(void){

  
	
  /* Fill EraseInit structure*/
  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector        = 2;
  EraseInitStruct.NbSectors     = 1;
	
	
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK){eraseError=1;}
	
	


}





void flashWriteF(uint32_t Address, float* data, uint8_t N ){

	uint8_t i;
	
	for(i=0;i<N;i++){
	
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, *(uint32_t *)(&data[i])) != HAL_OK){writeError=1;}
		
		Address=Address+4;
	
	}


}



void flashWriteD(uint32_t Address, uint32_t* data, uint8_t N ){

	uint8_t i;
	
	for(i=0;i<N;i++){
	
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, *(uint32_t *)(&data[i])) != HAL_OK){writeError=1;}
		Address=Address+4;
		
	}

}




void flashReadF(uint32_t Address, float* data, uint8_t N ){

	uint8_t i;
	
	for(i=0;i<N;i++){
	
		data[i]=*(float *)(Address);
		Address+=4;
			
	}

}



void flashReadD(uint32_t Address, uint32_t* data, uint8_t N ){

	uint8_t i;
	
	for(i=0;i<N;i++){
	
		data[i]=*(uint32_t *)(Address);
		Address+=4;
			
	}

}






uint8_t checkFlashData(void){
	
	uint32_t key=0;
	uint32_t passed=0;
	
	flashReadD(ADDR_FLASH_SECTOR_2, &key,1);
		
	if(key==sentinel){
		
	passed=1;
		
	}
	
	return passed;
	
}


void bulkFlashWrite(void){
	
	__disable_irq();
	
	HAL_FLASH_Unlock();
	
	flashErase();
	
	if(eraseError==0){
	
	flashWriteD(ADDR_FLASH_SECTOR_2,&sentinel,1);
	flashWriteD(dataStartAddressD, comParams_uart.recDataBufferDW,5);
	flashWriteF(dataStartAddressF1,comParams_uart.recDataBufferF,56);
	flashWriteF(dataStartAddressF2,&comParams_uart.recDataBufferF[56],61);
	flashWriteF(dataStartAddressF3,nucArray,4);
	
	}
	
	HAL_FLASH_Lock();
	
	__enable_irq();
	
}



void bulkFlashRead(void){
	

	
	if(writeError==0){
	
	
	flashReadD(dataStartAddressD,comParams_uart.recDataBufferDW,5);	
	flashReadF(dataStartAddressF1,comParams_uart.recDataBufferF,56);	
	flashReadF(dataStartAddressF2,&comParams_uart.recDataBufferF[56],61);	
	flashReadF(dataStartAddressF3,nucArray,4);	
		
	}

}


void flashDataCheckStartup(void){
	
	uint8_t availableFlashData=0;
	
	availableFlashData=checkFlashData();
	
	if(availableFlashData){
	
		bulkFlashRead();
		
		alarm.bit.configDataReception=1;
		
	}else{
	
		alarm.bit.configDataReception=0;
	
	}

}


void flashConfigDataWrite(uint8_t* enable){

	if(*enable){
		
		DO.bits.IBF=0;
		bulkFlashWrite();
		bulkFlashRead();
		DO.bits.IBF=1;
		*enable=0;
	}

}


void flashDataWriteChecking(void){
	

	if(flashWritePending==0 && incoming_data_flag==1){
		
	flashWritePending=1;	

	}
	
	
	if(DI.bit.start_stop==0 && incoming_data_flag==0){
	
	flashConfigDataWrite(&flashWritePending);
	
	}
	
}









