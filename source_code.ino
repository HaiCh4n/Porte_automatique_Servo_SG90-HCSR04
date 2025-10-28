#include <Servo.h>

// ==== Pin setup ====
const uint8_t SERVO_PIN = 10;
const uint8_t TRIG_PIN  = 11;
const uint8_t ECHO_PIN  = 12;
const uint8_t led = 3;

// ==== Objects ====
Servo myservo;

// ==== Helpers ====
long getDistanceCm() {
  // Phát xung trigger: LOW 2µs -> HIGH 10µs -> LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Đo xung phản hồi; timeout 30ms ~ 5m
  unsigned long dur = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (dur == 0) {
    // Không nhận được echo trong timeout
    return -1;
  }

  // Tốc độ âm thanh ~ 343 m/s => 29.1 µs/cm (khứ hồi nên chia 2)
  // Công thức chuẩn: distance(cm) = dur / 58.0
  long cm = lround(dur / 58.0);
  return cm;
}



void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  pinMode(led,OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Đặt trạng thái ban đầu
  digitalWrite(TRIG_PIN, LOW);
  myservo.write(90);
  digitalWrite(led,LOW);
}

void loop() {
  long d = getDistanceCm();
  if(d>0){
    Serial.print("Distance: "); 
    Serial.print(d);
    Serial.println("cm");
  }else{
    Serial.println("Distance: -- (no echo)");
  }
  if (d>0 && d<20){
    Serial.println("Found something in valid distance");
    myservo.write(180);
    digitalWrite(led,HIGH);
    delay(15000);
    Serial.println("returning to 0");
    digitalWrite(led,LOW);
    myservo.write(0);
  }else{
    myservo.write(0);
  }
  delay(200);
}
