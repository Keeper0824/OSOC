 #!/usr/bin/env bash

count=0
logfile="output.log"

while true;do
	count=$((count+1))

	./err.sh > "$logfile"
	if [[ $? -ne 0 ]]; then
		echo "Script failed after $count runs" >> "$logfile"
		break
	fi
done

cat "$logfile"

