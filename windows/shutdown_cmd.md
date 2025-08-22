# Shutdown
# 1. Immediate Shutdown — shutdown_now.bat
```
@echo off
shutdown /s /t 0

```
### - /s = shutdown
### - /t 0 = wait 0 seconds before shutdown

# 2. Shutdown at 6 PM — shutdown_at_6pm.bat
```
@echo off
REM Cancel any previous shutdown schedules
shutdown /a

REM Schedule shutdown for 6:00 PM (18:00)
schtasks /create /sc once /tn "ShutdownAt6PM" /tr "shutdown /s /t 0" /st 18:00 /f
echo Shutdown scheduled for 6:00 PM today.
pause

```
### - This uses Task Scheduler to run the shutdown command at 6 PM today.
### - /f forces overwrite if a task with the same name exists.
### - /a aborts any previously scheduled shutdowns before scheduling the new one.
