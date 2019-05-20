void FilamentCalculator_RotaryEncoderClick()
{
  if (PinC == HIGH)
  {

    if (HoldLock)
    {
      countertick = 1;
      lcd.clear();
      count1 = 0, count2 = 0, count3 = 0;

      if (Screen_RemoveWeight)
      {
        tone(9, 700);
        delay(100);
        noTone(9);
        lcd.setCursor(0, 0);
        lcd.print("    ZEROING     ");
        lcd.setCursor(0, 1);
        lcd.print("    SCALE...    ");

        scale.tare();
        tone(9, 600);
        delay(100);
        noTone(9);
        delay(50);
        tone(9, 600);
        delay(100);
        noTone(9);
        Screen_RemoveWeight = false;
        Screen_AddWeight = true;
      }

      else if (Screen_AddWeight)
      {
        tone(9, 700);
        delay(100);
        noTone(9);
        FilamentTotalWeight = scale.get_units() * 1000, 0;

        Screen_AddWeight = false;
        Screen_FilamentSpool = true;
      }

      else if (Screen_FilamentSpool)
      {
        tone(9, 700);
        delay(100);
        noTone(9);
        FilamentSpool = FilamentSpools[FilamentSpoolPosition];
        FilamentSpoolWeight = FilamentSpoolWeights[FilamentSpoolPosition];
        ScrollLock = true;
        SelectionPrevious = 0;
        SelectionNext = 0;

        Screen_FilamentSpool = false;
        Screen_FilamentMaterial = true;
      }

      else if (Screen_FilamentMaterial)
      {
        tone(9, 700);
        delay(100);
        noTone(9);
        FilamentMaterial = FilamentMaterials[FilamentMaterialPosition];
        FilamentMaterialDensity = FilamentMaterialDensities[FilamentMaterialPosition];
        ScrollLock = true;
        SelectionPrevious = 0;
        SelectionNext = 0;

        Screen_FilamentMaterial = false;
        Screen_FilamentDiameter = true;
      }

      else if (Screen_FilamentDiameter)
      {
        tone(9, 700);
        delay(75);
        noTone(9);
        delay(50);
        tone(9, 700);
        delay(100);
        noTone(9);
        FilamentDiameter = FilamentDiameters[FilamentDiameterPosition];
        float FilamentWeightCompensation = (FilamentMaterialDensity * 150)/100;
        float FilamentFinalWeight = FilamentTotalWeight - FilamentSpoolWeight;
        float FilamentFinalMeters = (FilamentFinalWeight / (pi * sq(((FilamentDiameter / 2) / 10)) * FilamentMaterialDensity)) / 100;
        Screen_FilamentDiameter = false;
        Screen_Output = true;
        FilamentOutputWeight = String((FilamentFinalWeight- FilamentWeightCompensation), 0) + "g";
        FilamentOutputMeters = String((FilamentFinalMeters - CompensationFactor), 1) + "m";
        ScrollLock = true;
        SelectionPrevious = 0;
        SelectionNext = 0;
      }

      else if (Screen_Output)
      {
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
        Screen_Output = false;
        Screen_StandBy = true;
        //disable screen
        digitalWrite(PinBacklight, LOW);
        //disable timeout
        TimerStart = false;
      }
      else if (Screen_StandBy)
      {
        
        //reset arduino
        void(* resetFunc) (void) = 0;
        resetFunc();
      }

      HoldLock = false;

    }

  }

  else HoldLock = true;
}
