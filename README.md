# USB-veryFIRE

**HID-based System Auditor for Windows Environments**
 
## Descrição

O **USB-veryFIRE** é uma ferramenta de auditoria rápida baseada em HID (Human Interface Device) para sistemas Windows. Desenvolvido para o hardware Digispark (ATtiny85), ele permite que um auditor ou pentester colete informações críticas de configuração e segurança de forma automatizada, sem a necessidade de interação manual com periféricos do alvo.

Ao ser conectado, o dispositivo emula um teclado para abrir o console de comando (CMD) e executar uma varredura rápida de identificação do ativo e status das políticas de dispositivos removíveis. O objetivo é gerar uma evidência visual imediata na tela para registro fotográfico em avaliações de segurança física.

## Funcionalidades

* **Compatibilidade Ampla:** Funciona em Windows 7, 10, 11 e Windows Server.
* **Auditoria de Compliance:** Verifica instantaneamente se o serviço de armazenamento USB (`USBSTOR`) está habilitado ou bloqueado via registro.
* **Rastreabilidade de Evidência:** Exibe Hostname, Usuário logado e Timestamp exato na mesma tela para facilitar a documentação de Proof of Concept (PoC).
* **Non-Intrusive:** Não altera arquivos ou configurações do sistema; utiliza apenas comandos de leitura nativos (`reg query`).
* **ABNT2 Layout Bypass:** Código otimizado com Raw HID Scan Codes para contornar problemas de mapeamento de caracteres especiais (`\`, `/`) em teclados configurados para o padrão brasileiro (ABNT2).

## Como Usar

1. Realize o upload do código `.ino` para o seu Digispark utilizando a Arduino IDE.
2. Conecte o Digispark em qualquer porta USB de uma máquina Windows desbloqueada.
3. O script abrirá o Prompt de Comando (CMD) automaticamente e imprimirá o relatório de segurança na tela.
4. Capture a foto da tela com a evidência gerada para compor seu relatório de Pentest ou Auditoria.

## Disclaimer

Este projeto é destinado estritamente para fins de segurança defensiva e ofensiva ética. O uso em sistemas sem autorização explícita é ilegal e de inteira responsabilidade do usuário.

---
**Desenvolvido por nailtpax**