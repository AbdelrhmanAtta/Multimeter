#pragma once

#include <util/delay.h>
#include "../inc/adc.h"
#include "../inc/lcd.h"
#include "../inc/i2c.h"


float ranges_adc_to_reading(float Vref, int adc_reading);

void ranges_lcd_print(float volt_value, float gain1, float gain2, float gain3, float gain4, float gain5, float gain6, float gain7, float gain8, float Vref);
