#ifndef __bit_expansions_h
#define __bit_expansions_h


#define BIT_0                 ((uint32_t)0x0001U)  /* BIT 0 selected    */
#define BIT_1                 ((uint32_t)0x0002U)  /* BIT 1 selected    */
#define BIT_2                 ((uint32_t)0x0004U)  /* BIT 2 selected    */
#define BIT_3                 ((uint32_t)0x0008U)  /* BIT 3 selected    */
#define BIT_4                 ((uint32_t)0x0010U)  /* BIT 4 selected    */
#define BIT_5                 ((uint32_t)0x0020U)  /* BIT 5 selected    */
#define BIT_6                 ((uint32_t)0x0040U)  /* BIT 6 selected    */
#define BIT_7                 ((uint32_t)0x0080U)  /* BIT 7 selected    */
#define BIT_8                 ((uint32_t)0x0100U)  /* BIT 8 selected    */
#define BIT_9                 ((uint32_t)0x0200U)  /* BIT 9 selected    */
#define BIT_10                ((uint32_t)0x0400U)  /* BIT 10 selected   */
#define BIT_11                ((uint32_t)0x0800U)  /* BIT 11 selected   */
#define BIT_12                ((uint32_t)0x1000U)  /* BIT 12 selected   */
#define BIT_13                ((uint32_t)0x2000U)  /* BIT 13 selected   */
#define BIT_14                ((uint32_t)0x4000U)  /* BIT 14 selected   */
#define BIT_15                ((uint32_t)0x8000U)  /* BIT 15 selected   */
#define BIT_16                	((uint32_t)(BIT_15<<1))  /* BIT 16 selected    */
#define BIT_17                 	((uint32_t)(BIT_16<<1))  /* BIT 17 selected    */
#define BIT_18                 	((uint32_t)(BIT_17<<1))  /* BIT 18 selected    */
#define BIT_19                 	((uint32_t)(BIT_18<<1))  /* BIT 19 selected    */
#define BIT_20                 	((uint32_t)(BIT_19<<1))  /* BIT 20 selected    */
#define BIT_21                	((uint32_t)(BIT_20<<1))  /* BIT 21 selected    */
#define BIT_22                 	((uint32_t)(BIT_21<<1))  /* BIT 22 selected    */
#define BIT_23                 	((uint32_t)(BIT_22<<1))  /* BIT 23 selected    */
#define BIT_24                 	((uint32_t)(BIT_23<<1))  /* BIT 24 selected    */
#define BIT_25                 	((uint32_t)(BIT_24<<1))  /* BIT 25 selected    */
#define BIT_26                	((uint32_t)(BIT_25<<1))  /* BIT 26 selected    */
#define BIT_27                	((uint32_t)(BIT_26<<1))  /* BIT 27 selected    */
#define BIT_28                	((uint32_t)(BIT_27<<1))  /* BIT 28 selected    */
#define BIT_29                	((uint32_t)(BIT_28<<1))  /* BIT 29 selected    */
#define BIT_30                	((uint32_t)(BIT_29<<1))  /* BIT 30 selected    */
#define BIT_31                	((uint32_t)(BIT_30<<1))  /* BIT 31 selected    */



enum fault_codes{
	
	no_fault=0,
	
	_50_1_a=1,
	_50_1_b=2,
	_50_1_c=3,
	
	_50_2_a=4,
	_50_2_b=5,
	_50_2_c=6,
	
	_50_3_a=7,
	_50_3_b=8,
	_50_3_c=9,
	
	
	_50_1_a_q1=10,
	_50_1_b_q1=11,
	_50_1_c_q1=12,
	
	_50_2_a_q1=13,
	_50_2_b_q1=14,
	_50_2_c_q1=15,
	
	_50_3_a_q1=16,
	_50_3_b_q1=17,
	_50_3_c_q1=18,
	
	_50N_1=19,
	_50N_2=20,
	_50N_3=21,
	
	_51_a=22,
	_51_b=23,
	_51_c=24,
	
	_51_a_q1=25,
	_51_b_q1=26,
	_51_c_q1=27,
	
	_51N=28,
	
	_27_1_a=29,
	_27_1_b=30,
	_27_1_c=31,
	
	_27_2_a=32,
	_27_2_b=33,
	_27_2_c=34,
	
	_59_1a=35,
	_59_1b=36,
	_59_1c=37,
	
	_59_2a=38,
	_59_2b=39,
	_59_2c=40,

	
	_49_a_valve=41,
	_49_b_valve=42,
	_49_c_valve=43,
	
	_49_a_reactor=44,
	_49_b_reactor=45,
	_49_c_reactor=46,
	

	_37_a=47,
	_37_b=48,
	_37_c=49,
	

	
	
};


extern enum fault_codes fault_code;



#endif
