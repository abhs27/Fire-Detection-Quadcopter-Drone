


# **<span style="text-decoration:underline;">DRONE BUILDING AND IMPLEMENTATION</span>**

## **MENTORS**

Abhinith D

Jobin Jacob

Pratheek Bandigedi 

## **<span style="text-decoration:underline;">INTRODUCTION</span>**

Drone technology is rapidly advancing, becoming more efficient, versatile, and affordable. Innovations in battery life, autonomous navigation, and camera quality enhance their utility in various fields. Drones offer unique aerial perspectives in photography and filmmaking, revolutionizing cinematography and media production. They also inspect infrastructure like bridges, power lines, and pipelines, reducing downtime and enhancing safety. These applications demonstrate drones' growing significance in enhancing efficiency, safety, and innovation across various sectors. This project aims to build a drone from scratch and have a useful implementation of it with the help of camera and image processing.



## **<span style="text-decoration:underline;">PROJECT OBJECTIVES</span>**

## ***Embedded System Objectives:***

This project aims to implement a flight controller for the drone, including a PID control stabilization and 6 DOF movement using an accelerometer and gyroscope<sub>, </sub>BLDC(brushless DC) motor speed/thrust control through electronic speed controller (ESC), GPS mapping, communication with pilot, and data/image transfer to a external computer for image detection capabilities, particularly fire detection, implemented through a machine learning model.

## ***SPS Objective:***

 Implement a fire detection model that returns the location of the fire using gps. The camera feed from the drone is taken and processing is done via a an external device (laptop). We then return the processed output to the drone and drone makes decision based on it.

The primary application and motive is to create a human-manned drone to detect wildfires in difficult to traverse and access locations where humans struggle to maintain surveillance and prevent escalation of such wildfires through early detection.



## **<span style="text-decoration:underline;">METHODOLOGY</span>** 
### 1)	Embedded System:

Tools and Framework: STM32 Environment, STM32Cube/CubeMX, Keil uVision

Hardware: STM32 Microcontroller 




* Implement basic communication with laptop (UART)
* GPS data receiving and parsing
* Barometer interfacing and kill switch (safety device)
* Gyrometer reading and processing (roll, pitch, yaw readings)
* Actuator implementation (BLDC and ESC)
* Motor speed control
* Wireless communication 
* Image clicking and transfer



![block diagram](https://github.com/user-attachments/assets/0b1318f1-1909-4fe8-b458-c5e5afba15c3)





## **<span style="text-decoration:underline;">SOURCES AND REFERENCES</span>**



1. Reviews on Design and Development of Unmanned Aerial Vehicles (Drone) for Different Applications - Abdul Aabid
2. Fast and Efficient Method for Fire Detection Using Image Processing - Turgay Celik
3. Course on STM32 Drone programming - Chris Park (m-hive.net)
