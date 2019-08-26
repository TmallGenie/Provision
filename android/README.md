# 天猫精灵Android端配网SDK接入文档

## 文件接入
1. 引入tmallgenie-release-android.aar依赖
2. 拷贝musicfile.wav至assets目录

## 接口文档
1. 启动声波配网(AINetSoundConfig)
```
    /*
     * @param ssid           Wi-Fi id
     * @param password       Wi-Fi 密码，不超过64位英文字符（电信版本长度控制在30英文字符内）
     * @param userId         天猫精灵用户id（通过TOP/MTOP接口调用获取，运营商版本请替换为 openId）
     * @param token          配网校验token（通过TOP/MTOP接口调用获取，即 AuthCode）
     */
    startEncodeAndPlayAudio(String ssid, String password, String userId, String token)
```
2. 结束声波配网(AINetSoundConfig)
```
    stopPlayAudio()
```
3. 启动smartconfig配网(AINetSmartConfig)
```
    /*
     * @param ssid           Wi-Fi id
     * @param password       Wi-Fi 密码，不超过64位英文字符（电信版本长度控制在30英文字符内）
     * @param userId         天猫精灵用户id（通过TOP/MTOP接口调用获取，运营商版本请替换为 openId）
     * @param token          配网校验token（通过TOP/MTOP接口调用获取，即 AuthCode）
     */
    startProvision(String ssid, String password, String userId, String token)
```
4. 结束smartconfig配网(AINetSmartConfig)
```
    /*
     * @param ssid           Wi-Fi id
     * @param password       Wi-Fi 密码，不超过64位英文字符（电信版本长度控制在30英文字符内）
     * @param userId         天猫精灵用户id（通过TOP/MTOP接口调用获取，运营商版本请替换为 openId）
     * @param token          配网校验token（通过TOP/MTOP接口调用获取，即 AuthCode）
     */
    stopProvision（）
```

## 调用方式
1. 同步调用
2. 建议同时进行声波与smartconfig配网，以提高配网成功率
3. 通过TOP/MTOP接口轮询得到配网结果后，结束配网
