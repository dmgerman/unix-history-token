begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCK_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCK_TYPES_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * If any of WITNESS, INVARIANTS, or KTR_LOCK KTR tracing has been enabled,  * then turn on LOCK_DEBUG.  When this option is on, extra debugging  * facilities such as tracking the file and line number of lock operations  * are enabled.  Also, mutex locking operations are not inlined to avoid  * bloat from all the extra debugging code.  We also have to turn on all the  * calling conventions for this debugging code in modules so that modules can  * work with both debug and non-debug kernels.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|||
name|defined
argument_list|(
name|WITNESS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|KTR
argument_list|)
operator|&&
operator|(
name|KTR_COMPILE
operator|&
name|KTR_LOCK
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|LOCK_DEBUG
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
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|lock_object
block|{
name|struct
name|lock_class
modifier|*
name|lo_class
decl_stmt|;
specifier|const
name|char
modifier|*
name|lo_name
decl_stmt|;
name|u_int
name|lo_flags
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|lock_object
argument_list|)
name|lo_list
expr_stmt|;
comment|/* List of all locks in system. */
name|struct
name|witness
modifier|*
name|lo_witness
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_LOCK_TYPES_H_ */
end_comment

end_unit

