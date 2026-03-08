# USB-veryFIRE

**HID-based System Auditor for Windows Environments**

O **USB-veryFIRE** é uma ferramenta de auditoria rápida baseada em HID (Human Interface Device) desenvolvida para o hardware **Digispark (ATtiny85)**. Ele permite que um auditor ou pentester colete informações críticas de configuração e segurança de forma automatizada, sem a necessidade de interação manual com periféricos do alvo.

## 📖 Descrição

Ao ser conectado, o dispositivo emula um teclado para abrir o Prompt de Comando (CMD) e executar uma varredura rápida de identificação do ativo e status das políticas de dispositivos removíveis. O objetivo principal é gerar uma **evidência visual imediata** na tela para registro fotográfico em avaliações de segurança física e conformidade.

## ✨ Funcionalidades

* **Compatibilidade Ampla:** Funciona em Windows 7, 10, 11 e Windows Server.
* **Auditoria de Compliance:** Verifica instantaneamente se o serviço de armazenamento USB (`USBSTOR`) está habilitado ou bloqueado via registro.
* **Rastreabilidade de Evidência:** Exibe Hostname, Usuário logado e Timestamp exato na mesma tela para facilitar a documentação de Proof of Concept (PoC).
* **Non-Intrusive:** Não altera arquivos ou configurações do sistema; utiliza apenas comandos de leitura nativos (`reg query`).
* **ABNT2 Layout Bypass:** Código otimizado com *Raw HID Scan Codes* para contornar problemas de mapeamento de caracteres especiais (`\`, `/`, `:`) em teclados configurados no padrão brasileiro.

---

## 🖥️ Exemplo de Output (PoC)

Ao conectar o dispositivo em uma máquina alvo, o relatório gerado no terminal seguirá este modelo:

```text
########################################################
#                USB-veryFIRE AUDIT REPORT             #
########################################################

[+] DATA/HORA: 08/03/2026 - 08:45
[+] HOSTNAME:  WORKSTATION-01
[+] USUARIO:   CORP\pente.tester

--------------------------------------------------------
[!] VERIFICANDO STATUS DO USB STORAGE (USBSTOR)
--------------------------------------------------------

HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\USBSTOR
    Start    REG_DWORD    0x3

--------------------------------------------------------
[ANALISE DE COMPLIANCE]
Status 0x3: USB Habilitado (Vulnerável)
Status 0x4: USB Desabilitado (Seguro)
--------------------------------------------------------

AUDITORIA CONCLUIDA. AGUARDANDO REGISTRO FOTOGRAFICO...