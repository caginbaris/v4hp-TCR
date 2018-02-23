#ifndef externalData_H
#define externalData_H

#include "plib_handles.h"

extern struct plib_handles pick;
extern struct plib_handles trip;

union ToWord{
	
	struct plib_handles w_str;
	uint32_t w_arr[3];
	
};

	
extern union ToWord pick_words;
extern union ToWord trip_words;

extern struct spectra spect_Ia;
extern struct spectra spect_Ib;
extern struct spectra spect_Ic;

extern struct thd_data thd;
extern struct sym_out mag_sym;


extern struct phase_cs_out phase_cs_A_out;
extern struct phase_cs_out phase_cs_B_out;
extern struct phase_cs_out phase_cs_C_out;

#endif

