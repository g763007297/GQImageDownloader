//
//  UIImageView+GQImageDownloader.h
//  GQImageDownload
//
//  Created by 高旗 on 2017/11/23.
//  Copyright © 2017年 gaoqi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GQImageDownloaderOperationManager.h"

@interface UIImageView (GQImageDownloader)

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

@end
