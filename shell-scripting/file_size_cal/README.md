# File Size Calculator
```
1-Create a file with size greater than 400000
./xml_file_generator.sh
ls -ll
-rw-r--r-- 1 developer developer 443001 Feb 17 19:35 sample.xml

2-Validate file size
cat check_file_size.sh 

#!/bin/bash
size=$(wc -c < sample.xml)
if (($size >= 400000 )); then
        echo "File have the GOOD size :)"
else
        echo "Oh-oh WRONG size :("

fi
```
