//  Copyright (c) 2015 Adblade. All rights reserved.

#import "AdbladeInterstitialCustomEvent.h"
@import AdbladeSDK;

@interface AdbladeInterstitialCustomEvent () <AdbladeDelegate>
    @property (nonatomic, strong) AdbladeInterstitialViewController *interstitialController;
@end

@implementation AdbladeInterstitialCustomEvent
- (void)requestInterstitialWithCustomEventInfo:(NSDictionary *)info {
    NSString *containerId = [info objectForKey: @"container_id"];
    if (containerId == nil) {
        AdbladeError *error = [AdbladeError init];
        [self.delegate interstitialCustomEvent:self didFailToLoadAdWithError:error];
    }
    else {
        AdbladeInterstitialView *interstitial = (AdbladeInterstitialView *)[AdbladeViewFactory createView: containerId adType: AdbladeAdTypemediumRectangle delegate: self];
        self.interstitialController = [[AdbladeInterstitialViewController alloc] init];
        [[self interstitialController] loadAd];
        self.interstitialController.view = interstitial;
    }
}

- (void)willSendRequest:(id<AdbladeView> __nonnull)view url:(NSURL * __nonnull)url {
    NSLog(@"%@", url);
}

- (void)didReceiveAd:(UIView<AdbladeView>*)view {
    [self.delegate interstitialCustomEvent:self didLoadAd:self];
}

- (void)didHaveError:(id<AdbladeView> __nonnull)view error:(AdbladeError * __nonnull)error {
    NSLog(@"%@", error.description);
    [self.delegate interstitialCustomEvent:self didFailToLoadAdWithError:error];
}

- (void)didDismissScreen:(AdbladeInterstitialView * __nonnull)view {
    [self.delegate interstitialCustomEventWillDisappear:self];
}

- (void)willLeaveApplication:(id<AdbladeView> __nonnull)view {
    [self.delegate interstitialCustomEventDidReceiveTapEvent:self];
}

- (void)willShowScreen:(AdbladeInterstitialView * __nonnull)view {
    [self.delegate interstitialCustomEventWillAppear:self];
    [self.delegate interstitialCustomEventDidAppear:self];
}

- (void)showInterstitialFromRootViewController:(UIViewController *)rootViewController {
    [rootViewController.navigationController pushViewController:self.interstitialController animated:YES];
}
@end