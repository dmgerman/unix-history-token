begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGGING_H
end_ifndef

begin_define
define|#
directive|define
name|LOGGING_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|log_critical
value|(-5)
end_define

begin_define
define|#
directive|define
name|log_error
value|(-4)
end_define

begin_define
define|#
directive|define
name|log_warning
value|(-3)
end_define

begin_define
define|#
directive|define
name|log_notice
value|(-2)
end_define

begin_define
define|#
directive|define
name|log_info
value|(-1)
end_define

begin_define
define|#
directive|define
name|log_debug
parameter_list|(
name|level
parameter_list|)
value|(level)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|log_syslog
block|,
name|log_file
block|,
name|log_null
block|}
name|log_channel_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOG_MAX_VERSIONS
value|99
end_define

begin_define
define|#
directive|define
name|LOG_CLOSE_STREAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|LOG_TIMESTAMP
value|0x0002
end_define

begin_define
define|#
directive|define
name|LOG_TRUNCATE
value|0x0004
end_define

begin_define
define|#
directive|define
name|LOG_USE_CONTEXT_LEVEL
value|0x0008
end_define

begin_define
define|#
directive|define
name|LOG_PRINT_LEVEL
value|0x0010
end_define

begin_define
define|#
directive|define
name|LOG_REQUIRE_DEBUG
value|0x0020
end_define

begin_define
define|#
directive|define
name|LOG_CHANNEL_BROKEN
value|0x0040
end_define

begin_define
define|#
directive|define
name|LOG_PRINT_CATEGORY
value|0x0080
end_define

begin_define
define|#
directive|define
name|LOG_CHANNEL_OFF
value|0x0100
end_define

begin_typedef
typedef|typedef
name|struct
name|log_context
modifier|*
name|log_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|log_channel
modifier|*
name|log_channel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOG_OPTION_DEBUG
value|0x01
end_define

begin_define
define|#
directive|define
name|LOG_OPTION_LEVEL
value|0x02
end_define

begin_define
define|#
directive|define
name|log_open_stream
value|__log_open_stream
end_define

begin_define
define|#
directive|define
name|log_close_stream
value|__log_close_stream
end_define

begin_define
define|#
directive|define
name|log_get_stream
value|__log_get_stream
end_define

begin_define
define|#
directive|define
name|log_get_filename
value|__log_get_filename
end_define

begin_define
define|#
directive|define
name|log_check_channel
value|__log_check_channel
end_define

begin_define
define|#
directive|define
name|log_check
value|__log_check
end_define

begin_define
define|#
directive|define
name|log_vwrite
value|__log_vwrite
end_define

begin_define
define|#
directive|define
name|log_write
value|__log_write
end_define

begin_define
define|#
directive|define
name|log_new_context
value|__log_new_context
end_define

begin_define
define|#
directive|define
name|log_free_context
value|__log_free_context
end_define

begin_define
define|#
directive|define
name|log_add_channel
value|__log_add_channel
end_define

begin_define
define|#
directive|define
name|log_remove_channel
value|__log_remove_channel
end_define

begin_define
define|#
directive|define
name|log_option
value|__log_option
end_define

begin_define
define|#
directive|define
name|log_category_is_active
value|__log_category_is_active
end_define

begin_define
define|#
directive|define
name|log_new_syslog_channel
value|__log_new_syslog_channel
end_define

begin_define
define|#
directive|define
name|log_new_file_channel
value|__log_new_file_channel
end_define

begin_define
define|#
directive|define
name|log_set_file_owner
value|__log_set_file_owner
end_define

begin_define
define|#
directive|define
name|log_new_null_channel
value|__log_new_null_channel
end_define

begin_define
define|#
directive|define
name|log_inc_references
value|__log_inc_references
end_define

begin_define
define|#
directive|define
name|log_dec_references
value|__log_dec_references
end_define

begin_define
define|#
directive|define
name|log_get_channel_type
value|__log_get_channel_type
end_define

begin_define
define|#
directive|define
name|log_free_channel
value|__log_free_channel
end_define

begin_function_decl
name|FILE
modifier|*
name|log_open_stream
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_close_stream
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|log_get_stream
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|log_get_filename
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_check_channel
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_check
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_vwrite
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_write
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_new_context
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|log_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_free_context
parameter_list|(
name|log_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_add_channel
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_remove_channel
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_option
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_category_is_active
parameter_list|(
name|log_context
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|log_channel
name|log_new_syslog_channel
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|log_channel
name|log_new_file_channel
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_set_file_owner
parameter_list|(
name|log_channel
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|log_channel
name|log_new_null_channel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_inc_references
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_dec_references
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|log_channel_type
name|log_get_channel_type
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|log_free_channel
parameter_list|(
name|log_channel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOGGING_H */
end_comment

end_unit

