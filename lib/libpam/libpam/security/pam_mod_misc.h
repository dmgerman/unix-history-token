begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_MOD_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_MOD_MISC_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Standard options  */
end_comment

begin_enum
enum|enum
name|opt
block|{
name|PAM_OPT_DEBUG
block|,
name|PAM_OPT_NO_WARN
block|,
name|PAM_OPT_ECHO_PASS
block|,
name|PAM_OPT_USE_FIRST_PASS
block|,
name|PAM_OPT_TRY_FIRST_PASS
block|,
name|PAM_OPT_USE_MAPPED_PASS
block|,
name|PAM_OPT_TRY_MAPPED_PASS
block|,
name|PAM_OPT_EXPOSE_ACCOUNT
block|,
name|PAM_OPT_STD_MAX
comment|/* XXX */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PAM_MAX_OPTIONS
value|32
end_define

begin_struct
struct|struct
name|opttab
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|options
block|{
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|bool
decl_stmt|;
name|char
modifier|*
name|arg
decl_stmt|;
block|}
name|opt
index|[
name|PAM_MAX_OPTIONS
index|]
struct|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
name|void
name|pam_std_option
parameter_list|(
name|struct
name|options
modifier|*
parameter_list|,
name|struct
name|opttab
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pam_test_option
parameter_list|(
name|struct
name|options
modifier|*
parameter_list|,
name|enum
name|opt
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pam_set_option
parameter_list|(
name|struct
name|options
modifier|*
parameter_list|,
name|enum
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pam_clear_option
parameter_list|(
name|struct
name|options
modifier|*
parameter_list|,
name|enum
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pam_verbose_error
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|PAM_LOG
parameter_list|(
name|args
modifier|...
parameter_list|)
define|\
value|openpam_log(PAM_LOG_DEBUG, ##args)
end_define

begin_define
define|#
directive|define
name|PAM_RETURN
parameter_list|(
name|arg
parameter_list|)
define|\
value|return (arg)
end_define

begin_define
define|#
directive|define
name|PAM_VERBOSE_ERROR
parameter_list|(
name|args
modifier|...
parameter_list|)
define|\
value|_pam_verbose_error(pamh, flags, __FILE__, __FUNCTION__, ##args)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

