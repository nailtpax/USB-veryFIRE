# 🛡️ USB-veryFIRE

**HID-based System Security Auditor for Windows (Desktop, Server and OT)**

O **USB-veryFIRE** é um script para microcontroladores compatíveis com Digispark (ATtiny85) que atua como um dispositivo HID (Teclado). Seu objetivo é auditar de forma rápida e automatizada o status de bloqueio de armazenamento em massa (USB Mass Storage) em sistemas Windows, identificando se a máquina está vulnerável à exfiltração de dados ou infecção via pendrives.

## 🎯 Funcionalidades

* **Auditoria Rápida:** Executa a verificação do registro do Windows em poucos segundos via terminal (`cmd`).
* **Compatibilidade ABNT2:** Utiliza mapeamento de teclas cruas (Raw HID codes) para injetar corretamente barras (`\`), pipes (`|`) e outros caracteres especiais em teclados com layout Português-Brasil (ABNT2).
* **Feedback Imediato:** Retorna no próprio prompt de comando se a máquina auditada está `VULNERÁVEL` (armazenamento permitido) ou `COMPLIANT` (armazenamento bloqueado).
* **Coleta de Evidências:** Imprime automaticamente o hostname, usuário atual (`whoami`), data e hora da execução da auditoria.

## ⚙️ Como Funciona

O script simula o pressionamento de teclas (Win + R) para abrir o Prompt de Comando e injeta a seguinte consulta no registro do Windows:

```cmd
reg query HKLM\SYSTEM\CurrentControlSet\Services\USBSTOR /v Start
```

Em seguida, o script avalia o retorno dessa chave com os operadores `&&` e `||`:
* Se o valor for `0x3` (Manual/Habilitado), o script acusa a vulnerabilidade.
* Caso contrário (geralmente `0x4` para Desabilitado), o sistema é considerado em conformidade (Compliant).

## 🖥️ Exemplos de Output

Abaixo estão exemplos do que será impresso na tela do alvo após a execução automática do script:

### Cenário 1: Máquina Vulnerável (USB Permitido)
```cmd
C:\>echo Running USB-veryFIRE...
Running USB-veryFIRE...

C:\>reg query HKLM\SYSTEM\CurrentControlSet\Services\USBSTOR /v Start | findstr 0x3 && echo !!! VULNERAVEL - Mass Storage PERMITIDO !!! || echo *** COMPLIANT - Mass Storage BLOQUEADO ***
    Start    REG_DWORD    0x3
!!! VULNERAVEL - Mass Storage PERMITIDO !!! 

C:\>hostname && whoami && echo %date% %time%
PC-DESKTOP-01
dominio\usuario
08/03/2026 10:15:30
```

### Cenário 2: Máquina Segura (USB Bloqueado)
```cmd
C:\>echo Running USB-veryFIRE...
Running USB-veryFIRE...

C:\>reg query HKLM\SYSTEM\CurrentControlSet\Services\USBSTOR /v Start | findstr 0x3 && echo !!! VULNERAVEL - Mass Storage PERMITIDO !!! || echo *** COMPLIANT - Mass Storage BLOQUEADO ***
*** COMPLIANT - Mass Storage BLOQUEADO ***

C:\>hostname && whoami && echo %date% %time%
SRV-OT-04
dominio\admin
08/03/2026 10:16:45
```

## 🛠️ Requisitos

* Placa de desenvolvimento **Digispark ATtiny85** (ou compatível).
* **Arduino IDE** configurada com o suporte às placas Digistump.
* Biblioteca `DigiKeyboard.h` (padrão no pacote Digistump).

## 🚀 Instalação e Uso

1. Abra a Arduino IDE.
2. Certifique-se de que a placa "Digispark (Default - 16.5mhz)" está selecionada em `Ferramentas > Placa`.
3. Copie o código-fonte do `USB-veryFIRE` e cole na IDE.
4. Clique em **Upload**.
5. Quando a IDE solicitar, **conecte o Digispark à porta USB** do seu computador.
6. Aguarde a mensagem de sucesso. O dispositivo está pronto para uso.

> **Nota de Execução:** Ao plugar o Digispark em uma máquina alvo, o script possui um `delay` inicial de 5 segundos (`5000ms`) para permitir o reconhecimento dos drivers do teclado pelo sistema operacional antes de iniciar a injeção.

## ⚠️ Aviso Legal

Este projeto foi desenvolvido estritamente para fins de **Auditoria de Segurança** e **Testes de Invasão Autorizados**. O uso desta ferramenta para acessar sistemas ou extrair informações sem o consentimento explícito do proprietário é ilegal. O autor não se responsabiliza pelo uso indevido ou por danos causados por este script.

---
**Autor:** nailtpax  
