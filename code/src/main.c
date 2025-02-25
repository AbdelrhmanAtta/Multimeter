/*
 *
 *
 *
 */


#include <avr/io.h>
#include <util/delay.h>

#include "../inc/i2c.h"
#include "../inc/lcd.h"
#include "../inc/adc.h"
#include "../inc/ranges.h"


int main(void)
{
	i2c_init();
	lcd_init();
	adc_init();
	
	DDRD |= 0xFF;
	//DDRB |= 0xFF;
	//PORTB |= 0xFF;
		
	while(1)
	{ 
		float reading = adc_read(0);
		//float x = adc_to_volt(5, reading);
		
		//lcd_print_float(reading, 2);
		//_delay_ms(500);
		//lcd_clear();
		//control_volt_by_potentiometer(3, 0, 1, 2, 3, 4);
		//lcd_print_volt(1, reading, 5, 2);
	
		ranges_lcd_print(ranges_adc_to_reading(5,reading), 10.755, 0.96, 0.04468, 0.018,0.18, 1, 1, 1, 5);
	
	}

	return 0;
}
