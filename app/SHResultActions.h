#import <AppKit/AppKit.h>
@interface SHResultActions : NSObject
// action: open, reveal, openWith (application is the app to open with), trash, paste (a ⌘V key press in the app in front), or type (the result's copy text as key presses in the app in front, which leave the clipboard as it is; without Accessibility access the text is copied).
// A result of type "url" or "web" opens its url in the default browser for any action.
+ (void)perform:(NSString *)action result:(NSDictionary *)result application:(NSURL *)application completion:(void (^)(NSString *error))completion;
@end
