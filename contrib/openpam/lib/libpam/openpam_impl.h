begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2017 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_impl.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPAM_IMPL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|OPENPAM_IMPL_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<security/openpam.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|openpam_debug
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

begin_comment
comment|/*  * Module chains  */
end_comment

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

begin_comment
comment|/*  * Service policies  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENPAM_EMBEDDED
argument_list|)
end_if

begin_typedef
typedef|typedef
name|struct
name|pam_policy
name|pam_policy_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pam_policy
block|{
specifier|const
name|char
modifier|*
name|service
decl_stmt|;
name|pam_chain_t
modifier|*
name|chains
index|[
name|PAM_NUM_FACILITIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|pam_policy_t
modifier|*
name|pam_embedded_policies
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Module-specific data  */
end_comment

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

begin_comment
comment|/*  * PAM context  */
end_comment

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

begin_comment
comment|/*  * Default policy  */
end_comment

begin_define
define|#
directive|define
name|PAM_OTHER
value|"other"
end_define

begin_comment
comment|/*  * Internal functions  */
end_comment

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
name|openpam_dispatch
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
name|pam_module_t
modifier|*
name|openpam_load_module
parameter_list|(
specifier|const
name|char
modifier|*
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
name|void
name|openpam_clear_chains
parameter_list|(
name|pam_chain_t
modifier|*
modifier|*
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
name|openpam_check_desc_owner_perms
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
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
name|openpam_check_path_owner_perms
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

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
name|pam_module_t
modifier|*
name|openpam_dynamic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|OPENPAM_NONNULL
parameter_list|(
function_decl|(1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|p
parameter_list|)
define|\
value|do {					\ 		free(p);			\ 		(p) = NULL;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|FREEV
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
define|\
value|do {					\ 		if ((v) != NULL) {		\ 			while ((c)--> 0)	\ 				FREE((v)[(c)]);	\ 			FREE(v);		\ 		}				\ 	} while (0)
end_define

begin_include
include|#
directive|include
file|"openpam_constants.h"
end_include

begin_include
include|#
directive|include
file|"openpam_debug.h"
end_include

begin_include
include|#
directive|include
file|"openpam_features.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

