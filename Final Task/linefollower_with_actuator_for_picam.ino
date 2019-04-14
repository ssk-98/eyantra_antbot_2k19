/*
 * Team id : eYRC #902
 * Author List: Karthik Raj SS ,Jaffar Aleem,Likith S,Gagan L Naik
 * Filename : linefollower_with_actuator_for_picam
 * Theme : Ant Bot
 * Functions : get_sensor_left_data()
               get_sensor_right_data()
               get_sensor_center_data()
               move_straight(int spd)
               move_left(int spd)
               move_right(int spd)
               move_stop()
 *global variables :posleft_sensor_data,right_sensor_data,center_sensor_data,spd,spdstr
*/


//PWM Pins Defination
#define MOT1_EN 6
#define MOT2_EN 7

//Digital Pins for Motors
#define MOT1_IN1 2
#define MOT1_IN2 3

#define MOT2_IN1 4
#define MOT2_IN2 5

//Analog Pins for Sensors
#define SENSOR1 A0
#define SENSOR3 A2
#define SENSOR5 A4



void setup(){
  pinMode(MOT1_EN,OUTPUT);
  pinMode(MOT2_EN,OUTPUT);
  pinMode(MOT1_IN1,OUTPUT);
  pinMode(MOT1_IN2,OUTPUT);
  pinMode(MOT2_IN1,OUTPUT);
  pinMode(MOT2_IN2,OUTPUT);
  pinMode(SENSOR1,INPUT);                /*defining input and
                                             output pins*/
                               
  pinMode(SENSOR3,INPUT);
  pinMode(SENSOR5,INPUT);
  digitalWrite(MOT1_EN,HIGH);
  digitalWrite(MOT2_EN,HIGH);
  Serial.begin(9600);

}

void loop()
  
  {
  


  
  
  left_sensor_data = get_sensor_left_data();
  right_sensor_data = get_sensor_right_data();
  center_sensor_data = get_sensor_center_data();


  if(left_sensor_data > 110 && right_sensor_data < 110 && center_sensor_data <110){
    spd = map(left_sensor_data,0,3000,0,255);  //mapping speed according to sensor reading
    move_left(spd);
    
  }

  //condition for soft right
  else{
    if(right_sensor_data > 110 && left_sensor_data < 110 && center_sensor_data <110){
      
      spd = map(right_sensor_data,0,3000,0,255); //mapping speed according to sensor reading
      move_right(spd);

  //condition for stop
      
    }
    else{
      if(right_sensor_data > 110 && left_sensor_data >110 && center_sensor_data > 110 ){
        move_stop();
        if(count == 0)
        {
          while(i<10){
          move_forward(strspd);
          i++
          }
        }
        
        
      }

   //comdition for forward
      else
        move_straight(spdstr);
        
    }
  }
  delay(50);
  //Serial.println(sensor_data);
  //delay(1000);
  /*move_straight(255);
  delay(2000);
  move_straight(0);
  delay(1000);
  move_left(255); 
  delay(1000);
  move_straight(255);
  delay(2000);*/

   //Serial.println(left_sensor_data);
  //Serial.println(right_sensor_data);
  //Serial.println(center_sensor_data);
}
/*
 *Function Name : get_sensor_right_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from right analog sensor 
 *Example Call  : get_sensor_right_data()
 */



int get_sensor_right_data(){
  int data = 0;
  data += analogRead(SENSOR5);
  return data;
  
}

/*
 *Function Name : get_sensor_left_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from left analog sensor 
 *Example Call  : get_sensor_right_data()
 */


int get_sensor_left_data(){
  int data = 0;
  data += analogRead(SENSOR1);
  return data;
}

/*
 *Function Name : get_sensor_center_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from center analog sensor 
 *Example Call  : get_sensor_right_data()
 */


int get_sensor_center_data(){
  int data = 0;
  data += analogRead(SENSOR3);
  return data;

}

/*
 *Function Name : move_straight()
 *Input         : spd
 *Output        : spdstr
 *Logic         : making IN1 & IN3 of motor driver high for forward movement
 *Example Call  : move_straight()
 */
 
void move_straight(int spd){
  analogWrite(MOT1_IN1,spdstr);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,spdstr);
  analogWrite(MOT2_IN2,0);
  
}

/*
 *Function Name : move_left()
 *Input         : spd
 *Output        : spd
 *Logic         : making IN4 of motor driver high for slow left
 *Example Call  : move_left()
 */

void move_left(int spd){
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  analogWrite(MOT2_IN2,spd);
}


/*
 *Function Name : move_right()
 *Input         : spd
 *Output        : spd
 *Logic         : making IN2 of motor driver high for slow right
 *Example Call  : move_right()
 */

void move_right(int spd){
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,spd);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
}


/*
 *Function Name : move_stop()
 *Input         : none
 *Output        : none
 *Logic         : making all pins of motor driver low for stop
 *Example Call  : move_straight()
 */

void move_stop(){  
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
}


void picam_rotation(){
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    delay(100);// tell servo to go to position in variable 'pos'
                 
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    delay(100);// tell servo to go to position in variable 'pos'
                           
  }
}

