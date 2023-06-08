#ifndef _COLOR_LED_HPP
#define _COLOR_LED_HPP

typedef struct __Color {
    int red;
    int green;
    int blue;
} Color;

class ColorLED {
private:
    int rpin;
    int bpin;
    int gpin;

public:
    ColorLED(int rpin, int bpin, int gpin);
    void setColor(Color color);
    void off();
};

#endif
