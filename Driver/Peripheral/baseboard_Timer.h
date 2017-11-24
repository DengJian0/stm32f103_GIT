#ifndef __BASEBOARD_TIMER_H__
#define __BASEBOARD_TIMER_H__ 


extern  uint32_t timer3_counter;


#define LED_PIN                    GPIO_Pin_8             /* PC.8*/
#define LED_PORT                   GPIOC

//==============================
extern  void timer_Init (void);
//==============================
#endif
