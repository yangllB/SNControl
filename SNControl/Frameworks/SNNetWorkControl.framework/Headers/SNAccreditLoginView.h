//
//  SNAccreditLoginView.h
//  SNMobileOffice
//
//  Created by mac on 2023/7/18.
//

#import <UIKit/UIKit.h>
#import "SNOAuth.h"
NS_ASSUME_NONNULL_BEGIN

@interface SNAccreditLoginView : UIView

/**
 * 登录授权
 *\param callback 授权回调
 *
 */
- (void)authorizeLocalApp:(callback)callback;

@end

NS_ASSUME_NONNULL_END
