#include <Cocoa/Cocoa.h>

#include <math.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libproc.h>
#include <dlfcn.h>

// windows.h
// dsound.h
// xinput.h
#include <OpenGL/gl.h>

#define COUNTOF(a) (int)(sizeof(a) / sizeof(0 [a]))
#define FRAMERATE 60
#define PI 0x1.921fb6p+1f

#define FATAL(msg)                                      \
    do {                                                \
        MessageBoxA(0, msg, "Fatal Error", MB_OK);      \
        ExitProcess(-1);                                \
    } while (0)

#define INIT_COUNT      8
#define LEVEL_DISPLAY   3
#define TIME_STEP_MIN   1.0f/15
#define SHIP_TURN_RATE  PI
#define SHIP_DAMPEN     0.955f
#define SHIP_ACCEL      0.5f
#define SHIP_SCALE      0.025f
#define SHOT_SPEED      0.5f
#define SHOT_TTL        1.0f
#define SHOT_COOLDOWN   0.2f
#define DEBRIS_TTL      1.2f

#define AUDIO_HZ        8000
#define AUDIO_LEN       8 * AUDIO_HZ * 2

#define ASTEROID0_MIN   0.025f
#define ASTEROID0_MAX   0.050f
#define ASTEROID0_SCORE 1
#define ASTEROID1_MIN   0.012f
#define ASTEROID1_MAX   0.025f
#define ASTEROID1_SCORE 2
#define ASTEROID2_MIN   0.008f
#define ASTEROID2_MAX   0.015f
#define ASTEROID2_SCORE 5

enum asteroid_size { A0, A1, A2 };

/* format ARGB */
#define C_SHIP      0xffffffff
#define C_ASTEROID  0xffffffff
#define C_SHOT      0xffffffff
#define C_THRUST    0xffffff00
#define C_FIRE      0x00df9f5f
#define C_SCORE     0xffffffff

struct v2 { float x, y; };

static const struct v2 ship[] = {
    {+1.00f * SHIP_SCALE, +0.00f * SHIP_SCALE},
    {-0.71f * SHIP_SCALE, +0.57f * SHIP_SCALE},
    {-0.43f * SHIP_SCALE, +0.29f * SHIP_SCALE},
    {-0.43f * SHIP_SCALE, -0.29f * SHIP_SCALE},
    {-0.71f * SHIP_SCALE, -0.57f * SHIP_SCALE},
};
static const struct v2 tail[] = {
    {-0.43f * SHIP_SCALE, -0.20f * SHIP_SCALE},
    {-0.70f * SHIP_SCALE, +0.00f * SHIP_SCALE},
    {-0.43f * SHIP_SCALE, +0.20f * SHIP_SCALE},
};

/* 7-segment font for digits */
#define FONT_SX 0.015f
#define FONT_SY 0.025f
static const struct v2 segv[] = {
    {0.0f*FONT_SX, 1.0f*FONT_SY}, {1.0f*FONT_SX, 1.0f*FONT_SY},
    {0.0f*FONT_SX, 0.5f*FONT_SY}, {0.0f*FONT_SX, 1.0f*FONT_SY},
    {1.0f*FONT_SX, 0.5f*FONT_SY}, {1.0f*FONT_SX, 1.0f*FONT_SY},
    {0.0f*FONT_SX, 0.5f*FONT_SY}, {1.0f*FONT_SX, 0.5f*FONT_SY},
    {0.0f*FONT_SX, 0.0f*FONT_SY}, {0.0f*FONT_SX, 0.5f*FONT_SY},
    {1.0f*FONT_SX, 0.0f*FONT_SY}, {1.0f*FONT_SX, 0.5f*FONT_SY},
    {0.0f*FONT_SX, 0.0f*FONT_SY}, {1.0f*FONT_SX, 0.0f*FONT_SY},
};
static const char seg7[] = {
    0x77, 0x24, 0x5d, 0x6d, 0x2e, 0x6b, 0x7b, 0x25, 0x7f, 0x6f
};

static double uepoch(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}



int main(void) {
    return 0;
}
