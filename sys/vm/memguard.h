begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005,  *     Bosko Milekic<bmilekic@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_MEMGUARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_MEMGUARD_H_
end_define

begin_include
include|#
directive|include
file|"opt_vm.h"
end_include

begin_struct_decl
struct_decl|struct
name|malloc_type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmem
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEMGUARD
end_ifdef

begin_function_decl
name|unsigned
name|long
name|memguard_fudge
parameter_list|(
name|unsigned
name|long
parameter_list|,
specifier|const
name|struct
name|vm_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memguard_init
parameter_list|(
name|struct
name|vmem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memguard_alloc
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memguard_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|malloc_type
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memguard_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memguard_cmp_mtp
parameter_list|(
name|struct
name|malloc_type
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memguard_cmp_zone
parameter_list|(
name|uma_zone_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_memguard_addr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memguard_fudge
parameter_list|(
name|size
parameter_list|,
name|xxx
parameter_list|)
value|(size)
end_define

begin_define
define|#
directive|define
name|memguard_init
parameter_list|(
name|map
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|memguard_alloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|memguard_realloc
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|mtp
parameter_list|,
name|f
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|memguard_free
parameter_list|(
name|addr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|memguard_cmp_mtp
parameter_list|(
name|mtp
parameter_list|,
name|size
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|memguard_cmp_zone
parameter_list|(
name|zone
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|is_memguard_addr
parameter_list|(
name|addr
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_MEMGUARD_H_ */
end_comment

end_unit

