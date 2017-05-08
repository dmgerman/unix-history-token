begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2015 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECURITY_OPENPAM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SECURITY_OPENPAM_H_INCLUDED
end_define

begin_comment
comment|/*  * Annoying but necessary header pollution  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<security/openpam_attr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
struct_decl|struct
name|passwd
struct_decl|;
comment|/*  * API extensions  */
name|int
name|openpam_borrow_cred
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
name|_pwd
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|2
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|openpam_subst
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
modifier|*
name|_bufsize
parameter_list|,
specifier|const
name|char
modifier|*
name|_template
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpam_free_data
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|int
name|_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpam_free_envlist
parameter_list|(
name|char
modifier|*
modifier|*
name|_envlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|openpam_get_option
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpam_restore_cred
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|openpam_set_option
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_option
parameter_list|,
specifier|const
name|char
modifier|*
name|_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pam_error
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pam_get_authtok
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_item
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|_authtok
parameter_list|,
specifier|const
name|char
modifier|*
name|_prompt
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pam_info
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pam_prompt
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_style
parameter_list|,
name|char
modifier|*
modifier|*
name|_resp
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|4
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pam_setenv
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_value
parameter_list|,
name|int
name|_overwrite
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pam_vinfo
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
name|va_list
name|_ap
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pam_verror
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
name|va_list
name|_ap
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pam_vprompt
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_style
parameter_list|,
name|char
modifier|*
modifier|*
name|_resp
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
name|va_list
name|_ap
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|4
operator|,
function_decl|0
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|1
operator|,
literal|4
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Read cooked lines.  * Checking for _IOFBF is a fairly reliable way to detect the presence  * of<stdio.h>, as SUSv3 requires it to be defined there.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IOFBF
end_ifdef

begin_function_decl
name|char
modifier|*
name|openpam_readline
parameter_list|(
name|FILE
modifier|*
name|_f
parameter_list|,
name|int
modifier|*
name|_lineno
parameter_list|,
name|size_t
modifier|*
name|_lenp
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
modifier|*
name|openpam_readlinev
parameter_list|(
name|FILE
modifier|*
name|_f
parameter_list|,
name|int
modifier|*
name|_lineno
parameter_list|,
name|int
modifier|*
name|_lenp
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|openpam_readword
parameter_list|(
name|FILE
modifier|*
name|_f
parameter_list|,
name|int
modifier|*
name|_lineno
parameter_list|,
name|size_t
modifier|*
name|_lenp
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|openpam_straddch
parameter_list|(
name|char
modifier|*
modifier|*
name|_str
parameter_list|,
name|size_t
modifier|*
name|_sizep
parameter_list|,
name|size_t
modifier|*
name|_lenp
parameter_list|,
name|int
name|ch
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Enable / disable optional features  */
end_comment

begin_enum
enum|enum
block|{
name|OPENPAM_RESTRICT_SERVICE_NAME
block|,
name|OPENPAM_VERIFY_POLICY_FILE
block|,
name|OPENPAM_RESTRICT_MODULE_NAME
block|,
name|OPENPAM_VERIFY_MODULE_FILE
block|,
name|OPENPAM_FALLBACK_TO_OTHER
block|,
name|OPENPAM_NUM_FEATURES
block|}
enum|;
end_enum

begin_function_decl
name|int
name|openpam_set_feature
parameter_list|(
name|int
name|_feature
parameter_list|,
name|int
name|_onoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpam_get_feature
parameter_list|(
name|int
name|_feature
parameter_list|,
name|int
modifier|*
name|_onoff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Log levels  */
end_comment

begin_enum
enum|enum
block|{
name|PAM_LOG_LIBDEBUG
init|=
operator|-
literal|1
block|,
name|PAM_LOG_DEBUG
block|,
name|PAM_LOG_VERBOSE
block|,
name|PAM_LOG_NOTICE
block|,
name|PAM_LOG_ERROR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Log to syslog  */
end_comment

begin_function_decl
name|void
name|_openpam_log
parameter_list|(
name|int
name|_level
parameter_list|,
specifier|const
name|char
modifier|*
name|_func
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|3
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
operator|(
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|)
end_if

begin_define
define|#
directive|define
name|openpam_log
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_openpam_log((lvl), __func__, __VA_ARGS__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|3
operator|)
end_elif

begin_define
define|#
directive|define
name|openpam_log
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_openpam_log((lvl), __func__, __VA_ARGS__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|2
operator|)
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|95
operator|)
end_elif

begin_define
define|#
directive|define
name|openpam_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|_openpam_log((lvl), __func__, ##fmt)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FUNCTION__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|openpam_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|_openpam_log((lvl), __FUNCTION__, ##fmt)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|openpam_log
parameter_list|(
name|int
name|_level
parameter_list|,
specifier|const
name|char
modifier|*
name|_format
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_expr_stmt
unit|))
name|OPENPAM_NONNULL
argument_list|(
operator|(
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Generic conversation function  */
end_comment

begin_struct_decl
struct_decl|struct
name|pam_message
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pam_response
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|openpam_ttyconv
parameter_list|(
name|int
name|_n
parameter_list|,
specifier|const
name|struct
name|pam_message
modifier|*
modifier|*
name|_msg
parameter_list|,
name|struct
name|pam_response
modifier|*
modifier|*
name|_resp
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|openpam_ttyconv_timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Null conversation function  */
end_comment

begin_function_decl
name|int
name|openpam_nullconv
parameter_list|(
name|int
name|_n
parameter_list|,
specifier|const
name|struct
name|pam_message
modifier|*
modifier|*
name|_msg
parameter_list|,
name|struct
name|pam_response
modifier|*
modifier|*
name|_resp
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PAM primitives  */
end_comment

begin_enum
enum|enum
block|{
name|PAM_SM_AUTHENTICATE
block|,
name|PAM_SM_SETCRED
block|,
name|PAM_SM_ACCT_MGMT
block|,
name|PAM_SM_OPEN_SESSION
block|,
name|PAM_SM_CLOSE_SESSION
block|,
name|PAM_SM_CHAUTHTOK
block|,
comment|/* keep this last */
name|PAM_NUM_PRIMITIVES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Dummy service module function  */
end_comment

begin_define
define|#
directive|define
name|PAM_SM_DUMMY
parameter_list|(
name|type
parameter_list|)
define|\
value|PAM_EXTERN int								\ pam_sm_##type(pam_handle_t *pamh, int flags,				\     int argc, const char *argv[])					\ {									\ 									\ 	(void)pamh;							\ 	(void)flags;							\ 	(void)argc;							\ 	(void)argv;							\ 	return (PAM_IGNORE);						\ }
end_define

begin_comment
comment|/*  * PAM service module functions match this typedef  */
end_comment

begin_struct_decl
struct_decl|struct
name|pam_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pam_func_t
function_decl|)
parameter_list|(
name|struct
name|pam_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * A struct that describes a module.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pam_module
name|pam_module_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pam_module
block|{
name|char
modifier|*
name|path
decl_stmt|;
name|pam_func_t
name|func
index|[
name|PAM_NUM_PRIMITIVES
index|]
decl_stmt|;
name|void
modifier|*
name|dlh
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Source-code compatibility with Linux-PAM modules  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PAM_SM_AUTH
argument_list|)
operator|||
name|defined
argument_list|(
name|PAM_SM_ACCOUNT
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PAM_SM_SESSION
argument_list|)
operator|||
name|defined
argument_list|(
name|PAM_SM_PASSWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINUX_PAM_MODULE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINUX_PAM_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PAM_SM_AUTH
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PAM_SM_AUTHENTICATE
value|0
end_define

begin_define
define|#
directive|define
name|_PAM_SM_SETCRED
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|PAM_SM_AUTH
end_undef

begin_define
define|#
directive|define
name|PAM_SM_AUTH
end_define

begin_define
define|#
directive|define
name|_PAM_SM_AUTHENTICATE
value|pam_sm_authenticate
end_define

begin_define
define|#
directive|define
name|_PAM_SM_SETCRED
value|pam_sm_setcred
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINUX_PAM_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PAM_SM_ACCOUNT
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PAM_SM_ACCT_MGMT
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|PAM_SM_ACCOUNT
end_undef

begin_define
define|#
directive|define
name|PAM_SM_ACCOUNT
end_define

begin_define
define|#
directive|define
name|_PAM_SM_ACCT_MGMT
value|pam_sm_acct_mgmt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINUX_PAM_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PAM_SM_SESSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PAM_SM_OPEN_SESSION
value|0
end_define

begin_define
define|#
directive|define
name|_PAM_SM_CLOSE_SESSION
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|PAM_SM_SESSION
end_undef

begin_define
define|#
directive|define
name|PAM_SM_SESSION
end_define

begin_define
define|#
directive|define
name|_PAM_SM_OPEN_SESSION
value|pam_sm_open_session
end_define

begin_define
define|#
directive|define
name|_PAM_SM_CLOSE_SESSION
value|pam_sm_close_session
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINUX_PAM_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PAM_SM_PASSWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PAM_SM_CHAUTHTOK
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|PAM_SM_PASSWORD
end_undef

begin_define
define|#
directive|define
name|PAM_SM_PASSWORD
end_define

begin_define
define|#
directive|define
name|_PAM_SM_CHAUTHTOK
value|pam_sm_chauthtok
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Infrastructure for static modules using GCC linker sets.  * You are not expected to understand this.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PAM_SOEXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PAM_SOEXT
value|".so"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENPAM_STATIC_MODULES
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Don't know how to build static modules on non-GNU compilers"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gcc, static linking */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<linker_set.h>
end_include

begin_define
define|#
directive|define
name|PAM_EXTERN
value|static
end_define

begin_define
define|#
directive|define
name|PAM_MODULE_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|static char _pam_name[] = name PAM_SOEXT;			\ 	static struct pam_module _pam_module = {			\ 		.path = _pam_name,					\ 		.func = {						\ 			[PAM_SM_AUTHENTICATE] = _PAM_SM_AUTHENTICATE,	\ 			[PAM_SM_SETCRED] = _PAM_SM_SETCRED,		\ 			[PAM_SM_ACCT_MGMT] = _PAM_SM_ACCT_MGMT,		\ 			[PAM_SM_OPEN_SESSION] = _PAM_SM_OPEN_SESSION,	\ 			[PAM_SM_CLOSE_SESSION] = _PAM_SM_CLOSE_SESSION, \ 			[PAM_SM_CHAUTHTOK] = _PAM_SM_CHAUTHTOK		\ 		},							\ 	};								\ 	DATA_SET(_openpam_static_modules, _pam_module)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* normal case */
end_comment

begin_define
define|#
directive|define
name|PAM_EXTERN
end_define

begin_define
define|#
directive|define
name|PAM_MODULE_ENTRY
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SECURITY_OPENPAM_H_INCLUDED */
end_comment

end_unit

