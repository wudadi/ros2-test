#include <Arduino.h>
#include <Esp32PcntEncoder.h>
#include <Esp32McpwmMotor.h>

Esp32PcntEncoder encoders[2]; // 创建一个数组用于存储两个编码器
Esp32McpwmMotor motor;

int64_t last_ticks[2] = {0, 0};  // 用于存储上一次读取的编码器数值
int16_t delta_ticks[2] = {0, 0}; // 用于存储上一次读取的编码器数值
int64_t last_update_time = 0;    // 用于存储上一次更新电机速度的时间
float current_speed[2]={0,0};//用于存储当前电机速度

void setup()
{
    Serial.begin(115200); // 初始化串口通信，波特率为115200

    motor.attachMotor(0, 22, 23);  // 将电机0连接到引脚33和引脚25
    motor.attachMotor(1, 12, 13);  // 将电机1连接到引脚26和引脚27
    encoders[0].init(0, 32, 33);   // 初始化第一个编码器，使用GPI032和33连接
    encoders[1].init(1, 26, 25);   // 初始化第二个编码器，使用GPI026和25连接
    motor.updateMotorSpeed(0, 70); // 设置电机0的速度为负70
    motor.updateMotorSpeed(1, 70); // 设置电机1的速度为正70
}

void loop()
{
    delay(10); // 等待10毫秒
    // 计算编码器当前和上一次读取的数值之差
    int16_t dt = millis() - last_update_time;
    delta_ticks[0] = encoders[0].getTicks() - last_ticks[0];
    delta_ticks[1] = encoders[1].getTicks() - last_ticks[1];
    current_speed[0] = (delta_ticks[0] * 0.105805) / dt;
    current_speed[1] = (delta_ticks[1] * 0.105805) / dt;
    // 为了下次还可以正常的计算速度
    last_ticks[0] = encoders[0].getTicks();
    last_ticks[1] = encoders[1].getTicks();
    last_update_time = millis();
    Serial.printf("speedl=%f,speed2=%f\n", current_speed[0], current_speed[1]);
}
