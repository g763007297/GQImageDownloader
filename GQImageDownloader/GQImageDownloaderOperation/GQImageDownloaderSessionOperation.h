//
//  GQSessionOperation.h
//  GQNetWorkDemo
//
//  Created by 高旗 on 16/10/23.
//  Copyright © 2016年 gaoqi. All rights reserved.
//

#import "GQImageDownloaderBaseOperation.h"

@interface GQImageDownloaderSessionOperation : GQImageDownloaderBaseOperation<NSURLSessionTaskDelegate,NSURLSessionDataDelegate>

@property (nonatomic, strong) NSURLSessionDataTask  *operationSessionTask;

@end
