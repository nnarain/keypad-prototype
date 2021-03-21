# Design Summary

This board support a 3x3 key matrix and an OLED display.

Schematics can be found [here](./_generated/keyboard.pdf).

Key Matrix
----------

A key matrix is used to optimized the number of GPIO required to read key presses. In this case 6 GPIO are needed to
read 9 keys.

Column GPIO are outputs and Row GPIO are inputs (with a pull-up resistor).

Columns are pulled LOW to select the column and Rows are read to determine which keys are pressed.

Diodes are placed together with each switch. This is to prevent "ghosting", where a combination of key presses results
in the micro controller reading key presses for switch that are not pressed.


Micro Controller
----------------

The Pro Micro has more then enough GPIO to support a 9 key matrix and it is very popular in the DIY keyboard space.
