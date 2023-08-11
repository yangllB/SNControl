//
//  SNOAuth.h
//  SNMobileOffice
//
//  Created by mac on 2023/3/22.
//

#import <Foundation/Foundation.h>
@class SNOAuthModel;
NS_ASSUME_NONNULL_BEGIN

// 不返回值的block
typedef void (^requestCompleted)(void);
// 回调函数
typedef void (^callback)(SNOAuthModel * object);

@interface SNOAuth : NSObject

/** 第三方应用在互联开放平台申请的appID */
@property(nonatomic, retain) NSString *appId;


+(instancetype)sharedInstance;

/**
 * 初始化OAuth对象
 * \param appId 不可为nil，第三方应用在开放平台申请的唯一标识
 *  初始化后的授权登录对象
 */
- (void)startWithAppId:(NSString *)appId;

/**
 * 登录授权
 *\param callback 授权回调
 *
 */
- (void)authorizeLocalApp:(callback)callback;

/**
* 判断用户手机上是否安装移动办公
* \return YES:安装 NO:没安装
*
*/
+ (BOOL)iphoneSNMobileOfficeInstalled;


/**
 * (静态方法)处理应用拉起协议
 * \param url 处理被其他应用呼起时的逻辑
 * \return 处理结果，YES表示成功，NO表示失败
 * 
 */
- (BOOL)HandleOpenURL:(NSURL *)url;

@end


@interface SNOAuthModel : NSObject

@property(nonatomic, retain) NSString * code;

@property(nonatomic, retain) NSString * token;

@end
NS_ASSUME_NONNULL_END
