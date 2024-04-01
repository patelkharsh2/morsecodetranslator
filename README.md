# Pull the docker image
```bash
docker pull patelkharsh2/duo-sdk:latest
```

# To build the files:

 (dont have to run this everytime but if you dont have a build folder or made changes to cmake file then run it)
```bash
python3 build.py cmake -DCMAKE_TOOLCHAIN_FILE="/app/milkv_duo.cmake" ..
```

(run this everytime you make changes to the code)
```bash 
python3 build.py cmake --build . 
```


# To upload to the duo:
```bash
scp build/test root@192.168.42.1:/root/
```