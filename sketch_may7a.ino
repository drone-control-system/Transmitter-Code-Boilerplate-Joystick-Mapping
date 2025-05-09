// Define control packet structure
struct ControlPacket {
  int throttle;
  int yaw;
  int pitch;
  int roll;
};

// Create packet instance
ControlPacket packet;

// Analog pins
const int throttlePin = A0;
const int yawPin = A1;
const int pitchPin = A3;
const int rollPin = A4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read joystick values
  int rawThrottle = analogRead(throttlePin);
  int rawYaw = analogRead(yawPin);
  int rawPitch = analogRead(pitchPin);
  int rawRoll = analogRead(rollPin);

  // Map to 1000–2000 range
  packet.throttle = map(rawThrottle, 0, 1023, 1000, 2000);
  packet.yaw = map(rawYaw, 0, 1023, 1000, 2000);

  // Static placeholders
  packet.pitch = map(rawPitch, 0, 1023, 1000, 2000);
  packet.roll = map(rawRoll, 0, 1023, 1000, 2000);

  // Print to Serial
  Serial.print("Throttle: "); Serial.print(packet.throttle);
  Serial.print(" | Yaw: "); Serial.print(packet.yaw);
  Serial.print(" | Pitch: "); Serial.print(packet.pitch);
  Serial.print(" | Roll: "); Serial.println(packet.roll);

  // Send packet over Serial
  delay(500);
}
