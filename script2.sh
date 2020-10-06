# execute directly from shell and replace "author name" with appropriate values

#--- script 02 starts

export author="Shanilka-Navagamuwa"

git ls-files | while read f; do replaceEscaped=$(sed 's/[&/\]/\\&/g' <<<"$f"); git blame -w --line-porcelain -- "$f" | grep -I '^author ' | sed s/^/"$replaceEscaped"" "/; done | grep "$author" | awk '{print $1}' | sort -f | uniq -ic | sort -n

# --- script 02 ends

# ref for author information: https://gist.github.com/amitchhajer/4461043