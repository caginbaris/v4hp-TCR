#include "nfbm.h"
#include "plib_handles.h"
#include "plib_definitions.h"
#include "boardIO.h"
#include "externalData.h"
#include "bit_expansion.h"
#include "alarms.h"

#define totalPick 62
#define pickHold 1000

 struct plib_handles pick={0};
 struct plib_handles trip={0};

union ToWord pick_words={0};
union ToWord trip_words={0};

static long pick_buffer[totalPick]={0};

enum fault_codes fault_code=no_fault;


extern uint8_t eraseError;
extern uint8_t writeError;



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
		
		
		
  	break;
		
  	case 1:
			
		pick.fc50_obj1_L3_out_a=off_delay(fc50_obj1_L3_out_a.pick_up, pick.fc50_obj1_L3_out_a, pickHold, &pick_buffer[6]);
		pick.fc50_obj1_L3_out_b=off_delay(fc50_obj1_L3_out_b.pick_up, pick.fc50_obj1_L3_out_b, pickHold, &pick_buffer[7]);
		pick.fc50_obj1_L3_out_c=off_delay(fc50_obj1_L3_out_c.pick_up, pick.fc50_obj1_L3_out_c, pickHold, &pick_buffer[8]);
		

		pick.fc50N_obj1_L1_out=off_delay(fc50N_obj1_L1_out.pick_up, pick.fc50N_obj1_L1_out, pickHold, &pick_buffer[9]);
		pick.fc50N_obj1_L2_out=off_delay(fc50N_obj1_L2_out.pick_up, pick.fc50N_obj1_L2_out, pickHold, &pick_buffer[10]);
		pick.fc50N_obj1_L3_out=off_delay(fc50N_obj1_L3_out.pick_up, pick.fc50N_obj1_L3_out, pickHold, &pick_buffer[11]);	
			
  	break;
		
		
		
		case 2:
			
		
		pick.fc51_obj1_out_a=off_delay(fc51_obj1_out_a.pick_up, pick.fc51_obj1_out_a,pickHold,&pick_buffer[12]);
		pick.fc51_obj1_out_b=off_delay(fc51_obj1_out_b.pick_up, pick.fc51_obj1_out_b,pickHold,&pick_buffer[13]);	
		pick.fc51_obj1_out_c=off_delay(fc51_obj1_out_c.pick_up, pick.fc51_obj1_out_c,pickHold,&pick_buffer[14]);		

		pick.fc51N_obj1_out=off_delay(fc51N_obj1_out.pick_up, pick.fc51N_obj1_out,pickHold,&pick_buffer[15]);
		
		pick.fc27_obj1_L1_out=off_delay(fc27_obj1_L1_out.pick_up, pick.fc27_obj1_L1_out,pickHold,&pick_buffer[16]);
		pick.fc27_obj1_L2_out=off_delay(fc27_obj1_L2_out.pick_up, pick.fc27_obj1_L2_out,pickHold,&pick_buffer[17]);	

		break;
				
		case 3:
			
		
		pick.fc59_obj1_L1_out_a=off_delay(fc59_obj1_L1_out_a.pick_up, pick.fc59_obj1_L1_out_a,pickHold,&pick_buffer[18]);
		pick.fc59_obj1_L1_out_b=off_delay(fc59_obj1_L1_out_b.pick_up, pick.fc59_obj1_L1_out_b,pickHold,&pick_buffer[19]);
		pick.fc59_obj1_L1_out_c=off_delay(fc59_obj1_L1_out_c.pick_up, pick.fc59_obj1_L1_out_c,pickHold,&pick_buffer[20]);
		
		pick.fc59_obj1_L2_out_a=off_delay(fc59_obj1_L2_out_a.pick_up, pick.fc59_obj1_L2_out_a,pickHold,&pick_buffer[21]);
		pick.fc59_obj1_L2_out_b=off_delay(fc59_obj1_L2_out_b.pick_up, pick.fc59_obj1_L2_out_b,pickHold,&pick_buffer[22]);
		pick.fc59_obj1_L2_out_c=off_delay(fc59_obj1_L2_out_c.pick_up, pick.fc59_obj1_L2_out_c,pickHold,&pick_buffer[23]);
			

		break;
		
		
		
		case 4:
			
		pick.fc49_obj1_L1_out_a=off_delay(fc49_obj1_L1_out_a.alarm, pick.fc49_obj1_L1_out_a,pickHold,&pick_buffer[24]);
		pick.fc49_obj1_L1_out_b=off_delay(fc49_obj1_L1_out_b.alarm, pick.fc49_obj1_L1_out_b,pickHold,&pick_buffer[25]);
		pick.fc49_obj1_L1_out_c=off_delay(fc49_obj1_L1_out_c.alarm, pick.fc49_obj1_L1_out_c,pickHold,&pick_buffer[26]);
		
		pick.fc49_obj2_L1_out_a=off_delay(fc49_obj2_L1_out_a.alarm, pick.fc49_obj2_L1_out_a,pickHold,&pick_buffer[27]);
		pick.fc49_obj2_L1_out_b=off_delay(fc49_obj2_L1_out_b.alarm, pick.fc49_obj2_L1_out_b,pickHold,&pick_buffer[28]);
		pick.fc49_obj2_L1_out_c=off_delay(fc49_obj2_L1_out_c.alarm, pick.fc49_obj2_L1_out_c,pickHold,&pick_buffer[29]);

			
		break;
		
		
		case 5:
			
		pick.fc37_obj1_L1_out_a=off_delay(fc37_obj1_L1_out_a.pick_up,pick.fc37_obj1_L1_out_a,pickHold,&pick_buffer[30]);
		pick.fc37_obj1_L1_out_b=off_delay(fc37_obj1_L1_out_b.pick_up,pick.fc37_obj1_L1_out_b,pickHold,&pick_buffer[31]);
		pick.fc37_obj1_L1_out_c=off_delay(fc37_obj1_L1_out_c.pick_up,pick.fc37_obj1_L1_out_c,pickHold,&pick_buffer[32]);
			
		break;
	
		
		
	
		
  }
	
	

	if(++pick_up_counter==6){pick_up_counter=0;}
	
	
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
		
		
		if(!pick.fc50N_obj1_L1_out){fc50N_obj1_L1_out.trip_latch=0;}
		if(!pick.fc50N_obj1_L2_out){fc50N_obj1_L2_out.trip_latch=0;}
		if(!pick.fc50N_obj1_L3_out){fc50N_obj1_L3_out.trip_latch=0;}
		
		
		if(!pick.fc51_obj1_out_a){fc51_obj1_out_a.trip=0;}
		if(!pick.fc51_obj1_out_b){fc51_obj1_out_b.trip=0;}
		if(!pick.fc51_obj1_out_c){fc51_obj1_out_c.trip=0;}
	
		if(!pick.fc51N_obj1_out){fc51N_obj1_out.trip=0;}
		
		
		if(!pick.fc27_obj1_L1_out){fc27_obj1_L1_out.trip=0;}
		if(!pick.fc27_obj1_L2_out){fc27_obj1_L2_out.trip=0;}
		

		if(!pick.fc59_obj1_L1_out_a){fc59_obj1_L1_out_a.trip=0;}
		if(!pick.fc59_obj1_L1_out_b){fc59_obj1_L1_out_b.trip=0;}
		if(!pick.fc59_obj1_L1_out_c){fc59_obj1_L1_out_c.trip=0;}
		
		if(!pick.fc59_obj1_L2_out_a){fc59_obj1_L2_out_a.trip=0;}
		if(!pick.fc59_obj1_L2_out_b){fc59_obj1_L2_out_b.trip=0;}
		if(!pick.fc59_obj1_L2_out_c){fc59_obj1_L2_out_c.trip=0;}
		
		

		if(!pick.fc49_obj1_L1_out_a){fc49_obj1_L1_out_a.trip=0;}
		if(!pick.fc49_obj1_L1_out_b){fc49_obj1_L1_out_b.trip=0;}
		if(!pick.fc49_obj1_L1_out_c){fc49_obj1_L1_out_c.trip=0;}
		
		if(!pick.fc49_obj2_L1_out_a){fc49_obj2_L1_out_a.trip=0;}
		if(!pick.fc49_obj2_L1_out_b){fc49_obj2_L1_out_b.trip=0;}
		if(!pick.fc49_obj2_L1_out_c){fc49_obj2_L1_out_c.trip=0;}
		
		if(!pick.fc37_obj1_L1_out_a){fc37_obj1_L1_out_a.trip=0;}
		if(!pick.fc37_obj1_L1_out_b){fc37_obj1_L1_out_b.trip=0;}
		if(!pick.fc37_obj1_L1_out_c){fc37_obj1_L1_out_c.trip=0;}


		
	
		
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
	
		/**/trip.fc50_obj1_L3_out_a=fc50_obj1_L3_out_a.trip_latch;
		/**/trip.fc50_obj1_L3_out_b=fc50_obj1_L3_out_b.trip_latch;	
		/**/trip.fc50_obj1_L3_out_c=fc50_obj1_L3_out_c.trip_latch;	
		
		/**/trip.fc50N_obj1_L1_out=fc50N_obj1_L1_out.trip_latch;
		/**/trip.fc50N_obj1_L2_out=fc50N_obj1_L2_out.trip_latch;
		/**/trip.fc50N_obj1_L3_out=fc50N_obj1_L3_out.trip_latch;			
	
		/**/trip.fc51_obj1_out_a=fc51_obj1_out_a.trip;
		/**/trip.fc51_obj1_out_b=fc51_obj1_out_b.trip;	
		/**/trip.fc51_obj1_out_c=fc51_obj1_out_c.trip;
		
		/**/trip.fc51N_obj1_out=fc51N_obj1_out.trip;
		
		/**/trip.fc27_obj1_L1_out=fc27_obj1_L1_out.trip;
		/**/trip.fc27_obj1_L2_out=fc27_obj1_L2_out.trip;
		
		/**/trip.fc59_obj1_L1_out_a=fc59_obj1_L1_out_a.trip;
		/**/trip.fc59_obj1_L1_out_b=fc59_obj1_L1_out_b.trip;
		/**/trip.fc59_obj1_L1_out_c=fc59_obj1_L1_out_c.trip;
		
		/**/trip.fc59_obj1_L2_out_a=fc59_obj1_L2_out_a.trip;
		/**/trip.fc59_obj1_L2_out_b=fc59_obj1_L2_out_b.trip;
		/**/trip.fc59_obj1_L2_out_c=fc59_obj1_L2_out_c.trip;
		
		/**/trip.fc49_obj1_L1_out_a=fc49_obj1_L1_out_a.trip;
		/**/trip.fc49_obj1_L1_out_b=fc49_obj1_L1_out_b.trip;
		/**/trip.fc49_obj1_L1_out_c=fc49_obj1_L1_out_c.trip;
	
		/**/trip.fc49_obj2_L1_out_a=fc49_obj2_L1_out_a.trip;
		/**/trip.fc49_obj2_L1_out_b=fc49_obj2_L1_out_b.trip;
		/**/trip.fc49_obj2_L1_out_c=fc49_obj2_L1_out_c.trip;
		
			
		/**/trip.fc37_obj1_L1_out_a=fc37_obj1_L1_out_a.trip;
		/**/trip.fc37_obj1_L1_out_b=fc37_obj1_L1_out_b.trip;
		/**/trip.fc37_obj1_L1_out_c=fc37_obj1_L1_out_c.trip;
		

			
	
	trip_words.w_str=trip;
	alarm.bit.flashError=(writeError|eraseError);
	
	if(trip_words.w_arr[0]!=0 || trip_words.w_arr[1]!=0 || trip_words.w_arr[2]!=0 || trip_words.w_arr[1]!=0 || trip_words.w_arr[2]!=0  || (alarm.bit.configDataReception==0 || alarm.bit.flashError==1)){
		
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
		
		case BIT_18: 	fault_code=_50N_1;break;/*50-1a*/
		case BIT_19: 	fault_code=_50N_2;break;/*50-1b*/
		case BIT_20: 	fault_code=_50N_3;break;/*50-1c*/
		
		case BIT_21: 	fault_code=_51_a;break;/*51-a*/
		case BIT_22: 	fault_code=_51_b;break;/*51-b*/
		case BIT_23: 	fault_code=_51_c;break;/*51-c*/
		
		case BIT_27: 	fault_code=_51N;break;/*51-c*/
		
  	
  }
	
	
	
	switch (trip_words.w_arr[1]){
			
  	case BIT_0: 	fault_code=_27_1;break;	/*27-1-a*/
		case BIT_1: 	fault_code=_27_2;break;	/*27-1-b*/

		case BIT_2: 	fault_code=_59_1a;break;	/*59-1a*/
		case BIT_3: 	fault_code=_59_1b;break; 	/*59-1b*/
		case BIT_4: 	fault_code=_59_1c;break; 	/*59-1c*/
		
		case BIT_5: 	fault_code=_59_2a;break;	/*59-2a*/
		case BIT_6: 	fault_code=_59_2b;break;	/*59-2b*/
		case BIT_7: 	fault_code=_59_2c;break;	/*59-2c*/
		
		case BIT_10: 	fault_code=_49_a_reactor;break;	/*49-a-valve*/
		case BIT_11: 	fault_code=_49_b_reactor;break;	/*49-b-valve*/
		case BIT_12: 	fault_code=_49_c_reactor;break;	/*49-c-valve*/
		
		case BIT_16: 	fault_code=_49_a_valve;break;	/*49-a-res*/
		case BIT_17: 	fault_code=_49_b_valve;break;	/*49-b-res*/
		case BIT_18: 	fault_code=_49_c_valve;break;	/*49-c-res*/
		

		
		
  }
	
	
	
	switch (trip_words.w_arr[2]){
			

		case BIT_0: 	fault_code=_37_a;break;	/*59-1a*/
		case BIT_1: 	fault_code=_37_b;break; 	/*59-1b*/
		case BIT_2: 	fault_code=_37_c;break; 	/*59-1c*/
		
		
		}
	
	}
	
	
}





void pick_trip_reset_handles(){

	static long unlatch_counter=0;
	static uint8_t unlatch=0;
	
	pick_up_handles();
	reset_handles();
	trip_handles();
	
	//unlatch=on_off_delay(DO.bits.trip,unlatch,600,&unlatch_counter);
	
	//if(unlatch){DI.bit.reset=1;}
	

}
