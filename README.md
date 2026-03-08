USB-veryFIRE 🛡️🔥
HID-based System Auditor for Windows Environments

O USB-veryFIRE é uma ferramenta de auditoria rápida baseada em HID (Human Interface Device) desenvolvida para o hardware Digispark (ATtiny85). Ele permite que um auditor ou pentester colete informações críticas de configuração e segurança de forma automatizada, sem a necessidade de interação manual com periféricos do alvo.

📖 Descrição
Ao ser conectado, o dispositivo emula um teclado para abrir o Prompt de Comando (CMD) e executar uma varredura rápida de identificação do ativo e status das políticas de dispositivos removíveis. O objetivo principal é gerar uma evidência visual imediata na tela para registro fotográfico em avaliações de segurança física e conformidade (Compliance).

✨ Funcionalidades
Compatibilidade Ampla: Suporte total a Windows 7, 10, 11 e Windows Server.

Auditoria de Compliance: Verifica o status do serviço USBSTOR diretamente no registro do Windows.

Rastreabilidade: Consolida Hostname, Usuário e Timestamp em um único relatório visual.

Non-Intrusive: Operação baseada em comandos nativos (reg query), sem alteração de arquivos no disco.

ABNT2 Layout Bypass: Implementação via Raw HID Scan Codes para evitar erros de digitação em teclados brasileiros (problemas com /, \ e :).

🖥️ Exemplo de Output (PoC)
Ao conectar o dispositivo, o terminal exibirá o seguinte relatório:

Plaintext
########################################################
#                USB-veryFIRE AUDIT REPORT             #
########################################################

[+] DATA/HORA: 08/03/2026 - 09:00
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
🚀 Como Usar
Build: Realize o upload do código .ino para o seu Digispark via Arduino IDE.

Deploy: Conecte o dispositivo em uma porta USB de uma máquina Windows desbloqueada.

Execução: O dispositivo abrirá o CMD e digitará os comandos automaticamente.

Registro: Capture a foto da evidência para o seu relatório final.

⚠️ Disclaimer
Este projeto é destinado estritamente para fins de segurança defensiva e ofensiva ética. O uso em sistemas sem autorização explícita é ilegal e de inteira responsabilidade do usuário.
