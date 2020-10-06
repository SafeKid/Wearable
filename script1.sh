# -- script 01 starts

#!/usr/bin/env bash
from="1 Jul, 2020"
to="4 Oct, 2020"
users=$(git shortlog -sn --no-merges --since="$from" --before="$to" | awk '{printf "%s %s\n", $2, $3}')
IFS=$'\n'
echo -e "User name;Files changed;Lines added;Lines deleted;Total lines (delta);Add./Del. ratio (1:n);Commit count"

for userName in $users
do
     result=$(git log --author="$userName" --no-merges --shortstat  --since="$from" --before="$to" \
| grep -E "fil(e|es) changed" | awk '{files+=$1; inserted+=$4; deleted+=$6; delta+=$4-$6; ratio=deleted/inserted} \
END {printf "%s;%s;%s;%s;%s", files, inserted, deleted, delta, ratio }' -)
     countCommits=$(git shortlog -sn --no-merges  --since="$from" --before="$to" --author="$userName" \
| awk '{print $1}')
     if [[ ${result} != ';;;;' ]]
     then
        echo -e "$userName;$result;$countCommits"
     fi
done

#--- script 01 ends

# ref for author information: https://gist.github.com/eyecatchup/3fb7ef0c0cbdb72412fc

# execute directly from shell and replace "author name" with appropriate values