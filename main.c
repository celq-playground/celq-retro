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

#if defined(__MSL__) && defined(macintosh)
char** environ = NULL;
#else
extern char** environ;
#endif

#ifdef NEEDS_TRUNC_FALLBACK
#include <math.h>
double trunc(double x) {
    return (x >= 0.0) ? floor(x) : ceil(x);
}
#endif

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
