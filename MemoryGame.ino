#include <LinkedList.h> //download library LinkedList by Ivan Seidel

LinkedList<uint8_t> game_pattern = LinkedList<uint8_t>(); //Making a list game_pattern that holds numbers. It will be useful when the game makes a pattern for the user to follow
uint8_t choose_led; //Helps the game figure out what LED to add to the pattern
uint8_t button_pressed; //Stores what button did the user press
boolean GAME = true; //Pretty useless, if you want the game to end you can make this variable false in the code below, but I didn't

//Defining all the pin variables

const int LEDa = 2;
const int LEDb = 3;
const int LEDc = 4;
const int BUTTONc = 6;
const int BUTTONb = 7;
const int BUTTONa = 8;
const int LEDred = 10;
const int LEDgreen = 11;
const int Buzzer = 13;

//Function for the game to make AND show the pattern
void pattern(){
  choose_led = random(1,4); //Chooses a random number from 1-4 and stores it in choose_led
  game_pattern.add(choose_led); //Adds choose_led to the game_pattern list
  for (uint8_t i = 0; i < game_pattern.size(); i = i+1){ //The for loop will run once for every number in the game_pattern list. Everytime the loop runs the variable i corresponds to the next item in the list
    if (game_pattern.get(i) == 1){ //If the number i in the list is 1, light up the first LED for 500ms. It will also turn on a buzzer for 500ms
      digitalWrite(LEDa, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(500);
      digitalWrite(LEDa, LOW);
      digitalWrite(Buzzer, LOW);
    }
    else if (game_pattern.get(i) == 2){//Exact same but for 2 instead, and lights up the second LED
      digitalWrite(LEDb, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(500);
      digitalWrite(LEDb, LOW);
      digitalWrite(Buzzer, LOW);
    }
    else if (game_pattern.get(i) == 3){//Exact same but for 3 instead, and lights up the third LED
      digitalWrite(LEDc, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(500);
      digitalWrite(LEDc, LOW);
      digitalWrite(Buzzer, LOW);
    }
    delay(100);//Buffer
  }
}

//Function for detecting and checking button presses from user
int answer(){
  for (uint8_t u = 0; u< game_pattern.size(); u = u+1){ // Same loop as before but instead uses variable u
    while (digitalRead(BUTTONc) == HIGH && digitalRead(BUTTONb)==HIGH && digitalRead(BUTTONa)==HIGH){ //While no button is pressed, do nothing and wait. This is to wait until the user presses something and then moving on
    }
    if (digitalRead(BUTTONc) == LOW){ //If the button pressed is c, then turn variable Button_pressed to 3 and turn the 3rd LED on
      button_pressed = 3;
      digitalWrite(LEDc, HIGH);
      delay(50); //Buffer
    }
    else if (digitalRead(BUTTONb) == LOW){ //for buttonb, turns the var to 2 and for LED 2
      button_pressed = 2;
      digitalWrite(LEDb, HIGH);
      delay(50); //Buffer
    }
    else if (digitalRead(BUTTONa) == LOW){ //for buttona, turns the var to 1 and for 1st LED
      button_pressed = 1;
      digitalWrite(LEDa, HIGH);
      delay(50); //Buffer
    }
    digitalWrite(LEDa, LOW); //Turn of all LEDs
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDc, LOW);
    if (button_pressed == game_pattern.get(u)){ //If the button pressed is the same as the "u"th item in the list, turn on the buzzer until released
      while (digitalRead(BUTTONc) == LOW || digitalRead(BUTTONb)==LOW || digitalRead(BUTTONa)==LOW){
        digitalWrite(Buzzer, HIGH);
      }
      digitalWrite(Buzzer, LOW);
      delay(50);//buffer
    }
    else{ //if the user is wrong
      while (digitalRead(BUTTONc) == LOW || digitalRead(BUTTONb)==LOW || digitalRead(BUTTONa)==LOW){ //Turn all LEDs andd buzzers on until released
        digitalWrite(LEDa, HIGH);
        digitalWrite(LEDb, HIGH);
        digitalWrite(LEDc, HIGH);
        digitalWrite(Buzzer, HIGH);
      }
      digitalWrite(LEDa, LOW);
      digitalWrite(LEDb, LOW);
      digitalWrite(LEDc, LOW);
      digitalWrite(Buzzer, LOW);
      return(0); //Return 0 which is a loss
    }
  }
  return(1); //The user has finished the for loop, which means he moves on to the next level
}

void setup() {
  randomSeed(analogRead(A0)); //IMPORTANT: To make sure the numbers generated are actually random, Make sure nothing is in the analog pin, if there is change this variable to any other Analog pin. If you don't include this the pattern will stay the same even after you reset the board.

  //Declaring pins
  pinMode(LEDa, OUTPUT); 
  pinMode(LEDb, OUTPUT);
  pinMode(LEDc, OUTPUT);
  pinMode(BUTTONc, INPUT_PULLUP);
  pinMode(BUTTONb, INPUT_PULLUP);
  pinMode(BUTTONa, INPUT_PULLUP);
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  //Making a sick mini animation, you don't actually need it
  for (uint8_t w = 0; w<5; w += 1){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDc, LOW);
    delay(75);
    digitalWrite(Buzzer, LOW);
    digitalWrite(LEDa, LOW);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, LOW);
    delay(75);
    digitalWrite(LEDa, LOW);
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDc, HIGH);
    delay(75);
    digitalWrite(LEDc, LOW);
    digitalWrite(Buzzer, HIGH);
  }

}

void loop() {
  if (GAME){ //While game is true, Useful if you want game to stop permanently after you losw, but I didn't use it
    delay(200);//wait 200ms for user to actually breathe
    pattern(); // Do the pattern function
    if (answer() != 1){ // do the answer function, and if it does not return 1 i.e it returns 0
      delay(200);//buffer
      for (uint8_t t = 0; t < game_pattern.size(); t = t+1){//Turn the red light and buzzer on and off for every item in game_pattern list
        digitalWrite(Buzzer, HIGH);
        digitalWrite(LEDred, HIGH);
        delay(500);
        digitalWrite(Buzzer, LOW);
        digitalWrite(LEDred, LOW);
        delay(500);
      }
      game_pattern.clear();//clear the list, and therefore restarts the game
    }//If they did get it right, turn the green led on and then off and keep on running the cycle
    digitalWrite(LEDgreen, HIGH);
    delay(200);
    digitalWrite(LEDgreen, LOW);
  }
}
