begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/lib/openpam_impl.h#29 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENPAM_IMPL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_OPENPAM_IMPL_H_INCLUDED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<security/openpam.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_pam_func_name
index|[
name|PAM_NUM_PRIMITIVES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_pam_sm_func_name
index|[
name|PAM_NUM_PRIMITIVES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_pam_err_name
index|[
name|PAM_NUM_ERRORS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_pam_item_name
index|[
name|PAM_NUM_ITEMS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_openpam_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Control flags  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAM_BINDING
block|,
name|PAM_REQUIRED
block|,
name|PAM_REQUISITE
block|,
name|PAM_SUFFICIENT
block|,
name|PAM_OPTIONAL
block|,
name|PAM_NUM_CONTROL_FLAGS
block|}
name|pam_control_t
typedef|;
end_typedef

begin_comment
comment|/*  * Facilities  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAM_FACILITY_ANY
init|=
operator|-
literal|1
block|,
name|PAM_AUTH
init|=
literal|0
block|,
name|PAM_ACCOUNT
block|,
name|PAM_SESSION
block|,
name|PAM_PASSWORD
block|,
name|PAM_NUM_FACILITIES
block|}
name|pam_facility_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pam_chain
name|pam_chain_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pam_chain
block|{
name|pam_module_t
modifier|*
name|module
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|optc
decl_stmt|;
name|char
modifier|*
modifier|*
name|optv
decl_stmt|;
name|pam_chain_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pam_data
name|pam_data_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pam_data
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|pam_data_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pam_handle
block|{
name|char
modifier|*
name|service
decl_stmt|;
comment|/* chains */
name|pam_chain_t
modifier|*
name|chains
index|[
name|PAM_NUM_FACILITIES
index|]
decl_stmt|;
name|pam_chain_t
modifier|*
name|current
decl_stmt|;
name|int
name|primitive
decl_stmt|;
comment|/* items and data */
name|void
modifier|*
name|item
index|[
name|PAM_NUM_ITEMS
index|]
decl_stmt|;
name|pam_data_t
modifier|*
name|module_data
decl_stmt|;
comment|/* environment list */
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
name|int
name|env_count
decl_stmt|;
name|int
name|env_size
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NGROUPS_MAX
end_ifdef

begin_define
define|#
directive|define
name|PAM_SAVED_CRED
value|"pam_saved_cred"
end_define

begin_struct
struct|struct
name|pam_saved_cred
block|{
name|uid_t
name|euid
decl_stmt|;
name|gid_t
name|egid
decl_stmt|;
name|gid_t
name|groups
index|[
name|NGROUPS_MAX
index|]
decl_stmt|;
name|int
name|ngroups
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAM_OTHER
value|"other"
end_define

begin_function_decl
name|int
name|openpam_configure
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpam_dispatch
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpam_findenv
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pam_module_t
modifier|*
name|openpam_load_module
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpam_clear_chains
parameter_list|(
name|pam_chain_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|OPENPAM_STATIC_MODULES
end_ifdef

begin_function_decl
name|pam_module_t
modifier|*
name|openpam_static
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|pam_module_t
modifier|*
name|openpam_dynamic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|p
parameter_list|)
value|do { free((p)); (p) = NULL; } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ENTER
parameter_list|()
value|openpam_log(PAM_LOG_DEBUG, "entering")
end_define

begin_define
define|#
directive|define
name|ENTERI
parameter_list|(
name|i
parameter_list|)
value|do { \ 	int _i = (i); \ 	if (_i> 0&& _i< PAM_NUM_ITEMS) \ 		openpam_log(PAM_LOG_DEBUG, "entering: %s", _pam_item_name[_i]); \ 	else \ 		openpam_log(PAM_LOG_DEBUG, "entering: %d", _i); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ENTERN
parameter_list|(
name|n
parameter_list|)
value|do { \ 	int _n = (n); \ 	openpam_log(PAM_LOG_DEBUG, "entering: %d", _n); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ENTERS
parameter_list|(
name|s
parameter_list|)
value|do { \ 	const char *_s = (s); \ 	if (_s == NULL) \ 		openpam_log(PAM_LOG_DEBUG, "entering: NULL"); \ 	else \ 		openpam_log(PAM_LOG_DEBUG, "entering: '%s'", _s); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|openpam_log(PAM_LOG_DEBUG, "returning")
end_define

begin_define
define|#
directive|define
name|RETURNC
parameter_list|(
name|c
parameter_list|)
value|do { \ 	int _c = (c); \ 	if (_c>= 0&& _c< PAM_NUM_ERRORS) \ 		openpam_log(PAM_LOG_DEBUG, "returning %s", _pam_err_name[_c]); \ 	else \ 		openpam_log(PAM_LOG_DEBUG, "returning %d!", _c); \ 	return (_c); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNN
parameter_list|(
name|n
parameter_list|)
value|do { \ 	int _n = (n); \ 	openpam_log(PAM_LOG_DEBUG, "returning %d", _n); \ 	return (_n); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNP
parameter_list|(
name|p
parameter_list|)
value|do { \ 	const void *_p = (p); \ 	if (_p == NULL) \ 		openpam_log(PAM_LOG_DEBUG, "returning NULL"); \ 	else \ 		openpam_log(PAM_LOG_DEBUG, "returning %p", _p); \ 	return (p); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNS
parameter_list|(
name|s
parameter_list|)
value|do { \ 	const char *_s = (s); \ 	if (_s == NULL) \ 		openpam_log(PAM_LOG_DEBUG, "returning NULL"); \ 	else \ 		openpam_log(PAM_LOG_DEBUG, "returning '%s'", _s); \ 	return (_s); \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTER
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ENTERI
parameter_list|(
name|i
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTERN
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTERS
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|return
end_define

begin_define
define|#
directive|define
name|RETURNC
parameter_list|(
name|c
parameter_list|)
value|return (c)
end_define

begin_define
define|#
directive|define
name|RETURNN
parameter_list|(
name|n
parameter_list|)
value|return (n)
end_define

begin_define
define|#
directive|define
name|RETURNP
parameter_list|(
name|p
parameter_list|)
value|return (p)
end_define

begin_define
define|#
directive|define
name|RETURNS
parameter_list|(
name|s
parameter_list|)
value|return (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

