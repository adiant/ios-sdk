//  Copyright (c) 2015 Adblade. All rights reserved.

#import "AdbladeBannerCustomEvent.h"
@import AdbladeSDK;

@interface AdbladeBannerCustomEvent() <AdbladeDelegate>
@property (nonatomic, strong) AdbladeBannerView *adBannerView;
@end

@implementation AdbladeBannerCustomEvent
- (void)requestAdWithSize:(CGSize)size customEventInfo:(NSDictionary *)info {
    NSString *containerId = [info objectForKey: @"container_id"];
    NSString *bannerSize = [NSString stringWithFormat: @"%dx%d", (int)size.width, (int)size.height];
    
    if (containerId == nil) {
        AdbladeError *error = [AdbladeError init];
        [self.delegate bannerCustomEvent:self didFailToLoadAdWithError:error];
    }
    else {
        self.adBannerView = (AdbladeBannerView *)[AdbladeViewFactory createView:containerId adSize:bannerSize delegate:self];
        [self.adBannerView loadAd];
    }
}

- (void)willSendRequest:(id<AdbladeView> __nonnull)view url:(NSURL * __nonnull)url {
    NSLog(@"%@", url);
}

- (void)didReceiveAd:(UIView<AdbladeView>*)view {
    [self.delegate bannerCustomEvent:self didLoadAd:self.adBannerView];
}

- (void)didHaveError:(id<AdbladeView> __nonnull)view error:(AdbladeError * __nonnull)error {
    NSLog(@"%@", error.description);
    [self.delegate bannerCustomEvent:self didFailToLoadAdWithError:error];
}

- (void)didDismissScreen:(AdbladeInterstitialView * __nonnull)view {
    [self.delegate bannerCustomEventDidFinishAction:self];
    
}

- (void)willLeaveApplication:(id<AdbladeView> __nonnull)view {
    [self.delegate bannerCustomEventWillLeaveApplication:self];
}

- (void)willShowScreen:(AdbladeInterstitialView * __nonnull)view {
    [self.delegate bannerCustomEventWillBeginAction:self];
    
}

- (void)dealloc {
    self.adBannerView.delegate = nil;
}
@end
