// Motor A (drive)

int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B (steering)

int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()

{

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialise serial
  Serial.begin(9600);

}

void drive(int dir, int spd)
{
  // Direction: 1 (forward), 0 (backward)
  // Speed: ranges from 0~255
  
  // Turn on motor A (drive)
  digitalWrite(in1, dir == 1 ? LOW : HIGH);
  digitalWrite(in2, dir == 1 ? HIGH : LOW);

  // Set speed
  analogWrite(enA, spd);

  // Stop after 10 ms
  delay(10);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void turn(int dir, int spd)
{
  // Direction: 1 (left), 0 (right)
  // Speed: ranges from 0~255 (recommended max 255)

  // Turn on motor B (steering)
  digitalWrite(in3, dir == 1 ? LOW : HIGH);
  digitalWrite(in4, dir == 1 ? HIGH : LOW);

  // Set speed
  analogWrite(enB, spd);

  // Stop after 10 ms
  delay(10);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void stop()
{
  // Turn off all motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void control()
{
  while (Serial.available())
  {
    char input = (char) Serial.read();

    // Forwards + left
    if (input == '1')
    {
      Serial.println("Forwards + left");
      drive(1, 255);
      turn(1, 255);
    }
    // Forwards + right
    else if (input == '2')
    {
      Serial.println("Forwards + right");
      drive(1, 255);
      turn(0, 255);
    }
    // Forwards
    else if (input == '3')
    {
      Serial.println("Forwards");
      drive(1, 255);
    }
    
    // Backwards + left
    if (input == '4')
    {
      Serial.println("Backwards + left");
      drive(0, 255);
      turn(1, 255);
    }
    // Backwards + right
    if (input == '5')
    {
      Serial.println("Backwards + right");
      drive(0, 255);
      turn(0, 255);
    }
    // Backwards
    if (input == '6')
    {
      Serial.println("Backwards");
      drive(0, 255);
    }
  }
}

void loop()
{
  control();
}
