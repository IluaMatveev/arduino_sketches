#define LED_PIN 13
#define POT_PIN A1
#define PHOTORESISTOR_PIN A0

void setup()

{

  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  
}

void loop()

{

  int pot_val, photoresistor_val, brightness;

  pot_val = analogRead(POT_PIN);
  photoresistor_val = analogRead(PHOTORESISTOR_PIN);

  if (photoresistor_val < pot_val) {

    brightness = 255;
    
  } else {
    
    brightness = 0;
    
  }

  analogWrite(LED_PIN, brightness);
  
}
