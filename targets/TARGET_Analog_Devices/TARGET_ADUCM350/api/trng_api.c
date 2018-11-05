#include <stddef.h>
#include "trng_api.h"
#include "PeripheralNames.h"
#include "ADuCM350.h"

#define trng_t pADI_RNG_Type

void trng_init(trng_t * obj){

}	

void trng_free(trng_t * obj){

}

int trng_get_bytes(trng_t *obj, uint8_t *output, size_t length, size_t *output_length){
	return 0;
}