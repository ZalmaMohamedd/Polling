

//------------------------------------------------------------------------------
#include "TC72_Tempr.h"
#include "spi.h"
//------------------------------------------------------------------------------
void TC72_Init()
{
  
  SPI_initMaster();
  SPI_sendReceiveByte(CONTROL_REG);
  SPI_sendReceiveByte(START_CONV);      //Continous conversion

  

  for(int i =0; i< 10000000; i++);
}
//------------------------------------------------------------------------------
int TC72_ReadTempr()
{ 
  int temprMSB,temprLSB; 
    
  SPI_sendReceiveByte(TEMPR_REG);                  //Access Tempr register for reading
  temprMSB = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
  temprLSB = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);


  
  return ( (temprMSB<<8) + temprLSB );
}
//------------------------------------------------------------------------------
float GetData(signed int tempr)
{
  float result = (float)(tempr>>8);      //Discard LSByte (Only holds fraction flag bits)
  char count = tempr & FRAC_FLAG;          
  
  if(count) 
  {
    count = count >> 6; 
    result = result + (count * 0.25);
  }
  
  return  (result);
}
//------------------------------------------------------------------------------


