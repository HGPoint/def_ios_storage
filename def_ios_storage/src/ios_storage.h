#if defined(DM_PLATFORM_IOS) 

#pragma once

#include <dmsdk/sdk.h>

namespace dmAppsflyerAdRevenue 
{

void SetStringValue(const char* key, const char*  value);
const char*  GetStringValue(const char* key);

void SetDoubleValue(const char* key, double value);
double GetDoubleValue(const char* key, double defaultValue);

} // namespace


#endif // platform