void FilamentCalculator_MenuWalkthrough()
{

  if (Screen_RemoveWeight)//============================================================================Remove Weight
  {
    FilamentTotalWeight = scale.get_units() * 1000, 0;
    lcd.setCursor(0, 0);
    lcd.print("Please remove");
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("any mass:");
    lcd.print("                ");
    lcd.setCursor(9, 1);
    lcd.print(" ");
    lcd.print(FilamentTotalWeight, 0);
    lcd.print("g");
  }

  else if (Screen_AddWeight)//============================================================================Add Weight
  {
    String test1 = String(scale.get_units() * 1000, 0);
    if (test1.startsWith("-"))FilamentTotalWeight = 0;
    else FilamentTotalWeight = scale.get_units() * 1000, 0;
    lcd.setCursor(0, 0);
    lcd.print("Please add a");
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("fillament:");
    lcd.print("                ");
    lcd.setCursor(10, 1);
    lcd.print(" ");
    lcd.print(FilamentTotalWeight, 0);
    lcd.print("g");
  }

  else if (Screen_FilamentSpool)//============================================================================Spool
  {
    timer.tick();

    if (ScrollLock) {
      SelectionPrevious = FilamentSpoolPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = FilamentSpoolLength;
      SelectionNext = FilamentSpoolPosition + 1;
      if (SelectionNext > FilamentSpoolLength)SelectionNext = 0;
      ScrollLock = false;
    }
    if (LCDRefresh)lcd.clear();

    //current
    //Round odd numbers up
    if (FilamentMaterial.length() % 2)Startposition = 16 / 2 - (FilamentSpool.length() + 1) / 2;
    else Startposition = 16 / 2 - FilamentSpool.length() / 2;
    if (FilamentSpool.length() < 16) {
      lcd.setCursor(Startposition, 0);
      lcd.print(FilamentSpool);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 0);
      lcd.print(FilamentSpool.substring(count1, count1 + 16));
      count1++;
      if (count1 > FilamentSpool.length() - 16)count1 = 0;

    }

    //previous
    if (FilamentSpools[SelectionPrevious].length() < 8) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentSpools[SelectionPrevious]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentSpools[SelectionPrevious].substring(count2, count2 + 7));
      count2++;
      if (count2 > FilamentSpools[SelectionPrevious].length() - 7)count2 = 0;
    }

    //divider
    lcd.setCursor(7, 1);
    lcd.print("<>");

    //next
    if (FilamentSpools[SelectionNext].length() < 8) {
      lcd.setCursor(16 - FilamentSpools[SelectionNext].length(), 1);
      lcd.print(FilamentSpools[SelectionNext]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(9, 1);
      lcd.print(FilamentSpools[SelectionNext].substring(count3, count3 + 7));
      count3++;
      if (count3 > FilamentSpools[SelectionNext].length() - 7)count3 = 0;
    }
    LCDRefresh = false;
  }

  else if (Screen_FilamentMaterial)//============================================================================Material
  {
    timer.tick();

    if (ScrollLock) {
      SelectionPrevious = FilamentMaterialPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = FilamentMaterialLength;
      SelectionNext = FilamentMaterialPosition + 1;
      if (SelectionNext > FilamentMaterialLength)SelectionNext = 0;
      ScrollLock = false;
    }

    //current
    //Round odd numbers up
    if (FilamentMaterial.length() % 2)Startposition = 16 / 2 - (FilamentMaterial.length() + 1) / 2;
    else Startposition = 16 / 2 - FilamentMaterial.length() / 2;

    if (FilamentMaterial.length() < 16) {
      lcd.setCursor(Startposition, 0);
      lcd.print(FilamentMaterial);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 0);
      lcd.print(FilamentMaterial.substring(count1, count1 + 16));
      count1++;
      if (count1 > FilamentMaterial.length() - 16)count1 = 0;

    }

    //previous
    if (FilamentMaterials[SelectionPrevious].length() < 8) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentMaterials[SelectionPrevious]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentMaterials[SelectionPrevious].substring(count2, count2 + 7));
      count2++;
      if (count2 > FilamentMaterials[SelectionPrevious].length() - 7)count2 = 0;
    }

    //divider
    lcd.setCursor(7, 1);
    lcd.print("<>");

    //next
    if (FilamentMaterials[SelectionNext].length() < 8) {
      lcd.setCursor(16 - FilamentMaterials[SelectionNext].length(), 1);
      lcd.print(FilamentMaterials[SelectionNext]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(9, 1);
      lcd.print(FilamentMaterials[SelectionNext].substring(count3, count3 + 7));
      count3++;
      if (count3 > FilamentMaterials[SelectionNext].length() - 7)count3 = 0;
    }
    LCDRefresh = false;
  }

  else if (Screen_FilamentDiameter)//============================================================================Diameter
  {

    timer.tick();

    if (ScrollLock) {
      SelectionPrevious = FilamentDiameterPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = FilamentDiameterLength;
      SelectionNext = FilamentDiameterPosition + 1;
      if (SelectionNext > FilamentDiameterLength)SelectionNext = 0;
      ScrollLock = false;
    }

    //current
    //Round odd numbers up
    if (String(FilamentDiameter).length() % 2)Startposition = 16 / 2 - (String(FilamentDiameter).length() + 1) / 2;
    else Startposition = 16 / 2 - String(FilamentDiameter).length() / 2;
    if (String(FilamentDiameter).length() < 16) {
      lcd.setCursor(Startposition, 0);
      lcd.print(FilamentDiameter);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 0);
      lcd.print(String(FilamentDiameter).substring(count1, count1 + 16));
      count1++;
      if (count1 > String(FilamentDiameter).length() - 16)count1 = 0;

    }

    //previous
    if (String(FilamentDiameters[SelectionPrevious]).length() < 8) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentDiameters[SelectionPrevious]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 1);
      lcd.print(String(FilamentDiameters[SelectionPrevious]).substring(count2, count2 + 7));
      count2++;
      if (count2 > String(FilamentDiameters[SelectionPrevious]).length() - 7)count2 = 0;
    }

    //divider
    lcd.setCursor(7, 1);
    lcd.print("<>");

    //next
    if (String(FilamentDiameters[SelectionNext]).length() < 8) {
      lcd.setCursor(16 - String(FilamentDiameters[SelectionNext]).length(), 1);
      lcd.print(String(FilamentDiameters[SelectionNext]));
    }
    else if (LCDRefresh) {
      lcd.setCursor(9, 1);
      lcd.print(String(FilamentDiameters[SelectionNext]).substring(count3, count3 + 7));
      count3++;
      if (count3 > String(FilamentDiameters[SelectionNext]).length() - 7)count3 = 0;
    }
    LCDRefresh = false;
  }

  else if (Screen_Output)//============================================================================Output
  {
    timer.tick();

    if (FilamentOutputWeight.startsWith("-"))FilamentOutputWeight = "0g";
    if (FilamentOutputMeters.startsWith("-"))FilamentOutputMeters = "0.0m";


    //header
    lcd.setCursor(0, 0);
    lcd.print("Meters:  Weight:");

    //meters
    if (FilamentOutputMeters.length() < 8) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentOutputMeters);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 1);
      lcd.print(FilamentOutputMeters.substring(count2, count2 + 7));
      count2++;
      if (count2 > FilamentOutputMeters.length() - 7)count2 = 0;
    }

    //weight
    if (FilamentOutputWeight.length() < 8) {
      lcd.setCursor(9, 1);
      lcd.print(FilamentOutputWeight);
    }
    else if (LCDRefresh) {
      lcd.setCursor(9, 1);
      lcd.print(FilamentOutputWeight.substring(count3, count3 + 7));
      count3++;
      if (count3 > FilamentOutputWeight.length() - 7)count3 = 0;
    }
    LCDRefresh = false;
  }
  else if (Screen_StandBy)//============================================================================Stand By
  {
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
}
