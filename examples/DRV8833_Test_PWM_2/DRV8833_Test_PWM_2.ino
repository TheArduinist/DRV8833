/*
 * DRV8833_Test_PWM_2
 * PWM (Pulse Width Modulation) test for the DRV8833 library.
 * The DRV8833 is a dual motor driver carrier made by Pololu.
 * You can find it here: https://www.pololu.com/product/2130
 *
 * Attach the positive wire of a motor to the Aout1 and the negative
 * wire to the Aout2 pins on the DRV8833.
 * Attach the positive wire of a motor to the Bout1 and the negative
 * wire to the Bout2 pins on the DRV8833.
 * Attach the Arduino's ground to the one of the GND pins on the DRV8833.
 * Attach a 9V battery's positive connection to the Vin pin
 * on the DRV8833, and the negative connection to one of the GND pins.
 * Attach the center pin of a potentiometer to analog 0, one side
 * pin to ground, and one side pin to +5V.
 * 
 * Created March 31, 2015, by Aleksandr J. Spackman.
 */

#include <DRV8833.h>

// Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

// Pin numbers. Replace with your own!
// For this example sketch, these pin numbers MUST be PWM.
// Attach the Arduino's pin numbers below to the
// Ain1, Ain2, Bin1, and Bin2 DRV8833 pins.
const int inputA1 = 5, inputA2 = 6, inputB1 = 9, inputB2 = 10;

// The speed of the motors:
int motorSpeed = 0;

// The potentiometer's pin:
const int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  
  // Start the serial port:
  Serial.begin(9600);
  
  // Wait for the serial port to connect. Needed for Leonardo.
  while (!Serial);
  
  // Attach the motors to the input pins:
  driver.attachMotorA(inputA1, inputA2);
  driver.attachMotorB(inputB1, inputB2);
  Serial.println("Ready!");

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(potPin);
  
  motorSpeed = map(reading, 0, 1023, 0, 255);
  Serial.print(reading);
  Serial.print('\t');
  Serial.println(motorSpeed);
  
  // Put the motors in forward using the speed:
  driver.motorAForward(motorSpeed);
  driver.motorBForward(motorSpeed);

}
