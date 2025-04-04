#include <string.h>
#include <stdlib.h>
#include "OLED.h"
#include "Servo.h"
#include "Motor.h"
#include "Delay.h"

// 表情匹配
void faceMacth(char *actions)
{
    // 表情显示
    if (strcmp(actions, "blankFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, blankFace);
        OLED_Update();
    }
    else if (strcmp(actions, "bigEyesFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, bigEyesFace);
        OLED_Update();
    }
    else if (strcmp(actions, "astonishmentFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, astonishmentFace);
        OLED_Update();
    }
    else if (strcmp(actions, "happyFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, happyFace);
        OLED_Update();
    }
    else if (strcmp(actions, "trappedFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, trappedFace);
        OLED_Update();
    }
    else if (strcmp(actions, "sadFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, sadFace);
        OLED_Update();
    }
    else if (strcmp(actions, "angryFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, angryFace);
        OLED_Update();
    }
    else if (strcmp(actions, "boredFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, boredFace);
        OLED_Update();
    }
    else if (strcmp(actions, "loveFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, loveFace);
        OLED_Update();
    }
    else if (strcmp(actions, "questionFace") == 0)
    {
        OLED_ShowImage(0, 0, 128, 64, questionFace);
        OLED_Update();
    }
}

// 小车运动匹配
void carMoveMatch(char *actions){
    if (strcmp(actions, "forward") == 0)
    {
       MotorForward(80);
    }
    else if (strcmp(actions, "backward") == 0)
    {
       MotorBackward(80);
    }
    else if (strcmp(actions, "stop") == 0)
    {
        MotorStop();
    }
}


void beginActions(char *actions)
{
    // 表情匹配
    faceMacth(actions);
    carMoveMatch(actions);
    if (strncmp(actions, "delay,", 6) == 0) {
        int delay_ms = atoi(actions + 6); // 解析延时毫秒数
        Delay_ms(delay_ms); // 调用延时函数
    }
    
}
