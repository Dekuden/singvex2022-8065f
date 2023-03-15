#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h" 

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DigitalOutB          digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;



// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.

#pragma endregion VEXcode Generated Robot Configuration

// ----------------------------------------------------------------------------
//                                                                            
//    Project:                                               
//    Author:
//    Created:
//    Configuration:        
//                                                                            
// ----------------------------------------------------------------------------

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

motor leftfront = motor(PORT14,gearSetting::ratio18_1,true);
motor leftback = motor(PORT15,gearSetting::ratio18_1,false);
motor rightfront = motor(PORT4,gearSetting::ratio18_1,false);
motor rightback = motor(PORT5,gearSetting::ratio18_1,true);

motor cata = motor(PORT1,gearSetting::ratio18_1,false);
motor cata2 = motor(PORT11,gearSetting::ratio18_1,true);
motor botfly = motor(PORT9,gearSetting::ratio18_1,false);
motor intake1 = motor(PORT13,gearSetting::ratio18_1, false);
motor intake2 =  motor(PORT10,gearSetting::ratio18_1, true);

motor flap = motor(PORT9,gearSetting::ratio18_1,true);

controller HController = controller(primary);
controller VController = controller(partner);
int maxspeed = 100;
int slwspeed =  .5 * maxspeed;




const float pi = M_PI;
// Include the V5 Library
#include "vex.h"
float dia = 4.85;

const float degToticks = 0.2235;
// Allows for easier use of the VEX Library

void driver(){




leftfront.spin(vex::directionType::fwd,HController.Axis3.value(),vex::velocityUnits::pct);
rightfront.spin(vex::directionType::fwd,HController.Axis2.value(),vex::velocityUnits::pct);


}
using namespace vex;


void mvbase(int speed){

   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);


}


void baseleft(int speed){


    
    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);



}

void baseright(int speed){


    
    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);



}

void holoright(int speed){


    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);


}

void hololeft(int speed){


    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);


}

void intake(int speed){

  intake1.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
  intake2.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
}



void mvdfwed(int time, int speed){

   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);

   vex::task::sleep(time);
   leftfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);


}












void encfwd(float dist, int speed){


  float val = 0;
  float RV;
  float LV;
  leftfront.resetRotation();
  rightfront.resetRotation();


  while(val<dist){

    mvbase(speed);
    

    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV+LV)/2; 


  }

mvbase(speed*.1);
task::sleep(100);
mvbase(0);

}



void intkfwd(int duration, int speed, int intspd){

mvbase(speed);
intake(intspd);
vex::task::sleep(duration);
mvbase(0);
intake(0);


}







void advfwd(float dist, int speed,int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();
if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val< dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(speed);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    mvbase(slwspeed);
     

    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(-slwspeed);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}



void advfwdWintake(int dist, int speed,int slwspeed,int intkspd){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val< dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(speed);
       intake(intkspd);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    mvbase(slwspeed);
    intake(intkspd);
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(-slwspeed);
      intake(intkspd);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}

void backandintake(int dist, int speed, int spdofintake)
{
  float val = 0;
  float RV;
  float LV;
  leftfront.resetRotation();
  rightfront.resetRotation();
  while (val > dist)
  {   
    mvbase(speed);
    intake(spdofintake);
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
  }
}


void rightsidemv(int dist, int speed){
   int x  = dist/10;
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   vex::task::sleep(x*8);
   rightfront.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   vex::task::sleep(x*2);
   rightfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);





}


void leftsidemv(int dist, int speed){
   int x  = dist/10;
   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   vex::task::sleep(x*8);
   leftfront.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   vex::task::sleep(x*2);
   leftfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
}


void advrev(int dist, int speed,int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();

if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val< dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(-speed);

  
      RV = -rightfront.rotation(rev)*pi*dia;
      LV = -leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    mvbase(-slwspeed);
     

    
    RV = -rightfront.rotation(rev)*pi*dia;
    LV = -leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(slwspeed);
     
 
    
    RV = -rightfront.rotation(rev)*pi*dia;
    LV = -leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}




 void encturnright (int dist, float speed){


  float val = 0;
  float LV;
  float RV;
  
  leftfront.resetRotation();
  rightfront.resetRotation();

     
  while(val<dist){

    

    
    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    wait(10,msec);

    
    RV = rightfront.rotation(deg);
    LV = leftfront.rotation(deg);


    


    val = -(RV - LV)*degToticks;
    Brain.Screen.print(val);

    

  }

  
 leftfront.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);  
 rightfront.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);
 leftback.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);  
 rightback.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);
 task::sleep(50);
 mvbase(0);



}

 void encturnleft (int dist, float speed){


  float val = 0;
  float LV;
  float RV;
  
  leftfront.resetRotation();
  rightfront.resetRotation();

     
  while(val<dist){

    

    
    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    wait(10,msec);

    
    RV = rightfront.rotation(deg);
    LV = leftfront.rotation(deg);


    


    val = (RV - LV)*degToticks;
    Brain.Screen.print(val);

    

  }

  
 leftfront.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);  
 rightfront.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);
 leftback.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);  
 rightback.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);
 task::sleep(60);
 mvbase(0);



}
 
void advturnleft(float degr, int speed, int swlspd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseleft(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseleft(slwspeed);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseleft(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}

void reset(int duration, int speed){


mvbase(speed);
vex::task::sleep(duration);
mvbase(0);





}


void advturnleftWintake(float degr, int speed, int swlspd,int intkspd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseleft(speed);
       intake(intkspd);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseleft(slwspeed);
    intake(intkspd);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseleft(-slwspeed);
      intake(intkspd);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}


void intakefwd(int duration, int basespeed, int intkspd){

 intake(intkspd);
 mvbase(basespeed);
 vex::task::sleep(duration);
 intake(0);
 mvbase(basespeed/10);
 vex::task::sleep(duration/10);
 mvbase(0);
}

void advturnright(float degr, int speed, int swlspd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();

 
if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseright(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseright(slwspeed);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseright(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}

void shoot(int intime, float flyspeed){

      //topfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
      botfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
vex::task::sleep(intime);
      //topfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
      botfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
DigitalOutB.set(false);
vex::task::sleep(400);
DigitalOutB.set(true);






}
void flywheel(float flyspeed){
      //topfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
      botfly.spin(directionType::fwd, flyspeed, voltageUnits::volt);
}


void advturnrightWintake(float degr, int speed, int swlspd, int intakespd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseright(speed);
       intake(intakespd);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseright(slwspeed);
    intake(intakespd);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);
      


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseright(-slwspeed);
      intake(intakespd);
      

     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}
void timerleft(int duration, int speed){

int x = duration/100;
baseleft(speed);
vex::task::sleep(x*90);
baseleft(speed/10);
vex::task::sleep(x*10);
baseleft(0);


}

void advhololeft(float dist, int speed,int slwspd){



float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/10;

}

while (run == 1){
  Brain.Screen.clearScreen();



 if(val< dist - slwdist  ){
    Brain.Screen.clearScreen();
    hololeft(speed);

  
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = RV;
    HController.Screen.print(val);
     
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    hololeft(slwspeed);
     

    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = RV; 
    HController.Screen.print(val);

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      hololeft(-slwspeed);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = RV; 
    HController.Screen.print(val);

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");





}



void basicholo(int dist, int speed){


float val = 0;
rightfront.resetRotation();
HController.Screen.clearScreen();

while(val < dist){





val = rightfront.rotation(rev);
hololeft(speed);
HController.Screen.print(val);



}

hololeft(0);
}


void advholoright(float dist, int speed,int slwspd){



float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();

if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/10;

}

while (run == 1){
  Brain.Screen.clearScreen();



 if(val< dist - slwdist  ){
    Brain.Screen.clearScreen();
    holoright(speed);

  
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = -RV;
    HController.Screen.print(val);
     
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    holoright(slwspeed);
     

    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = -RV; 
    HController.Screen.print(val);

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      holoright(-slwspeed);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftback.rotation(rev)*pi*dia;
    val = -RV; 
    HController.Screen.print(val);

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");





}


void BlueMk1(){

}


void bluemk2(){
  advfwd(12,70,10);
  vex::task::sleep(210);
  advfwdWintake(16,12,5,100);
  intake(100);
  vex::task::sleep(300);
  // intakefwd(280, 50, 100);
  intakefwd(1000, -70, 100);
  vex::task::sleep(300);
  advfwdWintake(12,30,5,100);
  vex::task::sleep(210);
  advturnleft(135, 40, 30);
  vex::task::sleep(210);
  advfwdWintake(25,30,5,100);
  vex::task::sleep(210);
  rightsidemv(1000, 40);
  vex::task::sleep(210);
  mvbase(50);
  intake(100);
  vex::task::sleep(2000);
  mvbase(0);
  intake(0);
}


void redmk1(){
  advfwd(12,70,10);
  vex::task::sleep(210);
  advfwdWintake(16,12,5,100);
  intake(100);
  vex::task::sleep(300);
  // intakefwd(280, 50, 100);
  intakefwd(1000, -70, 100);
  vex::task::sleep(300);
  advfwdWintake(12,30,5,100);
  vex::task::sleep(210);
  advturnright(135, 40, 30);
  vex::task::sleep(210);
  advfwdWintake(28,30,5,100);
  vex::task::sleep(210);
  leftsidemv(1000, 40);
  vex::task::sleep(210);
  mvbase(50);
  intake(100);
  vex::task::sleep(2000);
  mvbase(0);
  intake(0);
}


void redmk2(){
  advfwd(12,70,10);
  vex::task::sleep(210);
  advfwdWintake(16,12,5,100);
  intake(100);
  vex::task::sleep(300);
  // intakefwd(280, 50, 100);
  intakefwd(1000, -70, 100);
  vex::task::sleep(300);
  advfwdWintake(12,30,5,100);
  vex::task::sleep(210);
  advturnleft(135, 40, 30);
  vex::task::sleep(210);
  advfwdWintake(25,30,5,100);
  vex::task::sleep(210);
  rightsidemv(1000, 40);
  vex::task::sleep(210);
  mvbase(50);
  intake(100);
  vex::task::sleep(2000);
  mvbase(0);
  intake(0);
}

// Begin project code

void preAutonomous(void) {
  // actions to do when the program starts
  Brain.Screen.clearScreen();
  Brain.Screen.print("pre auton code");
  DigitalOutB.set(true);
  wait(1, seconds);
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("autonomous code");
  // place automonous code here
  DigitalOutB.set(true);
  redmk1();
  }

void userControl(void) {
  Brain.Screen.clearScreen();
  // place driver control in this while loop
  while (true) {

    if (HController.ButtonL2.pressing())
    {     
      cata.spin(directionType::rev, 15, voltageUnits::volt);
      cata2.spin(directionType::rev, 15, voltageUnits::volt);
    }
    else
    {    
      cata.spin(directionType::rev, 0, voltageUnits::volt);
      cata2.spin(directionType::rev, 0, voltageUnits::volt);      
    }
    
    if(VController.ButtonA.pressing()==1)
    {
      DigitalOutB.set(false);
    }

    else
    {
      DigitalOutB.set(true);
    }
rightfront.spin(vex::directionType::fwd, HController.Axis2.value(),vex::velocityUnits::pct);
leftfront.spin(vex::directionType::fwd, HController.Axis3.value(),vex::velocityUnits::pct);
rightback.spin(vex::directionType::fwd, HController.Axis2.value(),vex::velocityUnits::pct);
leftback.spin(vex::directionType::fwd, HController.Axis3.value(),vex::velocityUnits::pct);
  intake1.spin(vex::directionType::fwd, VController.Axis2.value(),vex::velocityUnits::pct);
  intake2.spin(vex::directionType::fwd, VController.Axis2.value(),vex::velocityUnits::pct);

  }

 


    vex::task::sleep(20);
  }


int main() {
  // create competition instance
  competition Competition;

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(userControl);

  // Run the pre-autonomous function.
  preAutonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
 
    wait(1,msec);
  }
}