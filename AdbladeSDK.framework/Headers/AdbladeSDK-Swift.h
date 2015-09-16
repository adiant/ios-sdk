// Generated by Apple Swift version 1.2 (swiftlang-602.0.53.1 clang-602.0.53)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import CoreGraphics;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

/// Different types of ads.
///
/// <ul><li><dl><dt>native:</dt><dd><ul><li><p>298x224 image</p></li><li><p>title</p></li><li><p>description</p></li><li><p>display name</p></li></ul></dd></dl></li><li><p>mediumRectangle: 300x250</p></li><li><p>richMediaMediumRectangle: 300x250 Rich Media</p></li><li><p>leaderboard: 728x90</p></li><li><p>richMediaLeaderboard: 728x90 Rich Media</p></li><li><p>banner: 320x50</p></li><li><p>mediumBanner: 320x100</p></li><li><p>fullBanner: 468x60</p></li><li><p>slideshow - a collection of the other ad types that can be rotated through</p></li></ul>
/// If you do not specify ad ad type, one or more will be chosen for you based on the selected view. If this
/// is the case, the 300x250 ones can be grouped together and the 728x90 ones can be grouped together. Only
/// one ad will be returned, but it can be of any of those types. 
typedef SWIFT_ENUM(NSInteger, AdbladeAdType) {
  AdbladeAdTypenative = 1,
  AdbladeAdTyperichMediaMediumRectangle = 4,
  AdbladeAdTyperichMediaLeaderboard = 6,
  AdbladeAdTypemediumRectangle = 14,
  AdbladeAdTypeleaderboard = 15,
  AdbladeAdTypebanner = 77,
  AdbladeAdTypeslideshow = 79,
  AdbladeAdTypemediumBanner = 83,
  AdbladeAdTypefullBanner = 84,
};

enum AdbladeViewType : NSInteger;
@protocol AdbladeDelegate;


/// The protocol used for all Adblade views. This should not be implemented.
SWIFT_PROTOCOL("_TtP10AdbladeSDK11AdbladeView_")
@protocol AdbladeView <UIGestureRecognizerDelegate>

/// An integer representing the AdbladeAdType that the view will be showing.
@property (nonatomic, copy) NSArray * __nonnull adTypes;

/// The view type.
@property (nonatomic, readonly) enum AdbladeViewType viewType;

/// The container id the view will use. This should be provided by Adblade.
@property (nonatomic, copy) NSString * __null_unspecified containerId;

/// The AdViewDelegate the view will use if the implementing app wants to
/// track Adblade's events. This is optional.
@property (nonatomic) id <AdbladeDelegate> __nullable delegate;

/// Load the ad into the view.
- (void)loadAd;
@end

@class NSCoder;


/// The implementation of AdbladeView that handles banner ads.
SWIFT_CLASS("_TtC10AdbladeSDK17AdbladeBannerView")
@interface AdbladeBannerView : UIView <AdbladeView, UIGestureRecognizerDelegate>

/// The view type.
@property (nonatomic, readonly) enum AdbladeViewType viewType;

/// The AdbladeAdType that the view will be showing.
@property (nonatomic, copy) NSArray * __nonnull adTypes;

/// The AdbladeDelegate the view will use if the implementing app wants to
/// track Adblade's events. This is optional.
@property (nonatomic) id <AdbladeDelegate> __nullable delegate;

/// The container id the view will use. This should be provided by Adblade.
@property (nonatomic, copy) NSString * __null_unspecified containerId;

/// Load the ad into the view.
- (void)loadAd;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURL;
@class AdbladeError;
@class AdbladeInterstitialView;


/// This can be used if you want to track any events during the process. All methods are
/// optional and you only have to implement what you need.
///
/// <dl><dt>class ViewController: UIViewController, AdbladeDelegate {</dt><dd><p>//...
/// adbladeView.delegate = self
/// //...</p><dl><dt>func didReceiveAd(view: AdbladeView) {</dt><dd><p>//...</p></dd></dl><p>}</p></dd></dl>
/// }
SWIFT_PROTOCOL("_TtP10AdbladeSDK15AdbladeDelegate_")
@protocol AdbladeDelegate
@optional

/// Fires when request is sent to ad server.
- (void)willSendRequest:(id <AdbladeView> __nonnull)view url:(NSURL * __nonnull)url;

/// This executes when the ad is successfully received and ready to be shown.
///
/// \param view The AdbladeView that the ad will be shown in.
- (void)didReceiveAd:(id <AdbladeView> __nonnull)view;

/// This executes when the ad was not successfully received.
///
/// \param view The AdbladeView that the ad will be shown in.
///
/// \param error The NSError object that explains what went wrong.
- (void)didHaveError:(id <AdbladeView> __nonnull)view error:(AdbladeError * __nonnull)error;

/// This executes immediately before an AdbladeInterstitialView is going to be shown.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)willShowScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately before an AdbladeInterstitialView is going to be closed.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)willDismissScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately after an AdbladeInterstitialView is closed.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)didDismissScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately before the user leaves your application. This will
/// be run when a tap event occurs on an ad.
///
/// \param view The AdbladeView that the ad will be shown in.
- (void)willLeaveApplication:(id <AdbladeView> __nonnull)view;
@end



/// An extension of NSError.
SWIFT_CLASS("_TtC10AdbladeSDK12AdbladeError")
@interface AdbladeError : NSError

/// Constructor
///
/// \param aDecoder 
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIButton;


/// The implementation of AdbladeView that handles interstitial ads.
/// This is a subclass of AdbladeBannerView.
SWIFT_CLASS("_TtC10AdbladeSDK23AdbladeInterstitialView")
@interface AdbladeInterstitialView : UIView <AdbladeView, UIGestureRecognizerDelegate>

/// The view type.
@property (nonatomic, readonly) enum AdbladeViewType viewType;

/// The AdbladeAdType that the view will be showing.
@property (nonatomic, copy) NSArray * __nonnull adTypes;

/// The AdbladeDelegate the view will use if the implementing app wants to
/// track Adblade's events. This is optional.
@property (nonatomic) id <AdbladeDelegate> __nullable delegate;

/// The button used to close this view.
@property (nonatomic, readonly) UIButton * __nullable closeButton;

/// The container id the view will use. This should be provided by Adblade.
@property (nonatomic, copy) NSString * __null_unspecified containerId;

/// Load the ad into the view.
- (void)loadAd;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSBundle;


/// A controller for interstitial views. 
SWIFT_CLASS("_TtC10AdbladeSDK33AdbladeInterstitialViewController")
@interface AdbladeInterstitialViewController : UIViewController <AdbladeDelegate>

/// The container id used to show ads in the view.
@property (nonatomic, copy) NSString * __nonnull containerId;

/// Constructor
///
/// \param aDecoder 
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;

/// Constructor
///
/// \param nibNameOrNil 
///
/// \param nibBundleOrNil 
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;

/// Loads the view.
- (void)loadView;

/// Load the ad into the view.
- (void)loadAd;

/// Fires when request is sent to ad server.
- (void)willSendRequest:(id <AdbladeView> __nonnull)view url:(NSURL * __nonnull)url;

/// This executes when the ad is successfully received and ready to be shown.
///
/// \param view The AdbladeView that the ad will be shown in.
- (void)didReceiveAd:(id <AdbladeView> __nonnull)view;

/// This executes when the ad was not successfully received.
///
/// \param view The AdbladeView that the ad will be shown in.
///
/// \param error The NSError object that explains what went wrong.
- (void)didHaveError:(id <AdbladeView> __nonnull)view error:(AdbladeError * __nonnull)error;

/// This executes immediately before an AdbladeInterstitialView is going to be shown.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)willShowScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately before an AdbladeInterstitialView is going to be closed.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)willDismissScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately after an AdbladeInterstitialView is closed.
///
/// \param view The AdbladeInterstitialView that the ad will be shown in.
- (void)didDismissScreen:(AdbladeInterstitialView * __nonnull)view;

/// This executes immediately before the user leaves your application. This will
/// be run when a tap event occurs on an ad.
///
/// \param view The AdbladeView that the ad will be shown in.
- (void)willLeaveApplication:(id <AdbladeView> __nonnull)view;
@end


SWIFT_CLASS("_TtC10AdbladeSDK20AdbladeNativeAdapter")
@interface AdbladeNativeAdapter

/// The click URL of the ad.
@property (nonatomic, readonly) NSURL * __nonnull clickUrl;
@end



/// The implementation of AdbladeView that handles native ads.
SWIFT_CLASS("_TtC10AdbladeSDK17AdbladeNativeView")
@interface AdbladeNativeView : UIView <AdbladeView, UIGestureRecognizerDelegate>

/// The view type.
@property (nonatomic, readonly) enum AdbladeViewType viewType;

/// The AdbladeAdType that the view will be showing.
@property (nonatomic, copy) NSArray * __nonnull adTypes;

/// The AdbladeDelegate the view will use if the implementing app wants to
/// track Adblade's events. This is optional.
@property (nonatomic) id <AdbladeDelegate> __nullable delegate;

/// The exposed native ad for external libraries.
@property (nonatomic, readonly) AdbladeNativeAdapter * __nullable adAdapter;

/// The container id the view will use. This should be provided by Adblade.
@property (nonatomic, copy) NSString * __null_unspecified containerId;

/// This is called when each element (e.g. title) of the native ad is added
/// to the AdbladeView.
///
/// \param subview The subview that was added.
- (void)didAddSubview:(UIView * __nonnull)subview;

/// Resize this properly. 
///
/// \param size 
///
/// \returns The size to change that fits the subviews.
- (CGSize)sizeThatFits:(CGSize)size;

/// Load the ad into the view.
- (void)loadAd;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end



/// View for slideshow interstitial ads.
SWIFT_CLASS("_TtC10AdbladeSDK20AdbladeSlideshowView")
@interface AdbladeSlideshowView : UICollectionView

/// Constructor
///
/// \param aDecoder 
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end




/// Create views for Adblade Ads
SWIFT_CLASS("_TtC10AdbladeSDK18AdbladeViewFactory")
@interface AdbladeViewFactory

/// Create a view for Adblade Ads
///
/// \param containerId The container id used to fetch the ads. This should be provided by Adblade.
///
/// \param adSize The size of the ad that you want to show (e.g. "300x250")
///
/// \param delegate An (optional) implementation of AdbladeDelegate.
///
/// \returns an object that implements AdbladeView or nil
+ (id <AdbladeView> __nullable)createView:(NSString * __nonnull)containerId adSize:(NSString * __nonnull)adSize delegate:(id <AdbladeDelegate> __nullable)delegate;

/// Create a view for Adblade Ads
///
/// \param containerId The container id used to fetch the ads. This should be provided by Adblade.
///
/// \param viewType The type of view that you want to show.
///
/// \param delegate An (optional) implementation of AdbladeDelegate.
///
/// \returns an object that implements AdbladeView or nil
+ (id <AdbladeView> __nullable)createView:(NSString * __nonnull)containerId viewType:(enum AdbladeViewType)viewType delegate:(id <AdbladeDelegate> __nullable)delegate;

/// Create a view for Adblade Ads
///
/// \param containerId The container id used to fetch the ads. This should be provided by Adblade.
///
/// \param adType The type of ad that you want to display.
///
/// \param delegate An (optional) implementation of AdbladeDelegate.
///
/// \returns an object that implements AdbladeView or nil
+ (id <AdbladeView> __nullable)createView:(NSString * __nonnull)containerId adType:(enum AdbladeAdType)adType delegate:(id <AdbladeDelegate> __nullable)delegate;

/// Create a view for Adblade Ads
///
/// \param containerId The container id used to fetch the ads. This should be provided by Adblade.
///
/// \param adType The type of ad that you want to display.
///
/// \returns an object that implements UIView or nil
+ (id <AdbladeView> __nullable)createView:(NSString * __nonnull)containerId adType:(enum AdbladeAdType)adType;
@end


/// Different types of views.
///
/// <ul><li><dl><dt>banner: allowed ad types</dt><dd><ul><li><p>banner</p></li><li><p>mediumBanner</p></li><li><p>fullBanner</p></li></ul></dd></dl></li><li><dl><dt>interstitial: allowed ad types</dt><dd><ul><li><p>mediumRectangle</p></li><li><p>leaderboard</p></li><li><p>slideshow</p></li></ul></dd></dl></li><li><dl><dt>native</dt><dd><ul><li><p>native</p></li></ul></dd></dl></li></ul>
typedef SWIFT_ENUM(NSInteger, AdbladeViewType) {
  AdbladeViewTypebanner = 1,
  AdbladeViewTypeinterstitial = 2,
  AdbladeViewTypenative = 3,
};

#pragma clang diagnostic pop
