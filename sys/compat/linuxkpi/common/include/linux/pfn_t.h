begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_PFN_T_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_PFN_T_H_
end_define

begin_include
include|#
directive|include
file|<linux/mm.h>
end_include

begin_expr_stmt
name|CTASSERT
argument_list|(
name|PAGE_SHIFT
operator|>
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PFN_FLAGS_MASK
value|(((u64)(PAGE_SIZE - 1))<< (64 - PAGE_SHIFT))
end_define

begin_define
define|#
directive|define
name|PFN_SG_CHAIN
value|(1ULL<< (64 - 1))
end_define

begin_define
define|#
directive|define
name|PFN_SG_LAST
value|(1ULL<< (64 - 2))
end_define

begin_define
define|#
directive|define
name|PFN_DEV
value|(1ULL<< (64 - 3))
end_define

begin_define
define|#
directive|define
name|PFN_MAP
value|(1ULL<< (64 - 4))
end_define

begin_function
specifier|static
specifier|inline
name|pfn_t
name|__pfn_to_pfn_t
parameter_list|(
name|unsigned
name|long
name|pfn
parameter_list|,
name|u64
name|flags
parameter_list|)
block|{
name|pfn_t
name|pfn_t
init|=
block|{
name|pfn
operator||
operator|(
name|flags
operator|&
name|PFN_FLAGS_MASK
operator|)
block|}
decl_stmt|;
return|return
operator|(
name|pfn_t
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|pfn_t
name|pfn_to_pfn_t
parameter_list|(
name|unsigned
name|long
name|pfn
parameter_list|)
block|{
return|return
operator|(
name|__pfn_to_pfn_t
argument_list|(
name|pfn
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_PFN_T_H_ */
end_comment

end_unit

