#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

const uint32_t ref=1262304000; //01-01-2010 00:00:00 CEST

uint32_t series=0;
uint16_t OF=0;
uint32_t price=0;
uint16_t disc=0;
time_t t1=0, t2=0, t3=0;
uint16_t ibnr1=0, ibnr2=0;

int main(void)
{
	char buffer[94];

	read(0, buffer, 94);

	series=((uint8_t)buffer[8]<<24)+((uint8_t)buffer[7]<<16)+((uint8_t)buffer[6]<<8)+(uint8_t)buffer[5];
	price=((uint8_t)buffer[10]<<8)+(uint8_t)buffer[9];
	OF=(uint8_t)buffer[12];
	disc=(uint8_t)buffer[14];

	t1=((uint8_t)buffer[19]<<24)+((uint8_t)buffer[18]<<16)+((uint8_t)buffer[17]<<8)+(uint8_t)buffer[16];
	t2=((uint8_t)buffer[23]<<24)+((uint8_t)buffer[22]<<16)+((uint8_t)buffer[21]<<8)+(uint8_t)buffer[20];
	t3=((uint8_t)buffer[27]<<24)+((uint8_t)buffer[26]<<16)+((uint8_t)buffer[25]<<8)+(uint8_t)buffer[24];

	ibnr1=((uint8_t)buffer[29]<<8)+(uint8_t)buffer[28];
	ibnr2=((uint8_t)buffer[31]<<8)+(uint8_t)buffer[30];

	printf("NUMER:\t%c%c%010d\n", buffer[2], buffer[3], series);
	printf("CENA:\t%5.2f\n", (float)price/100);
	printf("OF:\t%d\n", OF);
	printf("ULGA:\t%d\n", disc);

	t1+=ref-7200; t2+=ref-7200; t3+=ref-7200; //CEST-UTC
	printf("KUPNO:\t%02d-%02d-%d, %02d:%02d:%02d\n", localtime(&t1)->tm_mday, localtime(&t1)->tm_mon+1, localtime(&t1)->tm_year+1900, localtime(&t1)->tm_hour, localtime(&t1)->tm_min, localtime(&t1)->tm_sec);	
	printf("POCZ.:\t%02d-%02d-%d, %02d:%02d:%02d\n", localtime(&t2)->tm_mday, localtime(&t2)->tm_mon+1, localtime(&t2)->tm_year+1900, localtime(&t2)->tm_hour, localtime(&t2)->tm_min, localtime(&t2)->tm_sec);	
	printf("KON.:\t%02d-%02d-%d, %02d:%02d:%02d\n", localtime(&t3)->tm_mday, localtime(&t3)->tm_mon+1, localtime(&t3)->tm_year+1900, localtime(&t3)->tm_hour, localtime(&t3)->tm_min, localtime(&t3)->tm_sec);
	
	printf("OD:\t%d\n", ibnr1);
	printf("DO:\t%d\n", ibnr2);

	return 0;
}

