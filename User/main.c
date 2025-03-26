#include "main.h"
int main(void)
{
	OLED_Init();
	Servo_Init(); // 舵机初始化
	Motor_Init(); // 电机初始化

	
	while (1)
	{
		OLED_ShowImage(0, 0, 128, 64, blankFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, questionFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, bigEyeFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, astonishmentFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, happyFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, trappedFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, sadFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, angryFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, boredFace);
		OLED_Update();
		Delay_ms(1000);
		OLED_ShowImage(0, 0, 128, 64, loveFace);
		OLED_Update();
		Delay_ms(1000);

		// Servo1_SetAngle(60);
		// Servo2_SetAngle(60);
		// MotorLeft1(50,"forward");
		// MotorLeft2(50,"forward");
		// MotorRight1(50,"forward");
		// MotorRight2(50,"forward");
		
	}
}
