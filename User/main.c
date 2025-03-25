#include "main.h"
int main(void)
{
	OLED_Init();
	Servo_Init(); // 舵机初始化
	Motor_Init(); // 电机初始化
	while (1)
	{
		OLED_ShowNum(2,3,1,1);
		OLED_ShowString(2,5,"Hello");
		Servo1_SetAngle(60);
		MotorLeft1(50,"forward");
		MotorLeft2(50,"forward");
		MotorRight1(50,"forward");
		MotorRight2(50,"forward");

	}
}
