# Angle Alarm firmware

##

This firmware for test project.
use STM8S003 to test the SCA103T's function. 
main function to commincate with SCA103T via spi port.

## G-Sensor

## SCA103T

单轴加速度传感器，水平放置，测量角度在箭头指定方向，+/-15度或+/-30度。如果放置不平的话会影响精度。

## BMA220

*Note. This IC supply voltage max 2.2V*
这是一个以前计划使用的一款BOSCH芯片，该芯片为3轴G-Sensor，但是该芯片需要电压为1.8V，最大为2.2V。对常规3.3V/5V系统兼容性差。

## MMA8452Q

这是一个3轴加速度传感器，该芯片采用I2C接口，在`二次事故报警器`设计当中有设计，但是没有实际应用。该芯片内部具有多种检测功能，并且可以通过IO口输出中断。

## MPU-6050

这是一款6轴传感器，3轴加速度+3轴陀螺仪，并且内置了温度传感器，是一款性价比非常高的芯片。

## ADXL345

