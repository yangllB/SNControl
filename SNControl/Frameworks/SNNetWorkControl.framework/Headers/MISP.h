//
//  MISP.h
//  MISP
//
//  Created by Mr.Cooriyou on 12-7-19.
//  Copyright (c) 2012年 wondersoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MISP : NSObject


+ (instancetype)sharedInstance;

/// 数据加密
/// @param data 原数据
/// @param levelNumber   密钥Number 使用文档 SECKEYS_LEVEL_NUMBER_00 字段  秘籍编号
/// @param completion 返回加密后的数据
-(void)encryptData:(NSData *)data encryptLevelNumber:(NSString*)levelNumber completion:(void (^)(NSData* encryptData))completion failure:(void (^)( NSString * err))failure;

/// 文件加密
/// @param filePath 原文件路径
/// @param levelNumber  密钥Number 使用文档 SECKEYS_LEVEL_NUMBER_00 字段 秘籍编号
/// @param completion 返回加密后的数据
-(void)encryptFileWithFilePath:(NSString*)filePath encryptLevelNumber:(NSString*)levelNumber completion:(void (^)(NSData* encryptData,NSString * encFilePath))completion failure:(void (^)( NSString * err))failure;


/// 数据解密
/// @param data 原数据
/// @param completion 返回加密后的数据
-(void)decryptionData:(NSData *)data completion:(void (^)(NSData* encryptData))completion  failure:(void (^)( NSString * err))failure;


/// 文件解密
/// @param filePath 源文件路径
/// @param completion 返回加密后文件路径
-(void)decryptionFileWithFilePath:(NSString*)filePath completion:(void (^)(NSString* decFilePath))completion failure:(void (^)( NSString * err))failure;



/// 判断是否是加密文件
/// @param data 数据
/// @return BOOL  YES 是加密文件  NO 不是加密文件
-(BOOL)isEncryptNewApproveFileData:(NSData *)data;

@end
