#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Simple test script to read and print data from the teleoperator serial port.
This matches the format sent by teleoperator.ino: "L3:value,L4:value"
"""

import serial
import time
import sys
import os

# Try to import utility to find port
try:
    # Add the project root to path so we can import force_gripper
    sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
    import force_gripper.utils
    HAS_UTILS = True
except ImportError:
    HAS_UTILS = False

def main():
    port_name = None
    baud_rate = 115200 # Must match Serial.begin(115200) in teleoperator.ino

    # 1. Try to find the port automatically
    if HAS_UTILS:
        try:
            port_name = force_gripper.utils.find_port_by_name("teleoperator")
            print(f"Find teleoperator port: {port_name}")
        except Exception as e:
            print(f"Could not find port via utils: {e}")
    
    # 2. If not found, ask user or use default
    if not port_name:
        if len(sys.argv) > 1:
            port_name = sys.argv[1]
        else:
            print("\nUsage: python test_teleoperator_serial.py [port_name]")
            print("Example: python test_teleoperator_serial.py /dev/ttyUSB0 (Linux) or COM3 (Windows)")
            input_port = input("\nEnter port name manually (or press Enter for /dev/ttyACM0): ").strip()
            port_name = input_port if input_port else "/dev/ttyACM0"

    print(f"Connecting to {port_name} at {baud_rate} baud...")

    try:
        # 3. Open serial port
        ser = serial.Serial(port_name, baud_rate, timeout=1)
        time.sleep(2) # Wait for Arduino to reset
        ser.flushInput()

        # Send an empty character to the device after connection
        ser.write('\n'.encode('utf-8'))

        print("Successfully connected. Reading data (Press Ctrl+C to stop)...\n")

        while True:
            if ser.in_waiting > 0:
                # Read a line from serial
                line = ser.readline().decode('utf-8', errors='replace').strip()
                if line:
                    # Print raw line
                    timestamp = time.strftime("[%H:%M:%S]")
                    print(f"{timestamp} RX: {line}")
                    
                    # Optional: Parse the data to verify format
                    if "L3:" in line and "L4:" in line:
                        try:
                            # Expected format: L3:value,L4:value
                            parts = line.split(',')
                            l3_val = parts[0].split(':')[1]
                            l4_val = parts[1].split(':')[1]
                            # print(f"  -> Parsed Load - L3: {l3_val}, L4: {l4_val}")
                        except Exception:
                            pass

    except serial.SerialException as e:
        print(f"Serial Error: {e}")
    except KeyboardInterrupt:
        print("\nStopping...")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()
            print("Serial port closed.")

if __name__ == "__main__":
    main()
