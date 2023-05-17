    /*
 PROJECT: Ardroid
 CODED BY: Anurag Goel
 PUBLIC Licence Free To Modify
*/

#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
#define CMD_DIGITALWRITE 10
#define CMD_ANALOGWRITE 11
#define CMD_TEXT 12
#define CMD_READ_ARDROID 13
#define MAX_COMMAND 20  
#define MIN_COMMAND 10  
#define IN_STRING_LENGHT 40
#define MAX_ANALOGWRITE 255
#define PIN_HIGH 3
#define PIN_LOW 2

String inText;

void setup() {
  Serial.begin(38400);
  Serial.println("Ardroid By : Anurag Goel");
  Serial.flush();
}

void loop()
{
  Serial.flush();
  int ard_command = 0;
  int pin_num = 0;
  int pin_value = 0;

  char get_char = ' ';  //read serial

  // wait for incoming data
  if (Serial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag 
  get_char = Serial.read();
  if (get_char != START_CMD_CHAR) return; // if no command start flag, return to loop().

  // parse incoming command type
  ard_command = Serial.parseInt(); // read the command
  // parse incoming pin# and value  
  pin_num = Serial.parseInt(); // read the pin
  pin_value = Serial.parseInt();  // read the value
  // 1) GET TEXT COMMAND FROM ARDROID
  if (ard_command == CMD_TEXT){   
    if(pin_num == 1){
      inText =""; //clears variable for new input   
      while (Serial.available())  {
      char c = Serial.read();
    
       //gets one byte from serial buffer
        delay(5);
        if (c == END_CMD_CHAR) { // if we the complete string has been read
          // add your code here
          Serial.println(inText);
          break;
        }              
        else {
          if (c !=  DIV_CMD_CHAR) {
            inText += c; 
            delay(5);
          }
        }
      }
    }
    if(pin_num == 2){
      char send_to_android[] = "Hello" ;
      Serial.println(send_to_android);   // Example: Sending text
      Serial.print(" Analog 0 = "); 
      Serial.println(analogRead(A0));  // Example: Read and send Analog pin value to Arduino
      return; 
    }
  }

  // 2) GET digitalWrite DATA FROM ARDROID
  if (ard_command == CMD_DIGITALWRITE){  
    if (pin_value == PIN_LOW) pin_value = LOW;
    else if (pin_value == PIN_HIGH) pin_value = HIGH;
    else return; // error in pin value. return.
    set_digitalwrite( pin_num,  pin_value);  
    return;  // return from start of loop()
  }

  // 3) GET analogWrite DATA FROM ARDROID
  if (ard_command == CMD_ANALOGWRITE) {  
    analogWrite(  pin_num, pin_value ); 
    // add your code here
    return;  // Done. return to loop();
  }
}

// 2a) select the requested pin# for DigitalWrite action
void set_digitalwrite(int pin_num, int pin_value)
{
  switch (pin_num) {
  case 13:
    pinMode(13, OUTPUT);
    digitalWrite(13, pin_value);  
    // add your code here      
    break;
  case 12:
    pinMode(12, OUTPUT);
    digitalWrite(12, pin_value);   
    // add your code here       
    break;
  case 11:
    pinMode(11, OUTPUT);
    digitalWrite(11, pin_value);         
    // add your code here 
    break;
  case 10:
    pinMode(10, OUTPUT);
    digitalWrite(10, pin_value);         
    // add your code here 
    break;
  case 9:
    pinMode(9, OUTPUT);
    digitalWrite(9, pin_value);         
    // add your code here 
    break;
  case 8:
    pinMode(8, OUTPUT);
    digitalWrite(8, pin_value);         
    // add your code here 
    break;
  case 7:
    pinMode(7, OUTPUT);
    digitalWrite(7, pin_value);         
    // add your code here 
    break;
  case 6:
    pinMode(6, OUTPUT);
    digitalWrite(6, pin_value);         
    // add your code here 
    break;
  case 5:
    pinMode(5, OUTPUT);
    digitalWrite(5, pin_value); 
    // add your code here       
    break;
  case 4:
    pinMode(4, OUTPUT);
    digitalWrite(4, pin_value);         
    // add your code here 
    break;
  case 3:
    pinMode(3, OUTPUT);
    digitalWrite(3, pin_value);         
    // add your code here 
    break;
  case 2:
    pinMode(2, OUTPUT);
    digitalWrite(2, pin_value); 
    // add your code here       
    break;      
  
  } 
}
