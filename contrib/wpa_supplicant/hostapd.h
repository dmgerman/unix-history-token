begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HOSTAPD_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTAPD_H
end_define

begin_comment
comment|/*  * Minimal version of hostapd header files for eapol_test to build  * radiusclient.c.  */
end_comment

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function_decl
name|void
name|hostapd_logger
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|,
name|unsigned
name|int
name|module
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_struct_decl
struct_decl|struct
name|hostapd_ip_addr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hostapd_ip_txt
parameter_list|(
specifier|const
name|struct
name|hostapd_ip_addr
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_enum
enum|enum
block|{
name|HOSTAPD_LEVEL_DEBUG_VERBOSE
init|=
literal|0
block|,
name|HOSTAPD_LEVEL_DEBUG
init|=
literal|1
block|,
name|HOSTAPD_LEVEL_INFO
init|=
literal|2
block|,
name|HOSTAPD_LEVEL_NOTICE
init|=
literal|3
block|,
name|HOSTAPD_LEVEL_WARNING
init|=
literal|4
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|BIT
end_ifndef

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IEEE80211
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IEEE8021X
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_RADIUS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_WPA
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_DRIVER
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IAPP
value|BIT(5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOSTAPD_H */
end_comment

end_unit

