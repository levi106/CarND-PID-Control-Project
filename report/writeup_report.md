# **PID Controller**

**PID Controller Project**

The goals / steps of this project are the following:

1. Clone/fork the project's template files from the project repository and have a look at the rubric here. (Note: Please do not submit your project as a pull request against our repo!)
2. Build a PID controller and tune the PID hyperparameters by applying the general processing flow as described in the previous lessons.
3. Test your solution on the simulator!
4. When the vehicle is able to drive successfully around the track, submit! Remember to include a file addressing the reflection portion of the project in .txt, .md, .html, or .pdf format.
5. Try to see how fast you get the vehicle to SAFELY go!

[//]: # (Image References)

[image1]: ./result-0.05-0-0.png "0.05 0 0"
[image2]: ./result-0.05-0-5.png "0.05 0 5"
[image3]: ./result-0.05-0.002-5.png "0.05 0.002 5"
[image4]: ./result-0.05-0.002-2.png "0.05 0.002 2"
[image5]: ./result-0.05-0.002-8.png "0.05 0.002 8"
[image6]: ./result-0.1-0.002-5.png "0.1 0.002 5"
[image7]: ./result-0.2-0.002-5.png "0.2 0.002 5"

## Rubic Points
### Here I will consider the [rubic points](https://review.udacity.com/#!/rubrics/824/view) individually and describe how I addressed each point in my implementation.

---

### Compilation

#### 1. Code must compile without errors with cmake and make.

My code could be compiled without errors.

To enable debugging, I appended the following line to CMakeLists.txt:

```cmake
set(CMAKE_BUILD_TYPE Debug)
```

### Implementation

#### 2. The PID procedure follows what was taught in the lessons.

The steering value was calculated by the following fomula:

```cpp
steer_value = -pid.Kp * cte - pid.Kd * pid.diff_cte - pid.Ki * pid.int_cte;
if (steer_value > 1) {
  steer_value = 1;
} else if (steer_value < -1) {
  steer_value = -1;
}
```

The value of `pid.int_cte` was taken as the sum of CTE values for the past 100 iterations.

### Reflection

#### 3. Describe the effect each of the P,I,D components had in your implementation.

**P-value**

P-value has the effect of minimizing cross track error. The following graph shows the values of CTE, steering value and total error when P-value is 0.05. The value of total error was chosen as the average of the sum of squares of CTE values.

![alt text][image1]

**D-value**

D-value has the effect of anticipating future behavior of errors. This reduced the CTE and was able to lap the track. The following graph is for P-value 0.05 and D-value 5.

![alt text][image2]

**I-value**

I-value has the effect of eliminating steady state error. The following graph is for P-value 0.05, D-value 5 and I-value 0.002. Compared with the previous graph, we can see that the CTE value and the total error are decreasing.

![alt text][image3]

#### 4. Describe how the final hyperparameters were chosen.

I tried various PID values manually and finally I decided that it is appropriate when P-value is 0.1, I-value is 0.002 and D-value is 5. Increasing the P-value will reduce the total error, but it will become serpentine because of increasing the steering value.

**P=0.05 I=0.002 D=2**

![alt text][image4]

**P=0.05, I=0.002, D=8**

![alt text][image5]

**P=0.1, I=0.002, D=5**

![alt text][image6]

**P=0.2, I=0.002, D=5**

![alt text][image7]


### Simulation

#### 5. The vehicle must successfully drive a lap around the track.

The car did not pop up onto ledges or roll over any surfaces.

