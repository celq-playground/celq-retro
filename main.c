#include <stdio.h>
#include "vendor/w2c2_base.h"
#include "vendor/wasi.h"
#include "celq.h"

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return celq_memory((celqInstance*)instance);
}

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    {
        celqInstance instance;
        celqInstantiate(&instance, NULL);
        celq__start(&instance);
        celqFreeInstance(&instance);
    }

    return 0;
}