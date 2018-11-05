#include <stddef.h>
#include "pwmout_api.h"
#include "PeripheralNames.h"
#include "ADuCM350.h"

#define pwmout_t pADI_GPT0_Type

void pwmout_init(pwmout_t *obj, PinName pin){
	
}

void pwmout_free(pwmout_t *obj){
	
}

void pwmout_write(pwmout_t *obj, float percent){
	
}

float pwmout_read(pwmout_t *obj){
	return (float)0;
}

void pwmout_period(pwmout_t *obj, float seconds){
	
}

void pwmout_period_ms(pwmout_t *obj, int ms){
	
}

void pwmout_period_us(pwmout_t *obj, int us){
	
}

void pwmout_pulsewidth(pwmout_t *obj, float seconds){
	
}

void pwmout_pulsewidth_ms(pwmout_t *obj, int ms){
	
}

void pwmout_pulsewidth_us(pwmout_t *obj, int us){
	
}