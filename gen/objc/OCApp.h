// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from app.djinni

#import <Foundation/Foundation.h>
@class OCApp;
@protocol OCConcurrency;


@interface OCApp : NSObject

+ (nullable OCApp *)instance;

- (void)setConcurrency:(nullable id<OCConcurrency>)concurrency;

- (void)setHost:(nonnull NSString *)host;

- (void)setPort:(int32_t)port;

- (void)setToken:(nonnull NSString *)token;

- (void)setName:(nonnull NSString *)name;

- (void)setEmail:(nonnull NSString *)email;

- (void)setAvatarUrl:(nonnull NSString *)avatarUrl;

- (void)openDatabase:(nonnull NSString *)path;

- (void)connect;

@end
