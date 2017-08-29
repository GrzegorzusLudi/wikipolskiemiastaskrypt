#!/bin/sh

#lynx -cookies -dump pl.wikipedia.org/wiki/$m | grep -A 4 -E 'Populacja|Na mapach:|Liczba ludności' | ./konw


readarray a < miejscowosci.txt
for i in "${a[@]}"
do
    j=`echo $i | tr -d '\n'`
    #echo "pl.wikipedia.org/wiki/$j"
    sleep 0.1
    k=`lynx -cookies -dump "pl.wikipedia.org/wiki/$j" | grep -A 8 -E 'Populacja|Na mapach:|Liczba ludności|Data założenia|wzmianka|zmiankowan|Historia\[' | ./konw2`
    if [ -n "$k" ]; then
        echo $k
    fi
	
done