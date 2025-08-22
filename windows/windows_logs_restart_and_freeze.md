# Windows Logs: Restart and Freeze (Hang) Monitoring via PowerShell

This README provides step-by-step PowerShell commands to check **restart/shutdown logs** and **application freeze/hang logs** in Windows.  
Useful for troubleshooting unexpected reboots, freezes, or application crashes.

---

## 🔹 Restart Logs

Shutdown and restart events are stored in the **System log** (sources: `EventLog`, `Kernel-Power`).

### Last 20 restarts (Kernel-Power Event ID 41)
```powershell
Get-WinEvent -LogName System | Where-Object { $_.Id -eq 41 } | 
Select-Object TimeCreated, Id, LevelDisplayName, Message -First 20
```

### Other useful Event IDs
- **1074** → Restart initiated by user or process  
- **1076** → Reason for restart/shutdown  
- **6005** → Event Log service started (system boot)  
- **6006** → Clean shutdown  

### Example: Get all common restart/shutdown events
```powershell
Get-WinEvent -LogName System | Where-Object { $_.Id -in 1074,1076,6005,6006,41 } |
Select-Object TimeCreated, Id, Message | Sort-Object TimeCreated -Descending
```

---

## 🔹 Freeze / Hang Logs

Application freezes are usually recorded in the **Application log**, source: `Application Hang` or `Application Error`.

### Last 20 application hangs
```powershell
Get-WinEvent -LogName Application | Where-Object { $_.ProviderName -in "Application Hang","Application Error" } |
Select-Object TimeCreated, Id, LevelDisplayName, Message -First 20
```

### System log entries for freezes or forced shutdowns
Freezes can also appear in the **System log** as hardware or driver issues:
- **Event ID 9, 11** → Hardware/driver errors  
- **Event ID 6008** → Unexpected shutdown (e.g., system froze and was powered off manually)

```powershell
Get-WinEvent -LogName System | Where-Object { $_.Id -eq 6008 } |
Select-Object TimeCreated, Id, Message | Sort-Object TimeCreated -Descending
```

---

## 🔹 Quick Tip: Filter by Date Range

Check unexpected restarts in the **last 7 days**:
```powershell
Get-WinEvent -LogName System -MaxEvents 1000 |
Where-Object { $_.TimeCreated -gt (Get-Date).AddDays(-7) -and $_.Id -eq 41 } |
Select TimeCreated, Message
```

---

## 🔹 Export Logs to CSV

You can export logs to a CSV file for easier analysis:
```powershell
Get-WinEvent -LogName System | Where-Object { $_.Id -in 1074,1076,6005,6006,41,6008 } |
Select-Object TimeCreated, Id, Message |
Export-Csv -Path "C:\Logs\Restart_Freeze_Logs.csv" -NoTypeInformation -Encoding UTF8
```

---

## ✅ Summary
- **System log** → Restart/shutdown and hardware-related freeze events  
- **Application log** → Application hangs and crashes  
- **Event IDs** help identify the cause (user action, hardware, crash, unexpected shutdown)  
- Use **date filters** and **CSV export** for deeper troubleshooting  

With these PowerShell commands, you can monitor and investigate restarts, freezes, and crashes directly from the command line.
