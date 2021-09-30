### Dependency installation on Ubuntu

Install the dependency
```sh
pip install pyserial   # if pip not found, use pip3 instead
```

### Check the function

Now you can verify your new Arduino program by executing the script:

```sh
python led_control.py --port /dev/kubot_led --mode 6
```
