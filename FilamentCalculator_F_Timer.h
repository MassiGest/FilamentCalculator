void FilamentCalculator_Timer()
{
  lcd.clear();
  LCDRefresh = true;
}
void FilamentCalculator_Timeout()
{
  Serial.println(countertick);
  if (countertick > TimeOutSec) {
    //shutdown sound
    tone(9, 700);
    delay(100);
    tone(9, 600);
    delay(100);
    tone(9, 500);
    delay(100);
    tone(9, 400);
    delay(100);
    tone(9, 300);
    delay(200);
    noTone(9);
    //go to blank screen to simulate stand by.
    Screen_RemoveWeight      = false;
    Screen_AddWeight         = false;
    Screen_FilamentSpool     = false;
    Screen_FilamentMaterial  = false;
    Screen_FilamentDiameter  = false;
    Screen_Output            = false;
    Screen_StandBy           = true;
    //disable screen
    digitalWrite(PinBacklight, LOW);
    //disable timeout
    TimerStart = false;
  }
  //give notification if timeout is about to happen
  else if(countertick == (TimeOutSec - 10)){
    tone(9, 700);
    delay(75);
    noTone(9);
    delay(50);
    tone(9, 700);
    delay(75);
    noTone(9);
    delay(50);
    tone(9, 700);
    delay(100);
    noTone(9);
    countertick++;
  }
  else {
    countertick++;

  }
}
