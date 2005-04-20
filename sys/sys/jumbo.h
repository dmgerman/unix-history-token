begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Duke University  * All rights reserved.  *  * Author:  *         Andrew Gallatin<gallatin@cs.duke.edu>    *              * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Duke University may not be used to endorse or promote   *    products derived from this software without specific prior written   *    permission.  *   * THIS SOFTWARE IS PROVIDED BY DUKE UNIVERSITY ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DUKE UNIVERSITY BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITSOR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_JUMBO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_JUMBO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|jumbo_basekva
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|__inline
name|caddr_t
name|jumbo_phys_to_kva
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|caddr_t
name|jumbo_phys_to_kva
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
block|{
name|vm_page_t
name|pg
decl_stmt|;
name|pg
operator|=
name|PHYS_TO_VM_PAGE
argument_list|(
name|pa
argument_list|)
expr_stmt|;
name|pg
operator|->
name|flags
operator|&=
operator|~
name|PG_BUSY
expr_stmt|;
return|return
call|(
name|caddr_t
call|)
argument_list|(
name|ptoa
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|pg
operator|->
name|pindex
argument_list|)
operator|+
name|jumbo_basekva
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|int
name|jumbo_vm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jumbo_freem
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|jumbo_pg_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jumbo_pg_free
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jumbo_pg_steal
parameter_list|(
name|vm_page_t
name|pg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_JUMBO_H_ */
end_comment

end_unit

