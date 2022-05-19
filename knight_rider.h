#define led1 5;
#define led2 6;
#define led3 7;
#define led4 8;
#define led5 9;
#define led6 10;
#define led7 11;
#define led8 12;

void knightRider(int delayTime){
  for (int i = 5;i<13;i++){
    digitalWrite(i,HIGH);
    delay(delayTime);
    digitalWrite(i,LOW);
    delay(delayTime);
  }
  for (int i = 11;i>4;i--){
    digitalWrite(i,HIGH);
    delay(delayTime);
    digitalWrite(i,LOW);
    delay(delayTime);
  }
}
