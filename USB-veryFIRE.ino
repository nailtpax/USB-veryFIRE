/*
 * Project: USB-veryFIRE
 * Description: HID-based System Security Auditor for Windows (Desktop, Server and OT)
 * Author: nailtpax (Pentester Pleno)
 * Target: Windows 7/10/11 / Windows Server
 */

#include "DigiKeyboard.h"

// Definindo os Scan Codes que resolvem o problema do ABNT2
#define KEY_BACKSLASH_ABNT2 100 // Código HID para a tecla ao lado do Shift esquerdo no ABNT2 (\)
#define KEY_SLASH_NUMPAD 84     // Código HID para a tecla de divisão do Teclado Numérico (Universal)

void setup() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0); // Limpa o estado do teclado para evitar bugs de buffer

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);

  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("echo USB STORAGE AUDIT");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Construindo o comando fatiado para usar os caracteres corretos
  DigiKeyboard.print("reg query HKLM");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("SYSTEM");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("CurrentControlSet");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("Services");
  DigiKeyboard.sendKeyStroke(KEY_BACKSLASH_ABNT2);
  DigiKeyboard.print("USBSTOR ");
  
  DigiKeyboard.sendKeyStroke(KEY_SLASH_NUMPAD); // Injeta a barra /
  DigiKeyboard.print("v Start");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // O % funciona bem porque a combinação Shift+5 é igual em US e ABNT2
  DigiKeyboard.print("hostname && whoami && echo %date% %time%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}