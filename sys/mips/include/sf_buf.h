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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_comment
comment|/* In 64 bit the whole memory is directly mapped */
end_comment

begin_function
specifier|static
specifier|inline
name|vm_offset_t
name|sf_buf_kva
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
name|vm_page_t
name|m
decl_stmt|;
name|m
operator|=
operator|(
name|vm_page_t
operator|)
name|sf
expr_stmt|;
return|return
operator|(
name|MIPS_PHYS_TO_DIRECT
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|m
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|vm_page
modifier|*
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
operator|(
name|vm_page_t
operator|)
name|sf
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__mips_n64 */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|sf_buf_map
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|pmap_qenter
argument_list|(
name|sf
operator|->
name|kva
argument_list|,
operator|&
name|sf
operator|->
name|m
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|sf_buf_unmap
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
name|pmap_qremove
argument_list|(
name|sf
operator|->
name|kva
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SF_BUF_H_ */
end_comment

end_unit

