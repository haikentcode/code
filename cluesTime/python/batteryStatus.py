import psutil

battery = psutil.sensors_battery()

print("my battery have this much power -->",battery.percent)
