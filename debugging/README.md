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


Debugging attached to process <PID> should run as root for this kernel feature
sudo gdbgui -p 2222 -r
[V]-> click Attach to Process -> <PID | 418268>


Using GDBSever
sudo apt install gdbserver

$ gdbserver localhost:2222 ./a.out 
Process ./a.out created; pid = 732969
Listening on port 2222
kill -9 732965  # force to exit if CTRL+Z don't work, run this after you complete you debug code.


$ gdbgui
[V]-> click Connect to gdbserver -> <GBB_SERVER_IP:PORT | 127.0.0.1:2222 >

Using rr(debugging)
rr is a debugging tool for Linux designed to record and replay program execution. During the replay phase, rr provides an enhanced gdb debugging experience that supports reverse execution. rr was originally developed by Mozilla to debug Mozilla Firefox on commodity hardware and software.

sudo apt install rr
$ rr record -n ./a.out
$ rr replay 
(rr) run
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

### Commands to search word/math.h header inside all code file, and all directory. 
```
# We want to find all the #include <math.h> in a big trading code.
$  echo "$(grep -r math.h)" > global-search-of-math.txt

# Same action but showing the line number
$  echo "$(grep -nr math.h)" > global-search-of-math.txt

# Looking for C functions - memcpy
$  echo "$(grep -nr 'memcpy(')" >  global-search-of-memcpy.txt
```
### count number of file in a directory
```
$ find .|wc -l

```
