/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG1(int);
void display7SEG2(int);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int duration1 = 0, duration2 = 0;
  int ledR1 = 0, ledY1 = 0, ledG1 = 0,
    		  ledR2 = 0, ledY2 = 0, ledG2 = 0;
  int counter1 = 0, counter2 = 0;

  while (1)
  {
    /* USER CODE END WHILE */
	  if (!duration1){ // 1ST DIRECTION LIGHTS
	     		  /* CURRENT IS RED, ABOUT TO TURN GREEN */
	     	  		if (ledR1 && !ledG1 && !ledY1){
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED1_Pin, GPIO_PIN_SET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_GREEN1_Pin, GPIO_PIN_RESET);
	     	  			ledR1 = 0; ledG1 = 1; ledY1 = 0;
	     	  			duration1 = 3;
	     	  			counter1 = 2;
	     	  		}

	          /* CURRENT IS GREEN, ABOUT TO TURN YELLOW */
	     	  		else if (!ledR1 && ledG1 && !ledY1){
	     		  		HAL_GPIO_WritePin(GPIOA , LED_GREEN1_Pin, GPIO_PIN_SET);
	     				HAL_GPIO_WritePin(GPIOA , LED_YELLOW1_Pin, GPIO_PIN_RESET);
	     	  			ledR1 = 0; ledG1 = 0; ledY1 = 1;
	     	  			duration1 = 2;
	     	  			counter1 = 1;
	     	  		}

	     	  		/* CURRENT IS YELLOW, ABOUT TO TURN RED */
	     	  		else if (!ledR1 && !ledG1 && ledY1){
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED1_Pin, GPIO_PIN_RESET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_YELLOW1_Pin, GPIO_PIN_SET);
	     	  			ledR1 = 1; ledG1 = 0; ledY1 = 0;
	     	  			duration1 = 5;
	     	  			counter1 = 4;
	     	  		}

	     	  		else{
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED1_Pin, GPIO_PIN_RESET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_GREEN1_Pin, GPIO_PIN_SET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_YELLOW1_Pin, GPIO_PIN_SET);
	     	  			ledR1 = 1; ledG1 = 0; ledY1 = 0;
	     	  			duration1 = 5;
	     	  			counter1 = 4;
	     	  		}
	     	  	}
	  	  	duration1--;

	     	  if (!duration2){  // 2ND DIRECTION LIGHTS
	     		  /* CURRENT IS RED, ABOUT TO TURN GREEN */
	    	  		if (ledR2 && !ledG2 && !ledY2){
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED2_Pin, GPIO_PIN_SET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_GREEN2_Pin, GPIO_PIN_RESET);
	     	  			ledR2 = 0; ledG2 = 1; ledY2 = 0;
	     	  			duration2 = 3;
	     	  			counter2 = 2;
	     	  		}

	     	  		/* CURRENT IS GREEN, ABOUT TO TURN YELLOW */
	     	  		else if (!ledR2 && ledG2 && !ledY2){
	     		  		HAL_GPIO_WritePin(GPIOA , LED_GREEN2_Pin, GPIO_PIN_SET);
	     				HAL_GPIO_WritePin(GPIOA , LED_YELLOW2_Pin, GPIO_PIN_RESET);
	     	  			ledR2 = 0; ledG2 = 0; ledY2 = 1;
	     	  			duration2 = 2;
	     	  			counter2 = 1;
	     	  		}

	     	  		/* CURRENT IS YELLOW, ABOUT TO TURN RED */
	     	  		else if (!ledR2 && !ledG2 && ledY2){
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED2_Pin, GPIO_PIN_RESET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_YELLOW2_Pin, GPIO_PIN_SET);
	     	  			ledR2 = 1; ledG2 = 0; ledY2 = 0;
	     	  			duration2 = 5;
	     	  			counter2 = 4;
	     	  		}

	     	  		else{
	     	  			HAL_GPIO_WritePin(GPIOA , LED_RED2_Pin, GPIO_PIN_SET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_GREEN2_Pin, GPIO_PIN_RESET);
	     	  			HAL_GPIO_WritePin(GPIOA , LED_YELLOW2_Pin, GPIO_PIN_SET);
	     	  			ledR2 = 0; ledG2 = 1; ledY2 = 0;
	     	  			duration2 = 3;
	     	  			counter2 = 2;
	     	  		}
	     	  	}
	     	  	duration2--;

	     	  	if (counter1 < 0) counter1 = 0;
	     	  	if (counter2 < 0) counter2 = 0;
	     	  	display7SEG1(counter1--);
	     	  	display7SEG2(counter2--);

	     	  	HAL_Delay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_YELLOW1_Pin|LED_GREEN1_Pin|LED_RED2_Pin
                          |LED_YELLOW2_Pin|LED_GREEN2_Pin|SEG20_Pin|SEG21_Pin
                          |SEG22_Pin|SEG23_Pin|SEG24_Pin|SEG25_Pin
                          |SEG26_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG10_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |SEG14_Pin|SEG15_Pin|SEG16_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED1_Pin LED_YELLOW1_Pin LED_GREEN1_Pin LED_RED2_Pin
                           LED_YELLOW2_Pin LED_GREEN2_Pin SEG20_Pin SEG21_Pin
                           SEG22_Pin SEG23_Pin SEG24_Pin SEG25_Pin
                           SEG26_Pin */
  GPIO_InitStruct.Pin = LED_RED1_Pin|LED_YELLOW1_Pin|LED_GREEN1_Pin|LED_RED2_Pin
                          |LED_YELLOW2_Pin|LED_GREEN2_Pin|SEG20_Pin|SEG21_Pin
                          |SEG22_Pin|SEG23_Pin|SEG24_Pin|SEG25_Pin
                          |SEG26_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG10_Pin SEG11_Pin SEG12_Pin SEG13_Pin
                           SEG14_Pin SEG15_Pin SEG16_Pin */
  GPIO_InitStruct.Pin = SEG10_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |SEG14_Pin|SEG15_Pin|SEG16_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void display7SEG2(int counter){
	switch (counter){
		case 0:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin | SEG13_Pin |
							  SEG14_Pin | SEG15_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG16_Pin , GPIO_PIN_SET);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOB , SEG11_Pin | SEG12_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG13_Pin | SEG14_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_SET);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG13_Pin | SEG14_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG12_Pin | SEG15_Pin , GPIO_PIN_SET);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin | SEG13_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG14_Pin | SEG15_Pin , GPIO_PIN_SET);
			break;

		case 4:
			HAL_GPIO_WritePin(GPIOB , SEG11_Pin | SEG12_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG13_Pin | SEG14_Pin , GPIO_PIN_SET);
			break;

		case 5:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG12_Pin | SEG13_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG11_Pin | SEG14_Pin , GPIO_PIN_SET);
			break;

		case 6:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG12_Pin | SEG13_Pin | SEG14_Pin |
							  SEG15_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG11_Pin , GPIO_PIN_SET);
			break;

		case 7:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG13_Pin | SEG14_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_SET);
			break;

		case 8:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin | SEG13_Pin |
							  SEG14_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_RESET);
			break;

		case 9:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin | SEG13_Pin |
							  SEG15_Pin | SEG16_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB , SEG14_Pin , GPIO_PIN_SET);
			break;

		default:
			HAL_GPIO_WritePin(GPIOB , SEG10_Pin | SEG11_Pin | SEG12_Pin | SEG13_Pin |
										  SEG14_Pin | SEG15_Pin | SEG16_Pin , GPIO_PIN_SET);
			break;
	}
}

void display7SEG1(int counter){
	switch (counter){
		case 0:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin | SEG23_Pin |
							  SEG24_Pin | SEG25_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG26_Pin , GPIO_PIN_SET);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOA , SEG21_Pin | SEG22_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG23_Pin | SEG24_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_SET);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG23_Pin | SEG24_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG22_Pin | SEG25_Pin , GPIO_PIN_SET);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin | SEG23_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG24_Pin | SEG25_Pin , GPIO_PIN_SET);
			break;

		case 4:
			HAL_GPIO_WritePin(GPIOA , SEG21_Pin | SEG22_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG23_Pin | SEG24_Pin , GPIO_PIN_SET);
			break;

		case 5:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG22_Pin | SEG23_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG21_Pin | SEG24_Pin , GPIO_PIN_SET);
			break;

		case 6:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG22_Pin | SEG23_Pin | SEG24_Pin |
							  SEG25_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG21_Pin , GPIO_PIN_SET);
			break;

		case 7:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG23_Pin | SEG24_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_SET);
			break;

		case 8:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin | SEG23_Pin |
							  SEG24_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_RESET);
			break;

		case 9:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin | SEG23_Pin |
							  SEG25_Pin | SEG26_Pin , GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA , SEG24_Pin , GPIO_PIN_SET);
			break;

		default:
			HAL_GPIO_WritePin(GPIOA , SEG20_Pin | SEG21_Pin | SEG22_Pin | SEG23_Pin |
										  SEG24_Pin | SEG25_Pin | SEG26_Pin , GPIO_PIN_SET);
			break;
	}
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
