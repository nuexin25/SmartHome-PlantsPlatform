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
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "esp8266.h"
#include "onenet.h"
#include "oled.h"
#include "dht11.h"
#define STACK_SIZE 1024 // 增加堆栈大小

int fputc(int ch, FILE *f){
	uint8_t temp[1] = {ch};
	HAL_UART_Transmit(&huart1, temp, 1, 0xffff);
return ch;
}
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
uint16_t GetHumidity(int times);
uint8_t GPIO_set(uint8_t status);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//#define Channels 4		//对应4个ADC频道提供后期传感器拓展接口
//#define Data 10			//ADC回调中ֵ每次读取10次值滤波
#define ESP8266_OneNet_INFO		"AT+CIPSTART=\"TCP\",\"mqtts.heclouds.com\",1883\r\n"			//OneNet 上云


uint8_t DATA[4] = {0XAA,0XAF,0X00,0XFF};		//串口调试用
//uint16_t ADC_Value[Data][Channels];
//uint8_t Hum = 0;
uint16_t Count = 0;
extern uint8_t Data[5];
float temp,humi;
int light_status;
int duoji_status;
int fan_status;
float pulse;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	unsigned char *dataPtr = NULL;

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
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	
   
	 
	 OLED_Init();  // 初始化OLED
	 OLED_CLS();   // 清屏
	 OLED_ON();    // 开启显示
	 ESP8266_Init();
	//HAL_UART_Transmit(&huart1,(uint8_t *)"Connect MQTTs Server...\r\n",sizeof("Connect MQTTs Server...\r\n"),0xffff);
	while(ESP8266_SendCmd(ESP8266_OneNet_INFO,"CONNECT"))
	HAL_Delay(10);
	//HAL_UART_Transmit(&huart1,(uint8_t *)"Connect MQTTs Server Success!\r\n",sizeof("Connect MQTTs Server Success!\r\n"),0xffff);
	HAL_Delay(10);
	while(OneNet_DevLink())
	HAL_Delay(10);
	 // 显示字符串
	OLED_ShowStr(0, 1, "1. AT", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(2000);
	OLED_CLS();   // 清屏
	OLED_ShowStr(0, 1, "2. CWMODE", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(2000);
	OLED_CLS();
	OLED_ShowStr(0, 1, "3. AT+CWDHCP", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(2000);
	OLED_CLS();
	OLED_ShowStr(0, 1, "4. CWJAP", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(2000);
	OLED_CLS();
	OLED_ShowStr(0, 1, "5. ESP8266 Init OK", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(2000);
	OLED_CLS();
	OLED_ShowStr(0, 1, "Hello World", 2);  // 在(0,1)位置显示"Hello World"，使用8*16字体
	HAL_Delay(5000);
	OLED_CLS();   // 清屏
	OneNET_Subscribe();
	
	 HAL_Delay(10);
	
	light_status = GPIO_set(0);
  duoji_status = Duoji_set(0);
	fan_status = fan_set(0);
	


	HAL_Delay(100);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
			
        DHT_Read();
		
				temp = Data[2]+0.1*Data[3];
				
				humi = Data[0]+0.1*Data[1];
				
				Count++;
		OLED_ShowStr(10, 1, "temp:", 2);
		OLED_ShowNum(40, 1,temp,5,16);//size2(16|12)
		OLED_ShowStr(10, 4, "humi:", 2);
		OLED_ShowNum(40,4,humi,5,16);//size2(16|12)
	

		if(Count > 30){
			
				temp = Data[2]+0.1*Data[3];
				
				humi = Data[0]+0.1*Data[1];
		
			HAL_Delay(50);
			//printf("OneNet_SendData\r\n");
			
			OneNet_SendData();				
			Count = 0;
			ESP8266_Clear();
		}
		HAL_Delay(50);
		dataPtr = ESP8266_GetIPD(0);
		if(dataPtr != NULL){
			OneNet_RevPro(dataPtr);
			ESP8266_Clear();
		}
		
		
		
//		 int i=1000; //循环时间间隔1s
//      
//      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,50); //相当于一个周期内（20ms）有0.5ms高脉冲
//      HAL_Delay(i);
//      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,250); //相当于一个周期内（20ms）有2.5ms高脉冲
//      HAL_Delay(i);

		
		
//		if(DHT_Read())
//			{
//				printf("DHT11 Read Success!\r\n");
//				printf("Temperature: %d.%d ℃\r\n", Data[2], Data[3]);
//				printf("Humidity: %d.%d %%\r\n", Data[0], Data[1]);
//			}
//			else
//			{
//				printf("DHT11 Read Failed!\r\n");
//			}
//			HAL_Delay(50);


//	printf("Temperature: %0.1f℃\r\n",temp);
//	printf("Temperature: %0.1f\r\n",humi);
	


//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
//		HAL_Delay(20);
		
	

//		HAL_UART_Transmit(&huart1,(uint8_t *)"Hello world\r\n",sizeof("Hello world\r\n"),0xffff);
//		OLED_ShowNum(0,1,15,3,16);//size2(16|12)
//		OLED_ShowStr(0,1,"text", 6*8);//显示字符串
		HAL_Delay(10);
    
    /* USER CODE END WHILE */

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
}

/* USER CODE BEGIN 4 */
void Motor_Start(void)
{
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
}
void Motor_SetSpeed(int Mode,float speed)
{
	//356为我是用的电机最大转速，此if判断保证速度的合理性
	if(0 <= speed && speed <= 356)
	//速度转换为比较寄存器值的一元一次函数
	 pulse = 0 + 2.8086*speed;
	
	if(Mode == 1)
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_SET);
	}
	if(Mode == 0)
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);	
	}
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,pulse);
}

uint8_t GPIO_set(uint8_t status)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, !status);
	return status;
}
uint8_t Duoji_set(uint8_t status)
{
	if(status == 1)
	{
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);//***定时器初始化
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,250);
	return 1 ;
	}
	else if(status == 0)
	{
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);//***定时器初始化
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,160);
	return 0 ;
	}
}
uint8_t fan_set(uint8_t status)
{
	if(status == 1)
	{
	HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
	 HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);//***定时器初始化
	 Motor_SetSpeed(0,300);
	return 1 ;
	}
	else if(status == 0)
	{
	HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_4);
	Motor_SetSpeed(0,0);

	return 0 ;
	}
}
//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
//  uint32_t Total_DAC_Data = 0;
//  uint32_t AVG_Data = 0;
//  for(uint8_t i = 0; i < Data; i++){
//		//printf("ADC Value: %d,%d,%d,%d\r\n",ADC_Value[i][0],ADC_Value[i][1],ADC_Value[i][2],ADC_Value[i][3]);
//    Total_DAC_Data = Total_DAC_Data + ADC_Value[i][3];    //目前只在 PB1(IN9)中接入了传感器 
//  }
//  AVG_Data = Total_DAC_Data/10;
//  Hum = (float)(4096 - AVG_Data)/(4096-1400)*100;
//  //printf("Average ADC Value: %d\r\n",AVG_Data);
//	Count++;
  //printf("\n--------------------------------------------\n");
//}

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
