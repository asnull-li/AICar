#include "main.h"

cJSON *str_json, *str_type, *str_data;
int main(void)
{
	OLED_Init();
	Servo_Init(); // 舵机初始化
	Motor_Init(); // 电机初始化
	Serial_Init(); // 串口初始化
	OLED_ShowImage(0, 0, 128, 64, boredFace);
	OLED_Update();
	while (1)
	{
		if (Serial_RxFlag == 1)
		{
			str_json = cJSON_Parse(Serial_RxPacket);	
			str_type = cJSON_GetObjectItem(str_json, "type");
			str_data = cJSON_GetObjectItem(str_json, "data");

			// 判断情绪
			if (strcmp(str_type->valuestring, "emotion") == 0)
			{
				char *emotion = str_data->valuestring;
				if (strcmp(emotion, "快乐") == 0)
				{
					OLED_ShowImage(0, 0, 128, 64, happyFace);
					OLED_Update();
				}else if (strcmp(emotion, "伤心") == 0)
				{
					OLED_ShowImage(0, 0, 128, 64, sadFace);
					OLED_Update();
				}else if (strcmp(emotion, "愤怒") == 0){
					OLED_ShowImage(0, 0, 128, 64, angryFace);
					OLED_Update();
				}
				else if (strcmp(emotion, "意外") == 0){
					OLED_ShowImage(0, 0, 128, 64, astonishmentFace);
					OLED_Update();	
				}
				else if (strcmp(emotion, "专注") == 0){
					OLED_ShowImage(0, 0, 128, 64, bigEyeFace);
					OLED_Update();	
				}
				else if (strcmp(emotion, "懊恼") == 0){
					OLED_ShowImage(0, 0, 128, 64, boredFace);
					OLED_Update();	
				}
				else if (strcmp(emotion, "困倦") == 0){
					OLED_ShowImage(0, 0, 128, 64, trappedFace);
					OLED_Update();	
				}
				else if (strcmp(emotion, "疑问") == 0){
					OLED_ShowImage(0, 0, 128, 64, questionFace);
					OLED_Update();	
				}
				else if (strcmp(emotion, "敬畏") == 0){
					OLED_ShowImage(0, 0, 128, 64, loveFace);
					OLED_Update();	
				}else{
					OLED_ShowImage(0, 0, 128, 64, blankFace);
					OLED_Update();
				}
			}
			
			Serial_SendString("face1_OK\r\n");
			OLED_ShowString(0, 0, Serial_RxPacket,OLED_6X8);
			OLED_Update();
			if (strcmp(Serial_RxPacket, "face1") == 0)
			{
				OLED_ShowImage(0, 0, 128, 64, blankFace);
				OLED_Update();
				Serial_SendString("face1_OK\r\n");
				
			}
			else if (strcmp(Serial_RxPacket, "face2") == 0)
			{
				OLED_ShowImage(0, 0, 128, 64, angryFace);
				OLED_Update();
				Serial_SendString("face1_OK\r\n");
			}
			Serial_RxFlag = 0;
		}
	
		
		/** 
		Servo1_SetAngle(0);
		Servo2_SetAngle(90);
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
*/
		// Servo1_SetAngle(60);
		// Servo2_SetAngle(60);
		// MotorLeft1(50,"forward");
		// MotorLeft2(50,"forward");
		// MotorRight1(50,"forward");
		// MotorRight2(50,"forward");
	}
}
