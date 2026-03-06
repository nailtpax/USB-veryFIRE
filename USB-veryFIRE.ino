/*
 * Project: USB-veryFIRE
 * Description: HID-based System Security Auditor for Windows (Desktop, Server and OT)
 * Author: nailtpax (Pentester Pleno)
 * Target: Windows 7/10/11 / Windows Server
 */

#include "DigiKeyboard.h"

// Definição de delays para estabilidade em máquinas lentas
#define WAIT_SYSTEM 2000
#define WAIT_SHORT 500

void setup() {
  // Inicializa o pino do LED (geralmente o 1 no Digispark)
  pinMode(1, OUTPUT);
}

void loop() {
  // O Digispark precisa desse comando inicial para ser reconhecido como teclado
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(WAIT_SHORT);

  // 1. Abrir o 'Executar' (Win + R)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(WAIT_SHORT);

  // 2. Chamar o PowerShell em modo tela cheia para a evidência
  // Usamos -NoProfile para evitar scripts de terceiros e carregar mais rápido
  DigiKeyboard.print("powershell -NoProfile -WindowStyle Maximized");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(WAIT_SYSTEM);

  // 3. Coleta de dados e Formatação do Relatório Visual
  // O comando abaixo verifica o registro, identifica o host e formata a saída
  
  // -- Definindo variáveis de auditoria --
  DigiKeyboard.print("$r = Get-ItemProperty 'HKLM:\\SYSTEM\\CurrentControlSet\\Services\\USBSTOR'; ");
  DigiKeyboard.print("$s = if($r.Start -eq 3) {'[ VULNERAVEL ]'} else {'[ PROTEGIDO ]'}; ");
  DigiKeyboard.print("$c = if($r.Start -eq 3) {'Red'} else {'Green'}; ");

  // -- Gerando a interface na tela --
  DigiKeyboard.print("cls; write-host '==================================================' -FG Yellow; ");
  DigiKeyboard.print("write-host '       USB-veryFIRE - AUDITORIA DE SEGURANCA        ' -FG White -BG Blue; ");
  DigiKeyboard.print("write-host '==================================================' -FG Yellow; ");
  DigiKeyboard.print("write-host 'DATA/HORA: ' -NoNewline; Get-Date; ");
  DigiKeyboard.print("write-host 'HOST/ATIVO: ' -NoNewline; hostname; ");
  DigiKeyboard.print("write-host 'USUARIO: ' -NoNewline; whoami; ");
  DigiKeyboard.print("write-host '--------------------------------------------------'; ");
  DigiKeyboard.print("write-host 'STATUS DA PORTA USB: ' -NoNewline; write-host $s -FG $c; ");
  DigiKeyboard.print("write-host 'DETALHE: Driver USBSTOR configurado com Start=' $r.Start; ");
  DigiKeyboard.print("write-host '--------------------------------------------------'; ");
  DigiKeyboard.print("write-host '  EVIDENCIA DE EXECUCAO DE CODIGO VIA DISPOSITIVO HID  ' -FG Black -BG White; ");
  DigiKeyboard.print("write-host '==================================================' -FG Yellow; ");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Finalização: Pisca o LED para indicar que a evidência está pronta para a foto
  for(;;) {
    digitalWrite(1, HIGH);
    DigiKeyboard.delay(200);
    digitalWrite(1, LOW);
    DigiKeyboard.delay(200);
  }
}
