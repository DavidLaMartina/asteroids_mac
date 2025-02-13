#import <Cocoa/Cocoa.h>
#include <CoreGraphics/CGContext.h>

@interface AsteroidsView : NSView
@end

@implementation AsteroidsView
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

    CGContextRef context = [[NSGraphicsContext currentContext] CGContext];

    // Example drawing: red rectangle
    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextFillRect(context, NSMakeRect(20, 20, 100, 100));
}
@end

static NSWindow* window_init() {
    NSString* title = @"Asteroids";

    // Define window dimensions
    NSScreen *screen = [NSScreen mainScreen];
    NSRect screenRect = [screen frame];
    int size = MIN(screenRect.size.width, screenRect.size.height) - 100;
    NSRect windowRect = NSMakeRect((screenRect.size.width - size) / 2,
                                    (screenRect.size.height - size) / 2,
                                    size,
                                    size);

    // Create and configure the window
    NSWindow *window = [[NSWindow alloc] initWithContentRect:windowRect
                                                    styleMask:(NSWindowStyleMaskTitled |
                                                               NSWindowStyleMaskClosable |
                                                               NSWindowStyleMaskMiniaturizable)
                                                    backing:NSBackingStoreBuffered
                                                      defer:NO];

    AsteroidsView *view = [[AsteroidsView alloc] initWithFrame:window.contentView.bounds];

    [window setTitle:title];
    [window setLevel:NSNormalWindowLevel];
    [window center];
    [window setContentView:view];
    [window makeKeyAndOrderFront:nil];

    return window;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        
        NSWindow *window = window_init();

        NSView *contentView = [window contentView];
        NSGraphicsContext *context = [contentView.window graphicsContext];
        CGContextRef cgContext = [context CGContext];

        [app run]; // Starts the application event loop
    }
    return 0;
}

