#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>


// ============ MOTOR PINS ============

#define AIN1 3
#define AIN2 4

#define BIN1 8
#define BIN2 9



// ============ PWM SETTINGS ============

#define PWM_FREQ 20000
#define PWM_RES 8

#define MIN_PWM 50



// ============ WIFI ============

const char* ssid = "  ";//Name of your esp32c3
const char* password = "";//Password of esp32c3


WebServer server(80);



// ============ FUNCTIONS ============

void motorAForward();
void motorAReverse();
void motorAStop();

void motorBForward();
void motorBReverse();
void motorBStop();

int mapSpeed(int s);



// ================= SETUP =================

void setup()
{

  Serial.begin(115200);

  delay(1000);



  // -------- LittleFS --------

  if(!LittleFS.begin())
  {
    Serial.println("LittleFS Failed");
    return;
  }

  Serial.println("LittleFS Ready");




  // -------- Motor pins --------

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);



  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);



  // -------- ESP32-C3 PWM --------

  ledcAttach(
    AIN1,
    PWM_FREQ,
    PWM_RES
  );


  ledcAttach(
    AIN2,
    PWM_FREQ,
    PWM_RES
  );


  ledcAttach(
    BIN1,
    PWM_FREQ,
    PWM_RES
  );


  ledcAttach(
    BIN2,
    PWM_FREQ,
    PWM_RES
  );



  // -------- WiFi AP --------

  WiFi.mode(WIFI_AP);

  WiFi.softAP(
    ssid,
    password
  );


  Serial.println("WiFi Started");

  Serial.print("IP Address: ");

  Serial.println(
    WiFi.softAPIP()
  );




  // ============ MOTOR ROUTES ============


  server.on(
    "/a/fwd",
    motorAForward
  );


  server.on(
    "/a/rev",
    motorAReverse
  );


  server.on(
    "/a/stop",
    motorAStop
  );



  server.on(
    "/b/fwd",
    motorBForward
  );


  server.on(
    "/b/rev",
    motorBReverse
  );


  server.on(
    "/b/stop",
    motorBStop
  );




  // ============ WEBSITE ============


  server.on(
    "/",
    []()
    {
      File file =
      LittleFS.open(
        "/index.html",
        "r"
      );

      server.streamFile(
        file,
        "text/html"
      );

      file.close();
    }
  );



  server.on(
    "/style.css",
    []()
    {
      File file =
      LittleFS.open(
        "/style.css",
        "r"
      );

      server.streamFile(
        file,
        "text/css"
      );

      file.close();
    }
  );



  server.on(
    "/js.js",
    []()
    {
      File file =
      LittleFS.open(
        "/js.js",
        "r"
      );

      server.streamFile(
        file,
        "application/javascript"
      );

      file.close();
    }
  );



  server.begin();


  Serial.println("Server Started");

}



// ================= LOOP =================


void loop()
{
  server.handleClient();
}






// ================= SPEED MAP =================


int mapSpeed(int s)
{

  s = constrain(
    s,
    0,
    255
  );


  return map(
    s,
    0,
    255,
    MIN_PWM,
    255
  );

}







// ================= MOTOR A =================



void motorAForward()
{

  int s =
  mapSpeed(
    server.arg("s").toInt()
  );


  digitalWrite(
    AIN2,
    LOW
  );


  ledcWrite(
    AIN1,
    s
  );


  server.send(
    200,
    "text/plain",
    "A FORWARD"
  );

}





void motorAReverse()
{

  int s =
  mapSpeed(
    server.arg("s").toInt()
  );


  digitalWrite(
    AIN1,
    LOW
  );


  ledcWrite(
    AIN2,
    s
  );


  server.send(
    200,
    "text/plain",
    "A REVERSE"
  );

}





void motorAStop()
{

  ledcWrite(
    AIN1,
    0
  );


  ledcWrite(
    AIN2,
    0
  );


  digitalWrite(
    AIN1,
    LOW
  );


  digitalWrite(
    AIN2,
    LOW
  );


  server.send(
    200,
    "text/plain",
    "A STOP"
  );

}








// ================= MOTOR B =================



void motorBForward()
{

  int s =
  mapSpeed(
    server.arg("s").toInt()
  );


  digitalWrite(
    BIN2,
    LOW
  );


  ledcWrite(
    BIN1,
    s
  );


  server.send(
    200,
    "text/plain",
    "B FORWARD"
  );

}





void motorBReverse()
{

  int s =
  mapSpeed(
    server.arg("s").toInt()
  );


  digitalWrite(
    BIN1,
    LOW
  );


  ledcWrite(
    BIN2,
    s
  );


  server.send(
    200,
    "text/plain",
    "B REVERSE"
  );

}





void motorBStop()
{

  ledcWrite(
    BIN1,
    0
  );


  ledcWrite(
    BIN2,
    0
  );


  digitalWrite(
    BIN1,
    LOW
  );


  digitalWrite(
    BIN2,
    LOW
  );


  server.send(
    200,
    "text/plain",
    "B STOP"
  );

}
