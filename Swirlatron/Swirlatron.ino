////////////////////////////////////////////////////////////////////////////////////////////
// Big Swirly Light 1000 ///// /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//
// This script relies heavily on example code from the libraries below! 
// 
// This works here but I accept no responsibility for broken hardware, fire, explosions etc! 
////////////////////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h> // https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

////////////////////////////////////////////////////////////////////////////////////////////
// CONFIG SECTION //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// CHANGEME: Captive portal name
const char* capName = "Swirlatron 1000";
//
// CHANGEME: Webpage title
String webpageTitle = "The Operations Big Swirly Light!";
String webpageHeader = "Operations Big Swirly Light!"
String webpageContent = "We like to turn it on and off again..."
/////////////////////////////////////////////////////////////////////////////////////////////

// If you are using a D1 mini with the relay shield then this is the pin it is connected to
// if you are using anything else you need to change this.
int swirlyPin = D1;

ESP8266WebServer server(80);

//Web Request Handling
void handleRoot() {
  String msg = server.arg("msg");
  Serial.println(msg);  
        server.send(200, "text/html", "<html><head><title>"
        +webpageTitle+
        "</title>"
        "<meta name=\"viewport\" content=\"width=device-width, target-densitydpi=device-dpi, initial-scale=0, maximum-scale=1, user-scalable=yes\" />"
        "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/milligram/1.3.0/milligram.css\">"
        "<link rel=\"stylesheet\" href=\"//fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic\">"
        "<link rel=\"stylesheet\" href=\"//cdn.rawgit.com/necolas/normalize.css/master/normalize.css\">"
        "</head><body><p><center><h1>"
        +webpageHeader+
        "</h1><h3>"
        +webpageContent+
        "</h3></center></body></html>");
}

void handleNotFound(){
        String message = "File Not Found\n\n";
        message += "URI: ";
        message += server.uri();
        message += "\nMethod: ";
        message += (server.method() == HTTP_GET) ? "GET" : "POST";
        message += "\nArguments: ";
        message += server.args();
        message += "\n";
        for (uint8_t i=0; i<server.args(); i++) {
                message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
        }
        server.send(404, "text/plain", message);
}

void handleOn(){
   digitalWrite(swirlyPin, HIGH);
   server.send(200, "text/html", "<html><head><title>"
        +webpageTitle+
        "</title>"
        "<meta name=\"viewport\" content=\"width=device-width, target-densitydpi=device-dpi, initial-scale=0, maximum-scale=1, user-scalable=yes\" />"
        "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/milligram/1.3.0/milligram.css\">"
        "<link rel=\"stylesheet\" href=\"//fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic\">"
        "<link rel=\"stylesheet\" href=\"//cdn.rawgit.com/necolas/normalize.css/master/normalize.css\">"
        "</head><body>" 
        "<p>"
        "<center>"
        "<h2>Swirly Light On!</h2>"
        
        "</body></html>");

}

void handleOff(){
   digitalWrite(swirlyPin, LOW);
   server.send(200, "text/html", "<html><head><title>"
        +webpageTitle+
        "</title>"
        "<meta name=\"viewport\" content=\"width=device-width, target-densitydpi=device-dpi, initial-scale=0, maximum-scale=1, user-scalable=yes\" />"
        "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/milligram/1.3.0/milligram.css\">"
        "<link rel=\"stylesheet\" href=\"//fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic\">"
        "<link rel=\"stylesheet\" href=\"//cdn.rawgit.com/necolas/normalize.css/master/normalize.css\">"
        "</head><body>" 
        "<p>"
        "<center>"
        "<h2>Swirly Light Off!</h2>"
        
        "</body></html>");

}

void handleRedalert(){
   server.send(200, "text/html", "<html><head><title>"
        +webpageTitle+
        "</title>"
        "<meta name=\"viewport\" content=\"width=device-width, target-densitydpi=device-dpi, initial-scale=0, maximum-scale=1, user-scalable=yes\" />"
        "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/milligram/1.3.0/milligram.css\">"
        "<link rel=\"stylesheet\" href=\"//fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic\">"
        "<link rel=\"stylesheet\" href=\"//cdn.rawgit.com/necolas/normalize.css/master/normalize.css\">"
        "</head><body>" 
        "<p>"
        "<center>"
        "<h2>Are you sure sir?  This does mean changing the bulb</h2>"       
        "</body></html>");

}


//Setup sketch
void setup() {
  pinMode(swirlyPin, OUTPUT); 

  WiFiManager wifiManager;
  wifiManager.autoConnect(capName);
   
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/redalert", handleRedalert);
  
  server.onNotFound(handleNotFound);
//If you go to this page it will wipe all settings and restart the ESP
//Useful for testing but probably best left commented out in production
//  server.on("/zz9reset!", [] (){
//            server.send(200, "text/plain", "ZMG?? where am I?");
//            WiFi.disconnect();
//            ESP.restart();
//            });
  
  server.begin();
}


//Main loop
void loop() {
  server.handleClient();
}
