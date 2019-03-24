#ifndef REG_H
#define REG_H

//REG OPERATIONS

#define UINT32_1 ((uint32_t)1)

#define REG(addr) (*((volatile uint32_t *)(addr)))

#define SET_BIT(addr, bit) (REG(addr) |= UINT32_1 << (bit))
#define CLEAR_BIT(addr, bit) (REG(addr) &= ~(UINT32_1 << (bit)))
#define READ_BIT(addr , bit)  (REG(addr) &= (UINT32_1 << (bit)))
// #define READ_BIT(addr, bit) ??????

//RCC
#define RCC_BASE 0x40023800

#define RCC_AHB1ENR_OFFSET 0x30
#define GPIO_EN_BIT(port) (port)

//GPIO
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

#define GPIO_BASE(port) (0x40020000 + 0x400 * (port))

#define GPIOx_MODER_OFFSET 0x00
#define MODERy_1_BIT(y) ((y)*2 + 1)
#define MODERy_0_BIT(y) ((y)*2)

#define GPIOx_OTYPER_OFFSET 0x04
#define OTy_BIT(y) (y)

#define GPIOx_OSPEEDR_OFFSET 0x08
#define OSPEEDRy_1_BIT(y) ((y)*2 + 1)
#define OSPEEDRy_0_BIT(y) ((y)*2)

#define GPIOx_PUPDR_OFFSET 0x0C
#define PUPDRy_1_BIT(y) ((y)*2 + 1)
#define PUPDRy_0_BIT(y) ((y)*2)

#define GPIOx_BSRR_OFFSET 0x18
#define BRy_BIT(y) ((y) + 16)
#define BSy_BIT(y) (y)

#define GPIOx_IDR_OFFSET  0x10
#define IDR_BIT(y) (y)

#define GPIO_SET_READY 0X01
#define GPIO_SET_fail 0x00
#define GPIO_Pin(x)  (x)
typedef enum {

GPIO_Mode_IN   = 0x00, 
GPIO_Mode_OUT  = 0x01, 
GPIO_Mode_AF   = 0x02,
GPIO_Mode_AN = 0x03 
} GPIO_MODE_def;

typedef enum {

GPIO_Type_pp = 0x00,
GPIO_Type_OD = 0x01

} GPIO_TYPE_def;

typedef enum {
GPIO_High_speed = 0x03 ,
GPIO_Fast_speed = 0x02,
GPIO_Medium_speed = 0x01,
GPIO_Low_speed = 0x00

} GPIO_SPEED_def;

typedef enum
{ 
GPIO_PuPd_nopull = 0x00,
GPIO_PuPd_up     = 0x01,
GPIO_PuPd_down   = 0x02
}GPIO_PUPD_def;
typedef struct GPIO_initdef 
{
  uint32_t GPIO_Pin;              

  GPIO_MODE_def GPIO_Mode;    

  GPIO_SPEED_def GPIO_Speed;   


  GPIO_TYPE_def GPIO_OType; 

  GPIO_PUPD_def  GPIO_PuPd;    
} GPIO_InitDef;

#endif
