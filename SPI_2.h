
#ifndef SPI_2_H_
#define SPI_2_H_


void masterInit(void);
void masterTransmit(char spiData);
char masterReceive(void);
void tc72Init(void);
void displayTemperature(char msb,char lsb);



#endif /* SPI_2_H_ */