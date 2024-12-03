import machine
import utime
import random
import os

#Void Setup or Setup Loop

#Define Motors

#Left Motors

#Left Motor Directions

leftMotorForward = PWM(PIN(14))
leftMotorReverse = PWM(PIN(15))

leftMotorForward.freq(1000)
leftMotorForward.freq(1000)
## Right Motors

#Right Motor Directions

rightMotorForward = PWM(PIN(26))

rightMotorForward.freq(1000)

#Define Forward Distance Sensor

fTrig = machine.Pin(2, machine.Pin.OUT)
fEcho = machine.Pin(1, machine.Pin.IN)

#Define Left Distance Sensor

lTrig = machine.Pin(7, machine.Pin.OUT)
lEcho = machine.Pin(6, machine.Pin.IN)

#Define Right Distance Sensor

rTrig = machine.Pin(19, machine.Pin.OUT)
rEcho = machine.Pin(18, machine.Pin.IN)

#Define Forward Distance Algorithm

def fUltra():

    #Ensure Sensor is Off

    fTrig.low()
    utime.sleep_us(2)
    
    #Trigger

    fTrig.high()
    utime.sleep_us(5)
    fTrig.low()

    # Check if no echo is recieved

    while fEcho.value() == 0:
        signaloff = utime.ticks_us
    
    # Check if echo is recieved

    while fEcho.value() == 1:
        signalon = utime.ticks_us()
    
    # Calculate Time Passed

    timepassed = signalon - signaloff
    
    # Calculate Distance 

    distance = (timepassed * 0.0343) / 2
    print("Distance ahead : ", distance, " cm")
    return distance
#Define Left Distance Algorithm

def lUltra():


    #Ensure Sensor is Off

    lTrig.low()
    utime.sleep_us(2)
    
    #Trigger

    lTrig.high()
    utime.sleep_us(5)
    lTrig.low()

    # Check if no echo is recieved

    while lEcho.value() == 0:
        signaloff = utime.ticks_us
    
    # Check if echo is recieved

    while lEcho.value() == 1:
        signalon = utime.ticks_us()
    
    # Calculate Time Passed

    timepassed = signalon - signaloff

    # Calculate Distance 

    distance = (timepassed * 0.0343) / 2
    print("Distance to the Left: ", distance, " cm")
    return distance

#Define Right Distance Algorithm

def rUltra():

    #Ensure Sensor is Off

    rTrig.low()
    utime.sleep_us(2)
    
    #Trigger

    rTrig.high()
    utime.sleep_us(5)
    rTrig.low()

    # Check if no echo is recieved

    while rEcho.value() == 0:
        signaloff = utime.ticks_us
    
    # Check if echo is recieved

    while rEcho.value() == 1:
        signalon = utime.ticks_us()
    
    # Calculate Time Passed

    timepassed = signalon - signaloff

    # Calculate Distance 

    distance = (timepassed * 0.0343) / 2
    print("Distance to the Left: ", distance, " cm")
    return distance

# Define Control Methods

def stop():
    leftMotorForward.duty(0)
    leftMotorReverse.duty(0)
    rightMotorForward.duty(0)

def forward():
    leftMotorReverse.duty(0)
    leftMotorForward.duty(1)
    rightMotorForward.duty(1)

    utime.sleep(0.1)

def rotateLeft():
    leftMotorForward.duty(0)
    leftMotorReverse.duty(1)
    rightMotorForward.duty(1)
    # Wait Time for 90 Degree Rotation. This is currently just filler:
    utime.sleep(5)
    leftMotorReverse.duty(0)
    rightMotorForward.duty(0)

def rotateRight():
    leftMotorForward.duty(0)
    leftMotorReverse.duty(1)
    rightMotorForward.duty(1)
    # Wait Time for 270 Degreee Rotation is unknown. This is just filler.
    utime.sleep(15)
    leftMotorReverse.duty(0)
    rightMotorForward.duty(0)

# Define the detect algorithms
def detectDistance():
        fUltra()
        lUltra()
        rUltra()
        utime.sleep_us(5)

        if fUltra > 2:
            forward()
        elif fUltra <= 2: # Maybe this should be larger
            stop()
            if lUltra > rUltra:
                rotateLeft()
            elif rUltra > rUltra:
                rotateRight()
            else:
                print("Error in Comparing R and L Distance Sensors")
        else:
            print("Error in comparing forward distance to 2cm")


# Define the VOID LOOP Algorithim or the Main Loop Code
if __name__ == "__main__":   
    while True:
        detectDistance()
    