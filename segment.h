#ifndef segment_h
#define segment_h

class Segment
{
  public:

    int latchPin;
    int clockPin;
    int dataPin;
    int segment1;
    int segment2;

    byte leds = 0;

    byte zero  =  B11111100;
    byte one   =  B01100000;
    byte two   =  B11011010;
    byte tree  =  B11110010;
    byte four  =  B01100110;
    byte five  =  B10110110;
    byte six   =  B10111110;
    byte seven =  B11100000;
    byte eight =  B11111110;
    byte nine  =  B11110110;
    byte point =  B00000001;


    int unite (int);
    int dizaine (int);
    void clear_All();
    void initial(int a = 4, int b = 3  , int c = 2, int d = 6, int e = 5);
    void zero_f();
    void one_f();
    void two_f();
    void tree_f();
    void four_f();
    void five_f();
    void six_f();
    void seven_f();
    void eight_f();
    void nine_f();
    void point_f();
    void segment_1_run();
    void segment_2_run();
    void screen(int);
    void updateShiftRegister();

};
#endif
