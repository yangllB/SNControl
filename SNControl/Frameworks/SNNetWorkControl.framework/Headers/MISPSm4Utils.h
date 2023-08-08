//
//  MISPSm4Utils.h
//  MISP
//
//  Created by lele yang on 2022/5/19.
//  Copyright © 2022 wondersoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MISPSm4Utils : NSObject

///MARK: - SM4 字符串加解密

/// SM4 字符串加密。返回值：加密后的字符串，Hex 编码格式
/// CBC 模式需传入 32 字节 Hex 编码格式 ivec 字符串
/// @param plaintext 待加密的字符串
/// @param key SM4 密钥，长度  32 字节 Hex 编码格式字符串
+ (nullable NSString *)ecbEncryptText:(NSString *)plaintext key:(NSString *)key;
+ (nullable NSString *)cbcEncryptText:(NSString *)plaintext key:(NSString *)key IV:(NSString *)ivec;

/// SM4 字符串解密。返回值：解密后的明文
/// CBC 模式需传入  32 字节 Hex 编码格式 ivec 字符串
/// @param ciphertext 密文（Hex 编码格式）
/// @param key SM4 密钥，长度  32 字节 Hex 编码格式字符串
+ (nullable NSString *)ecbDecryptText:(NSString *)ciphertext key:(NSString *)key;
+ (nullable NSString *)cbcDecryptText:(NSString *)ciphertext key:(NSString *)key IV:(NSString *)ivec;

///MARK: - SM4 Data 加解密

/// SM4 文件加密。返回值：加密后的 NSData 类型密文
/// CBC 模式需传入  32 字节 Hex 编码格式 ivec 字符串
/// @param plainData  明文（NSData 类型）
/// @param key SM4 密钥，长度  32 字节 Hex 编码格式字符串
+ (nullable NSData *)ecbEncryptData:(NSData *)plainData key:(NSString *)key;
+ (nullable NSData *)cbcEncryptData:(NSData *)plainData key:(NSString *)key IV:(NSString *)ivec;

/// SM4 文件解密。返回值：解密后的 NSData 类型原文
/// CBC 模式需传入  32 字节 Hex 编码格式 ivec 字符串
/// @param cipherData 密文（NSData 类型）
/// @param key SM4 密钥，长度  32 字节 Hex 编码格式字符串
+ (nullable NSData *)ecbDecryptData:(NSData *)cipherData key:(NSString *)key;
+ (nullable NSData *)cbcDecryptData:(NSData *)cipherData key:(NSString *)key IV:(NSString *)ivec;

@end

NS_ASSUME_NONNULL_END
