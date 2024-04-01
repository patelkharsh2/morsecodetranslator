# Pull the docker image
```bash
docker pull patelkharsh2/duo-sdk:latest
```
---
# Building Test files

```bash
py build.py cmake -DCMAKE_TOOLCHAIN_FILE="/app/milkv_duo.cmake" ..
```

```bash 
py build.py cmake --build . 
```

### To upload the the Milk-V Duo
```bash
scp build/test root@192.168.42.1:/root/
```
---
# Building in Release mode
```bash 
py build.py cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_TOOLCHAIN_FILE="/app/milkv_duo.cmake" ..
```
```bash 
py build.py cmake --build . 
```

### To upload the the Milk-V Duo
```bash
scp build/morse_blink_led root@192.168.42.1:/root/
```


**Disable the blink**
```bash
mv /mnt/system/blink.sh /mnt/system/blink.sh_backup && sync
```


**Enable the blink**
```bash
mv /mnt/system/blink.sh_backup /mnt/system/blink.sh && sync
```
*run on milk-v duo and reboot after running*
