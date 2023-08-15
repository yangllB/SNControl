//
//  SNControlManage.h
//  SNNetWorkControl
//
//  Created by mac on 2023/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNControlManage : NSObject

+(instancetype)sharedInstance;
/**
 *  初始化SNNetWork
 *
 *  @param appId 注册SNNetWork分配的应用唯一标识
 *  @param universalLink 开发者Universal Link
 */
- (void)startWithAppId:(NSString * )appId universalLink:(NSString *)universalLink;


-(void)initOAuth;

@end

NS_ASSUME_NONNULL_END
