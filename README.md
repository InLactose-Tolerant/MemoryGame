How to make the circuit I used...
You need:
- 1 Green LED
- 1 Red LED
- 3 Amber LEDs
- 3 Push Buttons
- 1 Buzzer
- 1 Potentiometer
- 5 Resistors
- 16 male to male wires
- Breadboard
- Arduino UNO

(Obviously you can make changes based on your own preferences, I'll try to address some)

1. Connect the two negative terminals of your bread board using a wire
2. Take a red LED and plug it on one end of the board
3. Connect the longer leg of the LED to pin 11 on the arduino using a wire
4. Connect the other leg to the negative terminal using a resistor
5. Take a green LED and do the same, but this time connect the longer leg to pin 11
6. Take three amber LEDs and plug them near the middle of the breadboard
7. Connect each LEDs longer leg to pins 2,3 and 4 respectively using wires
8. Connect each LEDs shorter leg to the negative terminal of the breadboard using resistors

The colour of the LEDs doesnt matter, and the resistor strength must add to at least 200 ohms - 300 ohms for each LED

9. Take three buttons and plug them in the middle gap of the bread board. Try to place the buttons in front of the LED you want it to control.
10. Connect one pin of each button to pins 6,7 and 8 respectively on the arduino using wires
11. Connect the diagnolly opposite pin of each button to the negative terminal of the breadboard using wires
12. Take a buzzer and place it on the right side of the board
13. Connect the negative wire to the negative terminal of the breadboard

Since the buzzer I have has a resistor in built I can just use a wire. If you don't have a in built resistor OR you dont have a potentiometer, use a resistor to connect the buzzer to the negative terminal

14. Take a potentiometer and plug it in near the buzzer
15. (With the dial facing towards you and the pins pointing to the ground) Connect the right pin of the potentiometer and connect it to pin 13 using a wire
16. Connect the middle pin of the potetiometer to the buzzer's negative positive or signal wire

The potentiometer is just for adjusting the volume, you don't really need it, neither do you need the buzzer,  but if you can add the buzzer I reccomend it, it makes it much more entertaining

This is the final circuit
<img width="1440" height="1920" alt="Image" src="https://github.com/user-attachments/assets/4c6910b9-6cfe-4db4-84d8-5e0371257357" />

If you're confused, I made the wires colour coded:
- Buttons have green wires
- Amber LEDs have red wires
- Green and Red LEDs have Saffron wires
- Buzzer and potentiometer circuit have white wires
- Gnd connectors have black wires


If when you run the code the buttons light up the wrong LED, move around the pin variables at the top of the code to match it properly
