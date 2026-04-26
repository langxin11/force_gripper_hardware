#include <Dynamixel2Arduino.h>

// --- Constants ---

// On OpenRB-150, the DXL serial port is Serial1
#define DXL_SERIAL Serial1
// The DIR pin is not needed for OpenRB-150
const int DXL_DIR_PIN = -1; 

// Motor IDs for this sensor board
const uint8_t DXL_ID_3 = 3;
const uint8_t DXL_ID_4 = 4;

// Communication Baud Rate
const int BAUDRATE = 57600;

// Create Dynamixel2Arduino object
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

// This namespace is required to use control table item names like PRESENT_LOAD
using namespace ControlTableItem;

void setup() {
  // Start the USB Serial for communication with the PC
  // This baud rate must match the Python script's BAUD RATE.
  Serial.begin(115200);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
  // while (!Serial); // Wait for Serial Monitor to connect

  // Start the Dynamixel bus
  dxl.begin(BAUDRATE);
  // Set the protocol version to 2.0
  dxl.setPortProtocolVersion(2.0);

  uint8_t dxl_ids[] = {DXL_ID_3, DXL_ID_4};
  for (int i = 0; i < 2; i++) {
    uint8_t dxl_id = dxl_ids[i];
    
    if (dxl.ping(dxl_id)) {
      // Successfully found motor
    } else {
      // Failed to find motor, stop here
      while(1);
    }

    // Set Operating Mode to Position Control (Mode 3)
    dxl.writeControlTableItem(OPERATING_MODE, dxl_id, 3);
    
    // Read the current position
    int32_t initial_position = dxl.readControlTableItem(PRESENT_POSITION, dxl_id);

    // Set the current position as the goal position to hold it
    dxl.writeControlTableItem(GOAL_POSITION, dxl_id, initial_position);
    
    // Enable Torque
    dxl.writeControlTableItem(TORQUE_ENABLE, dxl_id, 1);
  }
}

void loop() {
  // 1. Read the PRESENT_LOAD value for both motors first
  int16_t load3 = dxl.readControlTableItem(PRESENT_LOAD, DXL_ID_3);
  int16_t load4 = dxl.readControlTableItem(PRESENT_LOAD, DXL_ID_4);
  
  // 2. --- KEY CHANGE ---
  // Construct a single string in the format "L3:value,L4:value"
  // This format is required by the Python script.
  Serial.print("L3:");
  Serial.print(load3);
  Serial.print(",L4:");
  // Use println() on the last part to send the newline character,
  // which tells Python the message is complete.
  Serial.println(load4);
  
  // A small delay to control the data rate. 10ms = ~100Hz
  delay(10); 
}
