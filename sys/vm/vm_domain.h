begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Adrian Chadd<adrian@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VM_DOMAIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__VM_DOMAIN_H__
end_define

begin_include
include|#
directive|include
file|<sys/_vm_domain.h>
end_include

begin_struct
struct|struct
name|vm_domain_iterator
block|{
name|vm_domain_policy_type_t
name|policy
decl_stmt|;
name|int
name|domain
decl_stmt|;
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TODO: check to see if these should just become inline functions  * at some point.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|vm_domain_policy_init
parameter_list|(
name|struct
name|vm_domain_policy
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_policy_set
parameter_list|(
name|struct
name|vm_domain_policy
modifier|*
name|vp
parameter_list|,
name|vm_domain_policy_type_t
name|vt
parameter_list|,
name|int
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_policy_cleanup
parameter_list|(
name|struct
name|vm_domain_policy
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_domain_policy_localcopy
parameter_list|(
name|struct
name|vm_domain_policy
modifier|*
name|dst
parameter_list|,
specifier|const
name|struct
name|vm_domain_policy
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_domain_policy_copy
parameter_list|(
name|struct
name|vm_domain_policy
modifier|*
name|dst
parameter_list|,
specifier|const
name|struct
name|vm_domain_policy
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_policy_validate
parameter_list|(
specifier|const
name|struct
name|vm_domain_policy
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_iterator_init
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_iterator_set
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|,
name|vm_domain_policy_type_t
name|vt
parameter_list|,
name|int
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_domain_iterator_set_policy
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|,
specifier|const
name|struct
name|vm_domain_policy
modifier|*
name|vt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_iterator_run
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|,
name|int
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_iterator_isdone
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_domain_iterator_cleanup
parameter_list|(
name|struct
name|vm_domain_iterator
modifier|*
name|vi
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __VM_DOMAIN_H__ */
end_comment

end_unit

