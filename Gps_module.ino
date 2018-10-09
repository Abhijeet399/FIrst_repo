#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
float lat = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3,4);//rx,tx 
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;
TinyGPS gps; // create gps object 
void setup(){ 
  pinMode(smokeA0, INPUT);
Serial.begin(9600); // connect serial 
Serial1.begin(9600);
Serial2.begin(9600);
//Serial.println("The GPS Received Signal:"); 
gpsSerial.begin(9600); // connect gps sensor 

} 
void loop(){ 
  int analogSensor = analogRead(smokeA0);
  while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&lat,&lon); // get latitude and longitude 
  // display position 
  
  Serial.println("GPS Signal"); 
  //Serial.print("Position: "); 
  //Serial.print("Latitude:"); 
  //Serial.print(lat,6); 
  //Serial.print(";"); 
  //Serial.print("Longitude:"); 
  //Serial.println(lon,6);  
  Serial.print("LAT:"); 
  Serial.println(lat); 
  //Serial.print(lat); 
  //Serial.print(" "); 
  Serial.print(",LON:"); 
  Serial.println(lon); 
 }
}
String latitude = String(lat,6); 
  String longitude = String(lon,6); 
Serial.println("LATITUDE-"+latitude+";"+"LONGITUDE-"+longitude); 
delay(1000); 
if(Serial.available()>0){
char  d=Serial.read();
  Serial.println(d);
}
Serial.print("Pin A0: "+analogSensor);
if (analogSensor > sensorThres)
  {
    Serial.println("DANGER");
    
  }
  else
  {
    Serial.println("SAFE");
    
  }
  delay(100);
} 
