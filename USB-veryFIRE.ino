/*
 * Project: USB-veryFIRE
 * Description: HID-based System Security Auditor for Windows (Desktop, Server and OT)
 * Author: nailtpax (Pentester Pleno)
 * Target: Windows 7/10/11 / Windows Server
 */

#include "DigiKeyboard.h"

#define KEY_BACKSLASH_ABNT2 100 
#define KEY_SLASH_NUMPAD 84     

void setup() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0); 

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);

  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("echo Running USB-veryFIRE...");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Building the registry query with raw HID codes for the slashes
  DigiKeyboard.print("reg query HKLM");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("SYSTEM");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("CurrentControlSet");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("Services");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("USBSTOR ");
  
  DigiKeyboard.sendKeyStroke(KEY_SLASH_NUMPAD); 
  DigiKeyboard.print("v Start ");

  // 1. Inject Pipe (|) -> Shift + \ in ABNT2
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  DigiKeyboard.print(" findstr 0x3 ");

  // 2. AND operator (&&) + Safe characters (! and -)
  DigiKeyboard.print("&& echo !!! VULNERAVEL - Mass Storage PERMITIDO !!! ");

  // 3. OR operator (||) -> Inject two pipes
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  
  // Safe characters (* and -)
  DigiKeyboard.print(" echo *** COMPLIANT - Mass Storage BLOQUEADO ***");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // The % sign works natively because Shift+5 is universal
  DigiKeyboard.print("hostname && whoami && echo %date% %time%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}