//
//  BroadcastClient.h
//  hatomplayer-core
//
//  Created by chencancan on 2022/5/10.
//

#import "Constrants.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BroadcastClientDelegate <NSObject>

/// 广播状态回调方法
/// @param status 播放状态
/// @param errorCode 错误码，只有在 status 状态为： FAILED 、EXCEPTION 才有值 ,其他 status 值为 -1
- (void)onBroadcastStatus:(PlayStatus)status
                errorCode:(int)errorCode
                errorData:(NSString *)errorData;

@end

@interface BroadcastClient : NSObject

@property (nonatomic, weak) id <BroadcastClientDelegate> delegate;

- (void)setAudioType:(int)audioType;

/**
 * 设置广播参数，开启广播前必须调用
 *
 * @param path       取流URL
 * @param indexCodes 广播IndexCode集合
 * @param headers    参数
 */
- (void)addBroadcastDataSource:(NSString * _Nonnull )path
                    indexCodes:(NSArray  * _Nonnull )indexCodes
                       headers:(NSDictionary  * _Nullable )headers;
- (void)startBroadcast;
- (void)stopBroadcast;


@end

NS_ASSUME_NONNULL_END
