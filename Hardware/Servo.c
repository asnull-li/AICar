#include "stm32f10x.h"                  // Device header
#include "Servo_PWM.h"
#include "Delay.h"
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

void headLeft(void){
	Servo1_SetAngle(30);
}

void headRight(void){
	Servo1_SetAngle(120);
}

void headUp(void){
	Servo2_SetAngle(5);
}
void headDown(void){
	Servo2_SetAngle(80);
}

void headCenter(void){
	Servo1_SetAngle(75);
	Servo2_SetAngle(45);
}

void headNod(void){
	headDown();
	Delay_ms(200);
	headUp();
	Delay_ms(200);
	headDown();
	Delay_ms(200);
	headUp();
	Delay_ms(200);
	headDown();
	Servo2_SetAngle(45);
}

void headShake(void){
	headLeft();
	Delay_ms(200);
	headRight();
	Delay_ms(200);
	headLeft();
	Delay_ms(200);
	headRight();
	Delay_ms(200);
	headLeft();
	Servo1_SetAngle(75);
}
