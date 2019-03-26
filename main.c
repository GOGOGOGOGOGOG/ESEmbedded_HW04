#include <stdint.h>
#include "blink.h"
#include "reg.h"
#include <math.h>
//int GPIO_init (unsigned int GPIO_PORTx , unsigned int GPIO_Pinx , GPIO_InitDef * GPIO_initstruct );
int32_t LED_turn_on [4]= {0x0,0x0,0x0,0x0};
void user_button_Init(void)
{
	GPIO_InitDef GPIO_initstructure ;
        GPIO_initstructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_initstructure.GPIO_OType = GPIO_Type_pp;
	GPIO_initstructure.GPIO_PuPd = GPIO_PuPd_down;
	GPIO_initstructure.GPIO_Speed = GPIO_High_speed;
	GPIO_init(GPIO_PORTA,GPIO_Pin(0),&GPIO_initstructure);
}
int main(void)
{
	int a = 0;
	 int b = 0;
     user_button_Init();
	 int32_t LED_turn_on[4]={0x0C,0x0D,0x0E,0x00};  // 12 13 14 15 Stands for 0 1 2 3 array of position
	 //int32_t *p = &LED_turn_on;
	 while (1)
	{
		
		a = (int)READ_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_IDR_OFFSET, IDR_BIT(0));
		if (a != 0)
		{
			b=a+b;
		}

    	Delay(1000);
     
     
		if (b % 6== 1)
		{
		blink_count(LED_GREEN, 10);
		}

		else if (b % 6 == 2)
		{
		blink_count(LED_BLUE, 10);		
		}
       else if(b%6 ==3){
       blink_count(LED_RED, 10);
	   }
       else if (b%6==4)
       {
       blink_count(LED_ORANGE, 10);
       }
	   else if(b%6 ==5)
	   {
       //0xCDEF       
      // turn_light_all();
	   turn_light_one(LED_turn_on);
	   }
       else if(b%6==0)
       {
        close_light_all();
	   }
       else
	   {
		    b=0; //clear flag 
	   }
	}

}
