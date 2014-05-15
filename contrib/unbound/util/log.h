begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/log.h - logging service  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains logging functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_LOG_H
end_define

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * verbosity value:  */
end_comment

begin_enum
enum|enum
name|verbosity_value
block|{
comment|/** 0 - no verbose messages */
name|NO_VERBOSE
init|=
literal|0
block|,
comment|/** 1 - operational information */
name|VERB_OPS
block|,
comment|/** 2 - detailed information */
name|VERB_DETAIL
block|,
comment|/** 3 - query level information */
name|VERB_QUERY
block|,
comment|/** 4 - algorithm level information */
name|VERB_ALGO
block|,
comment|/** 5 - querier client information */
name|VERB_CLIENT
block|}
enum|;
end_enum

begin_comment
comment|/** The global verbosity setting */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|verbosity_value
name|verbosity
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * log a verbose message, pass the level for this message.  * It has printf formatted arguments. No trailing newline is needed.  * @param level: verbosity level for this message, compared to global   *	verbosity setting.  * @param format: printf-style format string. Arguments follow.  */
end_comment

begin_function_decl
name|void
name|verbose
parameter_list|(
name|enum
name|verbosity_value
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * call this to initialize logging services.  * @param filename: if NULL stderr is used.  * @param use_syslog: set to true to ignore filename and use syslog(3).  * @param chrootdir: to which directory we have been chrooted, if any.  */
end_comment

begin_function_decl
name|void
name|log_init
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|use_syslog
parameter_list|,
specifier|const
name|char
modifier|*
name|chrootdir
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set logging to go to the specified file *.  * This setting does not affect the use_syslog setting.  * @param f: to that file, or pass NULL to disable logging.  */
end_comment

begin_function_decl
name|void
name|log_file
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Init a thread (will print this number for the thread log entries).  * Must be called from the thread itself. If not called 0 is printed.  * @param num: number to print for this thread. Owned by caller, must  *	continue to exist.  */
end_comment

begin_function_decl
name|void
name|log_thread_set
parameter_list|(
name|int
modifier|*
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set identity to print, default is 'unbound'.   * @param id: string to print. Name of executable.  */
end_comment

begin_function_decl
name|void
name|log_ident_set
parameter_list|(
specifier|const
name|char
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the time value to print in log entries.  * @param t: the point is copied and used to find the time.  * 	if NULL, time(2) is used.  */
end_comment

begin_function_decl
name|void
name|log_set_time
parameter_list|(
name|time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set if the time value is printed ascii or decimal in log entries.  * @param use_asc: if true, ascii is printed, otherwise decimal.  *	If the conversion fails or you have no time functions,   *	decimal is printed.  */
end_comment

begin_function_decl
name|void
name|log_set_time_asc
parameter_list|(
name|int
name|use_asc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Log informational message.  * Pass printf formatted arguments. No trailing newline is needed.  * @param format: printf-style format string. Arguments follow.  */
end_comment

begin_function_decl
name|void
name|log_info
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Log error message.  * Pass printf formatted arguments. No trailing newline is needed.  * @param format: printf-style format string. Arguments follow.  */
end_comment

begin_function_decl
name|void
name|log_err
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Log warning message.  * Pass printf formatted arguments. No trailing newline is needed.  * @param format: printf-style format string. Arguments follow.  */
end_comment

begin_function_decl
name|void
name|log_warn
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Log a hex-string to the log. Can be any length.  * performs mallocs to do so, slow. But debug useful.  * @param msg: string desc to accompany the hexdump.  * @param data: data to dump in hex format.  * @param length: length of data.  */
end_comment

begin_function_decl
name|void
name|log_hex
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Easy alternative for log_hex, takes a sldns_buffer.  * @param level: verbosity level for this message, compared to global   *	verbosity setting.  * @param msg: string desc to print  * @param buf: the buffer.  */
end_comment

begin_function_decl
name|void
name|log_buf
parameter_list|(
name|enum
name|verbosity_value
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Log fatal error message, and exit the current process.  * Pass printf formatted arguments. No trailing newline is needed.  * @param format: printf-style format string. Arguments follow.  */
end_comment

begin_function_decl
name|void
name|fatal_exit
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * va_list argument version of log_info.  * @param pri: priority type, for example 5 (INFO).  * @param type: string to designate type of message (info, error).  * @param format: the printf style format to print. no newline.  * @param args: arguments for format string.  */
end_comment

begin_function_decl
name|void
name|log_vmsg
parameter_list|(
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * an assertion that is thrown to the logfile.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNBOUND_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|log_assert
parameter_list|(
name|x
parameter_list|)
define|\
value|do { if(!(x)) \ 		fatal_exit("%s:%d: %s: assertion %s failed", \ 			__FILE__, __LINE__, __func__, #x); \ 	} while(0);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|log_assert
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WINSOCK
end_ifdef

begin_comment
comment|/**  * Convert WSA error into string.  * @param err: from WSAGetLastError()  * @return: string.  */
end_comment

begin_function_decl
name|char
modifier|*
name|wsa_strerror
parameter_list|(
name|DWORD
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_WINSOCK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_LOG_H */
end_comment

end_unit

