begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technologies, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
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
name|_pam_sm_func_name
index|[
name|PAM_NUM_PRIMITIVES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Control flags  */
end_comment

begin_define
define|#
directive|define
name|PAM_REQUIRED
value|1
end_define

begin_define
define|#
directive|define
name|PAM_REQUISITE
value|2
end_define

begin_define
define|#
directive|define
name|PAM_SUFFICIENT
value|3
end_define

begin_define
define|#
directive|define
name|PAM_OPTIONAL
value|4
end_define

begin_define
define|#
directive|define
name|PAM_NUM_CONTROLFLAGS
value|5
end_define

begin_comment
comment|/*  * Chains  */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTH
value|0
end_define

begin_define
define|#
directive|define
name|PAM_ACCOUNT
value|1
end_define

begin_define
define|#
directive|define
name|PAM_SESSION
value|2
end_define

begin_define
define|#
directive|define
name|PAM_PASSWORD
value|3
end_define

begin_define
define|#
directive|define
name|PAM_NUM_CHAINS
value|4
end_define

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
name|PAM_NUM_CHAINS
index|]
decl_stmt|;
name|pam_chain_t
modifier|*
name|current
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

begin_define
define|#
directive|define
name|PAM_OTHER
value|"other"
end_define

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
name|int
name|openpam_add_module
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
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
name|void
name|openpam_clear_chains
parameter_list|(
name|pam_handle_t
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

