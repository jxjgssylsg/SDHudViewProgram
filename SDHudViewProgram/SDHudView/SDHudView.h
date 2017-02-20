//
//  SDHudView.h
//  Novo
//
//  Created by Novo on 16/1/6.
//  Copyright © 2016年 Novo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


// 内容视图显示动画
typedef enum EnumSDHudViewContentAnimateStyle {
    EnumSDHudViewAnimateStyleImmedia,        // 自然出现，默认
    EnumSDHudViewAnimateStyleFromTop,        // 从 HUD 上端移动到指定位置
    EnumSDHudViewAnimateStyleFromBottom,     // 屏幕底部移动到指定位置
    EnumSDHudViewAnimateStyleFromSmallSize   // 从小到大放大
} EnumSDHudViewContentAnimateStyle;


// 内容视图位置
typedef enum EnumSDHudViewContentPositionStyle {
    EnumSDHudViewPositionStyleCenter,   // HUD 中间，默认
    EnumSDHudViewPositionStyleTop,      // HUD 顶部
    EnumSDHudViewPositionStyleBottom    // 屏幕底部
} EnumSDHudViewContentPositionStyle;

// 蒙版
@interface SDHudView : UIView

#pragma mark - 主要
/** 内容视图动画样式 */
@property (nonatomic, assign) EnumSDHudViewContentAnimateStyle contentAnimateStyle;
/** 内容视图真实位置 */
@property (nonatomic, assign) EnumSDHudViewContentPositionStyle contentPositionStyle;

/** 初始化并添加到父视图 */
- (instancetype)initFromSuperView:(UIView *)superView;
/** 添加到父视图 */
- (void)addToSuperView:(UIView *)superView;
/** 每次显示前添加内容视图，内容和Hud会同处一个容器，而不是 Hud 的子视图 */
- (void)addContentView:(id)view;
/** 显示HUD和内容视图 */
- (void)uiShowWithContentView:(id)view;
/** 显示HUD和内容视图 */
- (void)uiShow;
/** 收起，收起之后内容视图被移除 */
- (void)uiHidden;


#pragma mark - 次要
/** 显示动画耗时 */
@property (nonatomic,assign) double timeShowDuring;
/** 收起动画耗时 */
@property (nonatomic,assign) double timeHiddenDuring;
/** 蒙版最终透明度，默认值 0.6 */
@property (nonatomic,assign) double alphaContentEnd;
/** 内容视图在 y 轴的偏移 */
@property (nonatomic,assign) CGFloat contentYOffset;
/** 内容视图在 x 轴的偏移 */
@property (nonatomic,assign) CGFloat contentXOffset;
/** 默认 NO，触摸蒙版是否隐藏 */
@property (nonatomic,assign) BOOL isHiddenWhenTouch;
/** 内容视图是否是在显示中 */
@property (nonatomic,assign,readonly) BOOL isShowing;

/** 蒙版尺寸参考父视图 */
- (void)uiFrameCopySuper;
/** 用户自定义的布局 */
- (void)contentLayoutInSuperUsingBlock:(void(^)(UIView *contentView))block;
/** 显示动画完成后的回调 */
- (void)eventDidContentViewShow:(void(^)())block;
/** 收起动画完成后的回调 */
- (void)eventDidContentViewHidden:(void(^)())block;



@end
