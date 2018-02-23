
#include <math.h>
#include "plib_definitions.h"
#include "pvp_curve.h"

#define fs 2500.0f
#define uber 1000000

//function-1,2,3
//count  has to be initialized and supplied as different in each invocation

int on_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count)
{

	int out;

	out = mem;

	if (input == 1 && mem == 0)
	{
		*count = *count + 1;

		if ((*count) == qual_sample)
		{
			out = 1;
			*count = 0;
		}

	}

	else
	{
		*count = 0;
	}

	if (input == 0)
	{
		out = 0;
		*count = 0;
	}

	return out;

}
int off_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count)
{

	int out;

	out = mem;

	if (input == 0 && mem == 1)
	{
		*count = *count + 1;

		if ((*count) == qual_sample)
		{
			out = 0;
			*count = 0;
		}

	}

	else
	{
		*count = 0;
	}

	if (input == 1)
	{
		out = 1;
		*count = 0;
	}

	return out;

}
int on_off_delay(unsigned int input, unsigned int mem, unsigned int qual_sample, long *count)
{

	int out;

	out = mem;

	if (input ^ mem)
	{
		*count = *count + 1;

		if ((*count) == qual_sample)
		{
			out = input;
			*count = 0;
		}

	}

	else
	{
		*count = 0;
	}

	return out;

}

//function-4
// Definite TOC

void fc50(float rms,struct fc50_inputParameters fc50_in, struct fc50_outputParameters *fc50_out, int enable)
{

	if (enable)
	{

		if (rms > fc50_in.level)
		{
			fc50_out->initial_pick_up = 1;
		}
		if (rms < fc50_in.level * fc50_in.dropout_ratio)
		{
			fc50_out->initial_pick_up = 0;
		}

		fc50_out->pick_up = off_delay(fc50_out->initial_pick_up, fc50_out->pick_up, fc50_in.dropout_time * fs, &(fc50_out->dropout_counter));

		fc50_out->trip = on_delay(fc50_out->pick_up, fc50_out->trip, fc50_in.delay * fs, &(fc50_out->trip_counter));

		if (fc50_out->trip == 1)
		{
			fc50_out->trip_latch = 1;
		}

	}

}

//function-5
// Inverse TOC

void fc51(float rms, struct fc51_inputParameters fc51_in, struct fc51_outputParameters *fc51_out, int enable)
{

	if (enable)
	{

		if (rms > fc51_in.level * 1.100f)
		{

			fc51_out->pick_up = 1;
			fc51_out->time2trip = fc51_in.time_multiplier * (fc51_in.curve_data[0] / (powf((rms / fc51_in.level), fc51_in.curve_data[1]) - 1.0f) + fc51_in.curve_data[2]);

		}
		if (rms < fc51_in.level * 1.045f)
		{

			fc51_out->pick_up = 0;
			fc51_out->time2trip = uber; //cau

		}

		if (fc51_out->pick_up && fc51_out->trip == 0)
		{

			fc51_out->trip_counter++;

		}
		else
		{

			fc51_out->trip_counter = 0;

		};

		if (fc51_out->trip_counter > fc51_out->time2trip * fs)
		{

			fc51_out->trip = 1;
			fc51_out->trip_counter = 0;

		}

	}

}

//function-6
//Undervoltage Protection
// cs trip caution...... (has to set externally by trigger of trip, but can be integrated)

void fc27(float rms, struct fc27_inputParameters fc27_in, struct fc27_outputParameters *fc27_out, int enable)
{

	if (enable)
	{

		if (rms < fc27_in.level)
		{

			fc27_out->pick_up = 1;

		}

		if (rms > fc27_in.level * fc27_in.dropout_ratio)
		{

			fc27_out->pick_up = 0;

		}
		
		if(fc27_out->cs){
		
		fc27_out->pick_up = 0;
		
		}
		
		
		

		if (fc27_out->pick_up && fc27_out->trip == 0)
		{

			fc27_out->trip_counter++;

		}
		else
		{

			fc27_out->trip_counter = 0;

		}

		if (fc27_out->trip_counter > fc27_in.delay * fs)
		{

			fc27_out->trip = 1;
			fc27_out->trip_counter = 0;

		}

	}

}

// function-7
// Overvoltage Protection

void fc59(float rms, struct fc59_inputParameters fc59_in, struct fc59_outputParameters *fc59_out, int enable)
{

	if (enable)
	{

		if (rms > fc59_in.level)
		{

			fc59_out->pick_up = 1;

		}

		if (rms < fc59_in.level * fc59_in.dropout_ratio)
		{

			fc59_out->pick_up = 0;

		}

		if ((fc59_out->pick_up) && (fc59_out->trip == 0))
		{

			fc59_out->trip_counter++;

		}
		else
		{

			fc59_out->trip_counter = 0;

		}

		if (fc59_out->trip_counter > fc59_in.delay * fs)
		{

			fc59_out->trip = 1;
			fc59_out->trip_counter = 0;

		}

	}

}

// function-8
// Definite TOC Negative Seq. Protection

void fc46d(float rms, float Inom, struct fc46d_inputParameters fc46d_in, struct fc46d_outputParameters *fc46d_out, int enable)
{

	if (enable)
	{
		
		fc46d_out->pass_flag = off_delay((rms > 0.1f * Inom && rms < 10.0f * Inom),fc46d_out->pass_flag,fs*0.02f,&(fc46d_out->pass_counter));


		if (rms > fc46d_in.level && fc46d_out->pass_flag)
		{
			fc46d_out->initial_pick_up = 1;
		}
		if (rms < fc46d_in.level * fc46d_in.dropout_ratio)
		{
			fc46d_out->initial_pick_up = 0;
		}

		fc46d_out->pick_up = off_delay(fc46d_out->initial_pick_up, fc46d_out->pick_up, fc46d_in.dropout_time * fs, &(fc46d_out->dropout_counter));

		fc46d_out->trip = on_delay(fc46d_out->pick_up, fc46d_out->trip, fc46d_in.delay * fs, &(fc46d_out->trip_counter));

		if (fc46d_out->trip == 1)
		{
			fc46d_out->trip_latch = 1;
		}

	}

}

// function-9
// Inverse TOC Negative Seq. Protection

void fc46i(float rms,float Inom, struct fc46i_inputParameters fc46i_in, struct fc46i_outputParameters *fc46i_out, int enable)
{

	if (enable)
	{
		
		fc46i_out->pass_flag = off_delay((rms > 0.1f * Inom && rms < 10.0f * Inom),fc46i_out->pass_flag,fs*0.02f,&(fc46i_out->pass_counter));


		if (rms > fc46i_in.level * 1.100f && fc46i_out->pass_flag )
		{

			fc46i_out->pick_up = 1;
			fc46i_out->time2trip = fc46i_in.time_multiplier * (fc46i_in.curve_data[0] / (powf((rms / fc46i_in.level), fc46i_in.curve_data[1]) - 1.0f) + fc46i_in.curve_data[2]);

		}
		
		if (rms < fc46i_in.level * 1.045f)
		{

			fc46i_out->pick_up = 0;
			fc46i_out->time2trip = uber;

		}

		if (fc46i_out->pick_up && fc46i_out->trip == 0)
		{

			fc46i_out->trip_counter++;

		}
		else
		{

			fc46i_out->trip_counter = 0;

		};

		if (fc46i_out->trip_counter > fc46i_out->time2trip * fs)
		{

			fc46i_out->trip = 1;
			fc46i_out->trip_counter = 0;

		}

	}

}

// function-10
// Overtempereature Protection

void fc49(float temp,struct fc49_inputParameters fc49_in, struct fc49_outputParameters *fc49_out, int enable)
{

	if (enable)
	{

		if (temp > fc49_in.alarm_level)
		{

			fc49_out->alarm = 1;

		}

		if (temp < fc49_in.alarm_level * 0.95f)
		{

			fc49_out->alarm = 0;

		}

		if (temp > 1.0f)
		{

			fc49_out->trip = 1;

		}

	}

}

// function-11
// Breaker Failure Protection
// single invocation

void fcBF(struct fcBF_inputParameters fcBF_in, struct fcBF_outputParameters *fcBF_out, int enable)
{

	if (enable)
	{



			fcBF_out->current_checked = (	fcBF_in.rmsA < fcBF_in.threshold && 
			
																		fcBF_in.rmsB < fcBF_in.threshold && 
			
																		fcBF_in.rmsC < fcBF_in.threshold);

			if (fcBF_in.CB_pos_check)
			{

				fcBF_out->pass_flag = (fcBF_out->current_checked && !(fcBF_in.CB_pos));

			}
			else
			{

				fcBF_out->pass_flag = fcBF_out->current_checked;

			}

			// for breaking latency, fcBF_out->pass_flag initialised to 1, 20ms delay entered
			fcBF_out->pass_flag_filtered = off_delay(fcBF_out->pass_flag, fcBF_out->pass_flag_filtered, fs*0.02f, &(fcBF_out->pass_flag_counter));

			if (fcBF_out->pass_flag_filtered == 0 && fcBF_in.trip_input==1 )
			{

				fcBF_out->pick_up = 1;

			}
			else
			{

				fcBF_out->pick_up = 0;

			}

			if (fcBF_out->pick_up == 1)
			{

				fcBF_out->trip_counter++;

			}
			else
			{

				fcBF_out->trip_counter = 0;

			}

			if (fcBF_out->trip_counter > fcBF_in.delay * fs)
			{

				fcBF_out->trip = 1;
				fcBF_out->trip_counter = 0;

		}
	}
}

// function-12
// Undercurrent Protection
// bs is CB input

void fc37(float rms,int cb_pos, struct fc37_inputParameters fc37_in, struct fc37_outputParameters *fc37_out, int enable)
{

	if (enable)
	{

		if (rms < fc37_in.level && cb_pos==1)
		{

			fc37_out->pick_up = 1;
                       
		}

		if (rms > fc37_in.level * fc37_in.dropout_ratio || cb_pos==0)
		{

			fc37_out->pick_up = 0;

		}

		if (fc37_out->pick_up)
		{

			fc37_out->trip_counter++;

		}
		else
		{

			fc37_out->trip_counter = 0;

		}

		if (fc37_out->trip_counter > fc37_in.delay * fs )
		{

			fc37_out->trip = 1;
			fc37_out->trip_counter = 0;

		}

	}


}

// Function 14
// Filter Unbalance Protection-Alarm Stage
// caution : vectoral difference has to be used

void fcUNBd(float rms,struct fcUNBd_inputParameters fcUNBd_in, struct fcUNBd_outputParameters *fcUNBd_out, int enable)
{

	if (enable)
	{

		if (rms > fcUNBd_in.level)
		{

			fcUNBd_out->pick_up = 1;

		}

		if (rms < fcUNBd_in.level * fcUNBd_in.dropout_ratio)
		{

			fcUNBd_out->pick_up = 0;

		}

		if (fcUNBd_out->pick_up && fcUNBd_out->trip == 0)
		{

			fcUNBd_out->trip_counter++;

		}
		else
		{

			fcUNBd_out->trip_counter = 0;

		}

		if (fcUNBd_out->trip_counter > fcUNBd_in.delay * fs)
		{

			fcUNBd_out->trip = 1;
			fcUNBd_out->trip_counter = 0;

		}

	}

}

// Function 15
// Filter Unbalance Protection-Trip Stage
// caution : vectoral difference has to be used @ input

void fcUNBi(float rms,struct fcUNBi_inputParameters fcUNBi_in, struct fcUNBi_outputParameters *fcUNBi_out, int enable)
{

	if (enable)
	{

		if (rms > fcUNBi_in.level * 1.100f)
		{

			fcUNBi_out->pick_up = 1;
			//fcUNBi_out->time2trip = fcUNBi_in.time_multiplier * (101.2f / (100.0f * (rms / fcUNBi_in.level) - 97.0f) + 0.02f);
			//fc51_out->time2trip = fc51_in.time_multiplier * (fc51_in.curve_data[0] / (powf((rms / fc51_in.level), fc51_in.curve_data[1]) - 1.0f) + fc51_in.curve_data[2]);
			fcUNBi_out->time2trip = fcUNBi_in.time_multiplier * 0.14f / (powf ((rms / fcUNBi_in.level),0.02 )-1.0f);

		}
		if (rms < fcUNBi_in.level * 1.045f)
		{

			fcUNBi_out->pick_up = 0;
			fcUNBi_out->time2trip = uber;

		}

		if (fcUNBi_out->pick_up && fcUNBi_out->trip == 0)
		{

			fcUNBi_out->trip_counter++;

		}
		else
		{

			fcUNBi_out->trip_counter = 0;

		};

		if (fcUNBi_out->trip_counter > fcUNBi_out->time2trip * fs)
		{

			fcUNBi_out->trip = 1;
			fcUNBi_out->trip_counter = 0;

		}

	}

}

// Function 16
// Filter PVP definite

void fcPVPd(float rms,struct fcPVPd_inputParameters fcPVPd_in, struct fcPVPd_outputParameters *fcPVPd_out, int enable)
{

	if (enable)
	{

		if (rms > fcPVPd_in.level)
		{

			fcPVPd_out->pick_up = 1;

		}

		if (rms < fcPVPd_in.level * fcPVPd_in.dropout_ratio)
		{

			fcPVPd_out->pick_up = 0;

		}

		if (fcPVPd_out->pick_up && fcPVPd_out->trip == 0)
		{

			fcPVPd_out->trip_counter++;

		}
		else
		{

			fcPVPd_out->trip_counter = 0;

		}

		if (fcPVPd_out->trip_counter > fcPVPd_in.delay * fs)
		{

			fcPVPd_out->trip = 1;
			fcPVPd_out->trip_counter = 0;

		}

	}

}

// Function 17
// Filter PVP-Trip Stage


float pvp_curve(float x){
	
	float tt=1000000.0f;
	
	
	
	if (x<b0)tt=uber; 
	if (x>=b0 && x<b1){tt=b0_m*(x-b0)+ b0_const;} 
	if (x>=b1 && x<b2){tt=b1_m*(x-b1)+ b1_const;} 	
	if (x>=b2 && x<b3){tt=b2_m*(x-b2)+ b2_const;} 	
	if (x>=b3 && x<b4){tt=b3_m*(x-b3)+ b3_const;}
	if (x>=b4 && x<b5){tt=b4_m*(x-b4)+ b4_const;}
	if (x>=b5 && x<b6){tt=b5_m*(x-b5)+ b5_const;}
	if (x>=b6){tt=0.1f;}
	
	
	
	return tt;
	
	
}

void fcPVPi(float rms,struct fcPVPi_inputParameters fcPVPi_in, struct fcPVPi_outputParameters *fcPVPi_out, int enable)
{

	if (enable)
	{

		if (rms > fcPVPi_in.level * 1.1f)
		{

			fcPVPi_out->pick_up = 1;
			//fcPVPi_out->time2trip = fcPVPi_in.time_multiplier * (fcPVPi_in.curve_data[0] / (100.0f * (rms / fcPVPi_in.level) - 97.0f) + 0.02f);
			fcPVPi_out->time2trip =pvp_curve(rms/fcPVPi_in.level);
			
		}
		
		if (rms < fcPVPi_in.level * 1.045f)
		{

			fcPVPi_out->pick_up = 0;
			fcPVPi_out->time2trip = uber;

		}

		if (fcPVPi_out->pick_up && fcPVPi_out->trip == 0)
		{

			fcPVPi_out->trip_counter++;

		}
		else
		{

			fcPVPi_out->trip_counter = 0;

		};

		if (fcPVPi_out->trip_counter > fcPVPi_out->time2trip * fs)
		{

			fcPVPi_out->trip = 1;
			fcPVPi_out->trip_counter = 0;

		}

	}

}




float minSelector_3p(float a, float b, float c){
	
	float min;
	
	min=a;
	if(b<min){min=b;}
	if(c<min){min=c;}
	
	return min;

}


float maxSelector_3p(float a, float b, float c){
	
	float max;
	
	max=a;
	if(b>max){max=b;}
	if(c>max){max=c;}
	
	return max;

}


