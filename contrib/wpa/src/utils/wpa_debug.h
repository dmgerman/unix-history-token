begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd / Debug prints  * Copyright (c) 2002-2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_DEBUG_H
end_define

begin_include
include|#
directive|include
file|"wpabuf.h"
end_include

begin_comment
comment|/* Debugging function - conditional printf and hex dump. Driver wrappers can  * use these for debugging purposes. */
end_comment

begin_enum
enum|enum
block|{
name|MSG_MSGDUMP
block|,
name|MSG_DEBUG
block|,
name|MSG_INFO
block|,
name|MSG_WARNING
block|,
name|MSG_ERROR
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_STDOUT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|wpa_debug_print_timestamp
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_printf
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_buf
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_key
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_buf_key
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii_key
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_debug_open_file
parameter_list|(
name|p
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_debug_close_file
parameter_list|()
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_function_decl
name|int
name|wpa_debug_open_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_debug_close_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_debug_printf_timestamp - Print timestamp for debug output  *  * This function prints a timestamp in seconds_from_1970.microsoconds  * format if debug output has been configured to include timestamps in debug  * messages.  */
end_comment

begin_function_decl
name|void
name|wpa_debug_print_timestamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_printf - conditional printf  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
end_comment

begin_function_decl
name|void
name|wpa_printf
parameter_list|(
name|int
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * wpa_hexdump - conditional hex dump  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|wpa_hexdump_buf
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
block|{
name|wpa_hexdump
argument_list|(
name|level
argument_list|,
name|title
argument_list|,
name|wpabuf_head
argument_list|(
name|buf
argument_list|)
argument_list|,
name|wpabuf_len
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * wpa_hexdump_key - conditional hex dump, hide keys  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump. This works  * like wpa_hexdump(), but by default, does not include secret keys (passwords,  * etc.) in debug output.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_key
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|wpa_hexdump_buf_key
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
block|{
name|wpa_hexdump_key
argument_list|(
name|level
argument_list|,
name|title
argument_list|,
name|wpabuf_head
argument_list|(
name|buf
argument_list|)
argument_list|,
name|wpabuf_len
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * wpa_hexdump_ascii - conditional hex dump  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump with both  * the hex numbers and ASCII characters (for printable range) are shown. 16  * bytes per line will be shown.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_ascii
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_hexdump_ascii_key - conditional hex dump, hide keys  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump with both  * the hex numbers and ASCII characters (for printable range) are shown. 16  * bytes per line will be shown. This works like wpa_hexdump_ascii(), but by  * default, does not include secret keys (passwords, etc.) in debug output.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_ascii_key
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_WPA_MSG
end_ifdef

begin_define
define|#
directive|define
name|wpa_msg
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_msg_register_cb
parameter_list|(
name|f
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_WPA_MSG */
end_comment

begin_comment
comment|/**  * wpa_msg - Conditional printf for default target and ctrl_iface monitors  * @ctx: Pointer to context data; this is the ctx variable registered  *	with struct wpa_driver_ops::init()  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. This function is like wpa_printf(), but it also sends the  * same message to all attached ctrl_iface monitors.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
end_comment

begin_function_decl
name|void
name|wpa_msg
parameter_list|(
name|void
modifier|*
name|ctx
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
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|wpa_msg_cb_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * wpa_msg_register_cb - Register callback function for wpa_msg() messages  * @func: Callback function (%NULL to unregister)  */
end_comment

begin_function_decl
name|void
name|wpa_msg_register_cb
parameter_list|(
name|wpa_msg_cb_func
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_WPA_MSG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_HOSTAPD_LOGGER
end_ifdef

begin_define
define|#
directive|define
name|hostapd_logger
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|hostapd_logger_register_cb
parameter_list|(
name|f
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_HOSTAPD_LOGGER */
end_comment

begin_function_decl
name|void
name|hostapd_logger
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
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
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hostapd_logger_cb_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
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
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * hostapd_logger_register_cb - Register callback function for hostapd_logger()  * @func: Callback function (%NULL to unregister)  */
end_comment

begin_function_decl
name|void
name|hostapd_logger_register_cb
parameter_list|(
name|hostapd_logger_cb_func
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_HOSTAPD_LOGGER */
end_comment

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IEEE80211
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IEEE8021X
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_RADIUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_WPA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_DRIVER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_IAPP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODULE_MLME
value|0x00000040
end_define

begin_enum
enum|enum
name|hostapd_logger_level
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

begin_ifdef
ifdef|#
directive|ifdef
name|EAPOL_TEST
end_ifdef

begin_define
define|#
directive|define
name|WPA_ASSERT
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							       \ 		if (!(a)) {					       \ 			printf("WPA_ASSERT FAILED '" #a "' "	       \ 			       "%s %s:%d\n",			       \ 			       __FUNCTION__, __FILE__, __LINE__);      \ 			exit(1);				       \ 		}						       \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WPA_ASSERT
parameter_list|(
name|a
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_DEBUG_H */
end_comment

end_unit

