begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technologies, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_OPENPAM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_OPENPAM_H_INCLUDED
end_define

begin_comment
comment|/*  * Annoying but necessary header pollution  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
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
comment|/*  * API extensions  */
name|int
name|pam_error
parameter_list|(
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
function_decl|;
name|int
name|pam_get_authtok
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
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
function_decl|;
name|int
name|pam_info
parameter_list|(
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
function_decl|;
name|int
name|pam_prompt
parameter_list|(
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
function_decl|;
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
function_decl|;
name|int
name|pam_vinfo
parameter_list|(
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
function_decl|;
name|int
name|pam_verror
parameter_list|(
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
function_decl|;
name|int
name|pam_vprompt
parameter_list|(
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
function_decl|;
comment|/*  * Log levels  */
enum|enum
block|{
name|PAM_LOG_DEBUG
block|,
name|PAM_LOG_VERBOSE
block|,
name|PAM_LOG_NOTICE
block|,
name|PAM_LOG_ERROR
block|}
enum|;
comment|/*  * Log to syslog  */
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
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|(
name|__STDC_VERSION__
operator|>
literal|199901L
operator|)
define|#
directive|define
name|openpam_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_openpam_log((lvl), __func__, fmt, __VA_ARGS__)
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
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
else|#
directive|else
extern|extern openpam_log(int _level
operator|,
extern|const char *_format
operator|,
extern|...
block|)
empty_stmt|;
end_extern

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
value|PAM_EXTERN int								\ pam_sm_##type(pam_handle_t *pamh, int flags,				\     int argc, const char *argv[])					\ {									\ 	return (PAM_IGNORE);						\ }
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
specifier|const
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
name|int
name|refcount
decl_stmt|;
name|pam_module_t
modifier|*
name|prev
decl_stmt|;
name|pam_module_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Infrastructure for static modules using GCC linker sets.  * You are not expected to understand this.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__PIC__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PAM_SOEXT
value|".so"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Static linking is not supported on your platform
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
name|OPENPAM_STATIC_MODULES
end_define

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
value|static struct pam_module _pam_module = { name PAM_SOEXT, {		\     pam_sm_authenticate, pam_sm_setcred, pam_sm_acct_mgmt,		\     pam_sm_open_session, pam_sm_close_session, pam_sm_chauthtok },	\     NULL, 0, NULL, NULL };						\ DATA_SET(_openpam_modules, _pam_module)
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

end_unit

