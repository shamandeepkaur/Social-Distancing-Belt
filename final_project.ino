int pingPin = 10; //Pin of the Ping is connected to port 10 
int piezzoPin = 9; //Pin of the piezo is connected to port 9
int blueledPin = 8; //Pin of blue led is connected to port 8
int duration = 0; // variable duration is declared
int cm = 0; //variable cm is declared

void setup(){
  pinMode(pingPin, INPUT);//ping pin is set up for taking inputs
  pinMode(piezzoPin, OUTPUT);//piezo pin is set up as output pin
  pinMode(blueledPin, OUTPUT);//blue led pin is setup as output pin
  Serial.begin(9600);// initialised serial communication 
}

void loop(){
      duration = pulseIn(pingPin, HIGH);
  
  // convert time to distance
      cm = microsecondsToCentimeters(duration);
  
  // Print the distance
  	  Serial.println("distance: ");
      Serial.print(cm);
      Serial.print("cm");
  
  //warn if the object is too close by turning on blue led and piezzo
      if (cm <= 200) {
        digitalWrite(piezzoPin, HIGH);
        digitalWrite(blueledPin, HIGH);
      }
  // if object is at distance greater than 200cm turn led and piezzo off
       else{
         digitalWrite(piezzoPin, LOW);
         digitalWrite(blueledPin, LOW);
       }
  
       delay(200);
   }
         
      

  // create method to convert microseconds to centimeters
   long microsecondsToCentimeters(long microseconds){
     // speed of sound in air is 344m/s or 29 microseconds/cm 
     // distance has to be divided by 2 because signal travels back and forth
     return ((microseconds*2)/29) ;
   }
  
        
         
         
         
         
         
         
         
         
    
