#include <ESP8266WiFi.h>

const char* ssid = "MYHOME";
const char* password = "Uttarpara321";

//int ledPin = 12; // GPIO12 D6
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(A0, INPUT);
  //digitalWrite(ledPin, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Trying to connect to  ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   String  ana,link;
  // Match the request
  int value = LOW;
  if (request.indexOf("/CHECK") != -1) {
     ana =String(analogRead(A0),DEC);
     link ="http://localhost/PROJECT/ldetect.php?data="+ana;
  }
Serial.println(ana);
Serial.println(link);
  // Set ledPin according to the request
  //digitalWrite(ledPin, value);

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Light Detector!!!</title>");
  client.println("<script src='http://code.jquery.com/jquery-1.12.4.js' type='text/javascript'></script>");
  client.println("<link rel='stylesheet' href='style.css'>"); 
  client.println("</head>");
  client.println("<header>");
  client.println(" <div id='header'>");
  client.println("<h1>Light Detector!!!</h1>"); 
  client.println("</div>");
  client.println("</header>");
  
  client.println("<body>");
  client.println("<br><br><br><br><br>");
  client.println("<p style='color:black;'><b>Light Sensing Data ::&nbsp;&nbsp;&nbsp;</b><span id='light'></span><br></p>");
 client.println("<a href=\"/CHECK\"><button id ='chk' align='center'>CHECK</button></a></p>");
  client.println("<p style='color:black;'><br>Status :-- </br></p>");
  client.println("<br><span id='status'></span></br>");
  client.println("<h3 style='color:white;'><button align='center' id='back' onclick='goBack()'>BACK</button></h3>");
  client.println("<script>");
  /*client.println("setInterval(function()");
  client.println(" {");
  client.println("     $.ajax({");
  client.println("         url: 'ldetect.php',");
  client.println("         method: 'GET',");
  client.println("         data:{data = a} ,");
  client.println("         success: function(result)");
  client.println("           {");
  client.println("             console.log(result);");
  client.println("             $('#light').append(result);");                        
  client.println("           }");
  client.println("             });");
  client.println(" }, 1000);");*/
  client.println("$(document).on('click', '#chk', function(){ ");
  client.println("      var k = {'disp':1};");
  client.println("      $.ajax({ ");
  client.println("       url     : 'ldetect.php',");
  client.println("       method  : 'GET',");
  client.println("       data    : k,");
  client.println("       success : function(result)");
  client.println("          {");
  client.println("            var a=result.split('\n');");
  client.println("              for (i in a)  "); 
  client.println("            {");
  client.println("             $('#status').append('<br>').append(a[i]);");
  client.println("            }");
  client.println("          }");
  client.println("        });");
  client.println("          });");

  
  
  client.println("function goBack() {");
  client.println("window.history.back();");
  client.println("}");
  client.println("</script>");
  client.println("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
