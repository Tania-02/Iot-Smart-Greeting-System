#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "MYHOME";
// the name of the wifi

const char* password = "Uttarpara321";
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
    
    String data = String(analogRead(A0), DEC);//DEC--Decimal
    String link ="http://192.168.0.101/PROJECT/ldetect.php?data="+data;
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

  delay(500);
  //Send a request every 30 seconds
}
