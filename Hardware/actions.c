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
    else if (strcmp(actions, "moveLeft") == 0)
    {
        MotorMoveLeft(80); 
    }
    else if (strcmp(actions, "moveRight") == 0)
    {
        MotorMoveRight(80);
    }
    else if (strcmp(actions, "rotateLeft") == 0)
    {
        MotorRotateLeft(80);
    }
    else if (strcmp(actions, "rotateRight") == 0)
    {
        MotorRotateRight(80);
    }
    else if (strcmp(actions, "moveLeftForward") == 0)
    {
        MotorMoveLeftForward(80);
    }
    else if (strcmp(actions, "moveRightForward") == 0)
    {
        MotorMoveRightForward(80);
    }
    else if (strcmp(actions, "moveLeftBackward") == 0)
    {
        MotorMoveLeftBackward(80);
    }
    else if (strcmp(actions, "moveRightBackward") == 0)
    {
        MotorMoveRightBackward(80); 
    }
}

// 头部动作匹配
void headActionsMatch(char *actions){
    if (strcmp(actions, "headLeft") == 0)
    {
        headLeft();
    }  
    else if (strcmp(actions, "headRight") == 0)
    {
        headRight();
    }
    else if (strcmp(actions, "headUp") == 0)
    {
        headUp();
    }
    else if (strcmp(actions, "headDown") == 0) 
    {
        headDown(); 
    }
    else if (strcmp(actions, "headCenter") == 0)
    {
        headCenter();
    }
    else if (strcmp(actions, "headNod") == 0)
    {
        headNod();
    }
    else if (strcmp(actions, "headShake") == 0)
    {
        headShake();
    }
}

void beginActions(char *actions)
{
    // 表情匹配
    faceMacth(actions);
    carMoveMatch(actions);
    headActionsMatch(actions);
    if (strncmp(actions, "delay,", 6) == 0) {
        int delay_ms = atoi(actions + 6); // 解析延时毫秒数
        Delay_ms(delay_ms); // 调用延时函数
    }
    
}
