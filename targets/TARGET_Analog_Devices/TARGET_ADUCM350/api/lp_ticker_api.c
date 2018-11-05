#include <stddef.h>
#include "lp_ticker_api.h"
#include "PeripheralNames.h"
#include "ADuCM350.h"

void lp_ticker_init(void){

}

void lp_ticker_free(void){
	
}

uint32_t lp_ticker_read(void)
{
    uint16_t count;
    uint16_t last_count;
    // Loop until the same tick is read twice since this
    // is ripple counter on a different clock domain.
    count = LPTMR_COUNT;
    do {
		last_count = count;
        count = LPTMR_COUNT;
    } while (last_count != count);
    return count;
 }


void lp_ticker_set_interrupt(timestamp_t timestamp){
     LPTMR_COMPARE = timestamp;
     LPTMR_CTRL |= LPTMR_CTRL_COMPARE_ENABLE_Msk;
}

 void lp_ticker_disable_interrupt(void)
 {
     // Disable the compare interrupt
     LPTMR_CTRL &= ~LPTMR_CTRL_COMPARE_ENABLE_Msk;
 }

 void lp_ticker_clear_interrupt(void)
 {
     // Write to the ICR (interrupt clear register) of the LPTMR
     LPTMR_ICR = LPTMR_ICR_COMPARE_Msk;
 }


 void lp_ticker_fire_interrupt(void)
 {
     NVIC_SetPendingIRQ(LPTMR_IRQn);
 }
  
 const ticker_info_t* lp_ticker_get_info(void)
 {
     static const ticker_info_t info = {
         32768,      // 32KHz
         16          // 16 bit counter
     };
     return &info;
 }