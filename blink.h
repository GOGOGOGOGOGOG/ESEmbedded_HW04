#ifndef BLINK_H
#define BLINK_H

#define LED_GREEN 12
#define LED_ORANGE 13
#define LED_RED 14
#define LED_BLUE 15

void blink(unsigned int led);
void blink_count(unsigned int led, unsigned int count);
void user_button_init(void);
void Delay(unsigned int nDelay);
void close_light(int led);
void turn_light_all(void);
void close_light_all (void);
#endif