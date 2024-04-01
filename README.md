# Instructions

## Pull the docker image
```bash
docker pull patelkharsh2/duo-sdk:latest
```
---
## Building Test files

Building the project without being in `Release` or `Debug` mode to run the 7 unit tests.
```bash
py build.py cmake -DCMAKE_TOOLCHAIN_FILE="/app/milkv_duo.cmake" ..
```

```bash 
py build.py cmake --build . 
```

### To upload the the Milk-V Duo
Uploading the `test` binary to the microcontroller.
```bash
scp build/test root@192.168.42.1:/root/
```
---
# Building in Release mode
Building the project in `Release` mode to get the morse code blinking on the microcontroller.
```bash 
py build.py cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_TOOLCHAIN_FILE="/app/milkv_duo.cmake" ..
```
```bash 
py build.py cmake --build . 
```

### To upload the the Milk-V Duo
Uploading the `morse_blink_led` binary to the microcontroller.
```bash
scp build/morse_blink_led root@192.168.42.1:/root/
```

**Disable the default blink script**
```bash
mv /mnt/system/blink.sh /mnt/system/blink.sh_backup && sync
```


**Enable the blink script**
```bash
mv /mnt/system/blink.sh_backup /mnt/system/blink.sh && sync
```
*run on milk-v duo and reboot after running*

---
# Challenges

## Morse code logic
- One of the challenges faced was the translated morse code had some random binary data in the beginning of the string. This was ressolved by clearing the first index of the morseOutput: 
```c 
morseOutput[0] = '\0'; 
```

- Another challenge that we faced was getting an accurate number of delays. This was fixed by adding cases to differentiate delays in morse of the same letter and different letters. Also added cases for words as well

## Blink Method
- Figuring out which blink method to utilize for this project was also a challenge that we encountered. We ended up going with WiringX and used their API to blink the LEDs
