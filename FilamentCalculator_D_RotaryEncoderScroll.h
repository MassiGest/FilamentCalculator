void FilamentCalculator_RotaryEncoderScroll()
{
  if ((PinALast == LOW) && (PinA == HIGH))
  {
    lcd.clear();
    count1 = 0, count2 = 0, count3 = 0;
    countertick = 1;

    ScrollLock = true;
    if (Screen_StandBy)
    {
      //reset arduino
        void(* resetFunc) (void) = 0;
        resetFunc();
    }

    else if (Screen_RemoveWeight)
    {
    }


    else if (Screen_AddWeight)
    {

    }

    else if (Screen_FilamentSpool)
    {
      //Reset all stuff on scroll
      count1 = 0, count2 = 0, count3 = 0;

      if (PinB == LOW)
      {
        tone(9, 350);
        delay(75);
        noTone(9);
        if (FilamentSpoolPosition == FilamentSpoolLength)FilamentSpoolPosition = 0;
        else FilamentSpoolPosition++;
        SelectionPrevious = FilamentSpoolPosition - 1;
        if (SelectionPrevious < 0)SelectionPrevious = FilamentSpoolLength;
        SelectionNext = FilamentSpoolPosition + 1;
        if (SelectionNext > FilamentSpoolLength)SelectionNext = 0;
      }

      else
      {
        tone(9, 300);
        delay(75);
        noTone(9);
        if (FilamentSpoolPosition == 0)FilamentSpoolPosition = FilamentSpoolLength;
        else FilamentSpoolPosition--;
      }

      FilamentSpool = FilamentSpools[FilamentSpoolPosition];
      FilamentSpoolWeight = FilamentSpoolWeights[FilamentSpoolPosition];
    }

    else if (Screen_FilamentMaterial)
    {
      //Reset all stuff on scroll
      count1 = 0, count2 = 0, count3 = 0;

      if (PinB == LOW)
      {
        tone(9, 350);
        delay(75);
        noTone(9);
        if (FilamentMaterialPosition == FilamentMaterialLength)FilamentMaterialPosition = 0;
        else FilamentMaterialPosition++;
      }

      else
      {
        tone(9, 300);
        delay(75);
        noTone(9);
        if (FilamentMaterialPosition == 0)FilamentMaterialPosition = FilamentMaterialLength;
        else FilamentMaterialPosition--;
      }
      FilamentMaterial = FilamentMaterials[FilamentMaterialPosition];
    }
    else if (Screen_FilamentDiameter)
    {
      //Reset all stuff on scroll
      count1 = 0, count2 = 0, count3 = 0;

      if (PinB == LOW)
      {
        tone(9, 350);
        delay(75);
        noTone(9);
        if (FilamentDiameterPosition == FilamentDiameterLength)FilamentDiameterPosition = 0;
        else FilamentDiameterPosition++;
      }

      else
      {
        tone(9, 300);
        delay(75);
        noTone(9);
        if (FilamentDiameterPosition == 0)FilamentDiameterPosition = FilamentDiameterLength;
        else FilamentDiameterPosition--;
      }
      FilamentDiameter = FilamentDiameters[FilamentDiameterPosition];

    }

  }
  PinALast = PinA;
}
