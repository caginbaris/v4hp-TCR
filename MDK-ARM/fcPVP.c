#include "measurement_functions.h"
#include "plib_definitions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "cs_handles.h"
#include "pDataConfigs.h"

#define ts (1.0f)/fs
#define N 50

struct pvp_data pvp_in={0};
struct pvp_data pvp_in_back={0};
struct pvp_data pvp_out={0};
struct pvp_data pvp_out_back={0};


struct fcPVPd_inputParameters fcPVPd_obj1_L1_in;
struct fcPVPi_inputParameters fcPVPi_obj1_L1_in;


struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_a={0};
struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_b={0};
struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_c={0};

struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_a={0};
struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_b={0};
struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_c={0};


float pvp_coefficents[101]={
-0.00499511956678885990
, -0.00021448154440842221
, -0.00001878414314248408
, 0.00024656380964603114
, 0.00052770843016241415
, 0.00083736213022550022
, 0.00113017176044514580
, 0.00142359401133266140
, 0.00167568541385370420
, 0.00190388618794389180
, 0.00206523967481659750
, 0.00218308410677488670
, 0.00221367552316458500
, 0.00218417004811285050
, 0.00205184802594768820
, 0.00185166635031662320
, 0.00154331611496724940
, 0.00116950127747589460
, 0.00069237906234783351
, 0.00016418561107954600
, -0.00044872026604057770
, -0.00108589037463804410
, -0.00178026022740209270
, -0.00245857814547932340
, -0.00315166577581365170
, -0.00377426357852949980
, -0.00436291862202973360
, -0.00482034387762833240
, -0.00519376365481972760
, -0.00537343337329428300
, -0.00541848076904331840
, -0.00518825660354715020
, -0.00476796692754071720
, -0.00402284909499116270
, -0.00302831070123731580
, -0.00163839630399520760
, 0.00003813742366550446
, 0.00218814326519349780
, 0.00466377442365825590
, 0.00771226227176221180
, 0.01112583738331451000
, 0.01527102233619121100
, 0.01985102882182500700
, 0.02544773878596931100
, 0.03163072626884851100
, 0.03948581184268437600
, 0.04834608651083680700
, 0.06088241896489415100
, 0.07610716482560016300
, 0.10795437896709038000
, 0.17400642198080865000
, 0.10795437896709038000
, 0.07610716482560016300
, 0.06088241896489415100
, 0.04834608651083680700
, 0.03948581184268437600
, 0.03163072626884851100
, 0.02544773878596931100
, 0.01985102882182500700
, 0.01527102233619121100
, 0.01112583738331451000
, 0.00771226227176221180
, 0.00466377442365825590
, 0.00218814326519349780
, 0.00003813742366550446
, -0.00163839630399520760
, -0.00302831070123731580
, -0.00402284909499116270
, -0.00476796692754071720
, -0.00518825660354715020
, -0.00541848076904331840
, -0.00537343337329428300
, -0.00519376365481972760
, -0.00482034387762833240
, -0.00436291862202973360
, -0.00377426357852949980
, -0.00315166577581365170
, -0.00245857814547932340
, -0.00178026022740209270
, -0.00108589037463804410
, -0.00044872026604057770
, 0.00016418561107954600
, 0.00069237906234783351
, 0.00116950127747589460
, 0.00154331611496724940
, 0.00185166635031662320
, 0.00205184802594768820
, 0.00218417004811285050
, 0.00221367552316458500
, 0.00218308410677488670
, 0.00206523967481659750
, 0.00190388618794389180
, 0.00167568541385370420
, 0.00142359401133266140
, 0.00113017176044514580
, 0.00083736213022550022
, 0.00052770843016241415
, 0.00024656380964603114
, -0.00001878414314248408
, -0.00021448154440842221
, -0.00499511956678885990
, };

float pvp_buf[3][101]={0};



float peak_a;
float peak_b;
float peak_c;

float peak_a_test;
float peak_b_test;
float peak_c_test;

void fcPVP_init(){
	
 struct fcPVPd_inputParameters fcPVPd_initStruct={	1.0f, /*level*/
																										0.05f,/*Delay*/		
																										0.9f, /*DropOutRatio*/
																								
																								};
	
	
 struct fcPVPi_inputParameters fcPVPi_initStruct={	1.0f, 							/*level*/
																										{0.0f,0.0f,0.0f}, 	/*Curve*/
																										0.02f 							/*TimeMultiplier*/};
		
	fcPVPd_obj1_L1_in=fcPVPd_initStruct;																									
	fcPVPi_obj1_L1_in=fcPVPi_initStruct;
																										
	//cau curve data is entered inside pfunctions



}






void fcPVP_all(){
	
	static float counter=0;
	static float peakBuffer[6][N]={0};
	

	/* first version
	
	pvp_in.a=fAdc.sAdc.Ia;
	pvp_in.b=fAdc.sAdc.Ib;
	pvp_in.c=fAdc.sAdc.Ic;
	
	pvp_filter(pvp_in,&pvp_in_back,&pvp_out,&pvp_out_back,ts*314.15926535897932384626433832795f);
	
	*/
	
	pvp_out.a=pvp_post_filter(fAdc.sAdc.Ia,pvp_coefficents,100,&pvp_buf[0][0]); 
	pvp_out.b=pvp_post_filter(fAdc.sAdc.Ib,pvp_coefficents,100,&pvp_buf[1][0]); 
	pvp_out.c=pvp_post_filter(fAdc.sAdc.Ic,pvp_coefficents,100,&pvp_buf[2][0]); 
	
	
	peak_a=peak_detect_rms(pvp_out.a,&peakBuffer[0][0],counter,N);
	peak_b=peak_detect_rms(pvp_out.b,&peakBuffer[1][0],counter,N);
	peak_c=peak_detect_rms(pvp_out.c,&peakBuffer[2][0],counter,N);
	
	
	
	
	
	
	
	
	
	
	
	//peak_a_test=peak_detect_rms(pvp_in.a,&peakBuffer[3][0],counter,N);
	//peak_b_test=peak_detect_rms(pvp_in.b,&peakBuffer[4][0],counter,N);
	//peak_c_test=peak_detect_rms(pvp_in.c,&peakBuffer[5][0],counter,N);
	
	if(++counter==N){
	
	counter=0;
		
	pvp_out_back.a=0.0f;
	pvp_out_back.b=0.0f;
	pvp_out_back.c=0.0f;	
		
	}
	
	fcPVPd_obj1_L1_in.level=fcPVPi_obj1_L1_in.level;
	
	fcPVPd(peak_a,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_a,EN.bits.fcPVPd_obj1);
	fcPVPd(peak_b,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_b,EN.bits.fcPVPd_obj1);
	fcPVPd(peak_c,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_c,EN.bits.fcPVPd_obj1);
	
	fcPVPi(peak_a,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_a,EN.bits.fcPVPi_obj1);
	fcPVPi(peak_b,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_b,EN.bits.fcPVPi_obj1);
	fcPVPi(peak_c,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_c,EN.bits.fcPVPi_obj1);
	
	
	
	
	

}