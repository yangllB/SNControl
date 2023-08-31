//
//  AuthorizedLoginViewController.h
//  SNControlDemo
//
//  Created by mac on 2023/8/22.
//

#import <UIKit/UIKit.h>
#import "SNOAuth.h"
NS_ASSUME_NONNULL_BEGIN

@interface AuthorizedLoginViewController : UIViewController


/**
 * 登录授权
 *\param callback 授权回调
 *
 */
- (void)authorizeLocalApp:(NSString *)appKey callback:(callback)callback;

@end

NS_ASSUME_NONNULL_END
