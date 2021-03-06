/* TwiSlave demo on RPUftdi board
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

For a copy of the GNU General Public License use
http://www.gnu.org/licenses/gpl-2.0.html

twi.c is the set of I2C functions that do the real work. it is found in Arduino\hardware\arduino\avr\libraries\Wire\src\utility folder.
Arduino's Wire C++ class wrapps it if you like that sort of thing, I have developed a dislike of such things.
I have modified my ..lib\twi.c therefor this program will not work with the one in Arduino's IDE.
 */ 

#include <stdbool.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../lib/timers.h"
#include "../lib/twi.h"
#include "../lib/pin_num.h"
#include "../lib/pins_board.h"

#define  SLAVE_ADDRESS 0x29  //slave address, use numbers between 0x08 to 0x78

static uint8_t rxBuffer[TWI_BUFFER_LENGTH];
static uint8_t rxBufferLength = 0;
static uint8_t txBuffer[TWI_BUFFER_LENGTH];
static uint8_t txBufferLength = 0;

#define FAST_DELAY_MILSEC 500
#define SLOW_DELAY_MILSEC 2000
static unsigned long blink_started_at;
#define NOTHING 0
#define FAST 1
#define SLOW 2
#define REPLETE 3
static uint8_t blink_delay;


// this function is called when I2C data is received. 
// twi_attachSlaveRxEvent is wrapped by the Wire::onReceive() C++ class.
// so they don't just work the same, they are the same but with less overhead.
// The class wrapper puts the data in a buffer... 
void receiveEvent(uint8_t* inBytes, int numBytes) 
{
    // I have to save the data
    for(uint8_t i = 0; i < numBytes; ++i)
    {
        rxBuffer[i] = inBytes[i];    
    }
    rxBufferLength = numBytes;
    
    // This will copy the data to the txBuffer, which I will use to echo it back
    for(uint8_t i = 0; i < numBytes; ++i)
    {
        txBuffer[i] = inBytes[i];    
    }
    txBufferLength = numBytes;
    blink_delay = FAST;
}

// the function is called when I2C data is requested..
// twi_attachSlaveTxEvent is wrapped in the Wire::onRequest() C++ class.
// so they don't just work the same, they are the same but with less overhead.
void slaveTransmit(void) 
{
    // respond with an echo of the last message sent
    uint8_t return_code = twi_transmit(txBuffer, txBufferLength);
    if (return_code==0)
        blink_delay = SLOW;
    else
        blink_delay = REPLETE;
}

int main(void)
{
    
    // Set the RPUbus in a Host 2 local mode so that programs can be loaded on the local MCU board from the host
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(FTDI_nRTS, INPUT);
    pinMode(FTDI_nCTS, OUTPUT);
    digitalWrite(FTDI_nCTS, LOW);
    pinMode(FTDI_nDTR, INPUT);
    pinMode(FTDI_nDSR, OUTPUT);
    digitalWrite(FTDI_nDSR, LOW);
    pinMode(RX_nRE, OUTPUT);
    digitalWrite(RX_nRE, LOW); // enable RX pair receiver
    pinMode(RX_DE, OUTPUT);
    digitalWrite(RX_DE, HIGH); // enable RX pair driver
    pinMode(TX_nRE, OUTPUT);
    digitalWrite(TX_nRE, LOW); // enable TX pair receiver
    pinMode(TX_DE, OUTPUT);
    digitalWrite(TX_DE, HIGH); // enable TX pair driver
    pinMode(DTR_nRE, OUTPUT);
    digitalWrite(DTR_nRE, HIGH); // disable DTR pair receiver
    pinMode(DTR_DE, OUTPUT);
    digitalWrite(DTR_DE, LOW); // disable DTR pair driver
    pinMode(DTR_TXD, OUTPUT);
    digitalWrite(DTR_TXD, HIGH); // transmit a true on DTR_TX pair, which is default for serial.
    pinMode(SS, INPUT); // warning SS is connecte to Arduino nRESET
    pinMode(nDTR, OUTPUT);
    digitalWrite(nDTR, HIGH); // start with a high and look for falling edge on FTDI_nDTR

    initTimers(); //Timer0 Fast PWM mode, Timer1 & Timer2 Phase Correct PWM mode.

    blink_delay = SLOW;
    blink_started_at = millis();

    twi_setAddress(SLAVE_ADDRESS);
    twi_attachSlaveTxEvent(slaveTransmit); // called when I2C data is requested
    twi_attachSlaveRxEvent(receiveEvent); // slave receive
    twi_init(false); // do not use internal pull-up

    sei(); // Enable global interrupts to start TIMER0 and TWI

    while (1) 
    {
        unsigned long kRuntime;
        
        if ( !digitalRead(FTDI_nDTR) )         // both FTDI_nDTR and FTDI_nRTS work for this and are active low
        { 
            digitalWrite(nDTR, LOW);             // copy to nDTR
        }
        else
        {
            digitalWrite(nDTR, HIGH);             // copy to nDTR
        }
        
        // delay between blink toggle
        kRuntime= millis() - blink_started_at;
        switch(blink_delay)
        {
            case NOTHING:
                digitalWrite(LED_BUILTIN, HIGH);      // turn the LED off
                break;
            case FAST:
                if ((kRuntime) > ((unsigned long)FAST_DELAY_MILSEC))
                {
                    digitalToggle(LED_BUILTIN);
                    blink_started_at = millis();
                }
                break;
            case SLOW:
                if ((kRuntime) > ((unsigned long)SLOW_DELAY_MILSEC))
                {
                    digitalToggle(LED_BUILTIN);
                    blink_started_at = millis();
                }
                break;
            case REPLETE:
                digitalWrite(LED_BUILTIN, LOW);      // turn the LED on by sinking current
                continue;
        }
    }
}

