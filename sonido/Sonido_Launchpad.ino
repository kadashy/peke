int ledPin = 13;
int speakerPin = 8;
 
#define c 261
#define d 294
#define e 329
#define faS 349
#define sol 391
#define solS 415
#define la 440
#define laS 455
#define si 466
#define d0 523
#define doS 554
#define re 587
#define reS 622
#define mi 659
#define fa 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

void march(char octava);
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds);

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}
 
void loop(){
  march(1);
  march(2);
  march(4);

  
} 
 
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{
    digitalWrite(ledPin, HIGH);
    //use led to visualize the notes being played
 
    int x;
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)    {
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    }
 
    digitalWrite(ledPin, LOW);
 
    delay(20);
}
 
void march(char octava){
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*faS, 350);
    beep(speakerPin, octava*d0, 150);
 
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*faS, 350);
    beep(speakerPin, octava*d0, 150);
    beep(speakerPin, octava*la, 1000);
 
    beep(speakerPin, octava*mi, 500);
    beep(speakerPin, octava*mi, 500);
    beep(speakerPin, octava*mi, 500);
    beep(speakerPin, octava*fa, 350);
    beep(speakerPin, octava*d0, 150);
 
    beep(speakerPin, octava*solS, 500);
    beep(speakerPin, octava*faS, 350);
    beep(speakerPin, octava*d0, 150);
    beep(speakerPin, octava*la, 1000);
 
    beep(speakerPin, octava*aH, 500);
    beep(speakerPin, octava*la, 350);
    beep(speakerPin, octava*la, 150);
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*gSH, 250);
    beep(speakerPin, octava*gH, 250);
 
    beep(speakerPin, octava*fSH, 125);
    beep(speakerPin, octava*fa, 125);
    beep(speakerPin, octava*fSH, 250);
    delay(250);
    beep(speakerPin, octava*laS, 250);
    beep(speakerPin, octava*reS, 500);
    beep(speakerPin, octava*re, 250);
    beep(speakerPin, octava*reS, 250);
 
    beep(speakerPin, octava*d0, 125);
    beep(speakerPin, octava*si, 125);
    beep(speakerPin, octava*d0, 250);
    delay(250);
    beep(speakerPin, octava*faS, 125);
    beep(speakerPin, octava*solS, 500);
    beep(speakerPin, octava*faS, 375);
    beep(speakerPin, octava*la, 125);
 
    beep(speakerPin, octava*d0, 500);
    beep(speakerPin, octava*la, 375);
    beep(speakerPin, octava*d0, 125);
    beep(speakerPin, octava*mi, 1000);
 
    beep(speakerPin, octava*aH, 500);
    beep(speakerPin, octava*la, 350);
    beep(speakerPin, octava*la, 150);
    beep(speakerPin, octava*aH, 500);
    beep(speakerPin, octava*gSH, 250);
    beep(speakerPin, octava*gH, 250);
 
    beep(speakerPin, octava*fSH, 125);
    beep(speakerPin, octava*fSH, 125);
    beep(speakerPin, octava*fSH, 250);
    delay(250);
    beep(speakerPin, octava*laS, 250);
    beep(speakerPin, octava*reS, 500);
    beep(speakerPin, octava*re, 250);
    beep(speakerPin, octava*doS, 250);
 
    beep(speakerPin, octava*d0, 125);
    beep(speakerPin, octava*si, 125);
    beep(speakerPin, octava*d0, 250);
    delay(250);
    beep(speakerPin, octava*faS, 250);
    beep(speakerPin, octava*solS, 500);
    beep(speakerPin, octava*faS, 375);
    beep(speakerPin, octava*d0, 125);
 
    beep(speakerPin, octava*la, 500);
    beep(speakerPin, octava*faS, 375);
    beep(speakerPin, octava*c, 125);
    beep(speakerPin, octava*la, 1000);
 
}
