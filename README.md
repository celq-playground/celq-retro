# celq-retro

celq for retrocomputing via [w2c2](https://github.com/turbolent/w2c2).

To compile this code on modern systems, run:

```bash
gcc -Os -std=gnu90 -D_GNU_SOURCE -DHAS_UNISTD=1 -DHAS_TIMESPEC=1 -DHAS_SYSUIO=1 -I./vendor main.c celq.c vendor/wasi.c -o celq -lm
```

For Windows 98, to compile it with [DJGPP](https://en.wikipedia.org/wiki/DJGPP):
```bash
i586-pc-msdosdjgpp-gcc \
    -o celq.exe \
    -O2 \
    -I./vendor \
    -DHAS_UNISTD=1 \
    -DHAS_TIMESPEC=0 \
    main.c celq.c vendor/wasi.c
```

For Windows 98, to compile it with Open [WATCOM](https://en.wikipedia.org/wiki/Watcom_C/C%2B%2B):
```bash
wcl386 -l=nt -os -i=./vendor \
	-d__inline__= \
	-d_WIN32 \
	-d_X86_ \
	-d_MSC_VER=1000 \
	-dHAS_UNISTD=0 \
	-dHAS_TIMESPEC=1 \
	-bm \
	main.c celq.c vendor/wasi.c vendor/win32.c -fe=celq.exe
```

## How was this made

First, clone [celq](https://github.com/IvanIsCoding/celq) and build `celq.wasm` with:

```bash
cargo build \
	--no-default-features \
    --features "from-toml,from-yaml,from-xml,greppable" \
    --release \
    --target wasm32-wasip1
```

Of course the above command assumes you have installed rust and the `wasm32-wasip1` toolchain. Then:

```bash
w2c2 celq.wasm celq.c
```

To generate `celq.c` and `celq.h`. The files in `vendor/` are from w2c2. The `main.c` is essentially a copy of [rust-wasi/main.c](https://github.com/turbolent/w2c2/blob/main/examples/rust-wasi/main.c) from the repository.
