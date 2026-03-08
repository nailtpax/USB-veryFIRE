# USB Storage Security Audit (Digispark)

## Overview

This project demonstrates a simple USB security assessment technique using a Digispark ATtiny85 device configured as a USB HID keyboard.

When connected to a Windows machine, the device automatically executes a command that queries the system registry to determine whether USB mass storage devices are enabled or disabled.

The goal is to produce a clear technical evidence output that can be used during physical security assessments or penetration tests.

---

## What the Script Checks

The script queries the following Windows registry key:

```
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\USBSTOR
```

Specifically the value:

```
Start
```

This value determines whether USB storage devices are allowed.

| Value | Meaning              |
| ----- | -------------------- |
| 0x3   | USB storage enabled  |
| 0x4   | USB storage disabled |

---

## Command Executed

The Digispark injects the following command into the Windows command prompt:

```
reg query HKLM\SYSTEM\CurrentControlSet\Services\USBSTOR /v Start
```

This command prints the registry configuration responsible for USB storage support.

---

## Example Output

```
USB STORAGE AUDIT

HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\USBSTOR
    Start    REG_DWORD    0x3

Nitro5-NCP
nitro5-ncp\nailt
06/03/2026 20:01:26
```

### Interpretation

If the output contains:

```
Start REG_DWORD 0x3
```

The device is considered:

```
USB STORAGE ENABLED
```

Which means removable storage devices can be connected to the system.

---

## Digispark Code

```cpp
#include "DigiKeyboard.h"

void setup() {

  DigiKeyboard.delay(5000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);

  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1500);

  DigiKeyboard.print("echo USB STORAGE AUDIT");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.print("reg query HKLM\\SYSTEM\\CurrentControlSet\\Services\\USBSTOR /v Start");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.print("hostname && whoami && echo %date% %time%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop(){}
```

---

## Use Cases

This technique can be used during:

* Physical penetration tests
* Red team engagements
* Security configuration audits
* Removable media policy validation

The output provides technical evidence showing whether the system allows USB storage devices.

---

## Security Implication

If USB storage is enabled, attackers may:

* Exfiltrate sensitive data
* Introduce malware via removable media
* Bypass network monitoring controls

Organizations should consider enforcing removable media restrictions where appropriate.

---

## Disclaimer

This project is intended only for authorized security testing, research, and educational purposes.

Use only on systems where you have explicit permission to perform security assessments.

Unauthorized use may violate organizational policies or applicable laws.
