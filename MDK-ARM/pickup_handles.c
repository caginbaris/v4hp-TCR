#include "nfbm.h"
#include "plib_handles.h"
#include "plib_definitions.h"
#include "boardIO.h"
#include "externalData.h"
#include "bit_expansion.h"

#define totalPick 62
#define pickHold 1000

 struct plib_handles pick={0};
 struct plib_handles trip={0};

union ToWord pick_words={0};
union ToWord trip_words={0};

static long pick_buffer[totalPick]={0};

enum fault_codes fault_code=no_fault;



void pick_up_handles(){
	
	static uint8_t pick_up_counter=0;
	
	
	pick_words.w_str=pick;
	
	
	
	switch (pick_up_counter)
  {
		
		
  	case 0:
			
		pick.fc50_obj1_L1_out_a=off_delay(fc50_obj1_L1_out_a.pick_up, pick.fc50_obj1_L1_out_a, pickHold, &pick_buffer[0]);
		pick.fc50_obj1_L1_out_b=off_delay(fc50_obj1_L1_out_b.pick_up, pick.fc50_obj1_L1_out_b, pickHold, &pick_buffer[1]);
		pick.fc50_obj1_L1_out_c=off_delay(fc50_obj1_L1_out_c.pick_up, pick.fc50_obj1_L1_out_c, pickHold, &pick_buffer[2]);

		pick.fc50_obj1_L2_out_a=off_delay(fc50_obj1_L2_out_a.pick_up, pick.fc50_obj1_L2_out_a, pickHold, &pick_buffer[3]);
		pick.fc50_obj1_L2_out_b=off_delay(fc50_obj1_L2_out_b.pick_up, pick.fc50_obj1_L2_out_b, pickHold, &pick_buffer[4]);	
		pick.fc50_obj1_L2_out_c=off_delay(fc50_obj1_L2_out_c.pick_up, pick.fc50_obj1_L2_out_c, pickHold, &pick_buffer[5]);
		
		pick.fc50N_obj1_L1_out=off_delay(fc50N_obj1_L1_out.pick_up, pick.fc50N_obj1_L1_out, pickHold, &pick_buffer[6]);
		
  	break;
		
  	case 1:
			
		pick.fc50_obj1_L3_out_a=off_delay(fc50_obj1_L3_out_a.pick_up, pick.fc50_obj1_L3_out_a, pickHold, &pick_buffer[7]);
		pick.fc50_obj1_L3_out_b=off_delay(fc50_obj1_L3_out_b.pick_up, pick.fc50_obj1_L3_out_b, pickHold, &pick_buffer[8]);
		pick.fc50_obj1_L3_out_c=off_delay(fc50_obj1_L3_out_c.pick_up, pick.fc50_obj1_L3_out_c, pickHold, &pick_buffer[9]);
		
		pick.fc50_obj2_L1_out_a=off_delay(fc50_obj2_L1_out_a.pick_up, pick.fc50_obj2_L1_out_a, pickHold, &pick_buffer[10]);
		pick.fc50_obj2_L1_out_b=off_delay(fc50_obj2_L1_out_b.pick_up, pick.fc50_obj2_L1_out_b, pickHold, &pick_buffer[11]);
		pick.fc50_obj2_L1_out_c=off_delay(fc50_obj2_L1_out_c.pick_up, pick.fc50_obj2_L1_out_c, pickHold, &pick_buffer[12]);

		pick.fc50N_obj1_L2_out=off_delay(fc50N_obj1_L2_out.pick_up, pick.fc50N_obj1_L2_out, pickHold, &pick_buffer[13]);
			
  	break;
		
		
		
		case 2:
			
		pick.fc50_obj2_L2_out_a=off_delay(fc50_obj2_L2_out_a.pick_up, pick.fc50_obj2_L2_out_a, pickHold, &pick_buffer[14]);
		pick.fc50_obj2_L2_out_b=off_delay(fc50_obj2_L2_out_b.pick_up, pick.fc50_obj2_L2_out_b, pickHold, &pick_buffer[15]);		
		pick.fc50_obj2_L2_out_c=off_delay(fc50_obj2_L2_out_c.pick_up, pick.fc50_obj2_L2_out_c, pickHold, &pick_buffer[16]);	
			
		pick.fc50_obj2_L3_out_a=off_delay(fc50_obj2_L3_out_a.pick_up, pick.fc50_obj2_L3_out_a, pickHold, &pick_buffer[17]);	
		pick.fc50_obj2_L3_out_b=off_delay(fc50_obj2_L3_out_b.pick_up, pick.fc50_obj2_L3_out_b, pickHold, &pick_buffer[18]);		
		pick.fc50_obj2_L3_out_c=off_delay(fc50_obj2_L3_out_c.pick_up, pick.fc50_obj2_L3_out_c, pickHold, &pick_buffer[19]);	
		
		pick.fc50N_obj1_L3_out=off_delay(fc50N_obj1_L3_out.pick_up, pick.fc50N_obj1_L3_out, pickHold, &pick_buffer[20]);	
			
		break;
				
		case 3:
			
		pick.fc51_obj1_out_a=off_delay(fc51_obj1_out_a.pick_up, pick.fc51_obj1_out_a,pickHold,&pick_buffer[21]);
		pick.fc51_obj1_out_b=off_delay(fc51_obj1_out_b.pick_up, pick.fc51_obj1_out_b,pickHold,&pick_buffer[22]);	
		pick.fc51_obj1_out_c=off_delay(fc51_obj1_out_c.pick_up, pick.fc51_obj1_out_c,pickHold,&pick_buffer[23]);		
		pick.fc51_obj2_out_a=off_delay(fc51_obj2_out_a.pick_up, pick.fc51_obj2_out_a,pickHold,&pick_buffer[24]);
		pick.fc51_obj2_out_b=off_delay(fc51_obj2_out_b.pick_up, pick.fc51_obj2_out_b,pickHold,&pick_buffer[25]);	
		pick.fc51_obj2_out_c=off_delay(fc51_obj2_out_c.pick_up, pick.fc51_obj2_out_c,pickHold,&pick_buffer[26]);
			
		pick.fc51N_obj1_out=off_delay(fc51N_obj1_out.pick_up, pick.fc51N_obj1_out,pickHold,&pick_buffer[27]);
			
		
		break;
		
		
		
		case 4:
			
		pick.fc27_obj1_L1_out=off_delay(fc27_obj1_L1_out.pick_up, pick.fc27_obj1_L1_out,pickHold,&pick_buffer[28]);
		pick.fc27_obj1_L2_out=off_delay(fc27_obj1_L2_out.pick_up, pick.fc27_obj1_L2_out,pickHold,&pick_buffer[29]);
		
		pick.fc59_obj1_L1_out_a=off_delay(fc59_obj1_L1_out_a.pick_up, pick.fc59_obj1_L1_out_a,pickHold,&pick_buffer[30]);
		pick.fc59_obj1_L1_out_b=off_delay(fc59_obj1_L1_out_b.pick_up, pick.fc59_obj1_L1_out_b,pickHold,&pick_buffer[31]);
		pick.fc59_obj1_L1_out_c=off_delay(fc59_obj1_L1_out_c.pick_up, pick.fc59_obj1_L1_out_c,pickHold,&pick_buffer[32]);
		
		pick.fc59_obj1_L2_out_a=off_delay(fc59_obj1_L2_out_a.pick_up, pick.fc59_obj1_L2_out_a,pickHold,&pick_buffer[33]);
		pick.fc59_obj1_L2_out_b=off_delay(fc59_obj1_L2_out_b.pick_up, pick.fc59_obj1_L2_out_b,pickHold,&pick_buffer[34]);
		pick.fc59_obj1_L2_out_c=off_delay(fc59_obj1_L2_out_c.pick_up, pick.fc59_obj1_L2_out_c,pickHold,&pick_buffer[35]);

			
		break;
		
		
		case 5:
			
		pick.fc46d_obj1_L1_out=off_delay(fc46d_obj1_L1_out.pick_up, pick.fc46d_obj1_L1_out,pickHold,&pick_buffer[36]);
		pick.fc46i_obj1_L1_out=off_delay(fc46i_obj1_L1_out.pick_up, pick.fc46i_obj1_L1_out,pickHold,&pick_buffer[37]);
		pick.fc49_obj1_L1_out_a=off_delay(fc49_obj1_L1_out_a.alarm, pick.fc49_obj1_L1_out_a,pickHold,&pick_buffer[38]);
		pick.fc49_obj1_L1_out_b=off_delay(fc49_obj1_L1_out_b.alarm, pick.fc49_obj1_L1_out_b,pickHold,&pick_buffer[39]);
		pick.fc49_obj1_L1_out_c=off_delay(fc49_obj1_L1_out_c.alarm, pick.fc49_obj1_L1_out_c,pickHold,&pick_buffer[40]);
		
		//pick.fc49_obj1_L2_out_a=off_delay(fc49_obj1_L2_out_a.alarm, pick.fc49_obj1_L2_out_a,pickHold,&pick_buffer[41]);/**/trip.fc49_obj1_L2_out_a=fc49_obj1_L2_out_a.trip;
		//pick.fc49_obj1_L2_out_b=off_delay(fc49_obj1_L2_out_b.alarm, pick.fc49_obj1_L2_out_b,pickHold,&pick_buffer[42]);/**/trip.fc49_obj1_L2_out_b=fc49_obj1_L2_out_b.trip;
		//pick.fc49_obj1_L2_out_c=off_delay(fc49_obj1_L2_out_c.alarm, pick.fc49_obj1_L2_out_c,pickHold,&pick_buffer[43]);/**/trip.fc49_obj1_L2_out_c=fc49_obj1_L2_out_c.trip;			
		
		break;
		
		
		case 6:
			
		pick.fc49_obj2_L1_out_a=off_delay(fc49_obj2_L1_out_a.alarm, pick.fc49_obj2_L1_out_a,pickHold,&pick_buffer[41]);
		pick.fc49_obj2_L1_out_b=off_delay(fc49_obj2_L1_out_b.alarm, pick.fc49_obj2_L1_out_b,pickHold,&pick_buffer[42]);
		pick.fc49_obj2_L1_out_c=off_delay(fc49_obj2_L1_out_c.alarm, pick.fc49_obj2_L1_out_c,pickHold,&pick_buffer[43]);
		
		//pick.fc49_obj2_L2_out_a=off_delay(fc49_obj2_L2_out_a.alarm, pick.fc49_obj2_L2_out_a,pickHold,&pick_buffer[47]);/**/trip.fc49_obj2_L2_out_a=fc49_obj2_L2_out_a.trip;
		//pick.fc49_obj2_L2_out_b=off_delay(fc49_obj2_L2_out_b.alarm, pick.fc49_obj2_L2_out_b,pickHold,&pick_buffer[48]);/**/trip.fc49_obj2_L2_out_b=fc49_obj2_L2_out_b.trip;
		//pick.fc49_obj2_L2_out_c=off_delay(fc49_obj2_L2_out_c.alarm, pick.fc49_obj2_L2_out_c,pickHold,&pick_buffer[49]);/**/trip.fc49_obj2_L2_out_c=fc49_obj2_L2_out_c.trip;
		
		
		pick.fcBF_out=off_delay(fcBF_out.pick_up,pick.fcBF_out,pickHold,&pick_buffer[44]);
		
			
		break;
		
		case 7:
			
		pick.fc37_obj1_L1_out_a=off_delay(fc37_obj1_L1_out_a.pick_up,pick.fc37_obj1_L1_out_a,pickHold,&pick_buffer[45]);
		pick.fc37_obj1_L1_out_b=off_delay(fc37_obj1_L1_out_b.pick_up,pick.fc37_obj1_L1_out_b,pickHold,&pick_buffer[46]);
		pick.fc37_obj1_L1_out_c=off_delay(fc37_obj1_L1_out_c.pick_up,pick.fc37_obj1_L1_out_c,pickHold,&pick_buffer[47]);
		
		pick.fc37_obj2_L1_out_a=off_delay(fc37_obj2_L1_out_a.pick_up,pick.fc37_obj2_L1_out_a,pickHold,&pick_buffer[48]);
		pick.fc37_obj2_L1_out_b=off_delay(fc37_obj2_L1_out_b.pick_up,pick.fc37_obj2_L1_out_b,pickHold,&pick_buffer[49]);
		pick.fc37_obj2_L1_out_c=off_delay(fc37_obj2_L1_out_c.pick_up,pick.fc37_obj2_L1_out_c,pickHold,&pick_buffer[50]);
		
		
		break;
		
		
		case 8:
			
		pick.fcUNBd_obj1_L1_out_a=off_delay(fcUNBd_obj1_L1_out_a.pick_up,pick.fcUNBd_obj1_L1_out_a,pickHold,&pick_buffer[51]);
		pick.fcUNBd_obj1_L1_out_b=off_delay(fcUNBd_obj1_L1_out_b.pick_up,pick.fcUNBd_obj1_L1_out_b,pickHold,&pick_buffer[52]);
		
		pick.fcUNBi_obj1_L1_out_a=off_delay(fcUNBi_obj1_L1_out_a.pick_up,pick.fcUNBi_obj1_L1_out_a,pickHold,&pick_buffer[53]);
		pick.fcUNBi_obj1_L1_out_b=off_delay(fcUNBi_obj1_L1_out_b.pick_up,pick.fcUNBi_obj1_L1_out_b,pickHold,&pick_buffer[54]);
	
		
		break;
		
		
		case 9:
			
		pick.fcPVPd_obj1_L1_out_a=off_delay(fcPVPd_obj1_L1_out_a.pick_up,pick.fcPVPd_obj1_L1_out_a,pickHold,&pick_buffer[55]);
		pick.fcPVPd_obj1_L1_out_b=off_delay(fcPVPd_obj1_L1_out_b.pick_up,pick.fcPVPd_obj1_L1_out_b,pickHold,&pick_buffer[56]);
		pick.fcPVPd_obj1_L1_out_c=off_delay(fcPVPd_obj1_L1_out_c.pick_up,pick.fcPVPd_obj1_L1_out_c,pickHold,&pick_buffer[57]);
		
		pick.fcPVPi_obj1_L1_out_a=off_delay(fcPVPi_obj1_L1_out_a.pick_up,pick.fcPVPi_obj1_L1_out_a,pickHold,&pick_buffer[58]);
		pick.fcPVPi_obj1_L1_out_b=off_delay(fcPVPi_obj1_L1_out_b.pick_up,pick.fcPVPi_obj1_L1_out_b,pickHold,&pick_buffer[59]);
		pick.fcPVPi_obj1_L1_out_c=off_delay(fcPVPi_obj1_L1_out_c.pick_up,pick.fcPVPi_obj1_L1_out_c,pickHold,&pick_buffer[60]);
		
	
		break; 
		
		
		
		
		
		
  }
	
	

	if(++pick_up_counter==10){pick_up_counter=0;}
	
	
	pick_words.w_str=pick;
	
		if(pick_words.w_arr[0]!=0 || pick_words.w_arr[1]!=0 || pick_words.w_arr[2]!=0){
		
		DO.bits.alarm=1;
		DO.bits.LD_ALARM=1;
		
		}else{
			
		DO.bits.alarm=0;
		DO.bits.LD_ALARM=0;	
		
		}


}


void reset_handles(){
	
		// cau , invoke after DO op.
	
		if(DI.bit.reset){
	
	
		if(!pick.fc50_obj1_L1_out_a){fc50_obj1_L1_out_a.trip_latch=0;}
		if(!pick.fc50_obj1_L1_out_b){fc50_obj1_L1_out_b.trip_latch=0;}
		if(!pick.fc50_obj1_L1_out_c){fc50_obj1_L1_out_c.trip_latch=0;}
		
		if(!pick.fc50_obj1_L2_out_a){fc50_obj1_L2_out_a.trip_latch=0;}
		if(!pick.fc50_obj1_L2_out_b){fc50_obj1_L2_out_b.trip_latch=0;}
		if(!pick.fc50_obj1_L2_out_c){fc50_obj1_L2_out_c.trip_latch=0;}
		
		if(!pick.fc50_obj1_L3_out_a){fc50_obj1_L3_out_a.trip_latch=0;}
		if(!pick.fc50_obj1_L3_out_b){fc50_obj1_L3_out_b.trip_latch=0;}
		if(!pick.fc50_obj1_L3_out_c){fc50_obj1_L3_out_c.trip_latch=0;}
		
		
		
		if(!pick.fc50_obj2_L1_out_a){fc50_obj2_L1_out_a.trip_latch=0;}
		if(!pick.fc50_obj2_L1_out_b){fc50_obj2_L1_out_b.trip_latch=0;}
		if(!pick.fc50_obj2_L1_out_c){fc50_obj2_L1_out_c.trip_latch=0;}
		
		if(!pick.fc50_obj2_L2_out_a){fc50_obj2_L2_out_a.trip_latch=0;}
		if(!pick.fc50_obj2_L2_out_b){fc50_obj2_L2_out_b.trip_latch=0;}
		if(!pick.fc50_obj2_L2_out_c){fc50_obj2_L2_out_c.trip_latch=0;}
		
		if(!pick.fc50_obj2_L3_out_a){fc50_obj2_L3_out_a.trip_latch=0;}
		if(!pick.fc50_obj2_L3_out_b){fc50_obj2_L3_out_b.trip_latch=0;}
		if(!pick.fc50_obj2_L3_out_c){fc50_obj2_L3_out_c.trip_latch=0;}
		
		
		
		if(!pick.fc50N_obj1_L1_out){fc50N_obj1_L1_out.trip_latch=0;}
		if(!pick.fc50N_obj1_L2_out){fc50N_obj1_L2_out.trip_latch=0;}
		if(!pick.fc50N_obj1_L3_out){fc50N_obj1_L3_out.trip_latch=0;}
		
		
		if(!pick.fc51_obj1_out_a){fc51_obj1_out_a.trip=0;}
		if(!pick.fc51_obj1_out_b){fc51_obj1_out_b.trip=0;}
		if(!pick.fc51_obj1_out_c){fc51_obj1_out_c.trip=0;}
		
		if(!pick.fc51_obj2_out_a){fc51_obj2_out_a.trip=0;}
		if(!pick.fc51_obj2_out_b){fc51_obj2_out_b.trip=0;}
		if(!pick.fc51_obj2_out_c){fc51_obj2_out_c.trip=0;}
		
		
		if(!pick.fc51N_obj1_out){fc51N_obj1_out.trip=0;}
		
		
		if(!pick.fc27_obj1_L1_out){fc27_obj1_L1_out.trip=0;}
		if(!pick.fc27_obj1_L2_out){fc27_obj1_L2_out.trip=0;}
		

		if(!pick.fc59_obj1_L1_out_a){fc59_obj1_L1_out_a.trip=0;}
		if(!pick.fc59_obj1_L1_out_b){fc59_obj1_L1_out_b.trip=0;}
		if(!pick.fc59_obj1_L1_out_c){fc59_obj1_L1_out_c.trip=0;}
		
		if(!pick.fc59_obj1_L2_out_a){fc59_obj1_L2_out_a.trip=0;}
		if(!pick.fc59_obj1_L2_out_b){fc59_obj1_L2_out_b.trip=0;}
		if(!pick.fc59_obj1_L2_out_c){fc59_obj1_L2_out_c.trip=0;}
		
		
		if(!pick.fc46d_obj1_L1_out){fc46d_obj1_L1_out.trip_latch=0;}
		if(!pick.fc46i_obj1_L1_out){fc46i_obj1_L1_out.trip=0;}
		
		
		if(!pick.fc49_obj1_L1_out_a){fc49_obj1_L1_out_a.trip=0;}
		if(!pick.fc49_obj1_L1_out_b){fc49_obj1_L1_out_b.trip=0;}
		if(!pick.fc49_obj1_L1_out_c){fc49_obj1_L1_out_c.trip=0;}
		
		if(!pick.fc49_obj2_L1_out_a){fc49_obj2_L1_out_a.trip=0;}
		if(!pick.fc49_obj2_L1_out_b){fc49_obj2_L1_out_b.trip=0;}
		if(!pick.fc49_obj2_L1_out_c){fc49_obj2_L1_out_c.trip=0;}
		
		if(!pick.fcBF_out){fcBF_out.trip=0;}
		
		
		if(!pick.fc37_obj1_L1_out_a){fc37_obj1_L1_out_a.trip=0;}
		if(!pick.fc37_obj1_L1_out_b){fc37_obj1_L1_out_b.trip=0;}
		if(!pick.fc37_obj1_L1_out_c){fc37_obj1_L1_out_c.trip=0;}
		
		if(!pick.fc37_obj2_L1_out_a){fc37_obj2_L1_out_a.trip=0;}
		if(!pick.fc37_obj2_L1_out_b){fc37_obj2_L1_out_b.trip=0;}
		if(!pick.fc37_obj2_L1_out_c){fc37_obj2_L1_out_c.trip=0;}
		
		
		if(!pick.fcUNBd_obj1_L1_out_a){fcUNBd_obj1_L1_out_a.trip=0;}
		if(!pick.fcUNBd_obj1_L1_out_b){fcUNBd_obj1_L1_out_b.trip=0;}
		
		if(!pick.fcUNBi_obj1_L1_out_a){fcUNBi_obj1_L1_out_a.trip=0;}
		if(!pick.fcUNBi_obj1_L1_out_b){fcUNBi_obj1_L1_out_b.trip=0;}
		
		
		if(!pick.fcPVPd_obj1_L1_out_a){fcPVPd_obj1_L1_out_a.trip=0;}
		if(!pick.fcPVPd_obj1_L1_out_b){fcPVPd_obj1_L1_out_b.trip=0;}
		if(!pick.fcPVPd_obj1_L1_out_c){fcPVPd_obj1_L1_out_c.trip=0;}
		
		if(!pick.fcPVPi_obj1_L1_out_a){fcPVPi_obj1_L1_out_a.trip=0;}
		if(!pick.fcPVPi_obj1_L1_out_b){fcPVPi_obj1_L1_out_b.trip=0;}
		if(!pick.fcPVPi_obj1_L1_out_c){fcPVPi_obj1_L1_out_c.trip=0;}
		
		
		
		
		//--reset end	
		
		}
		
		




}

void trip_handles(){
	
	  
			
		/**/trip.fc50_obj1_L1_out_a=fc50_obj1_L1_out_a.trip_latch;
		/**/trip.fc50_obj1_L1_out_b=fc50_obj1_L1_out_b.trip_latch;	
		/**/trip.fc50_obj1_L1_out_c=fc50_obj1_L1_out_c.trip_latch;

		/**/trip.fc50_obj1_L2_out_a=fc50_obj1_L2_out_a.trip_latch;
		/**/trip.fc50_obj1_L2_out_b=fc50_obj1_L2_out_b.trip_latch;	
		/**/trip.fc50_obj1_L2_out_c=fc50_obj1_L2_out_c.trip_latch;
		
		/**/trip.fc50N_obj1_L1_out=fc50N_obj1_L1_out.trip_latch;
		

			
		/**/trip.fc50_obj1_L3_out_a=fc50_obj1_L3_out_a.trip_latch;
		/**/trip.fc50_obj1_L3_out_b=fc50_obj1_L3_out_b.trip_latch;	
		/**/trip.fc50_obj1_L3_out_c=fc50_obj1_L3_out_c.trip_latch;	
		
		/**/trip.fc50_obj2_L1_out_a=fc50_obj2_L1_out_a.trip_latch;	
		/**/trip.fc50_obj2_L1_out_b=fc50_obj2_L1_out_b.trip_latch;		
		/**/trip.fc50_obj2_L1_out_c=fc50_obj2_L1_out_c.trip_latch;	

		/**/trip.fc50N_obj1_L2_out=fc50N_obj1_L2_out.trip_latch;
		/**/trip.fc50_obj2_L2_out_a=fc50_obj2_L2_out_a.trip_latch;	
		/**/trip.fc50_obj2_L2_out_b=fc50_obj2_L2_out_b.trip_latch;		
		/**/trip.fc50_obj2_L2_out_c=fc50_obj2_L2_out_c.trip_latch;	
			
		/**/trip.fc50_obj2_L3_out_a=fc50_obj2_L3_out_a.trip_latch;	
		/**/trip.fc50_obj2_L3_out_b=fc50_obj2_L3_out_b.trip_latch;		
		/**/trip.fc50_obj2_L3_out_c=fc50_obj2_L3_out_c.trip_latch;	
		
		/**/trip.fc50N_obj1_L3_out=fc50N_obj1_L3_out.trip_latch;	
			
		/**/trip.fc51_obj1_out_a=fc51_obj1_out_a.trip;
		/**/trip.fc51_obj1_out_b=fc51_obj1_out_b.trip;	
		/**/trip.fc51_obj1_out_c=fc51_obj1_out_c.trip;
		
		/**/trip.fc51_obj2_out_a=fc51_obj2_out_a.trip;
		/**/trip.fc51_obj2_out_b=fc51_obj2_out_b.trip;	
		/**/trip.fc51_obj2_out_c=fc51_obj2_out_c.trip;
			
		/**/trip.fc51N_obj1_out=fc51N_obj1_out.trip;
		
			
		/**/trip.fc27_obj1_L1_out=fc27_obj1_L1_out.trip;
		/**/trip.fc27_obj1_L2_out=fc27_obj1_L2_out.trip;
		
		/**/trip.fc59_obj1_L1_out_a=fc59_obj1_L1_out_a.trip;
		/**/trip.fc59_obj1_L1_out_b=fc59_obj1_L1_out_b.trip;
		/**/trip.fc59_obj1_L1_out_c=fc59_obj1_L1_out_c.trip;
		
		/**/trip.fc59_obj1_L2_out_a=fc59_obj1_L2_out_a.trip;
		/**/trip.fc59_obj1_L2_out_b=fc59_obj1_L2_out_b.trip;
		/**/trip.fc59_obj1_L2_out_c=fc59_obj1_L2_out_c.trip;
		
		
		/**/trip.fc46d_obj1_L1_out=fc46d_obj1_L1_out.trip_latch;
		/**/trip.fc46i_obj1_L1_out=fc46i_obj1_L1_out.trip;
			
		/**/trip.fc49_obj1_L1_out_a=fc49_obj1_L1_out_a.trip;
		/**/trip.fc49_obj1_L1_out_b=fc49_obj1_L1_out_b.trip;
		/**/trip.fc49_obj1_L1_out_c=fc49_obj1_L1_out_c.trip;
	
		/**/trip.fc49_obj2_L1_out_a=fc49_obj2_L1_out_a.trip;
		/**/trip.fc49_obj2_L1_out_b=fc49_obj2_L1_out_b.trip;
		/**/trip.fc49_obj2_L1_out_c=fc49_obj2_L1_out_c.trip;
		
		/**/trip.fcBF_out=fcBF_out.trip;
			
		/**/trip.fc37_obj1_L1_out_a=fc37_obj1_L1_out_a.trip;
		/**/trip.fc37_obj1_L1_out_b=fc37_obj1_L1_out_b.trip;
		/**/trip.fc37_obj1_L1_out_c=fc37_obj1_L1_out_c.trip;
		
		/**/trip.fc37_obj2_L1_out_a=fc37_obj2_L1_out_a.trip;
		/**/trip.fc37_obj2_L1_out_b=fc37_obj2_L1_out_b.trip;
		/**/trip.fc37_obj2_L1_out_c=fc37_obj2_L1_out_c.trip;
			
		/**/trip.fcUNBd_obj1_L1_out_a=fcUNBd_obj1_L1_out_a.trip;
		/**/trip.fcUNBd_obj1_L1_out_b=fcUNBd_obj1_L1_out_b.trip;
		
		/**/trip.fcUNBi_obj1_L1_out_a=fcUNBi_obj1_L1_out_a.trip;
		/**/trip.fcUNBi_obj1_L1_out_b=fcUNBi_obj1_L1_out_b.trip;
	
		
		/**/trip.fcPVPd_obj1_L1_out_a=fcPVPd_obj1_L1_out_a.trip;
		/**/trip.fcPVPd_obj1_L1_out_b=fcPVPd_obj1_L1_out_b.trip;
		/**/trip.fcPVPd_obj1_L1_out_c=fcPVPd_obj1_L1_out_c.trip;
		
		/**/trip.fcPVPi_obj1_L1_out_a=fcPVPi_obj1_L1_out_a.trip;
		/**/trip.fcPVPi_obj1_L1_out_b=fcPVPi_obj1_L1_out_b.trip;
		/**/trip.fcPVPi_obj1_L1_out_c=fcPVPi_obj1_L1_out_c.trip;
			
	
	trip_words.w_str=trip;
	
	if(trip_words.w_arr[0]!=0 || trip_words.w_arr[1]!=0 || trip_words.w_arr[2]!=0){
		
		DO.bits.trip=0;
		DO.bits.LD_TRIP=1;
	
	}else{
		
		DO.bits.trip=1;
		DO.bits.LD_TRIP=0;
		fault_code=no_fault;
	
	
	}
	
	
	if(DO.bits.trip==0 && fault_code==0){
	
	switch (trip_words.w_arr[0]){
		
  	case BIT_0: 	fault_code=_50_1_a;break;/*50-1a*/
		case BIT_1: 	fault_code=_50_1_b;break;/*50-1b*/
		case BIT_2: 	fault_code=_50_1_c;break;/*50-1c*/
		
		case BIT_3: 	fault_code=_50_2_a;break;/*50-2a*/
		case BIT_4: 	fault_code=_50_2_b;break;/*50-2b*/
		case BIT_5: 	fault_code=_50_2_c;break;/*50-2c*/
		
		case BIT_6: 	fault_code=_50_3_a;break;/*50-3a*/
		case BIT_7: 	fault_code=_50_3_b;break;/*50-3b*/
		case BIT_8: 	fault_code=_50_3_c;break;/*50-3c*/
		
		case BIT_9: 	fault_code=_50_1_a_q1;break;/*50-1a_q1*/
		case BIT_10: 	fault_code=_50_1_b_q1;break;/*50-1b_q1*/
		case BIT_11: 	fault_code=_50_1_c_q1;break;/*50-1c_q1*/
		
		case BIT_12: 	fault_code=_50_2_a_q1;break;/*50-2a_q1*/
		case BIT_13: 	fault_code=_50_2_b_q1;break;/*50-2b_q1*/
		case BIT_14: 	fault_code=_50_2_c_q1;break;/*50-2c_q1*/
		
		case BIT_15: 	fault_code=_50_3_a_q1;break;/*50-3a_q1*/
		case BIT_16: 	fault_code=_50_3_b_q1;break;/*50-3b_q1*/
		case BIT_17: 	fault_code=_50_3_c_q1;break;/*50-3c_q1*/
		
		case BIT_18: 	fault_code=_50N_1;break;/*50N-a*/
		case BIT_19: 	fault_code=_50N_2;break;/*50N-b*/
		case BIT_20: 	fault_code=_50N_3;break;/*50N-c*/
		
		case BIT_21: 	fault_code=_51_a;break;/*51-a*/
		case BIT_22: 	fault_code=_51_b;break;/*51-b*/
		case BIT_23: 	fault_code=_51_c;break;/*51-c*/
		
		case BIT_24: 	fault_code=_51_a_q1;break;/*51-a-q1*/
		case BIT_25: 	fault_code=_51_b_q1;break;/*51-b-q1*/
		case BIT_26: 	fault_code=_51_c_q1;break;/*51-c-q1*/
		
		case BIT_27: 	fault_code=_51N;break;/*51-c-q1*/
		
  	
  }
	
	
	
	switch (trip_words.w_arr[1]){
			
  	case BIT_0: 	fault_code=_27_1_a;break;	/*27-1-a*/
		case BIT_1: 	fault_code=_27_1_b;break;	/*27-1-b*/
		case BIT_2: 	fault_code=_27_1_c;break;	/*27-1-c*/
		
		case BIT_3: 	fault_code=_27_2_a;break;	/*27-2-a*/
		case BIT_4: 	fault_code=_27_2_b;break;	/*27-2-b*/
		case BIT_5: 	fault_code=_27_2_c;break;	/*27-2-c*/
		
		case BIT_6: 	fault_code=_59_1a;break;	/*59-1a*/
		case BIT_7: 	fault_code=_59_1b;break; 	/*59-1b*/
		case BIT_8: 	fault_code=_59_1c;break; 	/*59-1c*/
		
		case BIT_9: 	fault_code=_59_2a;break;	/*59-2a*/
		case BIT_10: 	fault_code=_59_2b;break;	/*59-2b*/
		case BIT_11: 	fault_code=_59_2c;break;	/*59-2c*/
		
		case BIT_12: 	fault_code=_49_a_valve;break;	/*49-a-valve*/
		case BIT_13: 	fault_code=_49_b_valve;break;	/*49-b-valve*/
		case BIT_14: 	fault_code=_49_c_valve;break;	/*49-c-valve*/
		
		case BIT_16: 	fault_code=_49_a_reactor;break;	/*49-a-res*/
		case BIT_17: 	fault_code=_49_b_reactor;break;	/*49-b-res*/
		case BIT_18: 	fault_code=_49_c_reactor;break;	/*49-c-res*/
		
		case BIT_19: 	fault_code=_37_a;break;	/*37-a*/
		case BIT_20: 	fault_code=_37_a;break;	/*37-b*/
		case BIT_21: 	fault_code=_37_a;break;	/*37-c*/
		
		
  }
	
	
	
	switch (trip_words.w_arr[2]){
			

		
		
		
		}
	
	}
	
	
}





void pick_trip_reset_handles(){


	pick_up_handles();
	reset_handles();
	trip_handles();

}
