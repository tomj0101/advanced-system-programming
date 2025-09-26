import requests
import time
import os
import subprocess

# Configurations
CHECK_INTERVAL_MINUTES = 20
CHECK_INTERVAL_SECONDS = CHECK_INTERVAL_MINUTES * 60
STATUS_URL = "https://www.githubstatus.com/api/v2/status.json"

def beep():
    # Cross-platform beep
    try:
        # Windows
        if os.name == 'nt':
            import winsound
            winsound.MessageBeep()
        else:
            # macOS / Linux
            print('\a', end='', flush=True)
    except Exception:
        pass

def check_status():
    try:
        resp = requests.get(STATUS_URL, timeout=10)
        resp.raise_for_status()
        data = resp.json()
        status = data['status']['description']  # e.g. "All Systems Operational"
        return status
    except Exception as e:
        return f"ERROR: {e}"

def write_status_file(status_message, now_struct):
    # Filename format: github_status_{YYYYMMDD}.txt
    filename = f"github_status_{now_struct.tm_year}{now_struct.tm_mon:02d}{now_struct.tm_mday:02d}.txt"
    with open(filename, "a") as f:
        f.write(status_message + "\n")
    beep()
    print(f"Status logged to {filename}")

def save_status_history():
    commands = [
        ["git", "status"],
        ["git", "add", "."],
        ["git", "commit", "-m", "update platform status"],
        ["git", "push"]
    ]
    for cmd in commands:
        try:
            subprocess.run(cmd, check=True)
        except Exception as e:
            print(f"Command '{' '.join(cmd)}' failed: {e}")
        time.sleep(1)

def main():
    while True:
        now_struct = time.localtime()
        now_str = time.strftime("%Y-%m-%d %H:%M:%S", now_struct)
        status = check_status()
        if status == "All Systems Operational":
            status_message = f"GitHub Status is  UP {now_str}"
            print(f"[{now_str}] Status: {status}")
        else:
            status_message = f"GitHub Status is NOT UP {now_str}"
            print(f"[{now_str}] ALERT: {status}")
        write_status_file(status_message, now_struct)
        save_status_history()  # <-- function is called here, after writing status and before waiting
        time.sleep(CHECK_INTERVAL_SECONDS)

if __name__ == "__main__":
    main()