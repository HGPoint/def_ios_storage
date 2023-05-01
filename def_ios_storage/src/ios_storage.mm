#if defined(DM_PLATFORM_IOS) 

#include <Foundation/Foundation.h>
#include <SystemConfiguration/SystemConfiguration.h>
#include <Security/Security.h>
#include <dmsdk/sdk.h>
#include "PDKeychainBindingsController.h"

#if defined(DM_PLATFORM_IOS)
#include <UIKit/UIKit.h>
#endif

namespace dmIOSStorageExt {


void SetStringValue(const char* key, const char*  value)
{
        PDKeychainBindings *bindings = [PDKeychainBindings sharedKeychainBindings];
        [bindings setObject:[NSString stringWithUTF8String:value] forKey:[NSString stringWithUTF8String:key]];

        NSString *username = [bindings objectForKey:[NSString stringWithUTF8String:key]];
}

const char* GetStringValue(const char* key, const char*  defaultValue)
{
        PDKeychainBindings *bindings = [PDKeychainBindings sharedKeychainBindings];
        NSString *username = [bindings objectForKey:[NSString stringWithUTF8String:key]];
        const char *cString = [username cStringUsingEncoding:NSASCIIStringEncoding];
        return cString;
}

void SetDoubleValue(const char* key, double value)
{
        NSString* doubleString = [NSString stringWithFormat:@"%f", value];
        PDKeychainBindings *bindings = [PDKeychainBindings sharedKeychainBindings];
        [bindings setObject:doubleString forKey:[NSString stringWithUTF8String:key]];
}

double GetDoubleValue(const char* key, double defaultValue)
{
        PDKeychainBindings *bindings = [PDKeychainBindings sharedKeychainBindings];

        double var = [[bindings objectForKey:[NSString stringWithUTF8String:key]] doubleValue];
        return var;
}

} // namespace

#endif // platform