// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[]           = "2b7cf06d-4017-44df-a3e5-355c6b1f734b";
const char DEVICE_LOGIN_NAME[]  = "d702e9b4-0495-4335-929b-31811f77b4ab";

const char SSID[]               = "FABLOW";    // Network SSID (name)
const char PASS[]               = "1234567654";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  ="5G95ADLYUVYK2USCLJQQ";    // Secret device password

void onRelayChange();
CloudElectricPotention volatge;
CloudElectricCurrent current;
CloudPower power;
float energy;
CloudLight relay;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(energy, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(volatge, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(current, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(power, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(relay, READWRITE, ON_CHANGE, onRelayChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
