// **********************************************************************************
// Example file to set the output values of the DAC
// **********************************************************************************
// Creative Commons Attrib Share-Alike License
// You are free to use/extend this library but please abide with the CC-BY-SA license:
// http://creativecommons.org/licenses/by-sa/4.0/
//
// For any explanation see DAC7565 information at
// http://www.ti.com/product/dac7565
//
// Code based on following datasheet
// http://www.ti.com/lit/gpn/dac7565 
//
// Written by Charles-Henri Hallard (http://hallard.me)
//
// History : V1.00 2015-04-14 - First release
//
// All text above must be included in any redistribution.
//
// **********************************************************************************

#include <SPI.h>
#include <DAC7565.h>

// DAC connection, If you do not have all these connected 
// (or hardwired), just set unconnected values to -1
// On dac shield board https://github.com/hallard/DAC-Shield
// we have Enable=D7, Sync=D4, LDAC=D8 but we use soft SPI
// (D11 MOSI used by PWM so Data=D12, Clock=D13
// Instantiate DAC with correct wiring
DAC dac(7, 4, 8, 12, 13);

int16_t pos, neg ;  //stores 0 to MAX_SCALE

void setup() 
{
  // Initialize the DAC
  dac.init();
  
  // Set DAC reference to be powered up, VREF = 2.5V
  // this mean that vout will be able to go from 0V to 2.5V (full scale)
  dac.setReference(DAC_REFERENCE_ALWAYS_POWERED_UP);

  // Set all outputs to 1V
  dac.writeChannel(DAC_CHANNEL_ALL, 0);

  Serial.begin(115200);

  while (!Serial);

  // I like to know what sketch is running on board
  Serial.println(F("\r\n"__FILE__"\r\n"__DATE__" "__TIME__));   
  Serial.flush();

  // We start at mid scale (VREF/2)
  pos = DAC_MAX_SCALE/2;
  neg = DAC_MAX_SCALE/2;
}

void loop() 
{
  // Loop from 1.25V to 2.25V then back to 1.25V
  if (++pos>=DAC_MAX_SCALE)
    pos = DAC_MAX_SCALE/2;

  // Every 100 points we show information
  if ( pos % 100 == 0)
  {
    Serial.print(F("Channel A & C DAC to "));
    Serial.print(pos);
    Serial.print(F(" => "));
    Serial.print(2.5 * pos / DAC_MAX_SCALE);
    Serial.print(F(" V\t"));
  }

  dac.writeChannel(DAC_CHANNEL_A, pos);
  dac.writeChannel(DAC_CHANNEL_C, pos);

  // Loop from 1.25V to 0V then back to 1.25V
  if (--neg<0)
    neg = DAC_MAX_SCALE/2;

  // Every 100 points we show information
  if ( neg % 100 == 0)
  {
    Serial.print(F("Channel B & D DAC to "));
    Serial.print(neg);
    Serial.print(F(" => "));
    Serial.print(2.5 * neg / DAC_MAX_SCALE);
    Serial.println(F(" V"));
  }

  dac.writeChannel(DAC_CHANNEL_B, neg);
  dac.writeChannel(DAC_CHANNEL_D, neg);
}

