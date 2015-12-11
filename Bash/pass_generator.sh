#! /bin/bash

numbers=(`echo {0..9}`)
letters=(`echo {A..Z} {a..z}`)

for a in "${numbers[@]}"; do
  for b in "${letters[@]}"; do
    for c in "${letters[@]}"; do
      for d in "${numbers[@]}"; do
        for e in "${letters[@]}"; do
          for f in "${letters[@]}"; do
            echo "$a$b$c$d$e$f"
          done
        done
      done
    done
  done
done