#include "mlib_definitions.h"
#include "plib_definitions.h"
#include "cs_handles.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "alarms.h"

union alarm_indications alarm={0};

void alarms(void){
	
	static uint8_t ENalarm=0;
	static long ENalarm_counter=0;

	
	static long alarm_counters[4]={0};
	
	//sequence alarms
	
	if(Sys.phaseRotation){
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V1>mag_sym.V2,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);

	
	}else{
		
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V2>mag_sym.V1,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);
	
	
	}
	
	ENalarm=on_off_delay((maxSelector_3p(fRMS.ITCR_ab,fRMS.ITCR_bc,fRMS.ITCR_ca)<Sys.I_Nom_obj1*0.5),ENalarm,fs,&ENalarm_counter);
	
	if(ENalarm){
	

	alarm.bit.voltage_phase_seq=0;

		
	}
	
	
																					
}



