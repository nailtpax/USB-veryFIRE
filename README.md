# 🛠️ USB-veryFIRE 

**HID-based System Auditor for Windows Environments**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Hardware: Digispark](https://img.shields.io/badge/Hardware-Digispark%20ATtiny85-blue.svg)](http://digistump.com/products/1)

## 📝 Descrição
O **USB-veryFIRE** é uma ferramenta de auditoria rápida baseada em HID (Human Interface Device) para sistemas Windows. Desenvolvido para o hardware **Digispark (ATtiny85)**, ele permite que um auditor ou pentester colete informações críticas de configuração e segurança de forma automatizada, sem a necessidade de interação manual com periféricos do alvo.

Ao ser conectado, o dispositivo emula um teclado para abrir o console e executar uma varredura de privilégios, identificação de ativo e status de políticas de dispositivos removíveis, gerando uma evidência visual imediata na tela para registro fotográfico.

---

## 🚀 Funcionalidades Universais
* **Compatibilidade Ampla:** Funciona em Windows 7, 10, 11 e Windows Server.
* **Auditoria de Compliance:** Verifica instantaneamente se o driver `USBSTOR` está habilitado ou bloqueado via registro.
* **Rastreabilidade de Evidência:** Exibe Hostname, Usuário (com nível de privilégio) e Timestamp na mesma tela.
* **Non-Intrusive:** Não altera arquivos do sistema; utiliza apenas comandos de leitura (`Get-ItemProperty`).
* **Visual Report:** Interface no terminal colorizada para garantir clareza em fotos de relatórios de auditoria.

---

## 📂 Como Usar
1.  Realize o upload do código `.ino` para o seu Digispark.
2.  Conecte em qualquer porta USB de uma máquina Windows desbloqueada.
3.  O script abrirá o PowerShell automaticamente e exibirá o relatório de segurança.
4.  Capture a foto da tela para compor seu relatório de Pentest ou Auditoria.

---

## ⚖️ Disclaimer
Este projeto é destinado estritamente para fins de segurança defensiva e ofensiva ética. O uso em sistemas sem autorização é de inteira responsabilidade do usuário.

---
**Desenvolvido por nailtpax
