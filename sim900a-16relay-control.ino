#include <SoftwareSerial.h>
#include <Keypad.h>

const byte ROWS = 4;  //four rows
const byte COLS = 3;  //three columns

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3 };     //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

SoftwareSerial SIM900A(12, 13);
String r_message;
boolean is_call = false;
String dtmf_cmd;

void setup() {
  SIM900A.begin(9600);  // GSM Module Baud rate - communication speed
  Serial.begin(9600);
  SIM900A.print("AT+CMGF=1\r");  // set SMS mode to text
  delay(100);
  SIM900A.print("AT+CMGD=1,4\r");


  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);

  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);

  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  digitalWrite(37, HIGH);
  delay(15000);
  SendStatusMessage();
}


void loop() {
  if (SIM900A.available() > 0) {
    r_message = SIM900A.readString();
  }

  if (r_message.indexOf("Light01 ON") > -1) {
    // Serial.println("LED-01 ON");
    digitalWrite(22, LOW);
  } else if (r_message.indexOf("Light01 OFF") > -1) {
    // Serial.println("LED-02 OFF");
    digitalWrite(22, HIGH);
  } else if (r_message.indexOf("Light02 ON") > -1) {
    // Serial.println("LED-01 ON");
    digitalWrite(23, LOW);
  } else if (r_message.indexOf("Light02 OFF") > -1) {
    // Serial.println("LED-02 OFF");
    digitalWrite(23, HIGH);
  } else if (r_message.indexOf("Fan ON") > -1) {
    // Serial.println("Fan ON");
    digitalWrite(24, LOW);
  } else if (r_message.indexOf("Fan OFF") > -1) {
    // Serial.println("Fan OFF");
    digitalWrite(24, HIGH);
  } else if (r_message.indexOf("Router ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(25, LOW);
  } else if (r_message.indexOf("Router OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(25, HIGH);
  } else if (r_message.indexOf("Light03 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(26, LOW);
  } else if (r_message.indexOf("Light03 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(26, HIGH);
  } else if (r_message.indexOf("Light04 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(27, LOW);
  } else if (r_message.indexOf("Light04 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(27, HIGH);
  } else if (r_message.indexOf("Light05 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(28, LOW);
  } else if (r_message.indexOf("Light05 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(28, HIGH);
  } else if (r_message.indexOf("Light06 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(29, LOW);
  } else if (r_message.indexOf("Light06 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(29, HIGH);
  } else if (r_message.indexOf("Light07 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(30, LOW);
  } else if (r_message.indexOf("Light07 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(30, HIGH);
  } else if (r_message.indexOf("Light08 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(31, LOW);
  } else if (r_message.indexOf("Light08 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(31, HIGH);
  } else if (r_message.indexOf("Light09 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(32, LOW);
  } else if (r_message.indexOf("Light09 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(32, HIGH);
  } else if (r_message.indexOf("Light10 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(33, LOW);
  } else if (r_message.indexOf("Light10 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(33, HIGH);
  } else if (r_message.indexOf("Light11 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(34, LOW);
  } else if (r_message.indexOf("Light11 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(34, HIGH);
  } else if (r_message.indexOf("Light12 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(35, LOW);
  } else if (r_message.indexOf("Light12 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(35, HIGH);
  } else if (r_message.indexOf("Light13 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(36, LOW);
  } else if (r_message.indexOf("Light13 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(36, HIGH);
  } else if (r_message.indexOf("Light14 ON") > -1) {
    // Serial.println("Router ON");
    digitalWrite(37, LOW);
  } else if (r_message.indexOf("Light14 OFF") > -1) {
    // Serial.println("Router OFF");
    digitalWrite(37, HIGH);
  }


  else if (r_message.indexOf("ALL ON") > -1) {
    // Serial.println("ALL ON");
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
  } else if (r_message.indexOf("ALL OFF") > -1) {
    // Serial.println("ALL OFF");
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
  }
  if (SIM900A.available() > 0) {
    Serial.write(SIM900A.read());
  }
}

void SendMessage(String s_message) {
  Serial.println("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");  //Text Mode initialisation
  delay(1000);
  Serial.println("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+919075706332\"\r");  // Receiver's Mobile Number
  delay(1000);
  Serial.println("Set SMS Content");
  SIM900A.println(s_message);  // Messsage content
  delay(100);
  Serial.println("Done");
  SIM900A.println((char)26);  //   delay(1000);
  Serial.println("Message sent succesfully");
}

void SendStatusMessage() {
  String send_msg = "Your System is ONLINE";
  Serial.println("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");  //Text Mode initialisation
  delay(1000);
  Serial.println("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+919075706332\"\r");  // Receiver's Mobile Number
  delay(1000);
  Serial.println("Set SMS Content");
  SIM900A.println(send_msg);  // Messsage content
  delay(100);
  Serial.println("Done");
  SIM900A.println((char)26);  //   delay(1000);
  Serial.println("Message sent succesfully");
}

void RecieveMessage() {
  Serial.println("Receiving Messeges");
  delay(1000);
  SIM900A.println("AT+CNMI=2,2,0,0,0");  // Eeceiving Mode Enabled
  delay(1000);
  Serial.write("Messege Received Sucessfully");
}
