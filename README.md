# x9c
Simple, foolproof Arduino IDE library for x9c potentiometers.
All required code for it to work:

`#include <x9c.h>`

`x9c name; `

`name.begin(CS, INC, UD, startposition);`

Assigns pin numbers to functions and moves wiper to startposition (optional, default value = 0).

`pot.setPot(value);`

Moves wiper of potentiometer to "value" position [0 - 99].

`pot.PotPos();`

Returns current value of potentiometer.
