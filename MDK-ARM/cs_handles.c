

#include "measurement_functions.h"
#include "conversion.h"
#include "cs_handles.h"
#include "nfbm.h"
#include <math.h>

#define N 						50
#define cs_scale 			0.04f
#define cs_rms_scale 	0.7071067811865475f

struct AdcData fRMS;

struct phase_cs_in phase_cs_A={0};
struct phase_cs_in phase_cs_B={0};
struct phase_cs_in phase_cs_C={0};

struct phase_cs_in phase_cs_TCR_A={0};
struct phase_cs_in phase_cs_TCR_B={0};
struct phase_cs_in phase_cs_TCR_C={0};
struct phase_cs_in phase_cs_TCR_N={0};

struct phase_cs_in phase_cs_TCR_AB={0};
struct phase_cs_in phase_cs_TCR_BC={0};
struct phase_cs_in phase_cs_TCR_CA={0};


struct phase_cs_out phase_cs_A_out={0};
struct phase_cs_out phase_cs_B_out={0};
struct phase_cs_out phase_cs_C_out={0};

struct phase_cs_out phase_cs_TCR_A_out={0};
struct phase_cs_out phase_cs_TCR_B_out={0};
struct phase_cs_out phase_cs_TCR_C_out={0};
struct phase_cs_out phase_cs_TCR_N_out={0};

struct phase_cs_out phase_cs_TCR_AB_out={0};
struct phase_cs_out phase_cs_TCR_BC_out={0};
struct phase_cs_out phase_cs_TCR_CA_out={0};

struct sym_out sym={0};
struct sym_out sym_hist={0};
struct sym_out mag_sym={0};

struct sym_out sym_tcr={0};
struct sym_out sym_hist_tcr={0};
struct sym_out mag_sym_tcr={0};


float c_buffer[channelNo][N]={0};
float s_buffer[channelNo][N]={0};

struct powerParameters P={0};
struct powerParameters Q={0};

struct powerParameters P_TCR={0};
struct powerParameters Q_TCR={0};


float sin_coeffs[]={
0.06279052048921585083f,
0.18738131225109100341f,0.30901700258255004882f,0.42577928304672241210f,
0.53582680225372314453f,0.63742399215698242187f,0.72896862030029296875f,
0.80901700258255004882f,0.87630665302276611328f,0.92977648973464965820f,
0.96858316659927368164f,0.99211472272872924804f,1.00000000000000000000f,
0.99211472272872924804f,0.96858316659927368164f,0.92977648973464965820f,
0.87630665302276611328f,0.80901700258255004882f,0.72896862030029296875f,
0.63742399215698242187f,0.53582680225372314453f,0.42577928304672241210f,
0.30901700258255004882f,0.18738131225109100341f,0.06279052048921585083f,
-0.06279052048921585083f,-0.18738131225109100341f,-0.30901700258255004882f,
-0.42577928304672241210f,-0.53582680225372314453f,-0.63742399215698242187f,
-0.72896862030029296875f,-0.80901700258255004882f,-0.87630665302276611328f,
-0.92977648973464965820f,-0.96858316659927368164f,-0.99211472272872924804f,
-1.00000000000000000000f,-0.99211472272872924804f,-0.96858316659927368164f,
-0.92977648973464965820f,-0.87630665302276611328f,-0.80901700258255004882f,
-0.72896862030029296875f,-0.63742399215698242187f,-0.53582680225372314453f,
-0.42577928304672241210f,-0.30901700258255004882f,-0.18738131225109100341f,
-0.06279052048921585083f};

float cos_coeffs[]={
0.99802672863006591796f,
0.98228722810745239257f,0.95105654001235961914f,0.90482705831527709960f,
0.84432792663574218750f,0.77051323652267456054f,0.68454712629318237304f,
0.58778524398803710937f,0.48175367712974548339f,0.36812454462051391601f,
0.24868988990783691406f,0.12533323466777801513f,0.00000000000000038286f,
-0.12533323466777801513f,-0.24868988990783691406f,-0.36812454462051391601f,
-0.48175367712974548339f,-0.58778524398803710937f,-0.68454712629318237304f,
-0.77051323652267456054f,-0.84432792663574218750f,-0.90482705831527709960f,
-0.95105654001235961914f,-0.98228722810745239257f,-0.99802672863006591796f,
-0.99802672863006591796f,-0.98228722810745239257f,-0.95105654001235961914f,
-0.90482705831527709960f,-0.84432792663574218750f,-0.77051323652267456054f,
-0.68454712629318237304f,-0.58778524398803710937f,-0.48175367712974548339f,
-0.36812454462051391601f,-0.24868988990783691406f,-0.12533323466777801513f,
0.00000000000000038286f,0.12533323466777801513f,0.24868988990783691406f,
0.36812454462051391601f,0.48175367712974548339f,0.58778524398803710937f,
0.68454712629318237304f,0.77051323652267456054f,0.84432792663574218750f,
0.90482705831527709960f,0.95105654001235961914f,0.98228722810745239257f,
0.99802672863006591796f};



void cs_PQ_combination(void){
	
	
	//P=INC
	
	P.a=phase_cs_A_out.P;
	P.b=phase_cs_B_out.P;
	P.c=phase_cs_C_out.P;
	
	P.ab=P.a+P.b-P.c;
	P.bc=P.b+P.c-P.a;
	P.ca=P.c+P.a-P.b;
	
	P.total=P.a+P.b+P.c;
	
	//Q=INC
	
	Q.a=phase_cs_A_out.Q;
	Q.b=phase_cs_B_out.Q;
	Q.c=phase_cs_C_out.Q;
	
	Q.ab=Q.a+Q.b-Q.c;
	Q.bc=Q.b+Q.c-Q.a;
	Q.ca=Q.c+Q.a-Q.b;
	
	Q.total=Q.a+Q.b+Q.c; 
	
	
	//P-TCR
	
	P_TCR.a=phase_cs_TCR_A_out.P;
	P_TCR.b=phase_cs_TCR_B_out.P;
	P_TCR.c=phase_cs_TCR_C_out.P;
	
	P_TCR.ab=P_TCR.a+P_TCR.b-P_TCR.c;
	P_TCR.bc=P_TCR.b+P_TCR.c-P_TCR.a;
	P_TCR.ca=P_TCR.c+P_TCR.a-P_TCR.b;
	
	P_TCR.total=P_TCR.a+P_TCR.b+P_TCR.c;
	
	//Q-TCR
	
	Q_TCR.a=phase_cs_TCR_A_out.Q;
	Q_TCR.b=phase_cs_TCR_B_out.Q;
	Q_TCR.c=phase_cs_TCR_C_out.Q;
	
	Q_TCR.ab=Q_TCR.a+Q_TCR.b-Q_TCR.c;
	Q_TCR.bc=Q_TCR.b+Q_TCR.c-Q_TCR.a;
	Q_TCR.ca=Q_TCR.c+Q_TCR.a-Q_TCR.b;
	
	Q_TCR.total=Q_TCR.a+Q_TCR.b+Q_TCR.c; 



}






void cs_handles(){

	
	
	
	
	//-PA
	
	phase_cs_A.Vc= 	cs_generation(fAdc.sAdc.Van,cos_coeffs,N,&c_buffer[0][0])*cs_scale;
	phase_cs_A.Vs= 	cs_generation(fAdc.sAdc.Van,sin_coeffs,N,&s_buffer[0][0])*cs_scale;
	
	phase_cs_A.Ic= 	cs_generation(fAdc.sAdc.Ia,cos_coeffs,N,&c_buffer[1][0])*cs_scale;
	phase_cs_A.Is= 	cs_generation(fAdc.sAdc.Ia,sin_coeffs,N,&s_buffer[1][0])*cs_scale;
	

	cs_computations(phase_cs_A,&phase_cs_A_out);
	
	
	//-PB
	
	phase_cs_B.Vc= 	cs_generation(fAdc.sAdc.Vbn,cos_coeffs,N,&c_buffer[2][0])*cs_scale;
	phase_cs_B.Vs= 	cs_generation(fAdc.sAdc.Vbn,sin_coeffs,N,&s_buffer[2][0])*cs_scale;
	
	phase_cs_B.Ic= 	cs_generation(fAdc.sAdc.Ib,cos_coeffs,N,&c_buffer[3][0])*cs_scale;
	phase_cs_B.Is= 	cs_generation(fAdc.sAdc.Ib,sin_coeffs,N,&s_buffer[3][0])*cs_scale;
	

	cs_computations(phase_cs_B,&phase_cs_B_out);


	
	//-PC
	
	
	phase_cs_C.Vc= 	cs_generation(fAdc.sAdc.Vcn,cos_coeffs,N,&c_buffer[4][0])*cs_scale;
	phase_cs_C.Vs= 	cs_generation(fAdc.sAdc.Vcn,sin_coeffs,N,&s_buffer[4][0])*cs_scale;
	
	phase_cs_C.Ic= 	cs_generation(fAdc.sAdc.Ic,cos_coeffs,N,&c_buffer[5][0])*cs_scale;
	phase_cs_C.Is= 	cs_generation(fAdc.sAdc.Ic,sin_coeffs,N,&s_buffer[5][0])*cs_scale;
	

	cs_computations(phase_cs_C,&phase_cs_C_out);
	

	
	//-P-TCR-A
	
	phase_cs_TCR_A.Vc=phase_cs_A.Vc;
	phase_cs_TCR_A.Vs=phase_cs_A.Vs;
	
	phase_cs_TCR_A.Ic= 	cs_generation(fAdc.sAdc.ITCR_a,cos_coeffs,N,&c_buffer[6][0])*cs_scale;
	phase_cs_TCR_A.Is= 	cs_generation(fAdc.sAdc.ITCR_a,sin_coeffs,N,&s_buffer[6][0])*cs_scale;
	
	cs_computations(phase_cs_TCR_A,&phase_cs_TCR_A_out);
	

	//-P-TCR-B
	
	phase_cs_TCR_B.Vc=phase_cs_B.Vc;
	phase_cs_TCR_B.Vs=phase_cs_B.Vs;
	
	phase_cs_TCR_B.Ic= 	cs_generation(fAdc.sAdc.ITCR_b,cos_coeffs,N,&c_buffer[7][0])*cs_scale;
	phase_cs_TCR_B.Is= 	cs_generation(fAdc.sAdc.ITCR_b,sin_coeffs,N,&s_buffer[7][0])*cs_scale;
	

	cs_computations(phase_cs_TCR_B,&phase_cs_TCR_B_out);
	
	
	
	//-P-TCR-C
	
	phase_cs_TCR_C.Vc=phase_cs_C.Vc;
	phase_cs_TCR_C.Vs=phase_cs_C.Vs;
	
	phase_cs_TCR_C.Ic= 	cs_generation(fAdc.sAdc.ITCR_c,cos_coeffs,N,&c_buffer[8][0])*cs_scale;
	phase_cs_TCR_C.Is= 	cs_generation(fAdc.sAdc.ITCR_c,sin_coeffs,N,&s_buffer[8][0])*cs_scale;
	

	cs_computations(phase_cs_TCR_C,&phase_cs_TCR_C_out);
	
	
	
	//-N-TCR
	
	phase_cs_TCR_N.Ic= 	cs_generation(fAdc.sAdc.ITCR_N,cos_coeffs,N,&c_buffer[9][0])*cs_scale;
	phase_cs_TCR_N.Is= 	cs_generation(fAdc.sAdc.ITCR_N,sin_coeffs,N,&s_buffer[9][0])*cs_scale;
	
	fRMS.ITCR_N= sqrtf(phase_cs_TCR_N.Ic*phase_cs_TCR_N.Ic +  phase_cs_TCR_N.Is*phase_cs_TCR_N.Is);
	
	
	//tcr delta
	
	phase_cs_TCR_AB.Ic= cs_generation(fAdc.sAdc.ITCR_ab,cos_coeffs,N,&c_buffer[10][0])*cs_scale;
	phase_cs_TCR_AB.Is= cs_generation(fAdc.sAdc.ITCR_ab,sin_coeffs,N,&s_buffer[10][0])*cs_scale;
	
	phase_cs_TCR_BC.Ic= cs_generation(fAdc.sAdc.ITCR_bc,cos_coeffs,N,&c_buffer[10][0])*cs_scale;
	phase_cs_TCR_BC.Is= cs_generation(fAdc.sAdc.ITCR_bc,sin_coeffs,N,&s_buffer[10][0])*cs_scale;
	
	phase_cs_TCR_CA.Ic= cs_generation(fAdc.sAdc.ITCR_ca,cos_coeffs,N,&c_buffer[10][0])*cs_scale;
	phase_cs_TCR_CA.Is= cs_generation(fAdc.sAdc.ITCR_ca,sin_coeffs,N,&s_buffer[10][0])*cs_scale;
	
	fRMS.ITCR_ab= sqrtf(phase_cs_TCR_AB.Ic*phase_cs_TCR_AB.Ic +  phase_cs_TCR_AB.Is*phase_cs_TCR_AB.Is);
	fRMS.ITCR_bc= sqrtf(phase_cs_TCR_BC.Ic*phase_cs_TCR_BC.Ic +  phase_cs_TCR_BC.Is*phase_cs_TCR_BC.Is);
	fRMS.ITCR_ca= sqrtf(phase_cs_TCR_CA.Ic*phase_cs_TCR_CA.Ic +  phase_cs_TCR_CA.Is*phase_cs_TCR_CA.Is);
	
	//-Seq Comp
	
	sym_comp(phase_cs_A,phase_cs_B,phase_cs_C, &sym);
	sym_mag(sym,&sym_hist,&mag_sym);
	
	sym_comp(phase_cs_TCR_A,phase_cs_TCR_B,phase_cs_TCR_C, &sym);
	sym_mag(sym_tcr,&sym_hist_tcr,&mag_sym_tcr);
	
	
	

	// PQ comb

	cs_PQ_combination();


}











