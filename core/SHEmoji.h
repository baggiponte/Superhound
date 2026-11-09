#import <Foundation/Foundation.h>
// Emoji found by name or keyword. Main thread only; the list loads in the background.
@interface SHEmoji : NSObject
// url: a file with one line per emoji: emoji, name, keywords separated by "|", with tabs between.
- (instancetype)initWithURL:(NSURL *)url;
// Every query word must start a word of the name or be the start of a keyword. Best first.
// Keys: type "emoji", id and path "emoji:<emoji>", name, emoji, copy.
- (NSArray<NSDictionary *> *)search:(NSString *)query limit:(NSUInteger)limit;
// Every emoji in file order, with the keys of search:limit:; empty while the list loads.
- (NSArray<NSDictionary *> *)list;
- (void)waitUntilLoaded;
@end
// text cut into pieces of at most units UTF-16 code units, each ending where a character ends, for key presses that carry text; a single character longer than units stays one piece.
NSArray<NSString *> *SHTypingChunks(NSString *text,NSUInteger units);
