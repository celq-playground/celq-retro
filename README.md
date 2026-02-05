# celq-retro
celq for retrocomputing via w2c2

Trying to compile with:
```
gcc -std=gnu90 -D_GNU_SOURCE -I./vendor main.c celq.c vendor/wasi.c -o celq -lm
```