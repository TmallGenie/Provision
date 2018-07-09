//
//  DALinkSmartConfig.h
//  Coin
//
//  Created by yaowan on 16/9/19.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import "ALGLinkProtocol.h"

@interface ALGLinkSmartConfig : NSObject <ALGLinkProtocol>

+ (instancetype)sharedInstance;

@end
