/*
 * OK, here we are goind to code a little script to make LED change its color in time
 * 
 */


#define LED_PIN 9 // Initialize and define variable to work

void setup()

// This function performs all actions described exactly one time after power on

{

  pinMode(LED_PIN, OUTPUT);

}

void loop()

// This function performs an infinite loop till break / power off

{

  for (int brightness = 0; brightness <= 255; brightness++) {

    analogWrite(LED_PIN, brightness); // This function changes output power in source LED_PIN defined earlier
    delay(50);
    
  }


  for (int brightness = 255; brightness >= 0; brightness--) {

    analogWrite(LED_PIN, brightness);
    delay(50);
    
  }

}
