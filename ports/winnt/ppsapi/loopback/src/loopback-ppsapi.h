begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|// serialpps-ppsapi-provider.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For this tiny project the single header serves as a precompiled header
end_comment

begin_comment
comment|// as well, meaning all the bulky headers are included before or within it.
end_comment

begin_comment
comment|// Within, in this case.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|_CRT_SECURE_NO_WARNINGS
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_typedef
typedef|typedef
name|__int32
name|int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|u_int64
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"timepps.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED
end_ifndef

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|item
parameter_list|)
value|((void)(item))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS data structure as captured by the serial line I/O system. This  * must match the local definition in 'ntp_iocompletionport.c' or  * 'Bad Things (tm)' are bound to happen.  */
end_comment

begin_struct
struct|struct
name|PpsData
block|{
name|u_long
name|cc_assert
decl_stmt|;
name|u_long
name|cc_clear
decl_stmt|;
name|ntp_fp_t
name|ts_assert
decl_stmt|;
name|ntp_fp_t
name|ts_clear
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|PpsData
name|PPSData_t
typedef|;
end_typedef

begin_comment
comment|/* prototypes imported from the NTPD executable */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|HANDLE
name|WINAPI
name|ntp_pps_attach_device
parameter_list|(
name|HANDLE
name|hndIo
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|WINAPI
name|ntp_pps_detach_device
parameter_list|(
name|HANDLE
name|ppsHandle
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|BOOL
name|WINAPI
name|ntp_pps_read
parameter_list|(
name|HANDLE
name|ppsHandle
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prototypes exported to the NTPD executable */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|prov_time_pps_create
parameter_list|(
name|HANDLE
parameter_list|,
name|pps_handle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|prov_time_pps_destroy
parameter_list|(
name|pps_unit_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|prov_time_pps_setparams
parameter_list|(
name|pps_unit_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|pps_params_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|prov_time_pps_fetch
parameter_list|(
name|pps_unit_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
name|pps_info_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|prov_time_pps_kcbind
parameter_list|(
name|pps_unit_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|int
name|WINAPI
name|ppsapi_prov_init
parameter_list|(
name|int
parameter_list|,
name|pcreate_pps_handle
parameter_list|,
name|ppps_ntp_timestamp_from_counter
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

