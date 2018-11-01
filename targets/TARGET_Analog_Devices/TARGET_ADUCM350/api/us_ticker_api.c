#include <stddef.h>
#include "us_ticker_api.h"
#include "PeripheralNames.h"

/** Set ticker IRQ handler
 *
 * @param ticker_irq_handler IRQ handler to be connected
 *
 * @return previous ticker IRQ handler
 *
 * @note by default IRQ handler is set to ::ticker_irq_handler
 * @note this function is primarily for testing purposes and it's not required part of HAL implementation
 *
 */
ticker_irq_handler_type set_us_ticker_irq_handler(ticker_irq_handler_type ticker_irq_handler){
	return null;
}

/** Get ticker's data
 *
 * @return The microsecond ticker data
 */
const ticker_data_t *get_us_ticker_data(void){
	return 0;
}


/** The wrapper for ticker_irq_handler, to pass us ticker's data
 *
 */
void us_ticker_irq_handler(void){
}

/* HAL us ticker */

/** Initialize the ticker
 *
 * Initialize or re-initialize the ticker. This resets all the
 * clocking and prescaler registers, along with disabling
 * the compare interrupt.
 *
 * @note Initialization properties tested by ::ticker_init_test
 *
 * Pseudo Code:
 * @code
 * void us_ticker_init()
 * {
 *     // Enable clock gate so processor can read TIMER registers
 *     POWER_CTRL |= POWER_CTRL_TIMER_Msk;
 *
 *     // Disable the timer and ensure it is powered down
 *     TIMER_CTRL &= ~(TIMER_CTRL_ENABLE_Msk | TIMER_CTRL_COMPARE_ENABLE_Msk);
 *
 *     // Configure divisors
 *     uint32_t prescale = SystemCoreClock / 1000000;
 *     TIMER_PRESCALE = prescale - 1;
 *     TIMER_CTRL |= TIMER_CTRL_ENABLE_Msk;
 *
 *     // Install the interrupt handler
 *     NVIC_SetVector(TIMER_IRQn, (uint32_t)us_ticker_irq_handler);
 *     NVIC_EnableIRQ(TIMER_IRQn);
 * }
 * @endcode
 */
void us_ticker_init(void);
{
	#if 0
      // Enable clock gate so processor can read TIMER registers
      POWER_CTRL |= POWER_CTRL_TIMER_Msk;
 
      // Disable the timer and ensure it is powered down
      TIMER_CTRL &= ~(TIMER_CTRL_ENABLE_Msk | TIMER_CTRL_COMPARE_ENABLE_Msk);
 
      // Configure divisors
      uint32_t prescale = SystemCoreClock / 1000000;
      TIMER_PRESCALE = prescale - 1;
      TIMER_CTRL |= TIMER_CTRL_ENABLE_Msk;
 
      // Install the interrupt handler
      NVIC_SetVector(TIMER_IRQn, (uint32_t)us_ticker_irq_handler);
      NVIC_EnableIRQ(TIMER_IRQn);
   #endif
}

/** Deinitialize the us ticker
 *
 * Powerdown the us ticker in preparation for sleep, powerdown, or reset.
 *
 * After this function is called, no other ticker functions should be called
 * except us_ticker_init(), calling any function other than init is undefined.
 *
 * @note This function stops the ticker from counting.
 *
 * Pseudo Code:
 * @code
 * uint32_t us_ticker_free()
 * {
 *     // Disable timer
 *     TIMER_CTRL &= ~TIMER_CTRL_ENABLE_Msk;
 *
 *     // Disable the compare interrupt
 *     TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
 *
 *     // Disable timer interrupt
 *     NVIC_DisableIRQ(TIMER_IRQn);
 *
 *     // Disable clock gate so processor cannot read TIMER registers
 *     POWER_CTRL &= ~POWER_CTRL_TIMER_Msk;
 * }
 * @endcode
 *
 */
 void us_ticker_free(void)
 {
#if 0
      // Disable timer
      TIMER_CTRL &= ~TIMER_CTRL_ENABLE_Msk;
 
      // Disable the compare interrupt
      TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
 
      // Disable timer interrupt
      NVIC_DisableIRQ(TIMER_IRQn);
 
      // Disable clock gate so processor cannot read TIMER registers
      POWER_CTRL &= ~POWER_CTRL_TIMER_Msk;
 #endif
 }

/** Read the current counter
 *
 * Read the current counter value without performing frequency conversions.
 * If no rollover has occurred, the seconds passed since us_ticker_init()
 * was called can be found by dividing the ticks returned by this function
 * by the frequency returned by ::us_ticker_get_info.
 *
 * @return The current timer's counter value in ticks
 *
 * Pseudo Code:
 * @code
 * uint32_t us_ticker_read()
 * {
 *     return TIMER_COUNT;
 * }
 * @endcode
 */
uint32_t us_ticker_read(void)
{
     return 0; // TIMER_COUNT;
}

/** Set interrupt for specified timestamp
 *
 * @param timestamp The time in ticks to be set
 *
 * @note no special handling needs to be done for times in the past
 * as the common timer code will detect this and call
 * us_ticker_fire_interrupt() if this is the case
 *
 * @note calling this function with timestamp of more than the supported
 * number of bits returned by ::us_ticker_get_info results in undefined
 * behavior.
 *
 * Pseudo Code:
 * @code
 * void us_ticker_set_interrupt(timestamp_t timestamp)
 * {
 *     TIMER_COMPARE = timestamp;
 *     TIMER_CTRL |= TIMER_CTRL_COMPARE_ENABLE_Msk;
 * }
 * @endcode
 */
void us_ticker_set_interrupt(timestamp_t timestamp);
{
      TIMER_COMPARE = timestamp;
      TIMER_CTRL |= TIMER_CTRL_COMPARE_ENABLE_Msk;
}
 
/** Disable us ticker interrupt
 *
 * Pseudo Code:
 * @code
 * void us_ticker_disable_interrupt(void)
 * {
 *     // Disable the compare interrupt
 *     TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
 * }
 * @endcode
 */
void us_ticker_disable_interrupt(void)
{
      // Disable the compare interrupt
      TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
}

/** Clear us ticker interrupt
 *
 * Pseudo Code:
 * @code
 * void us_ticker_clear_interrupt(void)
 * {
 *     // Write to the ICR (interrupt clear register) of the TIMER
 *     TIMER_ICR = TIMER_ICR_COMPARE_Msk;
 * }
 * @endcode
 */
void us_ticker_clear_interrupt(void)
{
    // Write to the ICR (interrupt clear register) of the TIMER
    TIMER_ICR = TIMER_ICR_COMPARE_Msk;
}

/** Set pending interrupt that should be fired right away.
 *
 * The ticker should be initialized prior calling this function.
 *
 * Pseudo Code:
 * @code
 * void us_ticker_fire_interrupt(void)
 * {
 *     NVIC_SetPendingIRQ(TIMER_IRQn);
 * }
 * @endcode
 */
void us_ticker_fire_interrupt(void)
{
     NVIC_SetPendingIRQ(TIMER_IRQn);
}

/** Get frequency and counter bits of this ticker.
 *
 * Pseudo Code:
 * @code
 * const ticker_info_t* us_ticker_get_info()
 * {
 *     static const ticker_info_t info = {
 *         1000000,    // 1 MHz
 *         32          // 32 bit counter
 *     };
 *     return &info;
 * }
 * @endcode
 */
const ticker_info_t *us_ticker_get_info(void);
{
     static const ticker_info_t info = {
         1000000,    // 1 MHz
         32          // 32 bit counter
     };
     return &info;
}