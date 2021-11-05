# KUBOT_LED_CONTROL

### Dependency
```sh
pip install pyserial   

# if pip not found, use pip3 instead
pip3 install pyserial
```

### LED Example

```sh
python led_control.py --port /dev/kubot_led --mode 6
```

You can look into `led_control.py` to see what else functions you can use to write your own program.

### ROS Example

Use ROS launch file to run LED python [scripts]()
```xml
<launch>
	<node name="led_control" pkg="kubot_ws2812" type="led_control.py" args="-p /dev/kubot_led -m 5">
	</node>
</launch>
```

### Raspberry Pi

```sh
sudo pip install rpi_ws281x
```

```sh
	roslaunch kubot_ws2812 raspberrypi_led_control.launch
```