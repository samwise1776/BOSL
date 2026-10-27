#![allow(dead_code)]

use core::ffi::{c_char, c_int, c_void};

#[repr(C)]
#[derive(Clone, Copy)]
pub struct BoslFramebuffer {
    pub pixels: *mut u32,
    pub width: u32,
    pub height: u32,
    pub pitch: u32,
}

unsafe extern "C" {
    pub fn bosl_memcpy(
        dest: *mut c_void,
        src: *const c_void,
        n: usize
    ) -> *mut c_void;

    pub fn bosl_memset(
        dest: *mut c_void,
        value: c_int,
        n: usize
    ) -> *mut c_void;

    pub fn bosl_strlen(s: *const c_char) -> usize;

    pub fn bosl_graphics_init(fb: BoslFramebuffer);
    pub fn bosl_graphics_clear(color: u32);
    pub fn bosl_graphics_pixel(x: u32, y: u32, color: u32);
    pub fn bosl_graphics_rect(
        x: u32, y: u32, w: u32, h: u32, color: u32
    );

    pub fn bosl_cpu_halt();
    pub fn bosl_cpu_relax();
}
