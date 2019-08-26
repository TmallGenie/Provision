# 天猫精灵iOS端配网SDK接入文档

## pod依赖
1. 本SDK依赖[CocoaAsyncSocket](https://github.com/robbiehanson/CocoaAsyncSocket)
2. 手动集成[CocoaAsyncSocket V7.4.3](https://codeload.github.com/robbiehanson/CocoaAsyncSocket/zip/7.4.3)
```
cocoapods: pod 'CocoaAsyncSocket', '~> 7.4.3'
```

## 文件接入
1. ALGLinkSDK.framework
2. 关闭Bitcode
3. Other Link Flags添加一行内容
```
-l"c++"
```

## 接口文档
1. 启动配网(ALGLinkSmartConfig & ALGLinkSoundConfig)
```
    /*
     * @param ssid           Wi-Fi id
     * @param password       Wi-Fi 密码，不超过64位英文字符（电信版本长度控制在30英文字符内）
     * @param userId         天猫精灵用户id（通过TOP/MTOP接口调用获取，运营商版本请替换为 openId）
     * @param token          配网校验token（通过TOP/MTOP接口调用获取，即 AuthCode）
     * @param callback       配网回调（仅表示是否启动成功，不是设备配网结果的回调）
     */
    - (void)linkWithSSID:(nonnull NSString *)ssid password:(nullable NSString *)password userId:(nonnull NSString *)userId token:(nonnull NSString *)token callback:(nullable ALGLinkCallback)callback;
```
2. 结束配网(ALGLinkSmartConfig & ALGLinkSoundConfig)
```
    - (void)stopLink;
```
3. 是否处于配网状态中(ALGLinkSmartConfig & ALGLinkSoundConfig)
```
    /*
     * @return YES or NO
     */
    - (BOOL)isLinking;
```


## 调用示例
1. 同步调用
2. 建议同时进行声波与smartconfig配网，以提高配网成功率
3. 通过TOP/MTOP接口轮询得到配网结果后，结束配网
```
    #import <ALGLinkSDK/ALGLinkSDK.h>
    ....
    // Wi-Fi配网
    [[ALGLinkSmartConfig sharedInstance] linkWithSSID:@"123" password:@"123" userId:@"123" token:@"123" callback:nil];
    // 声波配网
    [[ALGLinkSoundConfig sharedInstance] linkWithSSID:@"123" password:@"123" userId:@"123" token:@"123" callback:nil];

    // 停止配网
    [[ALGLinkSmartConfig sharedInstance] stopLink];
    [[ALGLinkSoundConfig sharedInstance] stopLink];
```
