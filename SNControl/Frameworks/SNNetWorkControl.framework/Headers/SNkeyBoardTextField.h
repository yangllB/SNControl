//
//  OttoTextField.h
//  ZSCSafeKeyBoard
//
//  Created by shian on 2022/12/20.
//  Copyright © 2022 jrjc. All rights reserved.
//

#import <UIKit/UIKit.h>

/** KeyboardType键盘类型
 *
 *  系统默认键盘:KeyboardTypeDefault
 *  自定义键盘:KeyboardTypeNumber
 */
typedef NS_ENUM(NSInteger,KeyboardType) {
    KeyboardTypeDefault = 0,  // 系统默认键盘
    KeyboardTypeNumber,   // 自定义键盘

};

@interface SNkeyBoardTextField : UITextField

@property (nonatomic, copy) NSString * keyBoardStr;

- (void)setOttoKeyboardType:(KeyboardType)keyboardType;
@end


