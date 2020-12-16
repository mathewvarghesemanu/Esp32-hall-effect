// Simple sketch to access the internal hall effect detector on the esp32.
// values can be quite low. 
// Brian Degger / @sctv  

int hall_val = 0;
int low_trig=0,high_trig=30;
int relay2pin= 4;
void setup() {
  pinMode(relay2pin,OUTPUT);
  digitalWrite(relay2pin,LOW);
  Serial.begin(9600);
}

// put your main code here, to run repeatedly
void loop() {
  // read hall effect sensor value
  hall_val = hallRead();
  // print the results to the serial monitor
  Serial.println(hall_val); 
  if ( hall_val<low_trig || hall_val>high_trig)
  {
    digitalWrite(relay2pin,LOW);
    Serial.println("triggered"); 
    delay(100);
  }
  else
  {
    digitalWrite(relay2pin,HIGH);
  }
}
