#include<WiFi.h>
#define LED1 13
#define LED2 12
#define LED3 27
#define LED4 25
#define LED5 32
 const char* ssid     = "KKAT AP";
const char* password = "200261725";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output13State = "off";
String output12State = "off";
String output25State = "off";
String output27State = "off";
String output32State = "off";

// Assign output variables to GPIO pins
const int output13 = 13;
const int output12 = 12;
const int output25 = 25;
const int output27 = 27;
const int output32 = 32;
int count=0;
void setup() {
  // Set pin mode
  pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
     pinMode(LED4,OUTPUT);
      pinMode(LED5,OUTPUT);

      
Serial.begin(9600);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
 
void loop() {
if(count==0){  delay(2000);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  delay(3000);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  delay(3000);
  digitalWrite(LED1,HIGH);
  delay(2000);
  digitalWrite(LED2,HIGH);
  delay(2000);
  digitalWrite(LED3,HIGH);
  delay(2000);
  digitalWrite(LED4,HIGH);
  delay(2000);
  digitalWrite(LED5,HIGH);
  delay(2000);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  delay(2000);
  count++;} 
 {WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /13/on") >= 0) {
              Serial.println("GPIO 13 on");
              output13State = "on";
              digitalWrite(output13, HIGH);
            } else if (header.indexOf("GET /13/off") >= 0) {
              Serial.println("GPIO 13 off");
              output13State = "off";
              digitalWrite(output13, LOW);
            } else if (header.indexOf("GET /12/on") >= 0) {
              Serial.println("GPIO 12 on");
              output12State = "on";
              digitalWrite(output12, HIGH);
            } else if (header.indexOf("GET /12/off") >= 0) {
              Serial.println("GPIO 12 off");
              output12State = "off";
              digitalWrite(output12, LOW);
            } else if (header.indexOf("GET /25/on") >= 0) {
              Serial.println("  GPIO 25 on");
              output25State = "on";
              digitalWrite(output25, HIGH);
            } else if (header.indexOf("GET /25/off") >= 0) {
              Serial.println("GPIO 25 off");
              output25State = "off";
              digitalWrite(output25, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            } else if (header.indexOf("GET /32/on") >= 0) {
              Serial.println("GPIO 32 on");
              output32State = "on";
              digitalWrite(output32, HIGH);
            } else if (header.indexOf("GET /32/off") >= 0) {
              Serial.println("GPIO 32 off");
              output32State = "off";
              digitalWrite(output32, LOW);
            }
            
            
            
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 13  
            client.println("<p>GPIO 13 - State " + output13State + "</p>");
            // If the output13State is off, it displays the ON button       
            if (output13State=="off") {
              client.println("<p><a href=\"/13/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/13/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 35  
            client.println("<p>GPIO 12 - State " + output12State + "</p>");
            // If the output12State is off, it displays the ON button       
            if (output12State=="off") {
              client.println("<p><a href=\"/12/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/12/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

               // Display current state, and ON/OFF buttons for GPIO 25  
            client.println("<p>GPIO 25 - State " + output25State + "</p>");
            // If the output25State is off, it displays the ON button       
            if (output25State=="off") {
              client.println("<p><a href=\"/25/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/25/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

           // Display current state, and ON/OFF buttons for GPIO 33  
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
                  
               
            // Display current state, and ON/OFF buttons for GPIO 32 
            client.println("<p>GPIO 32 - State " + output32State + "</p>");
            // If the output32State is off, it displays the ON button       
            if (output32State=="off") {
              client.println("<p><a href=\"/32/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/32/off\"><button class=\"button button2\">OFF</button></a></p>");
            }    
            
           
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
