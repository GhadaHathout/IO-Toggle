/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    28-04-2024
  *****************************************************************************
Includes ------------------------------------------------------------------*/
#include "gpio.h"

// Ajouter define pour RCC clock 

volatile unsigned short int *RCC_AHB1ENR =  (unsigned short int*)(0x40023830);
// Ajouter define pour RCC  rest
volatile unsigned short int *RCC_AHB1RSTR = (unsigned short int*)(0x40023810);

/**
  * @brief  Enable the gpio_x peripheral clock.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable(unsigned int * gpio_x)
{

  if (gpio_x == GPIO_A)
  {
    // activer le clock du GPIOA 
    *RCC_AHB1ENR |= (1<<0);
  }
  else if (gpio_x == GPIO_B)
  { 
    *RCC_AHB1ENR |= (1<<1);
  }
  
  else if (gpio_x == GPIO_C)
  { 
    *RCC_AHB1ENR |= (1<<2);
  }
  else if (gpio_x == GPIO_D)
  { 
    *RCC_AHB1ENR |= (1<<3);
  }
  else if (gpio_x == GPIO_E)
  { 
    *RCC_AHB1ENR |= (1<<4);
  }
  else if (gpio_x == GPIO_F)
  { 
    *RCC_AHB1ENR |= (1<<5);
  }  
  else if (gpio_x == GPIO_G)
  { 
    *RCC_AHB1ENR |= (1<<6);
  }
  else if (gpio_x == GPIO_H)
  { 
    *RCC_AHB1ENR |= (1<<7);
  }
  else if (gpio_x == GPIO_I)
  { 
    *RCC_AHB1ENR |= (1<<8);
  }
  else if (gpio_x == GPIO_J)
  { 
    *RCC_AHB1ENR |= (1<<9);
  }
  else if (gpio_x == GPIO_K)
  { 
    *RCC_AHB1ENR |= (1<<10);
  }          
}

/**
* @brief Deinitializes the gpio_x peripheral registers to their default reset values.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval None
*/
void GPIO_DeInit(unsigned int * gpio_x)
{
  if (gpio_x == GPIO_A)
  {
    /*RESET le clock du GPIOA 1: resets IO port*/
    *RCC_AHB1RSTR |= (1<<0);
    *RCC_AHB1RSTR &= ~(1<<0);
  }
  else if (gpio_x == GPIO_B)
  { 
    *RCC_AHB1RSTR |= (1<<1);
    *RCC_AHB1RSTR &= ~(1<<1);
  }
  else if (gpio_x == GPIO_C)
  { 
    *RCC_AHB1RSTR |= (1<<2);
    *RCC_AHB1RSTR &= ~(1<<2);
  }
  else if (gpio_x == GPIO_D)
  { 
    *RCC_AHB1RSTR |= (1<<3);
    *RCC_AHB1RSTR &= ~(1<<3);
  }
  else if (gpio_x == GPIO_E)
  { 
    *RCC_AHB1RSTR |= (1<<4);
    *RCC_AHB1RSTR &= ~(1<<4);
  }
  else if (gpio_x == GPIO_F)
  { 
    *RCC_AHB1RSTR |= (1<<5);
    *RCC_AHB1RSTR &= ~(1<<5);
  }  
  else if (gpio_x == GPIO_G)
  { 
    *RCC_AHB1RSTR |= (1<<6);
    *RCC_AHB1RSTR &= ~(1<<6);
  }
  else if (gpio_x == GPIO_H)
  { 
    *RCC_AHB1RSTR |= (1<<7);
    *RCC_AHB1RSTR &= ~(1<<7);
  }
  else if (gpio_x == GPIO_I)
  { 
    *RCC_AHB1RSTR |= (1<<8);
    *RCC_AHB1RSTR &= ~(1<<8);
  }
  else if (gpio_x == GPIO_J)
  { 
    *RCC_AHB1RSTR |= (1<<9);
    *RCC_AHB1RSTR &= ~(1<<9);
  }
  else if (gpio_x == GPIO_K)
  { 
    *RCC_AHB1RSTR |= (1<<10);
    *RCC_AHB1RSTR &= ~(1<<10);
  }    
}

/**
* @brief Configure the gpio_x
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param Mode: can be INPUT, OUTPUT, AF or AN
* @param typeOutput: can be PP or OD
* @param pin: can be 0...15
* @retval None
*/
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
   unsigned int mask = ~(0x3 <<(pin*2));
  
   /*Mettre a zero la valeur de Mode dans MODER*/
    *(gpio_x+ (MODER / sizeof(unsigned int))) &= mask;
  
   /*Appliquer le Mode choisit*/ 
    *(gpio_x+ (MODER / sizeof(unsigned int))) |= (Mode <<(pin*2)); /*Mode 00/01/10/11 ecrire "1" dans bit choisit*/
    
    /*Mettre a zero la valeur de Mode dans OTYPER*/
    mask = ~(0x1 <<(pin));  
    
    /*Appliquer le Output Type choisit*/
    if (typeOutput==PP)
    {
      *(gpio_x+ (OTYPER / sizeof(unsigned int))) &= mask;
    }
    else
    {
      *(gpio_x+ (OTYPER / sizeof(unsigned int))) |= ~mask;
    }
}

/**
* @brief Reads the specified input port pin.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to read.
* This parameter can be GPIO_Pin_x where x can be (0..15).
* @retval The input port pin value.
* IDR accessed in word mode only (4 bytes)
*/
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)
{

  unsigned char bit_states = 0x00;
  if ((*(gpio_x +(IDR / sizeof(unsigned int)))& GPIO_Pin)!=0x00) 
  {        
    bit_states = 0x01;    
  } 
  else 
  {
        
    bit_states = 0x00; 
  }
  return bit_states;
}

/**
* @brief Reads the specified GPIO input data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval GPIO input data port value.
*/
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x)
{
  // Calculate the address of the IDR
   
  return (unsigned short int)*(gpio_x + (IDR / sizeof(unsigned int)));
}

/**
* @brief Sets or clears the selected data port bit.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to be written.
* This parameter can be one of GPIO_Pin_x where x can be (0..15).
* @param BitVal: specifies the value to be written to the selected bit.
* This parameter can be one of the BitAction enum values:
* @arg Bit_RESET: to clear the port pin
* @arg Bit_SET: to set the port pin
* @retval None
* This function is used to set or clear a specific pin on the GPIO port.
It only affects one bit at a time
*/
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal)
{
  if (BitVal != 0x00)
  {
    *(gpio_x + ODR/ sizeof(unsigned int))|= GPIO_Pin;
  }
  else
  {
    *(gpio_x + ODR / sizeof(unsigned int))&= ~GPIO_Pin;
  }
}

/**
* @brief Writes data to the specified GPIO data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param PortVal: specifies the value to be written to the port output data register.
* @retval None
*This function writes a value to the entire output data register (ODR) of a GPIO port. 
It writes to all 16 pins at once.
*/
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)
{
  *(gpio_x + ODR / sizeof(unsigned int)) = PortVal;         /*ODR 0..15*/
}













/******************* (C) COPYRIGHT 2024 CSF *****END OF FILE*******************/

