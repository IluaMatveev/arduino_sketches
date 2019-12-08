/*
 * OK, here we'r going to connect photoresistor and speaker to change speaker volume in 
 * accordance w/th level of light in room (can be changed manually)
 */

/*
 * First, let's define aliases to ports we use
 */
 
#define SPEAKER_PIN 3
#define RESISTOR_PIN A0

void setup() 

{

  /*
   * Here we just "attach" to patricular ports it's functions; thus, "SPEAKER_PIN" port (#3) 
   * will be an output port, and "RESISTOR_PIN" (A0) – an input port. Arduino controller 
   * itself has special tips on it (if it is an input or an output port)
   */

  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(RESISTOR_PIN, INPUT);
  
}

void loop()

{

  /*
   * Similarly to previous task, we define two variables – "val" and "frequency". 
   * В "val" мы запишем входящие значения с порта A0 – то, что в итоге отдаст нам фоторезистор;
   * В "frequency" мы запишем то, сколько мы в итоге отдадим на динамик
   */

  int val, frequency;

     /*
    * 
    * Функция analogRead(pinA) возвращает целочисленное значение в диапазоне 
    * от 0 до 1023, пропорциональное напряжению, поданному на аналоговый вход, 
    * номер которого мы передаем функции 
    * (в нашем случае – то, что мы записали в алиас RESSTOR_PIN)
    */

  val = analogRead(RESISTOR_PIN);

  /*
   * Делаем простой маппинг между входом (принятым напряжением на входе RESISTOR_PIN) и 
   * выходом (диапазоном частоты звучания в герцах)
   */
  
  frequency = map(val, 0, 1023, 3500, 4500);

  /*
   * Объявляем переменную "buzz_length" и сразу же её инициализируем – пишем в неё 20
   * милисекунд, на протяжении которых динамик будет издавать соответствующий звук
   */

  int buzz_length = 20;

  tone(SPEAKER_PIN, frequency, buzz_length);

}
