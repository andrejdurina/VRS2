/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"



int main(void)
{

  //Systick init
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);	


 RCC_AHBENR_REG |= (uint32_t)(1 << 17);


  /*GPIOA pin 3 and 4 setup*/
  /*GPIO MODER register*/
  //Set mode for pin 3 input PA3
 GPIOA_MODER_REG &= ~(uint32_t)(0x3 << 6);

  //Set mode for pin 4 output PA4
 GPIOA_MODER_REG &= ~(uint32_t)(0x3 << 8);
 GPIOA_MODER_REG |= (uint32_t)(1 << 8);

  /*GPIO OTYPER register*/
 GPIOA_OTYPER_REG &= ~(1 << 4);

  /*GPIO OSPEEDR register*/
  //Set Low speed for GPIOB pin 4
 GPIOA_OSPEEDER_REG &= ~(0x3 << 8);

  /*GPIO PUPDR register, reset*/
  //Set pull up for GPIOB pin 3 (input)
 GPIOA_PUPDR_REG |= (1 << 6);
  //Set no pull for GPIOB pin 4 (output)
 GPIOA_PUPDR_REG &= ~(0x3 << 8);

  while (1)
  {

  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
