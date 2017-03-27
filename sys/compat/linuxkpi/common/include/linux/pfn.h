begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_PFN_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_PFN_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|u64
name|val
decl_stmt|;
block|}
name|pfn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PFN_ALIGN
parameter_list|(
name|x
parameter_list|)
value|(((unsigned long)(x) + PAGE_SIZE - 1)& ~(PAGE_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|PFN_UP
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGE_SIZE - 1)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PFN_DOWN
parameter_list|(
name|x
parameter_list|)
value|((x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PFN_PHYS
parameter_list|(
name|x
parameter_list|)
value|((phys_addr_t)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHYS_PFN
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)((x)>> PAGE_SHIFT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_PFN_H_ */
end_comment

end_unit

