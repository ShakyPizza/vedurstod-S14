info.md

---------

!
esptool.py -p /dev/cu.usbserial-110 flash_id
!

| Name      |  Device         |  MAC       | Manuf.  |  Device | Flash size |
|-----------|-----------------|------------|---------|---------|------------|
| Tæki 1    |  ESP32-WROOM-32 |  ...:5e:64 |    68   |   4016  |    4MB     |
| Tæki 2    |  ESP32-WROOM-32 |  ...:3d:2c |    68   |   4016  |    4MB     |
| Tæki 3    |                 |            |         |         |            |
| Tæki 4    |                 |            |         |         |            |
|-----------|-----------------|------------|---------|---------|------------|  


| Name      |  Device         |  MAC       | Manuf.  |  Device | Flash size |
|-----------|-----------------|------------|---------|---------|------------|
| Tæki 1    |  ESP32-WROOM-32 |  ...:5e:64 |    68   |   4016  |    4MB     |
| Tæki 2    |  ESP32-WROOM-32 |  ...:3d:2c |    68   |   4016  |    4MB     |
| Tæki 3    |       -         |     -      |    -    |    -    |     -      |
| Tæki 4    |       -         |     -      |    -    |    -    |     -      |
|-----------|-----------------|------------|---------|---------|------------|  


Tæki 1
---
esptool.py v4.7.0
Serial port /dev/cu.usbserial-110
Connecting......
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting......
Detecting chip type... ESP32
Chip is ESP32-D0WD-V3 (revision v3.1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: c8:2e:18:26:5e:64
Uploading stub...
Running stub...
Stub running...
Manufacturer: 68
Device: 4016
Detected flash size: 4MB
Hard resetting via RTS pin...

Tæki 2
---
esptool.py v4.7.0
Serial port /dev/cu.usbserial-110
Connecting...........
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting....
Detecting chip type... ESP32
Chip is ESP32-D0WD-V3 (revision v3.1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: c8:2e:18:25:3d:2c
Uploading stub...
Running stub...
Stub running...
Manufacturer: 68
Device: 4016
Detected flash size: 4MB
Hard resetting via RTS pin...

