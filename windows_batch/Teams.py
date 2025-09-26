import schedule
import time
import webbrowser
import os
from datetime import datetime

# URL for Microsoft Teams
teams_url = "https://teams.microsoft.com/v2/"

# Open Teams at 6:30 AM
def open_teams():
    current_time = datetime.now().time()
    current_day = datetime.now().weekday()  # Monday = 0, Sunday = 6
    if current_day < 5:  # Monday to Friday
        if current_time >= datetime.strptime("06:30", "%H:%M").time() and current_time <= datetime.strptime("17:30", "%H:%M").time():
            print("Opening Microsoft Teams...")
            webbrowser.open(teams_url)

# Close Teams at 5:30 PM
def close_teams():
    current_time = datetime.now().time()
    current_day = datetime.now().weekday()  # Monday = 0, Sunday = 6
    if current_day < 5:  # Monday to Friday
        if current_time > datetime.strptime("17:30", "%H:%M").time():
            print("Closing Microsoft Teams...")
            # Terminate browser processes (this method works for common browsers on Windows)
            os.system("taskkill /im chrome.exe /f")  # Replace with your browser's process name if needed

# Schedule the functions
schedule.every(60).minutes.do(open_teams)
schedule.every(60).minutes.do(close_teams)

print("Starting Teams Scheduler...")
while True:
    schedule.run_pending()
    time.sleep(60)  # Check every minute
