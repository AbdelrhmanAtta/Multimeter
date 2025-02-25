#ifndef ADC_H
#define ADC_H
#include <avr/io.h>



void adc_init(void); //InitialiZe the ADC
int adc_read (int channel ); //Read the input coming from the channel output
int adc_pot_control(uint8_t adc_channel1, uint8_t pin1, uint8_t pin2, uint8_t pin3,uint8_t pin4, uint8_t pin5,uint8_t pin6 ,uint8_t pin7 ,uint8_t pin8 );


#endif /* ADC_H */

