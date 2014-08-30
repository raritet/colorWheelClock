//  Color Wheel Clock
//  Displays the time as a color on the color wheel.
//  Yellow is at 12:00, with cooler colors to the right.

//  GLOBAL VARIABLES
int hour = 0;
int minute = 0;
int red = 0;
int green = 0;
int blue = 0;
float decimalTime = 0.0;

//  SETUP FUNCTION
void setup() {
    //  Take control of the RGB LED.
    RGB.control(true);
    //  Set the time zone of the device to Eastern Daylight Time.
    Time.zone(-5);
}

//  MAIN PROGRAM LOOP
void loop() {
    //  What time is it?
    hour = Time.hourFormat12();
    minute = Time.minute();
    //  Convert this time to a decimal to simplify the color conversion (6:30 = 6.5).
    decimalTime = hour + minute/60;
    //  Convert the time into a color.
    //  This is divided into 4 intervals based on my analysis of the color wheel.
    if((decimalTime >= 8.0) && (decimalTime < 12.0)) {
        red = map(decimalTime, 8, 12, 255, 127);
        green = map(decimalTime, 8, 12, 0, 127);
        blue = 0;
    }
    else if((decimalTime >= 12.0) && (decimalTime < 13.0)) {
        red = map(decimalTime, 12, 13, 127, 63);
        green = map(decimalTime, 12, 13, 127, 191);
        blue = 0;
    }
    else if((decimalTime >= 1.0) && (decimalTime < 2.0)) {
        red = map(decimalTime, 1, 2, 63, 0);
        green = map(decimalTime, 1, 2, 191, 255);
        blue = 0;
    }
    else if((decimalTime >= 2.0) && (decimalTime < 4.0)) {
        red = 0;
        green = map(decimalTime, 2, 4, 255, 0);
        blue = map(decimalTime, 2, 4, 0, 255);
    }
    else if((decimalTime >= 4.0) && (decimalTime < 8.0)) {
        red = map(decimalTime, 4, 8, 0, 255);
        green = 0;
        blue = map(decimalTime, 4, 8, 255, 0);
    }
    //  Show the color on the built-in RGB LED.
    RGB.color(red, green, blue);
}
