# Adblade iOS SDK integration with mopub

1. Integrate the Adblade iOS SDK into your app

For instructions, see our [quick start guide](https://github.com/adiant/ios-sdk/wiki/Getting-Started). 

2. Copy the following files into your project: 

* AdbladeBannerCustomEvent.h
* AdbladeBannerCustomEvent.m
* AdbladeInterstitialCustomEvent.h
* AdbladeInterstitialCustomEvent.m

3. Set native ads inside of mopub by following [their instructions](https://dev.twitter.com/mopub/ui-setup/network-setup-custom-native)

* The custom event class for banners will be "AdbladeBannerCustomEvent". 
* The custom event class for intertitials will be "AdbladeInterstitialCustomEvent". 
* In the "Custom Event Class Data" field, it should look like `{ "container_id": "12345-0001112220" }`. Replace "12345-0001112220" with the container id provided by Adblade.
