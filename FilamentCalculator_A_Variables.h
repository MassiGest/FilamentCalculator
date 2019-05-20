//Pin input
int PinALast  = LOW;
int PinA      = LOW;
int PinB      = LOW;
int PinC      = LOW;

//Pin to toggle screen on/off
int PinBacklight = 8;

//Loadcell input
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);

//lcd pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

//Prevention for holding the click button
bool HoldLock = true;
//Prevention for scroll thing
bool ScrollLock = true;

//Timer
auto timer = timer_create_default();
auto timeout = timer_create_default();

bool LCDRefresh = false;
bool TimerStart = true;

int countertick = 1;

//Menu Walkthrough
bool Screen_RemoveWeight      = true;
bool Screen_AddWeight         = false;
bool Screen_FilamentSpool     = false;
bool Screen_FilamentMaterial  = false;
bool Screen_FilamentDiameter  = false;
bool Screen_Output            = false;
bool Screen_StandBy           = false;

//Output values as strings
String FilamentOutputMeters = "";
String FilamentOutputWeight = "";

//for centering text
int Startposition = 0;

//Scroll throught strings
int count1 = 0;
int count2 = 0;
int count3 = 0;

float pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914;
