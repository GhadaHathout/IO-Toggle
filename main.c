/**
  ******************************************************************************
  * @file    Lab-Libraries/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************/

#include "gpio.h"

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
                                               
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned  int counter = 0x00;  
  
  /* Activer l'horloge pour le Port D */
  GPIO_ClockEnable(GPIO_D);

  /* re-intialiser les registers de port D */
  GPIO_DeInit(GPIO_D);
  
/* --- Configure PD12 et PD13 en mode Output Push pull */  
  GPIO_Init(GPIO_D, OUTPUT, PP, PIN_12);
  GPIO_Init(GPIO_D, OUTPUT, PP, PIN_13);
  GPIO_Init(GPIO_D, OUTPUT, PP, PIN_14);
  GPIO_Init(GPIO_D, OUTPUT, PP, PIN_15);
  
  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
   /* Turn On LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_PIN_12, 1); 
   GPIO_WriteBit(GPIO_D, GPIO_PIN_13, 1);
   /*if define full hethi ken definit full yi5demhom sinn le */
   GPIO_WriteBit(GPIO_D, GPIO_PIN_14, 1);
   GPIO_WriteBit(GPIO_D, GPIO_PIN_15, 1);
   /*endif*/
   Delay(0x5FFFFF) ;
    
    /* Turn off LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_PIN_12, 0);
   GPIO_WriteBit(GPIO_D, GPIO_PIN_13, 0);
   GPIO_WriteBit(GPIO_D, GPIO_PIN_14, 0);
   GPIO_WriteBit(GPIO_D, GPIO_PIN_15, 0);
   Delay(0x5FFFFF) ;
           
  }
  while(1);
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}

/******************* (C) COPYRIGHT 22024 CSF *****END OF FILE*******************/
