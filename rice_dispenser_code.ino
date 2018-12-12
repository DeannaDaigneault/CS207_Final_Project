//credit to That1guy99 on Arduino forums for making the original code in reply to brookish with the same problem
//The reply was posted September 28, 2012, 04:21am. 
//Here is the link to the forum post/thread (it is called a thread right?)
// https://forum.arduino.cc/index.php?topic=124707.0
//also credit to Alex aka the lab instructor himself for the labs. I took some code from one of the motor labs.

int switchPin = 2;  // switch is connected to pin 2
int dispensePin = 3; //dispense button is connected to pin 3
    int led1Pin = 10; 
    int led2pin = 11;
    int led3pin = 12;
    int led4pin = 13;
   const int motor = 9;

    int val;                        // variable for reading the pin status
    int val2;                       // variable for reading the delayed status
    int val3;                       // variable for reading the dispense button press
    int buttonState;                // variable to hold the button state
    int buttonDispense;
    int Mode = 0;              // What mode are the lights in?
    void motorPortions();

    void setup() {
      //ADD MOTOR TIME AND STOP LIKE IF MODE IS 2 THEN MOTOR SPINS 200 MILISECONDS
      pinMode(switchPin, INPUT);    // Set the switch pin as input
      pinMode(dispensePin, INPUT);    // Set the dispense pin as input too
      pinMode(led1Pin, OUTPUT);
      pinMode(led2pin, OUTPUT);
      pinMode(led3pin, OUTPUT);
      pinMode(led4pin, OUTPUT);
      pinMode(motor, OUTPUT);
      buttonState = digitalRead(switchPin);   // read the initial state
      buttonDispense = digitalRead(dispensePin);  // read this too
     
    }

    void loop(){
      val3 = digitalRead(dispensePin);  //read so it knows it has another input. This button will reset the LEDs and later move the motor depending on the Mode
      motorPortions();
      val = digitalRead(switchPin);      // read input value and store it in val
      delay(10);                         // 10 milliseconds is a good amount of time
      val2 = digitalRead(switchPin);     // read the input again to check for bounces
      if (val == val2) {                 // make sure we got 2 consistant readings!
        if (val != buttonState) {          // the button state has changed!
          if (val == LOW) {                // check if the button is pressed
            if (Mode == 0) {          
              Mode = 1;               
            } else {
                if (Mode == 1) {        
                Mode = 2;     
            } else {
                if (Mode == 2) {      
                Mode = 3;     
            } else {
                if (Mode == 3) { 
                Mode = 4;      
                  }
             else {
                if (Mode == 4) { 
                Mode = 0;          
                  }
            }
           }
          }
         }
        }
        buttonState = val;                 // save the new state in our variable
      }

          if (val3 == LOW) {                // check if the button is pressed
            if (Mode == 0) {          
              Mode = 0;  
            } else {
                if (Mode == 1) {        
                Mode = 0;        
            } else {
                if (Mode == 2) {      
                Mode = 0;    
            } else {
                if (Mode == 3) { 
                Mode = 0;    
                  }
             else {
                if (Mode == 4) { 
                Mode = 0;     
                
                  }
            }
           }
          }
         }
        }
        buttonDispense = val3;                 // save the new state in our variable
      

      // Now do whatever the lightMode indicates
      if (Mode == 0) { // all-off
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2pin, LOW);
        digitalWrite(led3pin, LOW);
        digitalWrite(led4pin, LOW);  
      }

      if (Mode == 1) { 
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2pin, LOW);
        digitalWrite(led3pin, LOW);
        digitalWrite(led4pin, LOW);  
      }

      if (Mode == 2) { 
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2pin, HIGH);
        digitalWrite(led3pin, LOW);
        digitalWrite(led4pin, LOW);        
      }
      if (Mode == 3)  { 
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2pin, HIGH);
        digitalWrite(led3pin, HIGH);
        digitalWrite(led4pin, LOW);
      }
      if (Mode == 4)  { 
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2pin, HIGH);
        digitalWrite(led3pin, HIGH);
        digitalWrite(led4pin, HIGH);
      }
      }  
      }
      void motorPortions()
{
 // const int onTime = 1000; the number of milliseconds for the motor to turn on for
 // const int offTime = 1000; the number of milliseconds for the motor to turn off for
digitalRead(Mode);
if (Mode == 1 && val3 == LOW){
  digitalWrite(motor, HIGH); // turns the motor On
  delay(700); // waits for onTime milliseconds
  digitalWrite(motor, LOW); // turns the motor Off
  delay(1000); // waits for offTime milliseconds
}
  if (Mode == 2 && val3 == LOW){
  digitalWrite(motor, HIGH); // turns the motor On
  delay(1200); // waits for onTime milliseconds
  digitalWrite(motor, LOW); // turns the motor Off
  delay(1000); // waits for offTime milliseconds
  }
  if (Mode == 3 && val3 == LOW){
  digitalWrite(motor, HIGH); // turns the motor On
  delay(1600); // waits for onTime milliseconds
  digitalWrite(motor, LOW); // turns the motor Off
  delay(1000); // waits for offTime milliseconds
}

  if (Mode == 4 && val3 == LOW){
  digitalWrite(motor, HIGH); // turns the motor On
  delay(1800); // waits for onTime milliseconds
  digitalWrite(motor, LOW); // turns the motor Off
  delay(1000); // waits for offTime milliseconds
  }
}
