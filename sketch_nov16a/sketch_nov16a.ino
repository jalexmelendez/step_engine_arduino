/**
  Proyecto final Sistemas Electromecanicos
  Name: sketch_nov16a.ino
  Purpose: Controls the steps motor to spin clockwise or counter-clockwise, spin at a certain angle
  in any direction and change speed.

  @author Jose Alejandro Melendez Garcia
  @author Daniel Jimenez
  @author Jatsumi Gamez
  @author Evelyn Alvardo
  @author Aylin Porras

  @version 1.0 16/11/22

  How to use this program:

  The values to modify are in the "GLOBAL CONFIGURATON VALUES" section,
  here's an overview of what those values modify:

- loops: Modifies the number of loops the engine does, it
  acepts full values for complete loops or floats to spin
  a fraction of a loop.
 (completes the macro NUMBER_OF_STEPS_PER_REV).

- inverse_spin: Modifies the direction of the spin (R -> L, L -> R)

- spin_delay: Modifies the delay of the spin, the smaller the value, the
  faster the motor will spin, THE MINIMUM VALUE OR FASTER PACE IS 1 (ONE).
*/

#define A 2
#define B 3
#define C 4
#define D 5
#define NUMBER_OF_STEPS_PER_REV 512

//GLOBAL CONFIGURATION VALUES
const float loops = 1.5;
const bool inverse_spin = false;
const float spin_delay = 7.5; // MAX SPEED IS 1

// PROGRAM FLOW VARIABLES, DO NOT MODIFY! //
bool program_was_executed = false;
// PROGRAM FLOW VARIABLES, DO NOT MODIFY! //

void setup() {
  // put your setup code here, to run once:  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (program_was_executed) {
    return;
  }

  spin();

  program_was_executed = true;
}

/**
  Executes the logic on the step engine.

  @param void
  @return void
*/
void spin() {
  int i = 0;
  
  while(i < NUMBER_OF_STEPS_PER_REV * loops) {
    
    if (inverse_spin) {
      onestepback();
    } else {
      onestep();
    }

    i++;
  }
}

/**
  Writes the input information to the
  digital pins.
  
  @param int a
  @param int b
  @param int c
  @param int d

  @return void
*/
void write(int a,int b,int c,int d) {
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

/**
  Executes a forward step on the step engine.

  @param null
  @return void
*/
void onestep() {
  write(1,0,0,0);
  delay(spin_delay);
  write(1,1,0,0);
  delay(spin_delay);
  write(0,1,0,0);
  delay(spin_delay);
  write(0,1,1,0);
  delay(spin_delay);
  write(0,0,1,0);
  delay(spin_delay);
  write(0,0,1,1);
  delay(spin_delay);
  write(0,0,0,1);
  delay(spin_delay);
  write(1,0,0,1);
  delay(spin_delay);
}

/**
  Executes a backward step on the step engine.

  @param null
  @return void
*/
void onestepback() {
  write(1,0,0,1);
  delay(spin_delay);
  write(0,0,0,1);
  delay(spin_delay);
  write(0,0,1,1);
  delay(spin_delay);
  write(0,0,1,0);
  delay(spin_delay);
  write(0,1,1,0);
  delay(spin_delay);
  write(0,1,0,0);
  delay(spin_delay);
  write(1,1,0,0);
  delay(spin_delay);
  write(1,0,0,0);
  delay(spin_delay);
}
