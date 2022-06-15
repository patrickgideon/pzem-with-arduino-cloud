#include <PZEM004Tv30.h>
#include "thingProperties.h"
PZEM004Tv30 pzem(D4,D5);
int led = D3;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
delay(1500);
 pinMode(led,OUTPUT);
 digitalWrite(led,HIGH);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
void loop() {
   ArduinoCloud.update();
  float voltage1 = pzem.voltage();
    if( !isnan(voltage1) ){
        Serial.print("Voltage: "); Serial.print(voltage1); Serial.println("V");
    } else {
      voltage1 = volatge;// to avoid error number in display
        Serial.println("Error reading voltage");
    }

    float current1 = pzem.current();
    if( !isnan(current1) ){
        Serial.print("Current: "); Serial.print(current1); Serial.println("A");
    } else {
      current1 = current;// to avoid error number in display
        Serial.println("Error reading current");
    }

    float power1 = pzem.power();
    if( !isnan(power1) ){
        Serial.print("Power: "); Serial.print(power1); Serial.println("W");
    } else {
      power1 =power;// to avoid error number in display
        Serial.println("Error reading power");
    }

    float energy1 = pzem.energy();
    if( !isnan(energy1) ){
        Serial.print("Energy: "); Serial.print(energy1,3); Serial.println("kWh");
    } else {
      energy1 = energy;// to avoid error number in display
        Serial.println("Error reading energy");
    }

    float frequency1 = pzem.frequency();
    if( !isnan(frequency1) ){
        Serial.print("Frequency: "); Serial.print(frequency1, 1); Serial.println("Hz");
    } else {
        Serial.println("Error reading frequency");
    }

    float pf1 = pzem.pf();
    if( !isnan(pf1) ){
        Serial.print("PF: "); Serial.println(pf1);
    } else {
        Serial.println("Error reading power factor");
    }
volatge = voltage1;
current = current1;
power = power1;
energy = energy1;
    Serial.println();
    

delay(2000);
}
void onRelayChange(){
  
  if(relay ==1){
    Serial.println("Lampu Menyala");
    digitalWrite(led,HIGH);
  }
  else{
    Serial.println("LampuMati");
;    digitalWrite(led,LOW);
  }
}
