#pragma region MainMenu
void onShowMain()
{
  String currPHStr = String("Current PH:");
  currPHStr += currPH;
  currPHStr.toCharArray(secondScreenStr, SCREEN_WIDTH);

  String phRange = String("Low:");
  phRange += String(settings->phLow->getValue(), 2);
  phRange += " High:";
  phRange += String(settings->phHigh->getValue(), 2);
  phRange.toCharArray(thirdScreenStr, SCREEN_WIDTH);

  lcd.clear();
  lcd.printstr(secondScreenStr);
  lcd.setCursor(0, 2);
  lcd.printstr(thirdScreenStr);
}

void onShowSettings()
{
  lcd.clear();
  lcd.printstr("Settings");
}

void onShowPhCalibration()
{
  lcd.clear();
  lcd.printstr("Ph Calibration");
}

void onShowTestPump()
{
  lcd.clear();
  lcd.printstr("Test Pump");
}
#pragma endregion MainMenu

#pragma region SettingsSubmenu
#pragma region Mode
void onShowSetMode()
{
  lcd.clear();
  lcd.printstr("Mode");

  lcd.setCursor(0, 1);
  settings->mode->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightMode()
{
  settings->mode->inc();
  onShowSetMode();
}

void onHoldLeftMode()
{
  settings->mode->dec();
  onShowSetMode();
}
#pragma endregion Mode

#pragma region PhLow
void onShowSetPhLow()
{
  lcd.clear();
  lcd.printstr("PhLow");

  lcd.setCursor(0, 1);
  settings->phLow->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightPhLow()
{
  settings->phLow->inc();
  onShowSetPhLow();
}

void onHoldLeftPhLow()
{
  settings->phLow->dec();
  onShowSetPhLow();
}
#pragma endregion PhLow

#pragma region PhHigh
void onShowSetPhHigh()
{
  lcd.clear();
  lcd.printstr("PhHigh");

  lcd.setCursor(0, 1);
  settings->phHigh->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightPhHigh()
{
  settings->phHigh->inc();
  onShowSetPhHigh();
}

void onHoldLeftPhHigh()
{
  settings->phHigh->dec();
  onShowSetPhHigh();
}
#pragma endregion PhHigh

#pragma region SmallAdjust
void onShowSetSmallAdjust()
{
  lcd.clear();
  lcd.printstr("Small Adjust");

  lcd.setCursor(0, 1);
  settings->smallAdjust->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightSmallAdjust()
{
  settings->smallAdjust->inc();
  onShowSetSmallAdjust();
}

void onHoldLeftSmallAdjust()
{
  settings->smallAdjust->dec();
  onShowSetSmallAdjust();
}
#pragma endregion SmallAdjust

#pragma region LargeAdjust
void onShowSetLargeAdjust()
{
  lcd.clear();
  lcd.printstr("Large Adjust");

  lcd.setCursor(0, 1);
  settings->largeAdjust->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightLargeAdjust()
{
  settings->largeAdjust->inc();
  onShowSetLargeAdjust();
}

void onHoldLeftLargeAdjust()
{
  settings->largeAdjust->dec();
  onShowSetLargeAdjust();
}
#pragma endregion LargeAdjust

#pragma region Delay
void onShowSetDelay()
{
  lcd.clear();
  lcd.printstr("Delay");

  lcd.setCursor(0, 1);
  settings->delay->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightDelay()
{
  settings->delay->inc();
  onShowSetDelay();
}

void onHoldLeftDelay()
{
  settings->delay->dec();
  onShowSetDelay();
}
#pragma endregion Delay

#pragma region LED
void onShowSetLED()
{
  lcd.clear();
  lcd.printstr("LED");

  lcd.setCursor(0, 1);
  settings->LED->getDisplayValue(secondScreenStr);
  lcd.printstr(secondScreenStr);
}

void onHoldRightLED()
{
  settings->LED->inc();
  onShowSetLED();
}

void onHoldLeftLED()
{
  settings->LED->dec();
  onShowSetLED();
}
#pragma endregion LED

#pragma region SaveAll
void onShowSaveAll()
{
  lcd.clear();
  lcd.printstr("Save All");
}

void onClickSaveAll()
{
  settings->saveToMemory();
}
#pragma endregion SaveAll

#pragma region ResetAll
void onShowResetAll()
{
  lcd.clear();
  lcd.printstr("Reset All");
}

void onClickResetAll()
{
  settings->returnToDefault();
}
#pragma endregion ResetAll
#pragma endregion SettingsSubmenu

#pragma region PhCalibrationSubmenu
void onShowCalibratePh4()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph4");
}

void onShowCalibratePh7()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph7");
}

void onShowCalibratePh10()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph10");
}
#pragma endregion PhCalibrationSubmenu

#pragma region TestPumpSubmenu
void onShowPump1()
{
  lcd.clear();
  lcd.printstr("Pump1");
}

void onShowPump2()
{
  lcd.clear();
  lcd.printstr("Pump2");
}
#pragma endregion TestPumpSubmenu

Menu *createMenu()
{
  Menu *mainMenu = new Menu();

  // Create elemnts main menu
  MenuElement *mainScreen = new MenuElement(onShowMain);
  mainScreen->isUpdateble = true;

  MenuElement *settings = new MenuElement(onShowSettings);
  settings->subMenu = new Menu();
  MenuElement *phCalibration = new MenuElement(onShowPhCalibration);
  phCalibration->subMenu = new Menu();
  MenuElement *testPump = new MenuElement(onShowTestPump);
  testPump->subMenu = new Menu();

  // Create settings submenu
  Menu *settingsSubmenu = settings->subMenu;
  settingsSubmenu->add(new MenuElement(onShowSetMode, onHoldRightMode, onHoldLeftMode));
  settingsSubmenu->add(new MenuElement(onShowSetPhLow, onHoldRightPhLow, onHoldLeftPhLow));
  settingsSubmenu->add(new MenuElement(onShowSetPhHigh, onHoldRightPhHigh, onHoldLeftPhHigh));
  settingsSubmenu->add(new MenuElement(onShowSetSmallAdjust, onHoldRightSmallAdjust, onHoldLeftSmallAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetLargeAdjust, onHoldRightLargeAdjust, onHoldLeftLargeAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetDelay, onHoldRightDelay, onHoldLeftDelay));
  settingsSubmenu->add(new MenuElement(onShowSetLED, onHoldRightLED, onHoldLeftLED));
  settingsSubmenu->add(new MenuElement(onShowSaveAll, onClickSaveAll));
  settingsSubmenu->add(new MenuElement(onShowResetAll, onClickResetAll));

  // Create phCalibration submenu
  Menu *phCalibrationSubmenu = phCalibration->subMenu;
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh4));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh7));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh10));

  // Create testPump submenu
  Menu *testPumpSubmenu = testPump->subMenu;
  testPumpSubmenu->add(new MenuElement(onShowPump1));
  testPumpSubmenu->add(new MenuElement(onShowPump2));

  // Fill main menu
  mainMenu->add(mainScreen);
  mainMenu->add(settings);
  mainMenu->add(phCalibration);
  mainMenu->add(testPump);

  return mainMenu;
}
