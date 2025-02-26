#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <util/delay>
#include <util/twi.h>

#define ADDRESS_W 0x4E

void i2c_init(void);
void i2c_send(uint8_t data);
void i2c_start(void);
void i2c_stop(void);
void i2c_wait(void);
void send_over_twi(uint8_t data);

