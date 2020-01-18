
#include <Keypad.h>
#include <WiFi.h>
const char* ssid     = "Epic Lab";
const char* password = "@@ataikram@@";
WiFiServer server(80);
// Variable to store the HTTP request
String header;
String a;
// Auxiliar variables to store the current output state
String output13State = "off";
String output12State = "off";
String output25State = "off";
String output27State = "off";
String output32State = "off";
String output33State = "off";
String output35State = "off";
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";
String output34State = "off";




// Assign output variables to GPIO pins
const int output13 = 13;
const int output12 = 12;
const int output25 = 25;
const int output27 = 27;
const int output32 = 32;

int count=0;
const int ROWS=4;
const int COLS=3;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte colPins[COLS] =  {33, 32, 35};/* connect to the row pinouts of the keypad */
byte rowPins[ROWS] = {13, 12, 27, 25}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
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

void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
Serial.println(customKey);
 a=customKey;
 }

if( customKey=='1')
output13State = "on";
if( customKey=='2')
output12State = "on";
if( customKey=='3')
output27State = "on";
if( customKey=='4')
output25State = "on";
if( customKey=='5')
output32State = "on";
if( customKey=='6')
output33State = "on";
if( customKey=='7')
output35State = "on";
if( customKey=='8')
output1State = "on";
if( customKey=='9')
output2State = "on";
if( customKey=='*')
output3State = "on";
if( customKey=='0')
output4State = "on";
if( customKey=='#')
output5State = "on";

 
   WiFiClient client = server.available();   // Listen for incoming clients

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
            

          
           
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          /*  client.print("<meta http-equiv=\"refresh\" content=\"10\">");
            /*client.println("<head><meta http-equiv:'refresh' content='5' />");*/
           client.println("<script type='text/javascript'>");
           client.println("setInterval('window.location.reload()', 10000);");
           client.println("</script>");
      
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #555555; border: 4px; color: #add8e6; padding: 16px 20px;");
            
     
            client.println("text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #4CAF50;}</style></head>");
            
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
              // Display current state, and ON/OFF buttons for GPIO 13  
      /*      client.print("<p>GPIO 13 - State " + output13State + "</p>"); */
            // If the output13State is off, it displays the ON button       
           

            
            
            if (output13State=="off") {
              client.print("<p><a href=\"/13/on\"><button class=\"button\">1</button></a>");
            } else {
              client.print("<p><a href=\"/13/off\"><button class=\"button button2\">1</button></a>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 35  
           /* client.print("<p>GPIO 12 - State " + output12State + "</p>");*/
            // If the output12State is off, it displays the ON button       
            if (output12State=="off") {
              client.print("<a href=\"/12/on\"><button class=\"button\">2</button></a>");
            } else {
              client.print("<a href=\"/12/off\"><button class=\"button button2\">2</button></a>");
            } 

               // Display current state, and ON/OFF buttons for GPIO 25  
         /*   client.print("<p>GPIO 25 - State " + output27State + "</p>");*/
            // If the output25State is off, it displays the ON button       
            if (output27State=="off") {
              client.print("<a href=\"/27/on\"><button class=\"button\">3</button></a></p>");
            } else {
              client.print("<a href=\"/27/off\"><button class=\"button button2\">3</button></a></p>");
            }

           // Display current state, and ON/OFF buttons for GPIO 33  
            /*client.print("<p>GPIO 25 - State " + output25State + "</p>");*/
            // If the output27State is off, it displays the ON button       
            if (output25State=="off") {
              client.print("<p><a href=\"/25/on\"><button class=\"button\">4</button></a>");
            } else {
              client.print("<p><a href=\"/25/off\"><button class=\"button button2\">4</button></a>");
            } 
                  
               
            // Display current state, and ON/OFF buttons for GPIO 32 
           /* client.print("<p>GPIO 32 - State " + output32State + "</p>"); */
            // If the output32State is off, it displays the ON button       
            if (output32State=="off") {
              client.print("<a href=\"/32/on\"><button class=\"button\">5</button></a>");
            } else {
              client.print("<a href=\"/32/off\"><button class=\"button button2\">5</button></a>");
            }    
            // Display current state, and ON/OFF buttons for GPIO 33
            /*client.print("<p>GPIO 33 - State " + output33State + "</p>");*/
            // If the output33State is off, it displays the ON button       
            if (output33State=="off") {
              client.print("<a href=\"/33/on\"><button class=\"button\">6</button></a></p>");
            } else {
              client.print("<a href=\"/33/off\"><button class=\"button button2\">6</button></a></p>");
            }    
            
            // Display current state, and ON/OFF buttons for GPIO 35 
           /* client.println("<p>GPIO 35 - State " + output35State + "</p>");*/
            // If the output35State is off, it displays the ON button       
            if (output35State=="off") {
              client.println("<p><a href=\"/35/on\"><button class=\"button\">7</button></a>");
            } else {
              client.println("<p><a href=\"/35/off\"><button class=\"button button2\">7</button></a>");
            }    

             // Display current state, and ON/OFF buttons for GPIO 32 
           /* client.println("<p>GPIO 1 - State " + output1State + "</p>");*/
            // If the output32State is off, it displays the ON button       
            if (output1State=="off") {
              client.println("<a href=\"/1/on\"><button class=\"button\">8</button></a>");
            } else {
              client.println("<a href=\"/1/off\"><button class=\"button button2\">8</button></a>");
            }    

             // Display current state, and ON/OFF buttons for GPIO 32 
           /* client.println("<p>GPIO 2 - State " + output2State + "</p>");*/
            // If the output32State is off, it displays the ON button       
            if (output2State=="off") {
              client.println("<a href=\"/2/on\"><button class=\"button\">9</button></a></p>");
            } else {
              client.println("<a href=\"/2/off\"><button class=\"button button2\">9</button></a></p>");
            }    

             // Display current state, and ON/OFF buttons for GPIO 32 
           /* client.println("<p>GPIO 3 - State " + output3State + "</p>");*/
            // If the output3State is off, it displays the ON button       
            if (output3State=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">*</button></a>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">*</button></a>");
            }    

             // Display current state, and ON/OFF buttons for GPIO 32 
            /*client.println("<p>GPIO 4 - State " + output4State + "</p>");*/
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<a href=\"/4/on\"><button class=\"button\">0</button></a>");
            } else {
              client.println("<a href=\"/4/off\"><button class=\"button button2\">0</button></a>");
            }    
             // Display current state, and ON/OFF buttons for GPIO 32 
           /* client.println("<p>GPIO 5 - State " + output5State + "</p>");*/
            // If the output3State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<a href=\"/5/on\"><button class=\"button\">#</button></a></p>");
            } else {
              client.println("<a href=\"/5/off\"><button class=\"button button2\">#</button></a></p>");
            }    
            client.println("</div></body></html></color>");
            
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
