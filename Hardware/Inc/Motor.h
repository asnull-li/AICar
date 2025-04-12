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
void MotorMoveLeft(int speed);
void MotorMoveRight(int speed);
void MotorRotateLeft(int speed);
void MotorRotateRight(int speed);
void MotorMoveLeftForward(int speed);
void MotorMoveRightForward(int speed);
void MotorMoveLeftBackward(int speed);
void MotorMoveRightBackward(int speed);

#endif

