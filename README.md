# celq-retro
celq for retrocomputing via w2c2

Trying to compile with:

```bash
gcc -std=gnu90 -D_GNU_SOURCE -DHAS_UNISTD=1 -DHAS_TIMESPEC=1 -DHAS_SYSUIO=1 -I./vendor main.c celq.c vendor/wasi.c -o celq -lm
```