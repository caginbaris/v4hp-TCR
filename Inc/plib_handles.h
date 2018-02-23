
#ifndef __plib_handles_h
#define __plib_handles_h


#include "stdint.h"


//fc50-----------------------------------------------18 obj,total=18


extern struct fc50_outputParameters fc50_obj1_L1_out_a;
extern struct fc50_outputParameters fc50_obj1_L1_out_b;
extern struct fc50_outputParameters fc50_obj1_L1_out_c;

extern struct fc50_outputParameters fc50_obj1_L2_out_a;
extern struct fc50_outputParameters fc50_obj1_L2_out_b;
extern struct fc50_outputParameters fc50_obj1_L2_out_c;

extern struct fc50_outputParameters fc50_obj1_L3_out_a;
extern struct fc50_outputParameters fc50_obj1_L3_out_b;
extern struct fc50_outputParameters fc50_obj1_L3_out_c;



extern struct fc50_outputParameters fc50_obj2_L1_out_a;
extern struct fc50_outputParameters fc50_obj2_L1_out_b;
extern struct fc50_outputParameters fc50_obj2_L1_out_c;

extern struct fc50_outputParameters fc50_obj2_L2_out_a;
extern struct fc50_outputParameters fc50_obj2_L2_out_b;
extern struct fc50_outputParameters fc50_obj2_L2_out_c;

extern struct fc50_outputParameters fc50_obj2_L3_out_a;
extern struct fc50_outputParameters fc50_obj2_L3_out_b;
extern struct fc50_outputParameters fc50_obj2_L3_out_c;


//fc50N------------------------------------------------3 obj,,total=21


extern struct fc50_outputParameters fc50N_obj1_L1_out;
extern struct fc50_outputParameters fc50N_obj1_L2_out;
extern struct fc50_outputParameters fc50N_obj1_L3_out;


//fc51------------------------------------------------6 obj,total=27

extern struct fc51_outputParameters fc51_obj1_out_a;
extern struct fc51_outputParameters fc51_obj1_out_b;
extern struct fc51_outputParameters fc51_obj1_out_c;

extern struct fc51_outputParameters fc51_obj2_out_a;
extern struct fc51_outputParameters fc51_obj2_out_b;
extern struct fc51_outputParameters fc51_obj2_out_c;

//fc51N-----------------------------------------------1 obj,,total=28

extern struct fc51_outputParameters 	fc51N_obj1_out;

//fc27------------------------------------------------2 obj,,total=30

extern struct fc27_outputParameters fc27_obj1_L1_out;
extern struct fc27_outputParameters fc27_obj1_L2_out;


//fc59------------------------------------------------6 obj,total=36


extern struct fc59_outputParameters fc59_obj1_L1_out_a;
extern struct fc59_outputParameters fc59_obj1_L1_out_b;
extern struct fc59_outputParameters fc59_obj1_L1_out_c;

extern struct fc59_outputParameters fc59_obj1_L2_out_a;
extern struct fc59_outputParameters fc59_obj1_L2_out_b;
extern struct fc59_outputParameters fc59_obj1_L2_out_c;


//fc46di----------------------------------------------2 obj,total=38

extern struct fc46d_outputParameters fc46d_obj1_L1_out;
extern struct fc46i_outputParameters fc46i_obj1_L1_out;


//fc49------------------------------------------------12 obj,total=50


extern struct fc49_outputParameters fc49_obj1_L1_out_a;
extern struct fc49_outputParameters fc49_obj1_L1_out_b;
extern struct fc49_outputParameters fc49_obj1_L1_out_c;

extern struct fc49_outputParameters fc49_obj1_L2_out_a;
extern struct fc49_outputParameters fc49_obj1_L2_out_b;
extern struct fc49_outputParameters fc49_obj1_L2_out_c;

extern struct fc49_outputParameters fc49_obj2_L1_out_a;
extern struct fc49_outputParameters fc49_obj2_L1_out_b;
extern struct fc49_outputParameters fc49_obj2_L1_out_c;

extern struct fc49_outputParameters fc49_obj2_L2_out_a;
extern struct fc49_outputParameters fc49_obj2_L2_out_b;
extern struct fc49_outputParameters fc49_obj2_L2_out_c;

//fcBF------------------------------------------------1 obj,total=51

extern struct fcBF_outputParameters fcBF_out;

//fc37------------------------------------------------6 obj,total=57


extern struct fc37_outputParameters fc37_obj1_L1_out_a;
extern struct fc37_outputParameters fc37_obj1_L1_out_b;
extern struct fc37_outputParameters fc37_obj1_L1_out_c;

extern struct fc37_outputParameters fc37_obj2_L1_out_a;
extern struct fc37_outputParameters fc37_obj2_L1_out_b;
extern struct fc37_outputParameters fc37_obj2_L1_out_c;

//fcUNB------------------------------------------------4 obj,total=61


extern struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_a;
extern struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_b;

extern struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_a;
extern struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_b;


//fcPVP------------------------------------------------6 obj,total=67

extern struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_a;
extern struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_b;
extern struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_c;

extern struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_a;
extern struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_b;
extern struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_c;



struct plib_handles{
	
//fc50-----------------------------------------------18 obj,total=18	
	
uint32_t fc50_obj1_L1_out_a:1;
uint32_t fc50_obj1_L1_out_b:1;
uint32_t fc50_obj1_L1_out_c:1;

uint32_t fc50_obj1_L2_out_a:1;
uint32_t fc50_obj1_L2_out_b:1;
uint32_t fc50_obj1_L2_out_c:1;

uint32_t fc50_obj1_L3_out_a:1;
uint32_t fc50_obj1_L3_out_b:1;
uint32_t fc50_obj1_L3_out_c:1;



uint32_t fc50_obj2_L1_out_a:1;
uint32_t fc50_obj2_L1_out_b:1;
uint32_t fc50_obj2_L1_out_c:1;

uint32_t fc50_obj2_L2_out_a:1;
uint32_t fc50_obj2_L2_out_b:1;
uint32_t fc50_obj2_L2_out_c:1;

uint32_t fc50_obj2_L3_out_a:1;
uint32_t fc50_obj2_L3_out_b:1;
uint32_t fc50_obj2_L3_out_c:1;


//fc50N------------------------------------------------3 obj,total=21


uint32_t fc50N_obj1_L1_out:1;
uint32_t fc50N_obj1_L2_out:1;
uint32_t fc50N_obj1_L3_out:1;


//fc51------------------------------------------------6 obj,total=27

uint32_t fc51_obj1_out_a:1;
uint32_t fc51_obj1_out_b:1;
uint32_t fc51_obj1_out_c:1;

uint32_t fc51_obj2_out_a:1;
uint32_t fc51_obj2_out_b:1;
uint32_t fc51_obj2_out_c:1;



//fc51N-----------------------------------------------1 obj,total=28

uint32_t fc51N_obj1_out:1;
uint32_t W1_spare:4;

//fc27------------------------------------------------2 obj,total=30

uint32_t fc27_obj1_L1_out:1;
uint32_t fc27_obj1_L2_out:1;


//fc59------------------------------------------------6 obj,total=36


uint32_t fc59_obj1_L1_out_a:1;
uint32_t fc59_obj1_L1_out_b:1;
uint32_t fc59_obj1_L1_out_c:1;

uint32_t fc59_obj1_L2_out_a:1;
uint32_t fc59_obj1_L2_out_b:1;
uint32_t fc59_obj1_L2_out_c:1;


//fc46di----------------------------------------------2 obj,total=38

uint32_t fc46d_obj1_L1_out:1;
uint32_t fc46i_obj1_L1_out:1;


//fc49------------------------------------------------6 obj,total=44


uint32_t fc49_obj1_L1_out_a:1;
uint32_t fc49_obj1_L1_out_b:1;
uint32_t fc49_obj1_L1_out_c:1;

uint32_t fc49_obj1_L2_out_a:1;  //cau disc
uint32_t fc49_obj1_L2_out_b:1;	//cau disc
uint32_t fc49_obj1_L2_out_c:1;	//cau disc

uint32_t fc49_obj2_L1_out_a:1;
uint32_t fc49_obj2_L1_out_b:1;
uint32_t fc49_obj2_L1_out_c:1;

uint32_t fc49_obj2_L2_out_a:1;  //cau disc
uint32_t fc49_obj2_L2_out_b:1;	//cau disc
uint32_t fc49_obj2_L2_out_c:1;	//cau disc

//fcBF------------------------------------------------1 obj,total=45

uint32_t fcBF_out:1;

uint32_t W2_spare:9;

//fc37------------------------------------------------6 obj,total=51


uint32_t fc37_obj1_L1_out_a:1;
uint32_t fc37_obj1_L1_out_b:1;
uint32_t fc37_obj1_L1_out_c:1;

uint32_t fc37_obj2_L1_out_a:1;
uint32_t fc37_obj2_L1_out_b:1;
uint32_t fc37_obj2_L1_out_c:1;

//fcUNB------------------------------------------------4 obj,total=55


uint32_t fcUNBd_obj1_L1_out_a:1;
uint32_t fcUNBd_obj1_L1_out_b:1;

uint32_t W3_spare:1;

uint32_t fcUNBi_obj1_L1_out_a:1;
uint32_t fcUNBi_obj1_L1_out_b:1;


uint32_t W4_spare:1;


//fcPVP------------------------------------------------6 obj,total=61

uint32_t fcPVPd_obj1_L1_out_a:1;
uint32_t fcPVPd_obj1_L1_out_b:1;
uint32_t fcPVPd_obj1_L1_out_c:1;

uint32_t fcPVPi_obj1_L1_out_a:1;
uint32_t fcPVPi_obj1_L1_out_b:1;
uint32_t fcPVPi_obj1_L1_out_c:1;	


uint32_t W5_spare:14;
	


};

#endif


