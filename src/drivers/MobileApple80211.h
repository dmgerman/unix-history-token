begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MOBILEAPPLE80211_H
end_ifndef

begin_define
define|#
directive|define
name|MOBILEAPPLE80211_H
end_define

begin_comment
comment|/*  * MobileApple80211 interface for iPhone/iPod touch  * These functions are available from Aeropuerto.  */
end_comment

begin_struct_decl
struct_decl|struct
name|Apple80211
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Apple80211
modifier|*
name|Apple80211Ref
typedef|;
end_typedef

begin_function_decl
name|int
name|Apple80211Open
parameter_list|(
name|Apple80211Ref
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211Close
parameter_list|(
name|Apple80211Ref
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211GetIfListCopy
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFArrayRef
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211BindToInterface
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFStringRef
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211GetInterfaceNameCopy
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFStringRef
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211GetInfoCopy
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFDictionaryRef
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211GetPower
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|char
modifier|*
name|pwr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211SetPower
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|char
name|pwr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parameters can be NULL; returns scan results in CFArrayRef *list;  * caller will need to free with CFRelease() */
end_comment

begin_function_decl
name|int
name|Apple80211Scan
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFArrayRef
modifier|*
name|list
parameter_list|,
name|CFDictionaryRef
name|parameters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211Associate
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFDictionaryRef
name|bss
parameter_list|,
name|CFStringRef
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Apple80211AssociateAndCopyInfo
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|CFDictionaryRef
name|bss
parameter_list|,
name|CFStringRef
name|password
parameter_list|,
name|CFDictionaryRef
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|APPLE80211_VALUE_SSID
init|=
literal|1
block|,
name|APPLE80211_VALUE_BSSID
init|=
literal|9
block|}
enum|;
end_enum

begin_function_decl
name|int
name|Apple80211CopyValue
parameter_list|(
name|Apple80211Ref
name|handle
parameter_list|,
name|int
name|field
parameter_list|,
name|CFDictionaryRef
name|arg2
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOBILEAPPLE80211_H */
end_comment

end_unit

