begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Adrian Chadd<adrian@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_VM_DOMAIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_VM_DOMAIN_H__
end_define

begin_include
include|#
directive|include
file|<sys/seq.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|VM_POLICY_NONE
block|,
name|VM_POLICY_ROUND_ROBIN
block|,
name|VM_POLICY_FIXED_DOMAIN
block|,
name|VM_POLICY_FIXED_DOMAIN_ROUND_ROBIN
block|,
name|VM_POLICY_FIRST_TOUCH
block|,
name|VM_POLICY_FIRST_TOUCH_ROUND_ROBIN
block|,
name|VM_POLICY_MAX
block|}
name|vm_domain_policy_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vm_domain_policy_entry
block|{
name|vm_domain_policy_type_t
name|policy
decl_stmt|;
name|int
name|domain
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_domain_policy
block|{
name|seq_t
name|seq
decl_stmt|;
name|struct
name|vm_domain_policy_entry
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VM_DOMAIN_POLICY_STATIC_INITIALISER
parameter_list|(
name|vt
parameter_list|,
name|vd
parameter_list|)
define|\
value|{ .seq = 0, \ 	  .p.policy = vt, \ 	  .p.domain = vd }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_VM_DOMAIN_H__ */
end_comment

end_unit

