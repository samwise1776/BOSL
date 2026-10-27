#pragma once
#include "bosl/bosl.h"

namespace bosl {

namespace memory {
    inline void* copy(void* d, const void* s, size_t n) {
        return bosl_memcpy(d, s, n);
    }

    inline void* set(void* d, int v, size_t n) {
        return bosl_memset(d, v, n);
    }
}

namespace string {
    inline size_t length(const char* s) {
        return bosl_strlen(s);
    }
}

namespace graphics {
    inline void init(bosl_framebuffer fb) {
        bosl_graphics_init(fb);
    }

    inline void clear(uint32_t color) {
        bosl_graphics_clear(color);
    }

    inline void pixel(uint32_t x, uint32_t y, uint32_t color) {
        bosl_graphics_pixel(x, y, color);
    }

    inline void rect(uint32_t x, uint32_t y,
                     uint32_t w, uint32_t h, uint32_t color) {
        bosl_graphics_rect(x, y, w, h, color);
    }
}

namespace cpu {
    inline void halt() { bosl_cpu_halt(); }
    inline void relax() { bosl_cpu_relax(); }
}

}
