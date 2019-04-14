/*
 * Team id : eYRC #902
 * Author List : Karthik Raj SS, jaffar aleem , Likith S , Gagan L naik
 * Filename :arm_code
 * Theme : Antbot
 * Functions : setup() , loop()
 * global variables : None
 * 
 */
 
#include<Servo.h>
Servo servo1;
Servo servo2;

/*
 * Function name : setup
 * input : none
 * output : none
 * logic : each servo is being connected to two different digital pins
 * example call: setup()
 */

void setup()
{
  // put your setup code here, to run once:
  
servo1.attach(9); // servo1 is attached to digital pin 9
servo2.attach(10); // servo1 is attached to digital pin 10

}

/*
 * Function name : loop 
 * input : arm_down(), gripper_hold() , arm_up() , gripper_release() are the function calls in the void loop
 * output : none
 * logic : the arm has to move down from an upward default position and and then has to pick up the block by closing the gripper , and the arm moves upward again and after a delay of 3 seconds the arm again moves down to place the block picked up earlier att the same position 
 * example call: loop() but its iterative by inbuilt
 */

void loop()
{
  // put your main code here, to run repeatedly:
  arm_down(); // arm movement from up to down
  gripper_hold(); // gripper movement to hold the block
  arm_up(); // arm movement down to up after grasping the block
  
  delay(3000); // holds the block for 3 seconds in air

  arm_down(); // arm movement from up to down
  gripper_release(); // gripper movement to release the block held 
  arm_up();  // arm movement down to up after grasping the block
  
  
}

/*
 * Function name : arm_down()
 * input : none
 * output: value of j is given to servo motor
 * logic : value of j is incrementes by steps of 1 in for loop and given as angle for rotation to the servo motor up in order to facilitate up and down motion
 * example call: arm_down()
 */
void arm_down()
{
   for(int j=0;j<70;j++) // j varies from 0 to 70 and incremented by 1 in every iteration
{
  servo2.write(j); //angle is given to servo motor
  delay(30);
}
}

/*
 * Function name : gripper_hold()
 * input : none
 * output: value of i given to servo motor
 * logic : value of i is incremented by 1 within for loop and given to servo motor for rotation in order to facilitate closing motion of gripper
 * example call: gripper_hold()
 */
void gripper_hold()
{
  for(int i=50;i<130;i++) // i varies from 50 to 130 and incremented by 1 in every iteration
{
  servo1.write(i);  //angle is given to servo motor
  delay(30); //
}
}

/*
 * Function name : arm_up()
 * input : none
 * output: value of j is given to servo motor
 * logic : value of j is incrementes by steps of 1 in for loop and given as angle for rotation to the servo motor up in order to facilitate up and down motion
 * example call: arm_up()
 */
void arm_up()
{
  for(int j=70;j>0;j--) // j varies from 70 to 0 and incremented by 1 in every iteration
{
  servo2.write(j);  //angle is given to servo motor
  delay(30);
}
}

/*
 * Function name : gripper_release()
 * input : none
 * output: value of i is given to servo motor
 * logic : value of i is incrementes by steps of 1 and given as angle for rotation to the servo motor up in order to facilitate releasing motion of the gripper
 * example call: gripper_release()
 */
void gripper_release()
{
  for(int i=130;i>50;i--) // i varies from 130 to 50 and incremented by 1 in every iteration
{
  servo1.write(i);  //angle is given to servo motor
  delay(30);
}
  
}


