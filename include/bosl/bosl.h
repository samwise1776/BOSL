#ifndef BOSL_H
#define BOSL_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOSL_VERSION_MAJOR 0
#define BOSL_VERSION_MINOR 1
#define BOSL_VERSION_PATCH 0

/* Memory */
void *bosl_memcpy(void *dest, const void *src, size_t n);
void *bosl_memset(void *dest, int value, size_t n);
int bosl_memcmp(const void *a, const void *b, size_t n);

/* Strings */
size_t bosl_strlen(const char *str);
int bosl_strcmp(const char *a, const char *b);

/* Framebuffer */
typedef struct {
    uint32_t *pixels;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
} bosl_framebuffer;

void bosl_graphics_init(bosl_framebuffer fb);
void bosl_graphics_pixel(uint32_t x, uint32_t y, uint32_t color);
void bosl_graphics_clear(uint32_t color);
void bosl_graphics_rect(uint32_t x, uint32_t y,
                        uint32_t w, uint32_t h,
                        uint32_t color);

/* CPU */
void bosl_cpu_halt(void);
void bosl_cpu_relax(void);

#ifdef __cplusplus
}
#endif
#endif
