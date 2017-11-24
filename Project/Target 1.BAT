SET PATH=D:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Intel\Shared Libraries\redist\intel64\compiler;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;%USERPROFILE%\.dnx\bin;C:\Program Files\Microsoft DNX\Dnvm\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;D:\Matlab\runtime\win64;D:\Matlab\bin;C:\Users\dengjian\AppData\Local\Microsoft\WindowsApps;C:\Users\dengjian\AppData\Local\GitHubDesktop\bin
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\misc.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\stm32f10x_gpio.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\stm32f10x_rcc.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\stm32f10x_tim.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\stm32f10x_usart.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\core_cm3.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\system_stm32f10x.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "..\output\startup_stm32f10x_md._ia"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\main.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\motor.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\pid.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\ecode.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\output\timer.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "..\Output\Baseboard V1.lnp"
"D:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" "..\Output\Baseboard V1.0" --i32combined --output "..\Output\Baseboard V1.hex"
