# Debugging
Using different debugging tools and utility for C & C++ code.

### gdbgui: Browser-based frontend to gdb. Debug C, C++
```
apt install python3.9-venv
pipx install gdbgui
sudo /home/$USER/.local/pipx/venvs/gdbgui/bin/gdbgui -p 3333 -r
--- OR ---
pip3 install gdbgui
sudo pip3 install gdbgui
pip3 show gdbgui


$which gdbgui
/home/$USER/.local/bin/gdbgui

compile with debudding flag ON -g
gcc -g main.c
gdbgui ./a.out -p 2222 -r
open http://127.0.1.1:2222/
open http://127.0.1.1:2222/dashboard


debugging attached to process <PID> should run as root for this kernel feature
sudo gdbgui -p 2222 -r
[V]-> click Attach to Process -> <PID | 418268>
```


### GDBFrontend
```
Tmux: Tmux is a terminal multiplexer an alternative to GNU Screen 
sudo apt install tmux
pip3 install gdbfrontend

$ gdbfrontend --port=2222
GDBFrontend v0.10.2-beta
Listening on 127.0.0.1: http://127.0.0.1:2222/
Open this address in web browser: http://127.0.0.1:2222/terminal/
```

### GNU DDD: DataDisplayDebugger - graphical front-end for command-line GDB
```
sudo apt install ddd
ddd
```

