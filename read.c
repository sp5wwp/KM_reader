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
	char buffer[32];

	while(read(0, buffer, 32)!=32);

	series=*((uint32_t*)&buffer[5]);
	price=*((uint16_t*)&buffer[9]);
	OF=buffer[12];
	disc=buffer[14];

	t1=*((uint32_t*)&buffer[16]);
	t2=*((uint32_t*)&buffer[20]);
	t3=*((uint32_t*)&buffer[24]);

	ibnr1=*((uint16_t*)&buffer[28]);
	ibnr2=*((uint16_t*)&buffer[30]);

	printf("NUMER:\t%c%c%010d\n", buffer[4], buffer[3], series);
	printf("CENA:\t%5.2f\n", price/100.0f);
	printf("OF:\t%d\n", OF);
	printf("ULGA:\t%d\n", disc);

	t1+=ref; t2+=ref; t3+=ref;
	printf("KUPNO:\t%02d-%02d-%d, %02d:%02d:%02d\n", gmtime(&t1)->tm_mday, gmtime(&t1)->tm_mon+1, gmtime(&t1)->tm_year+1900, gmtime(&t1)->tm_hour, gmtime(&t1)->tm_min, gmtime(&t1)->tm_sec);	
	printf("POCZ.:\t%02d-%02d-%d, %02d:%02d:%02d\n", gmtime(&t2)->tm_mday, gmtime(&t2)->tm_mon+1, gmtime(&t2)->tm_year+1900, gmtime(&t2)->tm_hour, gmtime(&t2)->tm_min, gmtime(&t2)->tm_sec);	
	printf("KON.:\t%02d-%02d-%d, %02d:%02d:%02d\n", gmtime(&t3)->tm_mday, gmtime(&t3)->tm_mon+1, gmtime(&t3)->tm_year+1900, gmtime(&t3)->tm_hour, gmtime(&t3)->tm_min, gmtime(&t3)->tm_sec);
	
	printf("OD:\t%d\n", ibnr1);
	printf("DO:\t%d\n", ibnr2);

	return 0;
}

