#include <Arduino.h>
#include <Esp32PcntEncoder.h>
#include<Esp32McpwmMotor.h>
#include<PidController.h>
#include <Kinematics.h>

Esp32PcntEncoder encoders[2];    //创建一个数组用于存储两个编码器
Esp32McpwmMotor motor;
//创建一个名为motor的对象，用于控制电机
PidController pid_controller[2];
Kinematics kinematics;
float target_linear_speed=50.0;  //单位毫米每秒
float target_angular_speed=0.1;  //单位弧度每秒
float out_left_speed=0.0;    //输出的左右轮速度，不是反馈的左右轮速度
float out_right_speed =0.0;

void setup()
{
    Serial.begin(115200); // 初始化串口通信，波特率为115200

    motor.attachMotor(0, 22, 23);  // 将电机0连接到引脚33和引脚25
    motor.attachMotor(1, 12, 13);  // 将电机1连接到引脚26和引脚27
    encoders[0].init(0, 32, 33);   // 初始化第一个编码器，使用GPI032和33连接
    encoders[1].init(1, 26, 25);   // 初始化第二个编码器，使用GPI026和25连接

    pid_controller[0].update_pid(0.625,0.125,0.0);
    pid_controller[1].update_pid(0.625,0.125,0.0);
    pid_controller[0].out_limit(-100,100);
    pid_controller[1].out_limit(-100,100);

    //初始化运动学参数
    kinematics.set_wheel_distance(175);//mm
    kinematics.set_motor_param(0, 0.105805);
    kinematics.set_motor_param(1, 0.105805);
    //测试下运动学逆解
    kinematics.kinematics_inverse(target_linear_speed,target_angular_speed,&out_left_speed,&out_right_speed);
    Serial.printf("out:left_speed=%f,right_speed=%f\n",out_left_speed,out_right_speed);
    pid_controller[0].update_target(out_left_speed);
    pid_controller[1].update_target(out_right_speed);
}

void loop()
{
    delay(10);//等待10毫秒
    //调用PID，获取动态输出值
    kinematics.update_motor_speed(millis(),encoders[0].getTicks(), encoders[1].
    getTicks());
    motor.updateMotorSpeed(0,pid_controller[0].update(
    kinematics.get_motor_speed(0)));
    motor.updateMotorSpeed(1,pid_controller[1].update(kinematics.get_motor_speed(1)));
}
