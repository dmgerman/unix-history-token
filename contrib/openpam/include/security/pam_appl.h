begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2017 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: pam_appl.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECURITY_PAM_APPL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SECURITY_PAM_APPL_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<security/pam_types.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_constants.h>
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
comment|/*  * XSSO 4.2.1, 6  */
name|int
name|pam_acct_mgmt
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pam_authenticate
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
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
name|pam_chauthtok
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
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
name|pam_close_session
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
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
name|pam_end
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pam_get_data
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_module_data_name
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|_data
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
name|pam_get_item
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_item_type
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|_item
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
name|pam_get_user
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|_user
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
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|pam_getenv
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
modifier|*
name|pam_getenvlist
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
name|pam_open_session
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
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
name|pam_putenv
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_namevalue
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pam_set_data
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|_module_data_name
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|void
function_decl|(
modifier|*
name|_cleanup
function_decl|)
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
name|_pam_end_status
parameter_list|)
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pam_set_item
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_item_type
parameter_list|,
specifier|const
name|void
modifier|*
name|_item
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
name|pam_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_flags
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
name|pam_start
parameter_list|(
specifier|const
name|char
modifier|*
name|_service
parameter_list|,
specifier|const
name|char
modifier|*
name|_user
parameter_list|,
specifier|const
name|struct
name|pam_conv
modifier|*
name|_pam_conv
parameter_list|,
name|pam_handle_t
modifier|*
modifier|*
name|_pamh
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(4
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|pam_strerror
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|_pamh
parameter_list|,
name|int
name|_error_number
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Single Sign-On extensions  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int pam_authenticate_secondary(pam_handle_t *_pamh, 	char *_target_username, 	char *_target_module_type, 	char *_target_authn_domain, 	char *_target_supp_data, 	char *_target_module_authtok, 	int _flags);  int pam_get_mapped_authtok(pam_handle_t *_pamh, 	const char *_target_module_username, 	const char *_target_module_type, 	const char *_target_authn_domain, 	size_t *_target_authtok_len, 	unsigned char **_target_module_authtok);  int pam_get_mapped_username(pam_handle_t *_pamh, 	const char *_src_username, 	const char *_src_module_type, 	const char *_src_authn_domain, 	const char *_target_module_type, 	const char *_target_authn_domain, 	char **_target_module_username);  int pam_set_mapped_authtok(pam_handle_t *_pamh, 	const char *_target_module_username, 	size_t _target_authtok_len, 	unsigned char *_target_module_authtok, 	const char *_target_module_type, 	const char *_target_authn_domain);  int pam_set_mapped_username(pam_handle_t *_pamh, 	char *_src_username, 	char *_src_module_type, 	char *_src_authn_domain, 	char *_target_module_username, 	char *_target_module_type, 	char *_target_authn_domain);
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

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
comment|/* !SECURITY_PAM_APPL_H_INCLUDED */
end_comment

end_unit

