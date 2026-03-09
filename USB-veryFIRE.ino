/*
 * Projeto: USB-veryFIRE
 * Descrição: Auditor de Segurança de Sistema baseado em HID para Windows (Desktop, Servidor e OT)
 * Autor: nailtpax 
 * Alvo: Windows 7/10/11 / Windows Server
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

  DigiKeyboard.print("echo Executando USB-veryFIRE...");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Construindo a consulta de registro com códigos HID brutos para as barras invertidas
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

  // 1. Injetando o Pipe (|) -> Shift + \ no layout ABNT2
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  DigiKeyboard.print(" findstr 0x3 ");

  // 2. Operador AND (&&) + caracteres seguros (! e -)
  DigiKeyboard.print("&& echo !!! VULNERAVEL - Mass Storage PERMITIDO !!! ");

  // 3. Operador OR (||) -> Injetando dois pipes
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2, MOD_SHIFT_LEFT);
  
  // Caracteres seguros (* e -)
  DigiKeyboard.print(" echo *** COMPLIANT - Mass Storage BLOQUEADO ***");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // O sinal de % funciona nativamente pois Shift+5 é universal
  DigiKeyboard.print("hostname && whoami && echo %date% %time%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
