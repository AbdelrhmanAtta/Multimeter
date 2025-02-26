/* adc.c
*
* Created : 11/4/2024 11:07:59 AM
* Author : Zeyad Emad 
* Coauthor : A.Atta
*/ 

#include "../inc/adc.h"


void adc_init(void)
{
	ADMUX |=(1<<REFS0); // to make the reference=VCC
	ADMUX &=~(1 <<REFS1); // to ensure that reference=VCC
	ADCSRA|=(1 << ADEN);  // to turn on the ADC
	ADCSRA|=(1 << ADSC); //to start new conversion
	ADCSRA|=(1 << ADPS0); //Set the prescaler to 256 or 128
	ADCSRA|=(1 << ADPS1);
	ADCSRA|=(1 << ADPS2); // to determine the frequency
	
}


int adc_read (int channel)
{
	ADMUX &= 0xF0; //to clear the value of the older channel
	ADMUX |= channel; // to determine which channel from 0 to 7
	ADCSRA|= (1<< ADSC); //to start new conversion
	while(ADCSRA &(1<< ADSC)); // wait until the conversion is done
	
	return ADC;
}


int adc_pot_control (uint8_t adc_channel1, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5,uint8_t pin6 ,uint8_t pin7 ,uint8_t pin8)
{
	uint16_t adc_value = adc_read(adc_channel1); // Read ADC value from adc channel 1
	uint8_t vflag = 0; 
	

	PORTD |= 0x00;
		 
	//to ensure that all pins are low in the beginning



	// Determine the range and set output pins
	if (adc_value < 48)
       	{                  // Range 0 (0-48) (off)
		PORTD |= 0x00;
		vflag = 0;    // vflag=0 means off
	}
	else if (adc_value > 48 && adc_value <= 148) 
	{                  // Range 1 (48-148)
		PORTD |= (1 << pin1);   // Set pin1 high
		PORTD &= ~(1 << pin2); // Clear pin2
		PORTD &= ~(1 << pin3); // Clear pin3
		PORTD &= ~(1 << pin4); // Clear pin4
		PORTD &= ~(1 << pin5); // Clear pin5
		PORTD &= ~(1 << pin6); // Clear pin6
		PORTD &= ~(1 << pin7); // Clear pin7
		PORTD &= ~(1 << pin8); // Clear pin8
		vflag = 1;  // the first voltmeter range
	} 
	else if (adc_value > 148 && adc_value <= 173) 
	{           // Range 0 (148-173)
		PORTD |= 0x00;
		vflag = 0;    // vflag=0 means off
	} 
	else if(adc_value > 173 && adc_value <= 273)
	{                                // Range 2 (173-273)
		PORTD &= ~(1 << pin1); // Clear pin1
		PORTD |= (1 << pin2);  // Set pin2
		PORTD &= ~(1 << pin3); // Clear pin3
		PORTD &= ~(1 << pin4); // Clear pin4
		PORTD &= ~(1 << pin5); // Clear pin5
		PORTD &= ~(1 << pin6); // Clear pin6
		PORTD &= ~(1 << pin7); // Clear pin7
		PORTD &= ~(1 << pin8); // Clear pin8
		vflag = 2;  // the second voltmeter range
	 }
	 else if(adc_value > 273 && adc_value <= 298)
	 {                                // Range 0 (273-298)
		PORTD |= 0x00;
		vflag = 0;    // vflag=0 means off
		
	 }
	 else if(adc_value > 298 && adc_value <= 398)
	 {                                // Range 3 (298-398)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD |= (1 << pin3);  // Set pin3
		 PORTD &= ~(1 << pin4); // Clear pin4
		 PORTD &= ~(1 << pin5); // Clear pin5
		 PORTD &= ~(1 << pin6); // Clear pin6
		 PORTD &= ~(1 << pin7); // Clear pin7
		 PORTD &= ~(1 << pin8); // Clear pin8
		 vflag = 3;  // the third voltmeter range
	 }
	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 // end of voltmeter 
	 else if(adc_value > 398 && adc_value <= 423)
	 {                                // Range 0 (398-423)
		 PORTD |= 0x00;
		 vflag = 0;    // vflag=0 means off
	 }
	 else if(adc_value > 423 && adc_value <= 523)
	 {                                // Range  (298-398)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD &= ~(1 << pin3); // Clear pin3
		 PORTD |= (1 << pin4);  // Set pin4
		 PORTD &= ~(1 << pin5); // Clear pin5
		 PORTD &= ~(1 << pin6); // Clear pin6
		 PORTD &= ~(1 << pin7); // Clear pin7
		 PORTD &= ~(1 << pin8); // Clear pin8
		 vflag = 4;  // the first Ammeter range
	 }
	 else if(adc_value > 523 && adc_value <= 548)
	 {                                // Range 0 (523-548)
		 PORTD |= 0x00;
		 vflag = 0;    // vflag=0 means off
	 }
	 else if(adc_value > 548 && adc_value <= 648)
	 {                                // Range  (548-648)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD &= ~(1 << pin3); // Clear pin3
		 PORTD &= ~(1 << pin4); // Clear pin4
		 PORTD |=  (1 << pin5); // Set pin5
		 PORTD &= ~(1 << pin6); // Clear pin6
		 PORTD &= ~(1 << pin7); // Clear pin7
		 PORTD &= ~(1 << pin8); // Clear pin8
		 vflag = 5;  // the second Ammeter range
	 }
	 ///////////////////////////////////////////////////////////////////////////////////////////
	  // end of Ammeter
	 else if(adc_value > 648 && adc_value <= 673)
	 {                                // Range 0 (648-673)
		 PORTD |= 0x00;
		 vflag = 0;    // vflag=0 means off
	 }
	 else if(adc_value > 673 && adc_value <= 773)
	 {                                // Range  (673-773)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD &= ~(1 << pin3); // Clear pin3
		 PORTD &= ~(1 << pin4); // Clear pin4
		 PORTD &= ~(1 << pin5); // Clear pin5
		 PORTD |=  (1 << pin6); // Set pin6
		 PORTD &= ~(1 << pin7); // Clear pin7
		 PORTD &= ~(1 << pin8); // Clear pin8
		 vflag = 6;  // the first Ohmmeter range
	 }
	 else if(adc_value > 773 && adc_value <= 798)
	 {                                // Range 0 (773-798)
		 PORTD |= 0x00;
		 vflag = 0;    // vflag=0 means off
	 }
	 else if(adc_value > 798 && adc_value <= 898)
	 {                                // Range  (798-898)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD &= ~(1 << pin3); // Clear pin3
		 PORTD &= ~(1 << pin4); // Clear pin4
		 PORTD &= ~(1 << pin5); // Clear pin5
		 PORTD &= ~(1 << pin6); // Clear pin6
		 PORTD |=  (1 << pin7); // Set pin7
		 PORTD &= ~(1 << pin8); // Clear pin8
		 vflag = 7;  // the second Ohmmeter range
	 }
	 else if(adc_value > 898 && adc_value <= 923)
	 {                                // Range 0 (898-923)
		 PORTD |= 0x00;
		 vflag = 0;    // vflag=0 means off
	 }
	 else if(adc_value > 923 && adc_value <= 1023)
	 {                                // Range  (923-1023)
		 PORTD &= ~(1 << pin1); // Clear pin1
		 PORTD &= ~(1 << pin2); // Clear pin2
		 PORTD &= ~(1 << pin3); // Clear pin3
		 PORTD &= ~(1 << pin4); // Clear pin4
		 PORTD &= ~(1 << pin5); // Clear pin5
		 PORTD &= ~(1 << pin6); // Clear pin6
		 PORTD &= ~(1 << pin7); // Clear pin7
		 PORTD |=  (1 << pin8); // Set pin8
		 vflag = 8;  // the third Ohmmeter range
	 }
	 //////////////////////////////////////////////////////////////////////////////////
	 // end of ohmmeter 

	return vflag;
 }
