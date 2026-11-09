#import <Foundation/Foundation.h>
// The defaults key clipboardHistory: NO turns the clipboard history off (no pasteboard check, no history shortcut, no clipboard rows in a search). A missing value is YES.
extern NSString *const SHClipboardHistoryKey;
BOOL SHClipboardHistoryOn(NSUserDefaults *defaults);
// Text copied in any app, newest first, at most 500 items. Main thread only; the file is written in the background.
@interface SHClipboard : NSObject
- (instancetype)initWithURL:(NSURL *)url;
@property(nonatomic,readonly) NSUInteger count;
// Records text as the newest item; the same text copied again moves to the top. source: the copying app's name, or nil.
// NO, and nothing kept, for a concealed, transient, or generated copy, a copy from Keychain Access or Passwords, and text that is blank or over 100,000 characters.
- (BOOL)addText:(NSString *)text types:(NSArray<NSString *> *)types application:(NSString *)bundleID source:(NSString *)source;
// Every query word must be in the text, without case, accent, or width differences. An empty query lists all items. Newest first.
// Keys: type "clipboard", id and path "clipboard:<number>", name (the first line with text), copy (the text), date, source.
- (NSArray<NSDictionary *> *)search:(NSString *)query limit:(NSUInteger)limit;
- (void)removeID:(NSString *)identifier;
- (void)clear;
- (void)waitUntilSaved;
@end
