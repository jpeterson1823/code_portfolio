##### Incrementing Loop #####
Description: loop for n iterations and then display n
Default Variables and their locations:
    counter:    0x0
    num    :    0x1

>,                          Move to 0x1 and take user input; then move back to 0x0
[                           While num != 0
    <+                      Move to counter and increment counter
    >-                      Move to num and decrement
]
<.                          Print data at counter after loop ends