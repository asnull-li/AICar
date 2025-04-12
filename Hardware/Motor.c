#include <string.h>
#include "stm32f10x.h"                  // Device header
#include "Motor_PWM.h"
#include "Delay.h"

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
/**
 * @brief 小车前进
 * @param speed 速度
 */
void MotorForward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"forward");
	MotorLeft2(speed,"forward");
	MotorRight1(speed,"forward");
	MotorRight2(speed,"forward");
}

/**
 * @brief 小车后退
 * @param speed 速度
 */
void MotorBackward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"backward");
	MotorLeft2(speed,"backward");
	MotorRight1(speed,"backward");
	MotorRight2(speed,"backward");	
}




/**
 * @brief 小车左平移
 * @param speed 速度
 */
void MotorMoveLeft(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"backward");
	MotorLeft2(speed,"forward");
	MotorRight1(speed,"forward");
	MotorRight2(speed,"backward");
}

/**
 * @brief 小车右平移
 * @param speed 速度
 */
void MotorMoveRight(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"forward");
	MotorLeft2(speed,"backward");
	MotorRight1(speed,"backward");
	MotorRight2(speed,"forward");	
}

/**
 * @brief 小车左旋转
 * @param speed 速度
 */
void MotorRotateLeft(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"backward");
	MotorLeft2(speed,"backward");
	MotorRight1(speed,"forward");
	MotorRight2(speed,"forward");	
}

/**
 * @brief 小车右旋转
 * @param speed 速度
 */
void MotorRotateRight(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"forward");
	MotorLeft2(speed,"forward");
	MotorRight1(speed,"backward");
	MotorRight2(speed,"backward");	
}

/**
 * @brief 小车左前
 * @param speed 速度
 */
void MotorMoveLeftForward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft2(speed,"forward");
	MotorRight1(speed,"forward");	
}

/**
 * @brief 小车右前
 * @param speed 速度
 */
void MotorMoveRightForward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"forward");
	MotorRight2(speed,"forward");	
}

/**
 * @brief 小车左后
 * @param speed 速度
 */
void MotorMoveLeftBackward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft1(speed,"backward");
	MotorRight2(speed,"backward");	
}

/**
 * @brief 小车右后
 * @param speed 速度
 */
void MotorMoveRightBackward(int speed){
	MotorStop();
	Delay_ms(20);
	MotorLeft2(speed,"backward");
	MotorRight1(speed,"backward");	
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

