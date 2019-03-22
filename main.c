#include <stdint.h>
#include "blink.h"
#include "reg.h"
#include <math.h>

int main(void)
{
	int a = 0;
	 int b = 0;
	user_button_init();
 
	//Delay(10000);
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
       turn_light_all();
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