begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)types.h	8.3 (Berkeley) 1/5/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TYPES_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|_physadr
block|{
name|int
name|r
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|physadr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|label_t
block|{
name|int
name|val
index|[
literal|6
index|]
decl_stmt|;
block|}
name|label_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|vm_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|vm_ooffset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|vm_pindex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|vm_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|u_register_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
name|intfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uintfptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Critical section value */
end_comment

begin_typedef
typedef|typedef
name|register_t
name|critical_t
typedef|;
end_typedef

begin_comment
comment|/* Interrupt mask (spl, xxx_imask, etc) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|intrmask_t
typedef|;
end_typedef

begin_comment
comment|/* Interrupt handler function type. */
end_comment

begin_typedef
typedef|typedef
name|void
name|ointhand2_t
parameter_list|(
name|int
name|_device_id
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TYPES_H_ */
end_comment

end_unit

