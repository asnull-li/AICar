#include "stm32f10x.h"                  // Device header
#include "Servo_PWM.h"

void Servo_Init(void)
{
	Servo_PWM_Init();
}

void Servo1_SetAngle(float Angle)
{
	Servo_PWM_SetCompare3(Angle / 180 * 2000 + 500);
}

void Servo2_SetAngle(float Angle)
{
	Servo_PWM_SetCompare4(Angle / 180 * 2000 + 500);
}
