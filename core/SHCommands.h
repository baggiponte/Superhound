#import <Foundation/Foundation.h>
// System commands, searched with applications. app/SHResultActions.m runs them.
@interface SHCommands : NSObject
// Keys: type "command", id and path "command:<key>", name, alias (other words that find it), relative "", symbol (an SF Symbol name).
+ (NSArray<NSDictionary *> *)entries;
// Well-known folders, searched with applications: Home, Desktop, Documents, Downloads, Pictures, Movies, Music, Applications in home and system,
// Utilities, iCloud Drive, and the Trash, each only when it exists. system is "/" outside tests.
// Keys: type "folder", place YES, id "place:<key>", path, name (in the user's language), alias (the English name and other words), relative "".
+ (NSArray<NSDictionary *> *)placesInHome:(NSString *)home system:(NSString *)system;
@end
