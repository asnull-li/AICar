#include <string.h>
#include "stm32f10x.h"                  // Device header
#include "Motor_PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9; // A4-7用于控制电机正反转
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	Motor_PWM_Init();
}

/**
 * @brief 左侧第一个电机
 * @param speed 速度
 * @param type 方向
 */
void MotorLeft1(int speed,char *type){
	if (strcmp(type,"forward")== 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		Motor_PWM_SetCompare1(speed);
	}
	else if (strcmp(type,"backward")== 0){
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		Motor_PWM_SetCompare1(speed);
	}
}

/**
 * @brief 左侧第二个电机
 * @param speed 速度
 * @param type 方向
 */
void MotorLeft2(int speed,char *type){
	if (strcmp(type,"forward")== 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		Motor_PWM_SetCompare2(speed);
	}
	else if (strcmp(type,"backward")== 0){
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		Motor_PWM_SetCompare2(speed);
	}
}

/**
 * @brief 右侧第一个电机
 * @param speed 速度
 * @param type 方向
 */
void MotorRight1(int speed,char *type){
	if (strcmp(type,"forward")== 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_9);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Motor_PWM_SetCompare3(speed);
	}
	else if (strcmp(type,"backward")== 0){
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);
		Motor_PWM_SetCompare3(speed);
	}
}

/**
 * @brief 右侧第二个电机
 * @param speed 速度
 * @param type 方向
 */
void MotorRight2(int speed,char *type){
	if (strcmp(type,"forward")== 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_6);
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		Motor_PWM_SetCompare4(speed);
	}
	else if (strcmp(type,"backward")== 0){
		GPIO_SetBits(GPIOB, GPIO_Pin_7);
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
		Motor_PWM_SetCompare4(speed);
	}
}

// 电机制动
void MotorBraking(void)
{
	// in1和in2高电平制动
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
	GPIO_SetBits(GPIOA, GPIO_Pin_8);
	GPIO_SetBits(GPIOA, GPIO_Pin_9);
	GPIO_SetBits(GPIOB, GPIO_Pin_6);
	GPIO_SetBits(GPIOB, GPIO_Pin_7);
}

// 电机停止
void MotorStop(void)
{
	// in1和in2低电平停止
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
}
