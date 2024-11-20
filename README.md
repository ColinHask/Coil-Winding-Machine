# Coil-Winding-Machine

Coil winding machine software for custom axiel flux motor manufacturing. The full machine will have a simple LCD screen GUI to enter neccesarry sizing values for the machine to use. One linear actuating stepper motor will move a rotary stepper motor back and forth as it spins coil around a custom-sized motor's bobbin.


## Motors

**NEMA17_linear** is the folder for the horizontal (linear) actuation stepper motor. 
  - This motor with move the *NEMA23_rotary* motor as it spins coils.
> Stepper motor library documentation: https://www.airspayce.com/mikem/arduino/AccelStepper/index.html

   
**NEMA23_rotary** is the folder for the coil spinning stepper motor. 
> Refrence video: https://www.youtube.com/watch?v=FggSRQqB_a4

![wire diagram for NEMA23](https://github.com/ColinHask/Coil-Winding-Machine/blob/main/img/Nema23_wires.png)

<br>

## LCD Screen

**lcd2004a_screen** is the folder for the lcd2004a screen.

This is GUI for the machine and will handle inputs for:
   - Total winding spins
   - Wires in parallel
   - Wire gauge
   - Bobbin width
   - Bobbin Cir

**lcd1602a** is a smaller version of the current screen that may be used for additional display needs.
> Refrence video: https://www.youtube.com/watch?v=BJ93XCcD858
