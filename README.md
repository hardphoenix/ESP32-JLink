# ESP32-JLink Debug And Program In VS Code

### ESP32-IDF In Windows Steps:


1- Download Example Source From My Github: https://github.com/hardphoenix/ESP32-JLink

2- Convert "J-Link" Driver To "WinUSB" Driver With "UsbDriverTool.exe"

3- Open Example Source In VS Code.

4- Install "VsCode Action Buttons" Extentions.

5- If you do not use VSCODE extension "Espressif IDF" -> Check the Python version,
   it should be 3.8.7 - It must be in the path Of Windows

![GetVersionOfPython](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/PythonVer.png)

6- Open Folder Of Project in VSCode And Go To 'File-> Save Workspace As' And Save Your File in Base Directory.

![SaveWorkspace](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/FileWorkspace.png)

7- Open Your File *.code-workspace  and edit it Whit These lines:

```json
"actionButtons": 
{
        "defaultColor": "FF0033",
        "loadNpmCommands": false,
        "reloadButton": "🍕",
        "commands": 
        [
            {
                "name": "Build",
                "command": "idf.py build",
                "color": "orange"
            },
            {
                "name": "Jlink-Flash",
                "command": "openocd -f interface/jlink.cfg -c \"adapter speed 20000\" -f target/esp32.cfg -c \"program_esp32 build/GPIO.bin 0x10000 verify reset exit\"",
                "color": "yellow"
            },
            {
                "name": "Run & Monitor",
                "command": "idf.py -p COM* flash monitor",
                "color": "orange"
            },
            {
                "name": "Menuconfig",
                "command": "start idf.py menuconfig",
                "color": "yellow"
            }
        ]
},

```

![OpenWorkSpaceAndEditing](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/edit.png)

After refresh Button:

8-open ".vscode" Folder in VSCode edit Line:14 in launch.json And Set Your ESP-IDF GDB.exe Directory And Save it.

![refresh](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/refresh.png)

![luanch-json](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/gdbpath.png)

9- To compile the program, just press the "build" button.

10- Connect Jlink To ESP32 Board

11- To flash and monitor as COM Port, edit the COM port in the "GPIO.code-workspace" And Refresh Button With "🍕" Pizza Icon.

![ComEdit](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/editCom.png)

Refresh Buttons:

![refresh](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/refresh.png)

12- To Flash And Verify Wtih Jlink Jtag Port 3 File (bootloader.bin , partition_table.bin , GPIO.bin)

13- To Debug ESP32 You Can Go Left Side VSCode Debug Section And Select "ESP32 JTAG" and Click "▶" Button.

![debug](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/debug.png)

### Wiring ESP32 And Jtag Port:

![Wiring:](https://github.com/hardphoenix/ESP32-JLink/blob/main/image/ESP32-JLINK_Wiring.png)


## You can see the video of the above steps in one of the following links:

[ESP32-jLink](It is being uploaded to Aparat)


## Contact ME:
[GITHUB](https://github.com/hardphoenix)

[Telegram](https://t.me/mhtaheri_ir)

## License
[GNU GENERAL PUBLIC LICENSE](https://github.com/hardphoenix/ESP32-JLink/blob/main/LICENSE)