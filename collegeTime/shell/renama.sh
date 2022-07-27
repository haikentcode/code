for file in *.jpg
do
  mv "$file" "${file/c-/A}"
done
