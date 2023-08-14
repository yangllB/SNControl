//
//  SNFileModel.h
//  SNMobileOffice
//
//  Created by mac on 2023/3/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, SNFileType) {
    
    SNFileTypeUnknown = 9, //其他
    
    SNFileTypeAll = 0, //所有
    
    SNFileTypeImage = 1, //图片

    SNFileTypePDF = 2, //PDF
    
    SNFileTypeXLS = 3, //XLS
    
    SNFileTypeWord = 4, //Word

    SNFileTypePPT = 5, //PPT
    
    SNFileTypeTxt = 6, //文档

    SNFileTypeVoice = 7, //音乐
    
    SNFileTypeAudioVidio = 11, //视频
    
    SNFileTypeApplication = 8, //应用
    
    SNFileTypeDirectory = 10, //目录
        
    
};

@interface SNFileModel : NSObject

//文件路径
@property (copy, nonatomic) NSString *filePath; ///< 全路径
//文件URL
@property (copy, nonatomic) NSString *fileUrl;

@property (copy, nonatomic) NSString *name; ///< 文件名称

@property (nonatomic, readonly) NSString *simpleName;/**< 获取文件(夹)名，没有后缀 */

@property (nonatomic, readonly) NSString *extension; /**< 获取文件后缀名 */

@property (copy, nonatomic) NSString *fileSize; ///< 大小用字符表述

@property (nonatomic, assign) float fileSizefloat; ///< 大小用float

@property (copy, nonatomic) NSString *modTime; ///< 修改时间

@property (copy, nonatomic) NSString *creatTime; ///< 修改时间
@property (copy, nonatomic) NSString *fileReadTime; ///< 修改时间

@property (assign, nonatomic) SNFileType fileType;

@property (nonatomic, strong) NSDictionary *attributes; ///<文件属性

@property (nonatomic, assign) BOOL isSelected;/**< 判断是否为选中状态 */


@property (nonatomic, readonly) BOOL isDirectory;/**< 判断是否是目录 */
@property (nonatomic, readonly) BOOL isFile;/**< 判断是否是文件 */
@property (nonatomic, readonly) BOOL isExists;/**< 判断是否存在 */
@property (nonatomic, readonly) BOOL hasParent;/**< 判断是否还有父目录 */
@property (nonatomic, readonly) NSString *md5;/**< 获取文件MD5值，如果此File是文件夹，则返回nil，耗时操作 */


#pragma mark - 网络字段
//文件ID
@property (copy, nonatomic) NSString *fileId;
@property (copy, nonatomic) NSString *fileName; ///< 文件名称
@property (copy, nonatomic) NSString *fileUpdateTime; ///< 文件更新时间
///<
@property (copy, nonatomic) NSString *fileDepartment; ///< 文件部门

@property (copy, nonatomic) NSString *fileFolder; ///< 文件位置

@property (copy, nonatomic) NSString *fileSource; ///< 文件来源
///<
@property (copy, nonatomic) NSString * isUpdate; ///< 是否有更新 1是2否

@property (copy, nonatomic) NSString * isFavorite; ///< 1是2否  是否有收藏

@property (copy, nonatomic) NSString *folderId; ///< 文件夹名称

@property (copy, nonatomic) NSString *folderName; ///< 文件夹名称
///<
@property (copy, nonatomic) NSString *folderUpdateTime; ///< 文件夹更新时间

@property (copy, nonatomic) NSString *folderSize; ///< 文件夹大小

@property (copy, nonatomic) NSString *type; ///< 类型
///<
@property (assign, nonatomic) BOOL isCollect; ///< 是否收藏

@property (copy, nonatomic) NSString * departmentCode; ///< 文件部门code

@property (copy, nonatomic) NSString * department; ///< 文件部门

#pragma mark - 权限
@property (nonatomic, readonly) BOOL isImmutable; /**< 是否可变的 */
@property (nonatomic, readonly) BOOL isReadable;/**< 是否可读 */
@property (nonatomic, readonly) BOOL isWritable;/** 是否可写 */
@property (nonatomic, readonly) BOOL isExecutable;/**< 是否可执行 */
@property (nonatomic, readonly) BOOL isDeletable;/**< 是否可删除 */

/**
 初始化方法
 
 @param filePath 全路径
 @return 自身对象
 */
- (instancetype)initWithFilePath:(NSString *)filePath;

+ (SNFileModel *)fileWithPath:(NSString *)path;
+ (SNFileModel *)fileWithURL:(NSURL *)url;

#pragma mark - 读取与写入
- (BOOL)delete;/**< 删除文件(夹) */
- (BOOL)clear;/**< 如果是文件夹, 则清空(不删除目录), 是文件, 则删除 */

-(NSString *)strFileSize:(NSString *)size;

- (BOOL)makeDirs;/**< 创建文件夹(如果不存在的话) */
-(NSString *)fileTypeSting; /**< 文件类型 */

-(NSString *)fileMimeType; /**< 文件mimeType */

-(NSString *)filePathPosition;/**< 文件位置 */
- (nullable NSData *)data; /**< 读取文件*/
- (nullable NSString *)text; /**< 使用UTF-8编码读取文件 */
- (nullable NSString *)textWithEncoding:(NSStringEncoding)encoding; /**< 读取文件 */
- (void)writeData:(NSData *)data; /**< 写入数据，如果当前文件有数据，直接覆盖 */
- (void)writeText:(NSString *)text; /**< 向文件写入文本，默认使用UTF-8编码，如果当前文件存在，直接覆盖 */
- (void)writeText:(NSString *)text withEncoding:(NSStringEncoding)encoding; /**< 向文件写入文本，如果当前文件存在，直接覆盖 */
- (void)appendData:(NSData *)data; /**< 写入数据，如果当前文件有数据，直接追加 */
- (void)appendText:(NSString *)text; /**< 向文件追加文本，使用UTF-8编码 */
- (void)appendText:(NSString *)text withEncoding:(NSStringEncoding)encoding; /**< 向文件追加文本 */

- (SNFileModel *)write:(NSData *)data withName:(NSString *)name;/**< 在当前文件夹下写文件. 如果已有文件, 则覆盖 */
- (SNFileModel *)write:(NSData *)data withName:(NSString *)simpleName andExtension:(NSString *)ext; /**< 在当前文件夹写文件.如果已有文件，则覆盖。extension：后缀名 */
- (BOOL)copyToPath:(SNFileModel *)newFile;/**< 复制文件, 如果newFile已存在, 则覆盖 */
- (BOOL)moveToPath:(SNFileModel *)newFile;/**< 移动文件, 如果newFile已存在, 则覆盖 */

#pragma mark - 进入/返回文件夹
- (SNFileModel *)root;/**< 返回根文件夹 */
- (nullable SNFileModel *)parent;/**< 获取父目录, 如果父目录超过沙盒，则返回空 */
- (SNFileModel *)child:(NSString *)name;/**< 获取子文件(夹) */
- (nullable NSArray<SNFileModel *> *)children;/**< 获取当前目录下所有文件(夹). 注意: 耗时操作 */
- (BOOL)isChildOf:(SNFileModel *)parent;/**< 判断是不是指定文件夹的子文件夹 */

// 通过后缀获得类型
- (SNFileType)judgeType:(NSString *)pathExtension;

#pragma mark - 其它
@property (nonatomic, readonly) NSError *lastError;/**< 最后一次发生的错误 */
- (BOOL)isEqualToFile:(SNFileModel *)otherFile; /**< 判断两个文件的路径是否相同 */
- (BOOL)isContentEqualToFile:(SNFileModel *)anotherFile; /**< 判断两个文件的内容是否相同 */

@end

@interface SNFileModel (Directory)
+ (SNFileModel *)home;/**< 获取Home目录, 根目录 */
+ (SNFileModel *)caches;/**< 获取Library/Caches目录, iTunes不会备份此目录, 应用退出时, 此目录不清空 */
+ (SNFileModel *)documents;/**< 获取Documents目录, iTunes将会备份此目录 */
+ (SNFileModel *)tmp;/**< 获取tmp目录, 应用退出时清空 */
+ (SNFileModel *)fileSafe;/**< 获取应用安全空间文件存储 */
@end

NS_ASSUME_NONNULL_END
