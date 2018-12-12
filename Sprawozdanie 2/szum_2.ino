#define echoPin 11#define trigPin 12#define USE_USBCON#include <ros.h>#include <std_msgs/Int16.h>ros::NodeHandle nh;std_msgs::Int16 str_msg;ros::Publisher chatter('chatter', &str_msg);char hello[13] = "hello world!";short helloInt = 10;void setup() {  nh.initNode();   nh.advertise(chatter);  Serial.begin(9600);   pinMode(trigPin, OUTPUT); //Pin. do którego podłączymy trig jako wyjscie  pinMode(echoPin, INPUT); //a echo, jako wejście }void loop() {  long czas, dystans;   digitalWrite(trigPin, LOw);   delayMicroseconds(2)  digitalWrite(tripPin, HIGH);  delayMicroseconds(10);  digitalWrite(trigPin, LOW);  czas = pulseIn(echoPin, HIGH);  dystans = czas / 58;  Serial.println(dystans);   str_msg.data = dystans;   chatter.publish(&str_msg);  nh.spinOnce();}