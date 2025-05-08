#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();
#define numButtons  7   // Number of buttons
#define Mode_button  9 //mode button 
#define buttons_delay 150

const int buttonPins[numButtons] = {2, 3, 4, 5, 6, 7, 8};  // rec,stop,tr1,tr2,tr3,tr4,undo
bool buttonState[numButtons];  // Track button state

const int Mode_Rgb [3] = {10, 11, 12}; //RED, GREEN, BLUE

bool isStopFunctionActive = false;




//const int Tracks_Rgb[4][2] = {{A0, A1},{A2, A3},{A4, A5},{12, 13}};  // TRACK1, TRACK2, TRACK3, TRACK4 ---------- RED, BLUE




void Record();
void Play();



//void Track_leds_control(int a, int b, int c, int d);


bool isFunction1Running = true;
bool isButtonPressed = false;




void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode(Mode_button, INPUT_PULLUP);
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Set the button pins as input with internal pull-up resistors
  }
  for (int i = 0; i < numButtons; i++) {
    buttonState[i] = HIGH;
  }

  // for (int i = 0; i <  4; i++) {
  //   for (int j = 0; j< 2; j++) {
  //     pinMode(Tracks_Rgb[i][j], OUTPUT);
  //   }
  // }

   for (int i = 0; i < 3; i++) {
      pinMode(Mode_Rgb[i], OUTPUT); 
   }

  //Serial.begin(9600);
  //Track_leds_control(HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW);
}





void loop() {
  // Check if the pushbutton is pressed
  if (digitalRead(Mode_button) == LOW) {
    delay(50);  // Button debounce delay

    // Check if the button is still pressed
    if (digitalRead(Mode_button) == LOW) {
      isButtonPressed = true;
      delay(250);
    }
  }

  // Call the appropriate function based on button state
  if (isButtonPressed) {
    if (isFunction1Running) {
      Play();
      isFunction1Running = false;
    } else {
      Record();
      isFunction1Running = true;
    }
    isButtonPressed = false;
  } else {
    if (isFunction1Running) {
      Record();
    } else {
      Play();
    }
  }
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Record()
{
  //Serial.println("Record");
  digitalWrite(Mode_Rgb[0], HIGH);
  digitalWrite(Mode_Rgb[1], LOW);
  digitalWrite(Mode_Rgb[2], LOW);
  
  for (int i = 0; i < numButtons; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    if (currentState != buttonState[i]) {
      buttonState[i] = currentState;

      if (currentState == LOW) {
        switch (i) {
    case 0:
      //Serial.println("Record selected track (hold global reset) ---PUSHED---");
      MIDI.sendNoteOn(30,  127, 4);
      break;
    case 1:
      //Serial.println("No function (Stop) ---PUSHED---");
      MIDI.sendNoteOn(31,  127, 4);
      break;
    case 2:
      //Serial.println("Track 1 select (Hold reset track) ---PUSHED---");
      MIDI.sendNoteOn(32,  127, 4);
      break;
    case 3:
      //Serial.println("Track 2 select (Hold reset track) ---PUSHED---");
      MIDI.sendNoteOn(33,  127, 4);
      break;
    case 4:
      //Serial.println("Track 3 select (Hold reset track) ---PUSHED---");
      MIDI.sendNoteOn(34,  127, 4);
      break;
    case 5:
      //Serial.println("Track 4 select (Hold reset track) ---PUSHED---");
      MIDI.sendNoteOn(35,  127, 4);
      break;
    case 6:
      //Serial.println("Undo selected track(double tap Redo) ---PUSHED---");
      MIDI.sendNoteOn(36,  127, 4);
      break;
    default:
       break;
     
  } delay(buttons_delay);

      } else {
        switch (i) {
    case 0:
      //Serial.println("Record selected track (hold global reset) ---RELEASED---");
      MIDI.sendNoteOff(30,  127, 4);
      break;
    case 1:
      //Serial.println("No function (Stop) ---Released---");
      MIDI.sendNoteOff(31,  127, 4);
      break;
    case 2:
      //Serial.println("Track 1 select (Hold reset track) ---Released---");
      MIDI.sendNoteOff(32,  127, 4);
      break;
    case 3:
      //Serial.println("Track 2 select (Hold reset track) ---Released---");
      MIDI.sendNoteOff(33,  127, 4);
      break;
    case 4:
      //Serial.println("Track 3 select (Hold reset track) ---Released---");
      MIDI.sendNoteOff(34,  127, 4);
      break;
    case 5:
      //Serial.println("Track 4 select (Hold reset track) ---Released---");
      MIDI.sendNoteOff(35,  127, 4);
      break;
    case 6:
      //Serial.println("Undo selected track(double tap Redo) ---Released---");
      MIDI.sendNoteOff(36,  127, 4);
      break;
    default:
      break;
  }
   delay(buttons_delay);
        
      }
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Play()
{
  //Serial.println("Play");
  digitalWrite(Mode_Rgb[0], LOW);
  digitalWrite(Mode_Rgb[2], HIGH);
  digitalWrite(Mode_Rgb[1], LOW);
  //Track_leds_control(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW);
  for (int i = 0; i < numButtons; i++) {
  bool currentState = digitalRead(buttonPins[i]);

  if (currentState != buttonState[i]) {
    buttonState[i] = currentState;

    if (currentState == LOW) {
      switch (i) {
        case 0:
          //Serial.println("No function (Record) ---PUSHED---");
          MIDI.sendNoteOn(37,  127, 4);
          break;
        case 1:
         // Serial.println("Mute all tracks and go to stop function () ---PUSHED---");
          MIDI.sendNoteOn(38,  127, 4);
          break;
        case 2:
          //Serial.println("Track 1 Mute/Unmute ---PUSHED---");
          MIDI.sendNoteOn(39,  127, 4);
          break;
        case 3:
          //Serial.println("Track 2 Mute/Unmute ---PUSHED---");
          MIDI.sendNoteOn(40,  127, 4);
          break;
        case 4:
          //Serial.println("Track 3 Mute/Unmute ---PUSHED---");
          MIDI.sendNoteOn(41,  127, 4);
          break;
        case 5:
          //Serial.println("Track 4 Mute/Unmute ---PUSHED---");
          MIDI.sendNoteOn(42,  127, 4);
          break;
        case 6:
          //Serial.println("Global reset ---PUSHED---");
          MIDI.sendNoteOn(43,  127, 4);
          break;
        default:
          break;
      }
      delay(buttons_delay);
    } else {
      switch (i) {
        case 0:
          //Serial.println("No function (Record) ---RELEASED---");
          MIDI.sendNoteOff(37,  127, 4);
          break;
        case 1:
          if (isStopFunctionActive) {
            isStopFunctionActive = false;  // Deactivate the stop function
            //Serial.println("Stop function deactivated ---PUSHED---");
          } else {
            isStopFunctionActive = true;  // Activate the stop function
            //Serial.println("Mute all tracks and go to stop function () ---RELEASED---");
            MIDI.sendNoteOff(38,  127, 4);
            Stop();  // Call the Stop function
          }
          break;
        case 2:
          //Serial.println("Track 1 Mute/Unmute ---Released---");
          MIDI.sendNoteOff(39,  127, 4);
          break;
        case 3:
          //Serial.println("Track 2 Mute/Unmute ---Released---");
          MIDI.sendNoteOff(40,  127, 4);
          break;
        case 4:
          //Serial.println("Track 3 Mute/Unmute ---Released---");
          MIDI.sendNoteOff(41,  127, 4);
          break;
        case 5:
          //Serial.println("Track 4 Mute/Unmute ---Released---");
          MIDI.sendNoteOff(42,  127, 4);
          break;
        case 6:
          //Serial.println("Global reset ---Released---");
          MIDI.sendNoteOff(43,  127, 4);
          break;
        default:
          break;
      }
      delay(buttons_delay);
    }
  }
}
}


void Stop() {
  delay(400);
  digitalWrite(Mode_Rgb[0], LOW);
  digitalWrite(Mode_Rgb[2], LOW);
  digitalWrite(Mode_Rgb[1], HIGH);
  while (isStopFunctionActive) {
    // Check if buttonpins[1] is pressed to escape the Stop function
    bool currentState = digitalRead(buttonPins[1]);
    //Serial.println("Stop");
    

  for (int i = 0; i < numButtons; i++) {
  bool currentState = digitalRead(buttonPins[i]);

  if (currentState != buttonState[i]) {
    buttonState[i] = currentState;

    if (currentState == LOW) {
      switch (i) {
        case 0:
          //Serial.println("Play all tracks ---PUSHED---");
          MIDI.sendNoteOn(44,  127, 4);
          break;
        case 1:
          //Serial.println("Play focused lock tracks ---PUSHED---");
          MIDI.sendNoteOn(45,  127, 4);
          break;
        case 2:
          //Serial.println("Track 1 Focus lock ---PUSHED---");
          MIDI.sendNoteOn(46,  127, 4);
          break;
        case 3:
          //Serial.println("Track 2 Focus lock ---PUSHED---");
          MIDI.sendNoteOn(47,  127, 4);
          break;
        case 4:
          //Serial.println("Track 3 Focus lock ---PUSHED---");
          MIDI.sendNoteOn(48,  127, 4);
          break;
        case 5:
          //Serial.println("Track 4 Focus lock ---PUSHED---");
          MIDI.sendNoteOn(49,  127, 4);
          break;
        case 6:
          //Serial.println("No function (Undo) ---PUSHED---");
          MIDI.sendNoteOn(50,  127, 4);
          break;
        default:
          break;
      }
      delay(buttons_delay);
    } else {
      switch (i) {
        case 0:
          //Serial.println("Play all tracks ---RELEASED---");
          MIDI.sendNoteOff(44,  127, 4);
          isStopFunctionActive = false;
          break;
        case 1:
          //Serial.println("Play focused lock tracks ---RELEASED---");
          MIDI.sendNoteOff(45,  127, 4);
          isStopFunctionActive = false;
          break;
        case 2:
          //Serial.println("Track 1 Focus lock ---RELEASED---");
          MIDI.sendNoteOff(46,  127, 4);
          break;
        case 3:
          //Serial.println("Track 2 Focus lock ---RELEASED---");
          MIDI.sendNoteOff(47,  127, 4);
          break;
        case 4:
          //Serial.println("Track 3 Focus lock ---RELEASED---");
          MIDI.sendNoteOff(48,  127, 4);
          break;
        case 5:
          //Serial.println("Track 4 Focus lock ---RELEASED---");
          MIDI.sendNoteOff(49,  127, 4);
          break;
        case 6:
          //Serial.println("No function (Undo) ---RELEASED---");
          MIDI.sendNoteOff(60,  127, 4);
          break;
        default:
          break;
      }
      delay(buttons_delay);
    }
  }
}

    // Add your desired functionality for the Stop function here
}
delay(400);
}



/*
void Track_leds_control(int tr1_red, int tr1_blue, int tr2_red, int tr2_blue,int tr3_red, int tr3_blue, int tr4_red, int tr4_blue)
{
  digitalWrite(Tracks_Rgb[0][0],tr1_red); //track 1, RED
  digitalWrite(Tracks_Rgb[0][1],tr1_blue);
  digitalWrite(Tracks_Rgb[1][0],tr2_red); //track 1, RED
  digitalWrite(Tracks_Rgb[1][1],tr2_blue);
  digitalWrite(Tracks_Rgb[2][0],tr3_red); //track 1, RED
  digitalWrite(Tracks_Rgb[2][1],tr3_blue);
  digitalWrite(Tracks_Rgb[3][0],tr4_red); //track 1, RED  
  digitalWrite(Tracks_Rgb[3][1],tr4_blue);
  
}
*/