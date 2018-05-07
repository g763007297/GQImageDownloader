 [![License MIT](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://raw.githubusercontent.com/angelcs1990/GQImageDownloader/master/LICENSE)&nbsp;
[![](https://img.shields.io/badge/platform-iOS-brightgreen.svg)](http://cocoapods.org/?q=GQImageDownloader)&nbsp;
[![support](https://img.shields.io/badge/support-iOS6.0%2B-blue.svg)](https://www.apple.com/nl/ios/)&nbsp;

# GQImageDownloader
网络图片异步多线程加载工具，可设置缓存方式，支持主流图片格式，以及webp图片，支持自定义网络请求类，支持根据系统级别自动区分使用NSURLSession与NSURLConnection请求。

## 使用CocoaPods导入

1.在 Podfile 中添加不带webp格式支持的图片加载器则添加 pod 'GQImageDownloader'，添加支持webp格式支持的则添加  pod 'GQImageDownloader/WebP'。
2.执行 pod install 或 pod update。
3.导入 GQImageDownloader.h。

## 使用方式

```objc

/**
只带url的请求方法

param url 图片地址
param progress 进度回调
param complete 完成回调
*/
- (void)loadImage:(NSURL*)url
progress:(GQImageDownloaderProgressBlock)progress
complete:(GQImageDownloaderCompleteBlock)complete;

/**
带默认图片的请求方法

param url 图片地址
param placeHolderImage 默认图片
param progress 进度回调
param complete 完成回调
*/
- (void)loadImage:(NSURL*)url
placeHolder:(UIImage *)placeHolderImage
progress:(GQImageDownloaderProgressBlock)progress
complete:(GQImageDownloaderCompleteBlock)complete;

/**
带自定义请求类的请求方法

param url 图片地址
param className 请求类名
param placeHolderImage 默认图片
param progress 进度回调
param complete 完成回调
*/
- (void)loadImage:(NSURL*)url
requestClassName:(NSString *)className
placeHolder:(UIImage *)placeHolderImage
progress:(GQImageDownloaderProgressBlock)progress
complete:(GQImageDownloaderCompleteBlock)complete;

/**
带缓存类型的请求方法

param url 图片地址
param className 请求类名
param cacheType 缓存类型
param placeHolderImage 默认图片
param progress 进度回调
param complete 完成回调
*/
- (void)loadImage:(NSURL*)url
requestClassName:(NSString *)className
cacheType:(GQImageDownloaderCacheType)cacheType
placeHolder:(UIImage *)placeHolderImage
progress:(GQImageDownloaderProgressBlock)progress
complete:(GQImageDownloaderCompleteBlock)complete;

/**
取消当前请求
*/
- (void)cancelCurrentImageRequest;

/**
取消所有的图片请求
*/
- (void)cancelAllImageRequest;

```

### 属性介绍

(1)缓存策略：

```objc

typedef enum : NSUInteger {
    GQImageDownloaderCacheTypeNone,//无缓存
    GQImageDownloaderCacheTypeOnlyMemory,//仅缓存在内存中
    GQImageDownloaderCacheTypeDisk//缓存至硬盘中
} GQImageDownloaderCacheType;


```

(2)设置请求类：
请求类必须继承于GQImageDownloaderBaseURLRequest，继承请求基类时可覆盖以下方法对自定义请求类进行参数设置

```objc

/**
 进行参数相关的配置，该方法旨在请求参数自定义
*/
- (void)configureRequestData;

/**
 User-Agent

@return User-Agent
*/
- (NSString *)userAgentString;

/**
Cookie

@return Cookie
*/
- (NSString *)storageCookies;

/**
请求接收类型

@return 接收类型
*/
- (NSString *)acceptType;


```


## Level history

(1) 1.0.0

    GitHub添加代码。

(2) 1.0.1

    修复抽取时session遗漏导致无法下载图片

(3) 1.0.2

    代码规范完善

(4) 1.0.3

    缓存判断更新

(5) 1.0.4

    更新缓存策略

(6) 1.0.5

    修改pod默认设置，避免使用webp时还需设置xcode中build setting默认参数

(7) 1.0.6
    
	消除xcode警告并解决可能造成循环引用的block问题
	
(8) 1.0.7
	
	wait a moment


## Support

欢迎指出bug或者需要改善的地方，欢迎提出issues、加Q群交流iOS经验：578841619 ， 我会及时的做出回应，觉得好用的话不妨给个star吧，你的每个star是我持续维护的强大动力。

