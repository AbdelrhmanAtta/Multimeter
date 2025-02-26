/* ranges.c
 *
 * Created : 9/12/2024
 * Author : A.Atta, Zeyad Emad
 *
 */

#include "../inc/ranges.h"

float ranges_adc_to_reading(float Vref, int adc_reading) 
{
    float value = (((float)adc_reading / 1023.0f) * Vref);
    return roundf(value * 100.0f) / 100.0f;
}



void ranges_lcd_print(float volt_value, float gain1, float gain2, float gain3, float gain4, float gain5, float gain6, float gain7, float gain8,float Vref)
{
	static float old_volt = 0.00;
	static float volt_dif = 0.00;
	volt_dif = fabs(volt_value - old_volt);
	int vflag = adc_pot_control(3, 7, 6, 5, 0, 1, 2, 3, 4);
	static int old_vflag;
	float print_value;

	if(volt_dif >= 0.01 || vflag != old_vflag)
	{
		old_volt = volt_value;
		//volt_dif = fabs(volt_value - old_volt);
		old_vflag = vflag;
		lcd_clear();
		_delay_ms(100);

		switch (vflag)
		{
			case 1:
				print_value = ((float)volt_value)/gain1;
				if(print_value > 0.5)
				{
					lcd_clear();
					lcd_print("Increase Range");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-0.5V");
					_delay_ms(500);
				}
				else
				{
					lcd_move_cursor(0,4);
					lcd_print_float(print_value, 3);
					lcd_move_cursor(0,9);
					lcd_print("V");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-0.5V");
				}
				break;
			case 2:
				print_value = ((float)volt_value)/gain2;
				if(print_value > 5)
				{
					lcd_clear();
					lcd_print("Increase Range");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-5V");
					_delay_ms(500);
				}
				else
				{
					lcd_move_cursor(0,5);
					lcd_print_float(print_value, 2);
					lcd_move_cursor(0,9);
					lcd_print("V");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-5V");
				}
				break;
				/*lcd_move_cursor(0,5);
				print_value = ((float)volt_value)/gain2;
				lcd_print_float(print_value, 2);
				lcd_move_cursor(0,9);
				lcd_print("V");
				lcd_move_cursor(1,0);
				lcd_print("Range 0-5V");
				break;*/
			case 3:
				print_value = ((float)volt_value)/gain3;
				lcd_move_cursor(0,5);
				lcd_print_float(print_value, 1);
				lcd_move_cursor(0,9);
				lcd_print("V");
				lcd_move_cursor(1,0);
				lcd_print("Range 0-20V");
				break;			
				
				/*lcd_move_cursor(0,5);
				print_value = ((float)volt_value)/gain3;
				lcd_print_float(print_value, 2);
				lcd_move_cursor(0,9);
				lcd_print("V");
				lcd_move_cursor(1,0);
				lcd_print("Range 0-20V");
				break;*/
			case 4:
				/*print_value = (float)volt_value/(1.6*gain4);

				if(print_value > 20.0)
				{
					lcd_clear();
					lcd_print("Increase Range");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-20mA");
					_delay_ms(500);
				}
				else
				{
					lcd_move_cursor(0,5);
					lcd_print_float(print_value, 2);
					lcd_move_cursor(0,9);
					lcd_print("mA");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-20mA");
				}
				break;*/
				print_value = (float)volt_value/(1.6*gain4);
				lcd_move_cursor(0,4);
				print_value = ((float)volt_value)/gain4;
				lcd_print_float(print_value,3);
				lcd_move_cursor(0,9);
				lcd_print("mA");
				lcd_move_cursor(1,0);
				lcd_print("Range 0-20mA");
				break;
			case 5:
				/*print_value = (float)volt_value/(1.6*gain5);

				if(print_value > 1.0 && print_value < 19.5)
				{
					lcd_clear();
					lcd_print("Decrease Range");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-200mA");
					_delay_ms(500);
				}
				else
				{
					lcd_move_cursor(0,5);
					lcd_print_float(print_value, 1);
					lcd_move_cursor(0,9);
					lcd_print("mA");
					lcd_move_cursor(1,0);
					lcd_print("Range 0-200mA");
				}
				break;*/
				print_value = (float)volt_value/(1.6*gain5);
				lcd_move_cursor(0,4);
				print_value = ((float)volt_value)/gain5;
				lcd_print_float(print_value,3);
				lcd_move_cursor(0,9);
				lcd_print("mA");
				lcd_move_cursor(1,0);
				lcd_print("Range 0-200mA");
				break;
			case 6:
				print_value =(float) (gain6*volt_value)/(Vref-volt_value);
				lcd_move_cursor(0,5);
				print_value = ((float)volt_value)/gain6;
				lcd_print_float(print_value,2);
				lcd_move_cursor(0,8);
				lcd_print("kohm");
				lcd_move_cursor(1,0);
				lcd_print("Range 0.1-10kohm");
				break;
			case 7:
				print_value =(float) (gain7*volt_value)/(Vref-volt_value);
				lcd_move_cursor(0,5);
				print_value = ((float)volt_value)/gain7;
				lcd_print_float(print_value,2);
				lcd_move_cursor(0,8);
				lcd_print("kohm");
				lcd_move_cursor(1,0);
				lcd_print("Range 10-100kohm");
				break;
			case 8:
				print_value =(float) (gain8*volt_value)/(Vref-volt_value);
				lcd_move_cursor(0,5);
				print_value = ((float)volt_value)/gain8;
				lcd_print_float(print_value,2);
				lcd_move_cursor(0,8);
				lcd_print("Mohm");
				lcd_move_cursor(1,0);
				lcd_print("Range0.1-0.5Mohm");
				break;
			default:
				lcd_print("Off");
				break;
		}
		_delay_ms(500);
		//PORTB ^= (1 << PB2);
	}

	/*if(vflag != old_vflag)
	{
		int i;
		
		for (int i = 0; i < 5; i++)
	       	{
        		PORTB ^= (1 << PB2);
        		_delay_ms(100);
    	}
		PORTB &= ~(1 << PB2);
		old_vflag = vflag;
	}*/
}
