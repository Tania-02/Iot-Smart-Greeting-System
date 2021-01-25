#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Connecting...";
// the name of the wifi

const char* password = "uiuiuiuu";
// the password of the wifi

void setup () {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) { 
  //Check WiFi connection status
    
    HTTPClient http;
    //Declare an object of class HTTPClient
    
    String data = String(analogRead(A0), DEC);
    String link ="http://localhost/iot_project/data.php?data="+data+","+data;
    Serial.println(link);
    
    http.begin(link); 
    //Specify request destination

    int httpCode = http.GET(); 
    //Send the request

    if (httpCode > 0) { 
    //Check the returning code

      String payload = http.getString();   
      //Get the request response payload
      
      Serial.println(payload);
      //Print the response payload

    }
    
    http.end();
    //Close connection
  }

  delay(10);
  //Send a request every 30 seconds
}