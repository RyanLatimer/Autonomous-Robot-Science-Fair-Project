import machine
import utime
import random

#Void Setup or Setup Loop

#Define Motors

#Left Motors

#Left Motor Speed

lSpeed = machine.PWM(machine.Pin(17))

#Left Motor Directions

leftMotorForward = machine.Pin(15, Pin.OUT)
leftMotorReverse = machine.Pin(16, Pin.OUT)


#Right Motors

#Right Motor Speed

rSpeed = machine.PWM(machine.Pin(24))

#Right Motor Directions

rightMotorForward = machine.Pin(26, Pin.OUT)
rightMotorReverse = machine.Pin(25, Pin.OUT)

#Define Forward Distance Sensor

fTrig = machine.Pin(2, Pin.OUT)
fEcho = machine.Pin(1, Pin.IN)

#Define Left Distance Sensor

lTrig = machine.Pin(7, Pin.OUT)
lEcho = machine.Pin(6, Pin.IN)

#Define Right Distance Sensor

rTrig = machine.Pin(12, Pin.OUT)
rEcho = machine.Pin(11, Pin.IN)

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

#Define the VOID LOOP Algorithim or the Main Loop Code

while True:
    fUltra()
    lUltra()
    rUltra()
    utime.sleep_us(5)
