//
//  MISPHelper.h
//  SNMobileOffice
//
//  Created by mac on 2023/6/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MISPHelper : NSObject

+ (MISPHelper *)sharedInstance;

/** 判断是否已初始化 进行心跳管理 新增 2021.07.29*/
-(void)startHeartbeatSuccess;


/// 加密
/// - Parameters:
///   - filePath: 文件路径
///   - completion: 成功回调
///   - failure: 失败回调
- (void)encryptWithFilePath:(NSString*)filePath fileDepartmentCode:(NSString *)departmentCode completion:(void (^)(NSData* encryptData,NSString * encFilePath))completion failure:(void (^)( NSString * err))failure;

- (void)encryptWithData:(NSData*)data fileDepartmentCode:(NSString *)departmentCode completion:(void (^)(NSData* encryptData))completion failure:(void (^)( NSString * err))failure;


/// 解密
/// - Parameters:
///   - filePath: 文件路径
///   - completion: 成功回调
///   - failure: 失败回调
- (void)decryptWithFilePath:(NSString*)filePath completion:(void (^)(NSString *decFilePath))completion failure:(void (^)(NSString * err))failure;


- (void)decryptWithData:(NSData*)data completion:(void (^)(NSData *decData))completion failure:(void (^)(NSString * err))failure;

- (void)decryptWithFilePath:(NSString*)filePath userDCode:(NSString *)userDCode completion:(void (^)(NSString *decFilePath))completion failure:(void (^)(NSString * err))failure;

@end

NS_ASSUME_NONNULL_END
