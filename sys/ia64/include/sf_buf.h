begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SF_BUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SF_BUF_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_struct
struct|struct
name|sf_buf
block|{
name|SLIST_ENTRY
argument_list|(
argument|sf_buf
argument_list|)
name|free_list
expr_stmt|;
comment|/* list of free buffer slots */
name|vm_page_t
name|m
decl_stmt|;
comment|/* currently mapped page */
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|sf_buf_kva
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
return|return
operator|(
name|IA64_PHYS_TO_RR7
argument_list|(
name|sf
operator|->
name|m
operator|->
name|phys_addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|vm_page_t
name|sf_buf_page
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
return|return
operator|(
name|sf
operator|->
name|m
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SF_BUF_H_ */
end_comment

end_unit

