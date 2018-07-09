//
//  DALinkProtocol.h
//  Coin
//
//  Created by yaowan on 16/9/19.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ALGLinkCallback)(NSError * _Nullable error);

@protocol ALGLinkProtocol <NSObject>

@required

/**
 配网入口

 @param ssid WiFi的ssid
 @param password 密码
 @param userId 用户id
 @param token 授权码
 @param callback 回调仅表示是否成功开始发送，不代表设备是否成功接收
 */
- (void)linkWithSSID:(nonnull NSString *)ssid password:(nullable NSString *)password userId:(nonnull NSString *)userId token:(nonnull NSString *)token callback:(nullable ALGLinkCallback)callback;

/**
 停止配网
 */
- (void)stopLink;

/**
 是否正在配网

 @return YES or NO
 */
- (BOOL)isLinking;

@end
