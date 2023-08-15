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

/// 第三方应用在开放平台申请的appID
@property(nonatomic, retain) NSString *appId;

/// 开发者Universal Link
@property(nonatomic, retain) NSString * universalLink;

+(instancetype)sharedInstance;

/**
 * 初始化OAuth对象
 *  @param appId 不可为nil，第三方应用在开放平台申请的唯一标识
 *  @param universalLink 开发者Universal Link
 *  初始化后的授权登录对象
 */
- (void)startWithAppId:(NSString *)appId universalLink:(NSString *)universalLink;

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


/*! @brief 处理安全空间通过Universal Link启动App时传递的数据
 *
 * 需要在 application:continueUserActivity:restorationHandler:中调用。
 * @param userActivity 安全空间启动第三方应用时系统API传递过来的userActivity
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;


@end


@interface SNOAuthModel : NSObject

@property(nonatomic, retain) NSString * code;

@property(nonatomic, retain) NSString * token;

@end
NS_ASSUME_NONNULL_END
