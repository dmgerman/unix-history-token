begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 EMC Corp.  * Author: Conrad Meyer<conrad.meyer@isilon.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DUMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DUMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|KERNELDUMP_ARCH_VERSION
value|KERNELDUMP_AMD64_VERSION
end_define

begin_define
define|#
directive|define
name|EM_VALUE
value|EM_X86_64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNELDUMP_ARCH_VERSION
value|KERNELDUMP_I386_VERSION
end_define

begin_define
define|#
directive|define
name|EM_VALUE
value|EM_386
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 20 phys_avail entry pairs correspond to 10 pa's */
end_comment

begin_define
define|#
directive|define
name|DUMPSYS_MD_PA_NPAIRS
value|10
end_define

begin_define
define|#
directive|define
name|DUMPSYS_NUM_AUX_HDRS
value|0
end_define

begin_function
specifier|static
specifier|inline
name|void
name|dumpsys_pa_init
parameter_list|(
name|void
parameter_list|)
block|{
name|dumpsys_gen_pa_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|dump_pa
modifier|*
name|dumpsys_pa_next
parameter_list|(
name|struct
name|dump_pa
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|dumpsys_gen_pa_next
argument_list|(
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|dumpsys_wbinv_all
parameter_list|(
name|void
parameter_list|)
block|{
name|dumpsys_gen_wbinv_all
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|dumpsys_unmap_chunk
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|size_t
name|s
parameter_list|,
name|void
modifier|*
name|va
parameter_list|)
block|{
name|dumpsys_gen_unmap_chunk
argument_list|(
name|pa
argument_list|,
name|s
argument_list|,
name|va
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|dumpsys_write_aux_headers
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
parameter_list|)
block|{
return|return
operator|(
name|dumpsys_gen_write_aux_headers
argument_list|(
name|di
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|dumpsys
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
parameter_list|)
block|{
return|return
operator|(
name|dumpsys_generic
argument_list|(
name|di
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
comment|/* !_MACHINE_DUMP_H_ */
end_comment

end_unit

