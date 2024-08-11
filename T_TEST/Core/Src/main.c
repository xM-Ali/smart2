/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
void SEL_CH0(void);
void SEL_CH1(void);
void SEL_CH4(void);
void SEL_CH5(void);
void SEL_CH6(void);
void SEL_CH7(void);
void SEL_CH8(void);
void SEL_CH9(void);
void ADC_Read(void);
void ADC_Voltage(void);
void Recieve_Temp(void);
void Transmit_Data(void);

volatile float ADC[9];
volatile float ADC_V1,ADC_V2,ADC_V3,ADC_V4,ADC_V5,ADC_V6,ADC_V7,ADC_V8;
int a,d,e;
float T1,T2;
char receivedBuffer[100];
HAL_StatusTypeDef receiveStatus;
float receivedTemperatures[2];
char uart2Buffer[50];



int main(void)
{
  
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
	MX_ADC1_Init();
	//MX_USART1_UART_Init();
  //MX_USART2_UART_Init();
	
	
  while (1)
  {
		
   ADC_Read();
   ADC_Voltage();
	 //Recieve_Temp();
	 //Transmit_Data();
   HAL_Delay(100);
  }
}

void SEL_CH0()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_0;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH1()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_1;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH4()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_4;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH5()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_5;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH6()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_6;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH7()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_7;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH8()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_8;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}

void SEL_CH9()
{
   ADC_ChannelConfTypeDef sConfig = {0};
   sConfig.Channel = ADC_CHANNEL_9;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
}
void ADC_Read()
{
 SEL_CH0();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[0] = (float)HAL_ADC_GetValue(&hadc1);
   }

	 
   SEL_CH1();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[1] = (float)HAL_ADC_GetValue(&hadc1);
   }
	 
	 
	 SEL_CH4();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[2] = (float)HAL_ADC_GetValue(&hadc1);
   }

	 
   SEL_CH5();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[3] = (float)HAL_ADC_GetValue(&hadc1);
   }
	 
	 SEL_CH6();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[4] = (float)HAL_ADC_GetValue(&hadc1);
   }

	 
   SEL_CH7();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[5] = (float)HAL_ADC_GetValue(&hadc1);
   }
	 
	 
	 SEL_CH8();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[6] = (float)HAL_ADC_GetValue(&hadc1);
   }

	 
   SEL_CH9();
   HAL_ADC_Start(&hadc1);
   if(HAL_ADC_PollForConversion(&hadc1, 4) == HAL_OK)
   {
    ADC[7] = (float)HAL_ADC_GetValue(&hadc1);
   }

}



void ADC_Voltage()
{
	ADC_V1=(ADC[0]/4096)*3.3;
	ADC_V2=(ADC[1]/4096)*3.3;
	ADC_V3=(ADC[2]/4096)*3.3;
	ADC_V4=(ADC[3]/4096)*3.3;
	ADC_V5=(ADC[4]/4096)*3.3;
	ADC_V6=(ADC[5]/4096)*3.3;
	ADC_V7=(ADC[6]/4096)*3.3;
	ADC_V8=(ADC[7]/4096)*3.3;

}

void Recieve_Temp(void)
{
	// Receive data via UART1
    receiveStatus = HAL_UART_Receive(&huart1, (uint8_t *)receivedBuffer, sizeof(receivedBuffer), HAL_MAX_DELAY);

    // Check if reception was successful
    if (receiveStatus == HAL_OK)
    {
        a = 1;

        // Process the received data
        char *token = strtok(receivedBuffer, " ");
        int sensorIndex = 0;

        while (token != NULL)
        {
            d += 1;
            if (strncmp(token, "Temperature:", strlen("Temperature:")) == 0)
            {
                token = strtok(NULL, " "); // Move to the value
                receivedTemperatures[sensorIndex++] = atof(token);
                if (sensorIndex >= 2)
                    break;
            }

            token = strtok(NULL, " ");
						 
        }
        d=100;

        // Now, you have the received temperatures in the receivedTemperatures array
        // You can use these values as needed, e.g., display them or log them
        T1 = receivedTemperatures[0];
        T2 = receivedTemperatures[1];
			}
		else
			{
					// Handle parsing error
					// For example, toggle an LED or print an error message
					a = 19;
			}

}

void Transmit_Data(void)
{
	   snprintf(uart2Buffer, sizeof(uart2Buffer), "V1:%.2lf V2:%.2lf T1:%.2lf T2:%.2fl \r\n", ADC_V1, ADC_V2, T1, T2);
     if (HAL_UART_Transmit(&huart2, (uint8_t *)uart2Buffer, strlen(uart2Buffer), HAL_MAX_DELAY) == HAL_OK)
     {
         e = 10;
     }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8
                          |GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB3 PB4 PB5 PB8
                           PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8
                          |GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
