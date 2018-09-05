#ifndef __alarms_h
#define __alarms_h

#include "stdint.h"

union alarm_indications{

	struct{
	
	uint32_t configDataReception:1;
	uint32_t voltage_phase_seq:1;
	uint32_t current_phase_seq:1;
	uint32_t unbalance_a:1;
	uint32_t unbalance_b:1;
	uint32_t flashError:1;		
		
	}bit;
	
	uint32_t all;

};

extern struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
extern union alarm_indications alarm;

#endif
