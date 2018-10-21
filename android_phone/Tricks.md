# Tricks:

There is a table for events!
https://source.android.com/devices/input/keyboard-devices.html
## Input keyevent fun!
By using the `input keyevent #`, sick things happen!

- 82 pops up the wallpapers screen.
- 81 opens up google!
- 26 presses the lock button
- 66 presses enter
- a - z-> 29 - 54

- "0" - "9"-> 7 - 16


## How to unlock the phone:

```
input keyevent 26
input touchscreen swipe 930 880 930 380
```

## Put text onto the screen
```
input text xxxx
The second option is on up swipe.
```

## Logging In with 1234
```
input keyevent 26
input text 1234
input keyevent 66
```


You can just go crazy with this one!
