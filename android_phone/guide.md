# Story:
Recently, quite a few Android phones released with the Android Debugger Port (adb) still on, with root privileges, on port 5555. So, I thought it was would fun to recreate this!

# Steps to setup:

The first thing I did was these instructions, while using termux on my android phone.
- https://stackoverflow.com/questions/48519847/is-it-possible-to-debug-over-wifi-without-using-any-usb-cable-in-android-studio

After running:
```
su
setprop service.adb.tcp.port 5555
stop adbd
start adbd
```

The android debugger port was setup to be connected to. Remember, using su needs permission from the user to do. The phone needs to be rooted.

# Connecting:

I got the IP address from the settings by going to: WIFI->menu->advanced.

Went to my computer (on the same WIFI) typed `adb connect $IP_address`
Run `adb shell`
Run `su`, to give yourself root privilege to read and write on the system.
The flag is in data/flags/flag

## Common Issues:
- Only one person can be connected to the phone at a time. 

# Bonus:
- Look at Tricks.md for further fun!
