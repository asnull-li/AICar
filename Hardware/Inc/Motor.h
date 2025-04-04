#ifndef __MOTOR_H
#define __MOTOR_H
void Motor_Init(void);
void MotorForward(int speed);
void MotorBackward(int speed);
void MotorLeft1(int speed,char *type);
void MotorLeft2(int speed,char *type);
void MotorRight1(int speed,char *type);
void MotorRight2(int speed,char *type);
void MotorBraking(void);
void MotorStop(void);
#endif

