#!bin/sh
cat /etc/passwd | sed '/#/d' | awk 'NR%2==0' | cut -f1 -d':' | rev | sort -r | sed -n "${FT_LINE1}, ${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./g' | tr -d '\n' 
