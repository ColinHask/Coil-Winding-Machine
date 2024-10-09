// stepper motor controll setup
// https://youtu.be/FggSRQqB_a4?si=JTkBBrD_HRUJXKyc


 bool clockwise = true; // global variable for direction

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  // change direction by changing this from low to high
  digitalWrite(2, HIGH);
}


void loop() {
  //loop to run for an amount of time before changing direction
  // 3350 seems to be a full rotation?
  for (int i = 0; i <= 3350; i++) {
    // put your main code here, to run repeatedly:
    // must set pin to low and back to high in order to do 1 step
    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    // change delay to change motor speed
    delayMicroseconds(600);
  }
  // swap direction to opposite direction
  if (clockwise == true) {
    digitalWrite(2, LOW);
    clockwise = false;
  }else{
    digitalWrite(2, HIGH);
    clockwise = true;
  }

}
