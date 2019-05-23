#include<Wire.h>
#include <Temperature_Humidity.h> 
#include <AirQuality.h>

AirQuality a;

Temperature_Humidity th;          
int flag,prev=0; 
uint16_t x=600,b;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  th.begin();
  a.begin();
  Serial.begin(9600);
 th.begin();        //Begin the temperature and humidity Sensor
}
// The loop function runs over and over again forever
void loop() {
int error = Wire.endTransmission();
flag =0 ;
if(error==0)
flag=1;
 //if(prev==0 && flag==1){
 
 //}

Wire.beginTransmission(0x69);
  float h=th.getHumidity();
  float tc=th.getTempC();
  float tf=th.getTempF();
  Serial.print("Humidity : ");
  Serial.println(h);
  Serial.print("Temperature in C : ");
  Serial.println(tc);
  Serial.print("Temperature in F : ");
  Serial.println(tf);
  Serial.flush();
  Serial.print("\n");
  delay(2000);
  Serial.print("CO2: ");
  b=a.getCO2();
  Serial.println(b);
  
  
  Serial.print("X: ");
  Serial.println(x);
  if(b>x){
  Serial.println("alert!!\n");
  }
  Serial.print("TVOC: ");
  Serial.println(a.getTVOC());
  delay(1000);
 
  prev=flag;

}
