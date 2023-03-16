//
//  SNNetWorkManage.h
//  SNNetWorkControl
//
//  Created by mac on 2023/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNNetWorkManage : NSObject

+(instancetype)sharedInstance;

/**
 *  初始化SNNetWork
 *
 *  @param appId 注册SNNetWork分配的应用唯一标识
 */
- (void)startWithAppId:(NSString * )appId;

@end

NS_ASSUME_NONNULL_END
