#include "main.h"

int main(void)
{
	OLED_Init();
	Servo_Init();  // 舵机初始化
	Motor_Init();  // 电机初始化
	Serial_Init(); // 串口初始化
	OLED_ShowImage(0, 0, 128, 64, blankFace);
	OLED_Update();
	while (1)
	{
		
		if (Serial_RxFlag == 1)
		{
			char jsonStr[512]; // 存储接收到的JSON字符串
			strcpy(jsonStr, Serial_RxPacket);

			// 查找actions数组
			char *actionsStart = strstr(jsonStr, "\"actions\":[");
			if (actionsStart)
			{
				actionsStart += 11; // 跳过"actions":[ （注意这里是11个字符）

				// 遍历actions数组中的每个元素
				char *currentPos = actionsStart;
				while (*currentPos && *currentPos != ']')
				{
					// 跳过空白字符和逗号
					while (*currentPos && (*currentPos == ' ' || *currentPos == ',' || *currentPos == '\r' || *currentPos == '\n'))
					{
						currentPos++;
					}

					// 如果到达数组结尾则退出
					if (*currentPos == ']' || *currentPos == '\0')
					{
						break;
					}

					// 寻找字符串开始位置
					if (*currentPos == '\"')
					{
						char *actionStart = currentPos + 1;
						char *actionEnd = strchr(actionStart, '\"');

						if (actionEnd)
						{
							// 临时存储action字符串
							char actionStr[64] = {0};
							int len = actionEnd - actionStart;
							if (len < sizeof(actionStr))
							{
								strncpy(actionStr, actionStart, len);
								actionStr[len] = '\0';

								// 输出并执行action
								Serial_SendString(actionStr);
								beginActions(actionStr);
							}

							// 移动到当前字符串之后
							currentPos = actionEnd + 1;
						}
						else
						{
							break; // 格式错误
						}
					}
					else
					{
						currentPos++; // 继续查找下一个引号
					}
				}
			}
			Serial_RxFlag = 0;
		}
		
	}
}
