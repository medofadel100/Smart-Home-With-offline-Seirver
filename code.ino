#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
/*
const char* www_username = "admin";
const char* www_password = "admin";
*/

const char* ssid = "Ahmed Fadel";
const char* password = "01223840100";
 
/*
IPAddress ip(192,168,1,9);
IPAddress router(192,168,1,1);
IPAddress netmask(255,255,255,0);
*/
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);

   pinMode(16, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(0, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(14, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(15, OUTPUT);

   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
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
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  ///////////////////// Test//////////////////
   
  // Match the request

 // Hall
    int valueH = LOW;
   if (request.indexOf("/HLED=ON") != -1)  {
    digitalWrite(16, HIGH);
    valueH = HIGH;
  }
  if (request.indexOf("/HLED=OFF") != -1)  {
    digitalWrite(16, LOW);
    valueH = LOW;
  }
   // Room1
  int valuea = LOW;
  if (request.indexOf("/R1LED=ON") != -1)  {
    digitalWrite(5, HIGH);
    valuea = HIGH;
  }
  if (request.indexOf("/R1LED=OFF") != -1)  {
    digitalWrite(5, LOW);
    valuea = LOW;
  }
  // Room 2
  int valueb = LOW;
  if (request.indexOf("/R2LED=ON") != -1)  {
    digitalWrite(4, HIGH);
    valueb = HIGH;
  }
  if (request.indexOf("/R2LED=OFF") != -1)  {
    digitalWrite(4, LOW);
    valueb = LOW;
  }

    int valuef = LOW;
  if (request.indexOf("/Fan=ON") != -1)  {
    digitalWrite(15, HIGH);
    valuef = HIGH;
  }
  if (request.indexOf("/Fan=OFF") != -1)  {
    digitalWrite(15, LOW);
    valuef = LOW;
  }
  // Kitchen
  int valuec = LOW;
  if (request.indexOf("/KLED=ON") != -1)  {
    digitalWrite(0, HIGH);
    valuec = HIGH;
  }
  if (request.indexOf("/KLED=OFF") != -1)  {
    digitalWrite(0, LOW);
    valuec = LOW;
  }
  // Bathroom
  int valued = LOW;
  if (request.indexOf("/BLED=ON") != -1)  {
    digitalWrite(2, HIGH);
    valued = HIGH;
  }
  if (request.indexOf("/BLED=OFF") != -1)  {
    digitalWrite(2, LOW);
    valued = LOW;
  }

   // garag
    int valueR = LOW;
   if (request.indexOf("/GSERVO=ON") != -1)  {
    digitalWrite(14, HIGH);
    valueR = HIGH;
  }
  if (request.indexOf("/GSERVO=OFF") != -1)  {
    digitalWrite(14, LOW);
    valueR = LOW;
  }

     // Front door
      int valueK = LOW;
   if (request.indexOf("/FSERVO=ON") != -1)  {
    digitalWrite(12, HIGH);
    valueK = HIGH;
  }
  if (request.indexOf("/FSERVO=OFF") != -1)  {
    digitalWrite(12, LOW);
    valueK = LOW;
  }

    // Front lamp
    int valueB = LOW;
   if (request.indexOf("/FLED=ON") != -1)  {
    digitalWrite(13, HIGH);
    valueB = HIGH;
  }
  if (request.indexOf("/FLED=OFF") != -1)  {
    digitalWrite(13, LOW);
    valueB = LOW;
  }
/*
  // -----

  // lamp2
  int value2 = LOW;
  if (request.indexOf("/FLED2=ON") != -1)  {
    digitalWrite(15, HIGH);
    value2 = HIGH;
  }
  if (request.indexOf("/FLED2=OFF") != -1)  {
    digitalWrite(15, LOW);
    value2 = LOW;
  }

  */
   
   // Set ledPin according to the request
   //digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Smart Home ^_^</title>");
  client.println("<style>");
  client.println("*{ padding:0; margin:0; }");
  client.println("body{ background: #e7e7e7;} ");
  client.println(" </style>");
  client.println("</head>");
  client.println("<body >");
  client.println("<nav style=\" background: #1e2650; height: 40px; padding:15px 0; position: fixed; width: 100%;\">");
  client.println(" <div class=container style=\"padding: 0 10% ;  background: #1e2650;\">");
  client.println(" <div class=logo style=\"float: left; color:white; font-size: 30px;\">");
  client.println("<h1>Smart Home</h1>");
  client.println("</div>");
  client.println("<ul style=\"float: right; list-style: none;  font-size: 30px; margin-top:2px;\">");
  client.println("<li style=\"display: inline-block; margin-right:30px;\">");
  client.println("<a href=#Main style=\"text-decoration: none; color:white;\">inro</a>");
  client.println("</li >");
  client.println("<li style=\"display: inline-block; margin-right:30px;\">");
  client.println("<a href=#Home style=\"text-decoration: none; color:white;\">My Home</a>");
  client.println("</li>");
  client.println("<li style=\"display: inline-block; margin-right:30px;\">");
  client.println("<a href=\"https://www.facebook.com/medofadel48\" style=\"text-decoration: none; color:white;\" >Coder &copy;</a>");
  client.println("</li>");
  client.println("</ul>");
  client.println("<div class=clearfix></div>");
  client.println("</div>");
  client.println("</nav>");
  client.println("<section class=\"intro\" id=\"Main\" style=\" background:url(http://imgur.com/IxwPZXS) no-repeat center center fixed;background-size:cover;height:100vh;text-align:center;padding-top:200px;\"> <h1 style=\"font-size:90px;color:#5a0d0d; margin-bottom:60px; margin-top: 170px;\">Welcome To Smart Home System </h1> </section>");
  client.println("<section class=\"Home\" id=\"Home\" style=\"background:#ddd; height:100vh; padding-top: 100px; text-align: center; padding-bottom:20%;\">");
  client.println("<div class=\"container\" style=\"padding: 0 10%; background: #1e2650;\" >");
  client.println(" <h2 style=\"font-size: 50px; color:white; margin-bottom: 50px;\"> My Home </h2> ");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/1D2w6qd.jpg\" style=\"width: 100%;\"> <a href=\"#ahall\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> Hall </h3> </a> </div>");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/Ws0OzFn.jpg\" style=\"width: 100%;\"> <a href=\".aroom1\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> Room1 </h3> </a> </div>");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/cTjjc7Q.jpg\" style=\"width: 100%;\"> <a href=\"#aroom2\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> Room2 </h3> </a> </div>");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/Yli5F0j.jpg\" style=\"width: 100%;\"> <a href=\"#akitchen\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> kitchen </h3> </a> </div>");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/abZpDom.jpg\" style=\"width: 100%;\"> <a href=\"#abathroom\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> Bathroom </h3> </a> </div>");
  client.println("<div class=\"room\" style=\"width: 30%; height: 100%; float: left; border:2px solid black; margin-right: 20px; margin-bottom: 25px;\" > <img src=\"http://i.imgur.com/9WdtJgU.jpg\" style=\"width: 100%;\"> <a href=\"#afront\" style=\"color:#fff; text-decoration: none; font-size: 25px;\"> <h3 style=\"background:#222; padding:15px; border-top:5px solid yellow; :hover{ background: red}\"> Front</h3> </a> </div>");
  client.println("</div>");
  client.println("</section>");
             //Every Room Start on Html & Css
                     
  client.println("<h1 class=\"eroom\" style=\"font-size: 120px; color:#1e2650; text-align: center; padding-bottom: 10%;\"> Every Room </h1>");
  
             //Hall
  client.println("<div class=\"ahall\" id=\"ahall\" style=\" height: 90vh; padding-top: 50px; padding-bottom: 0px; background: #a4addc;\">");
  client.println("<h2 style=\"text-align: center; font-size: 700%; color: #3f51b5; padding-bottom: 5%; \" >Hall</h2>");
  client.println("<div class=\"hall\" id=\"hall\">");
  client.println("<div class=\"lamp1\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/FlGedw2.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\"> ");
    
  client.print("<a href=\"/HLED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/HLED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>");  
  
  client.println("</div>");
  
  client.println("<div class=\"lamp2\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/scwrchy.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"fan\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/4o3XeKK.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");

  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>");
  client.println("</div>");
  
         //Room1
  client.println("<div class=\"aroom1\" id=\"aroom1\" style=\"margin-top: 7%;\">");
  client.println("<h2 style=\"text-align: center; font-size:700%; color:#3f51b5; padding-bottom:5%;\">Room1</h2>");
  client.println("<div class=\"room1\" id=\"room1\">");
  client.println("<div class=\"lamp1\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/FlGedw2.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/R1LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/R1LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"lamp2\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/scwrchy.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/R1LED2=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/R1LED2=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"fan\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/ijG9aIi.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/R1Fan=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/R1Fan=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"tv\" id=\"tv\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/1Q8O9kJ.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/R1TV=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/R1TV=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>");
  client.println("</div>");
          //Room2  
  client.println("<div class=\"aroom2\" id=\"aroom2\" style=\"margin-top:90%; height:150vh; padding-top:50px; padding-bottom:0px; background:#a4addc;\">");
  client.println("<h2 style=\"text-align:center; font-size:700%; color:#3f51b5; padding-bottom:5%;\">Room2</h2>");
  client.println("<div class=\"room2\" id=\"room2\">");
  client.println("<div class=\"lamp1\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/FlGedw2.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/R2LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/R2LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"lamp2\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/scwrchy.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"fan\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/ijG9aIi.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/Fan=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/Fan=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"tv\" id=\"tv\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/4C53xCI.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
  
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>");
  client.println("</div>");
         //Kitchen
  client.println("<div class=\"akitchen\" id=\"akitchen\" style=\"height:90vh; padding-top:50px; padding-bottom:0px;\">");
  client.println("<h2 style=\"text-align: center; font-size:700%; color:#3f51b5; padding-bottom:5%; \">Kitchen</h2>");
  client.println("<div class=\"kitchen\" class=\"lamp1\" style=\"width: 26%; float: left; margin: 3% 3% 0% 3%; height: 430px; \">");
  client.println("<img src=\"http://i.imgur.com/kqjRnMy.png\" style=\" width:100%; height:400px; padding-bottom:7%; float:left; border:2px solid black; margin-right: 7%; margin-bottom: 25px; border-radius: 25%;\">");
    
  client.print("<a href=\"/KLED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/KLED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"kitchen\" class=\"fan\" style=\"width: 26%; float: left; margin: 3% 3% 0% 3%; height: 430px; \">");
  client.println("<img src=\"http://i.imgur.com/7knPHAI.png\" style=\" width:100%; height:400px; padding-bottom:7%; float:left; border:2px solid black; margin-right: 7%; margin-bottom: 25px; border-radius: 25%;\">");
    
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"kitchen\" id=\"microwave\" class=\"microwave\" style=\"width: 26%; float: left; margin: 3% 3% 0% 3%; height: 430px; \">");
  client.println("<img src=\"http://i.imgur.com/Otf7C9e.png\" style=\" padding:3% 3% 3% 7%; width:100%; height:400px; padding-bottom:7%; float:left; border:2px solid black; margin-right: 7%; margin-bottom: 25px; border-radius: 25%;\">");
   
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>");
        //Bathroom
  client.println("<div class=\"abathroom\" id=\"abathroom\" style=\"margin-top:7% height:90vh; padding-top:300px; padding-bottom:0px; background:#a4addc;\">");
  client.println("<h2 style=\"text-align:center; font-size: 700%; color:#3f51b5; padding-bottom:5%; \">Bathroom</h2>");
  client.println("<div class=\"bathroom\" id=\"bathroom\"  style=\"  margin-left: 20%;\">");
  client.println("<div class=\"lamp1\" style=\"width: 30%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/FlGedw2.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
    
  client.print("<a href=\"/BLED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/BLED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"bouller\" style=\"  width: 35%; float: left; border:2px solid black; margin-right: 7%; margin-bottom: 25px; border-radius: 25%; \">");
  client.println("<img src=\"http://i.imgur.com/KpadeZh.png\" style=\"margin: 3% 10% 0% 3%; width: 85%; height: 400px; padding-right: 15%;\">");
    
  client.print("<a href=\"/LED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>"); 
  client.println("</div>");
        //Front Light
  client.println("<div class=\"afront\" id=\"afront\" style=\"height:80vh; padding-top:700px; padding-bottom:0px;\">");
  client.println("<h2 style=\" text-align: center; font-size: 700%; color: #3f51b5; padding-bottom: 5%;\">Front Light</h2>");
  client.println("<div class=\"front\" id=\"front\">");
  client.println("<div class=\"lamp1\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/FlGedw2.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
    
  client.print("<a href=\"/FLED=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/FLED=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"lamp2\" style=\"width: 25%;float: left;border:2px solid black;margin-right: 7%;margin-bottom: 25px;border-radius: 25%;\"> <img src=\"http://i.imgur.com/nc8g2Sz.png\" style=\"margin: 3% 3% 0% 3%; width: 100%; height: 400px;\">");
    
  client.print("<a href=\"/FSERVO=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/FSERVO=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("<div class=\"lamp3\" style=\"width: 25%; float: left; border:2px solid black; margin-right: 7%; margin-bottom: 25px; border-radius: 25%; \">");
  client.println("<img src=\"http://i.imgur.com/guXUd83.png\" style=\" margin: 3% 10% 0% 3%; width:100%; height:400px; padding-right:15%;\">");
  
  client.print("<a href=\"/GSERVO=ON\"\"><button style=\"margin-bottom: 3%;margin-top: 5%;margin-left: 18%;width: 30%;background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn On</h4> </button></a>");
  client.println("<a href=\"/GSERVO=OFF\"\"><button style=\"margin-bottom: 3%; margin-top: 5%; margin-left: 5%; width: 30%; background: #ddd;\"><h4 style=\"text-align:center;font-size: 200%; color: #5a6dd4;\">Turn Off</h4> </button></a>"); 
  
  client.println("</div>");
  client.println("</div>");
  client.println("</div>");




  client.println("<footer style=\"  background: #4688f1; color:#fff; padding:25px; height: 30px; text-align: center; margin-top: 50%;\"> <ahref=\"https://www.facebook.com/medofadel48\"> Ahmed Fade </a> &copy; </footer>");




   delay(1);
  
}
