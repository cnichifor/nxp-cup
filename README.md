# NXP Cup Autonomous Line-Following Car

Autonomous line-following car developed for the NXP Cup competition.
The project combines embedded programming, real-time sensor processing, and control logic to keep the car on track through curves and intersections.

## My Role

My main contribution was the implementation of the car’s line-following algorithm.
I developed the logic for lane tracking, curve handling, and intersection handling, while also contributing to hardware integration and testing within the team.

## Hardware and Software Stack

- NXP FRDM-MCXN947 development board
- Pixy2 camera sensor
- C programming language
- MCUXpresso IDE
- Embedded SDK / peripheral drivers
- Motor driver and steering control components

## How It Works

The car uses the Pixy2 camera to detect line vectors in real time.
These vectors are processed by the control algorithm to estimate the lane position and compute steering corrections.

The implemented logic was designed to:
- keep the car centered on the track
- handle curved segments robustly
- detect and handle intersections
- maintain stable track completion under changing visual conditions

## Features

- Real-time line following
- Curve handling
- Intersection handling
- Stable steering correction
- Embedded implementation in C
- Sensor-based control using Pixy2

## Results

The implemented control logic enabled stable and reliable track completion during competition runs.

- Achieved **11th place out of 46 teams** in the NXP Cup competition

## Demo

- Competition run in Bucharest: [Watch the video](https://youtube.com/shorts/tmlwgP5I4E4?feature=share)

## Challenges

Some of the main technical challenges included:
- maintaining stable steering in curves
- handling intersections correctly
- working with changing visual input from the camera
- tuning the control behavior for reliable real-world performance

## Future Improvements

- improve robustness under difficult lighting conditions
- refine steering control for higher speed
- improve lane center estimation
- optimize behavior when only partial lane information is available
