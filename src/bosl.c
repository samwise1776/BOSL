#include "bosl/bosl.h"

static bosl_framebuffer framebuffer = {0};

void *bosl_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];

    return dest;
}

void *bosl_memset(void *dest, int value, size_t n) {
    unsigned char *d = dest;

    for (size_t i = 0; i < n; i++)
        d[i] = (unsigned char)value;

    return dest;
}

int bosl_memcmp(const void *a, const void *b, size_t n) {
    const unsigned char *x = a;
    const unsigned char *y = b;

    for (size_t i = 0; i < n; i++) {
        if (x[i] != y[i])
            return (int)x[i] - (int)y[i];
    }

    return 0;
}

size_t bosl_strlen(const char *str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

int bosl_strcmp(const char *a, const char *b) {
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (int)(unsigned char)*a -
           (int)(unsigned char)*b;
}

void bosl_graphics_init(bosl_framebuffer fb) {
    framebuffer = fb;
}

void bosl_graphics_pixel(uint32_t x, uint32_t y, uint32_t color) {
    if (!framebuffer.pixels) return;
    if (x >= framebuffer.width || y >= framebuffer.height) return;
    framebuffer.pixels[(size_t)y * framebuffer.pitch + x] = color;
}

void bosl_graphics_clear(uint32_t color) {
    bosl_graphics_rect(0, 0, framebuffer.width,
                       framebuffer.height, color);
}

void bosl_graphics_rect(uint32_t x, uint32_t y,
                        uint32_t w, uint32_t h, uint32_t color) {
    if (!framebuffer.pixels) return;

    if (x >= framebuffer.width || y >= framebuffer.height) return;

    uint32_t xmax = w > framebuffer.width - x
                  ? framebuffer.width : x + w;
    uint32_t ymax = h > framebuffer.height - y
                  ? framebuffer.height : y + h;

    for (uint32_t py = y; py < ymax; py++)
        for (uint32_t px = x; px < xmax; px++)
            bosl_graphics_pixel(px, py, color);
}

void bosl_cpu_halt(void) {
#if defined(__x86_64__) || defined(__i386__)
    __asm__ volatile("hlt");
#endif
}

void bosl_cpu_relax(void) {
#if defined(__x86_64__) || defined(__i386__)
    __asm__ volatile("pause");
#endif
}
