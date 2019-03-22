#include <stdint.h>
#include "reg.h"

void led_init(unsigned int a)
{
//SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTD)); //set RCC Init 
// set 12 13  14 for output mode
//CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_1_BIT(14)|MODERy_1_BIT(13));

SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTD));
CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_1_BIT(a));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_0_BIT(a));
//OT led pin = 0 => Output push-pull
CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OTYPER_OFFSET, OTy_BIT(a));
//OSPEEDR led pin = 11 => High speed
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(a));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(a));
//PUPDR led pin = 01 => no pull-up,NO pull-down
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(a));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(a));

}
void user_button_init(void)
{
	//int a=0;
	//SET RCC parameter
SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTA));
  // set input mode
CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_1_BIT(0));
CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_0_BIT(0));
  // SET Output push pull
CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_OTYPER_OFFSET, OTy_BIT(0));
  //set high speed 
SET_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(0));
SET_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(0));
  // set pull down 
SET_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(0));
CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(0));

//return a;

}

void blink(unsigned int led)
{
    	/*  High speed 
		SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, PUPDRy_0_BIT(15));
	SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, PUPDRy_0_BIT(15));
	     */

		led_init(led);
		
	unsigned int i;
    //unsigned int cnt=0;  //READ_BIT(GPIO_BASE(GPIO_PORTA)+ GPIOx_IDR_OFFSET ,IDR_BIT(0));
	while (1)
	{
		//set GPIOD15
	  SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT(led));
     
		for (i = 0; i < 100000; i++) 
			;

		//reset GPIOD15
	   SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));
   
		for (i = 0; i < 100000; i++) 
			;
        
  
	}
}

void Delay(unsigned int nDelay)
{
	unsigned int i, j;
	int k = 0;

	for (i = 0; i < nDelay; i++)
		;

	for (j = 0; j < 6144; j++)
		;

	k++;
}

void blink_count (unsigned int led,int count)
{
    //unsigned int i;
    unsigned int cnt1=0;
	led_init(led);
	while (cnt1<count)
	{
		//set GPIOD15
	  SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT(led));
     
	    //for (i = 0; i < 50000; i++) 
			;
			Delay(50000)
             ;
		//reset GPIOD15
	   SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));
     
	    //for (i = 0; i < 50000; i++) 
			;
			Delay(50000)
			 ;
         ++cnt1;
  
	}

	
}
void close_light(int led)
{
unsigned int i;
	 SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));
	 for (i = 0; i < 100000; i++);
}
void turn_light_all (void)
{
	unsigned int i;
	int32_t led = 0xCDEF;
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT((int) ((led>>12&0x0C))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT((int)((led>>8&0x0D))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT((int)((led>>4&0x0E))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT((int)((led&0x0F))));
for (i = 0; i < 2000000; i++) 
			;
}
void close_light_all(void)
{
	unsigned int i;
	int32_t led = 0xCDEF;
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT((int) ((led>>12&0x0C))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT((int)((led>>8&0x0D))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT((int)((led>>4&0x0E))));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT((int)((led&0x0F))));
for (i = 0; i < 2000000; i++) 
			;
}