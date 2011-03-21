begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Topspin Communications.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFINIBAND_ARCH_H
end_ifndef

begin_define
define|#
directive|define
name|INFINIBAND_ARCH_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/endian.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/byteswap.h>
end_include

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_function
specifier|static
specifier|inline
name|uint64_t
name|htonll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|bswap_64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|ntohll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|bswap_64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_elif

begin_function
specifier|static
specifier|inline
name|uint64_t
name|htonll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|ntohll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|__BYTE_ORDER is neither __LITTLE_ENDIAN nor __BIG_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Architecture-specific defines.  Currently, an architecture is  * required to implement the following operations:  *  * mb() - memory barrier.  No loads or stores may be reordered across  *     this macro by either the compiler or the CPU.  * rmb() - read memory barrier.  No loads may be reordered across this  *     macro by either the compiler or the CPU.  * wmb() - write memory barrier.  No stores may be reordered across  *     this macro by either the compiler or the CPU.  * wc_wmb() - flush write combine buffers.  No write-combined writes  *     will be reordered across this macro by either the compiler or  *     the CPU.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("lock; addl $0,0(%%esp) " ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|asm volatile("" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|mb()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_comment
comment|/*  * Only use lfence for mb() and rmb() because we don't care about  * ordering against non-temporal stores (for now at least).  */
end_comment

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("lfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|asm volatile("" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|asm volatile("sfence" ::: "memory")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__PPC64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("sync" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|asm volatile("lwsync" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|wmb()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("mf" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|asm volatile("fwb" ::: "memory")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__PPC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("sync" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|wmb()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc_v9__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("membar #LoadLoad | #LoadStore | #StoreStore | #StoreLoad" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|asm volatile("membar #LoadLoad" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|asm volatile("membar #StoreStore" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|wmb()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|wmb()
end_define

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|No architecture specific defines found.  Using generic implementation.
end_warning

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|asm volatile("" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|wc_wmb
parameter_list|()
value|wmb()
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
comment|/* INFINIBAND_ARCH_H */
end_comment

end_unit

