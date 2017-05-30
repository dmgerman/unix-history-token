begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<asm/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__bitwise__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__CHECKER__
end_ifdef

begin_define
define|#
directive|define
name|__bitwise__
value|__attribute__((bitwise))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__bitwise__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint16_t
name|__le16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__le64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|gfp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|loff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vm_paddr_t
name|resource_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__bitwise__
name|__sum16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|pgoff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u64
name|phys_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DECLARE_BITMAP
parameter_list|(
name|n
parameter_list|,
name|bits
parameter_list|)
define|\
value|unsigned long n[howmany(bits, sizeof(long) * 8)]
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|irq_hw_number_t
typedef|;
end_typedef

begin_struct
struct|struct
name|rcu_head
block|{
name|void
modifier|*
name|raw
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|rcu_callback_t
function_decl|)
parameter_list|(
name|struct
name|rcu_head
modifier|*
name|head
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|call_rcu_func_t
function_decl|)
parameter_list|(
name|struct
name|rcu_head
modifier|*
name|head
parameter_list|,
name|rcu_callback_t
name|func
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|linux_task_fn_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_TYPES_H_ */
end_comment

end_unit

