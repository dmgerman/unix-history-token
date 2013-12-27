begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: src/sys/alpha/include/sigframe.h,v 1.1 1999/09/29 15:06:26 marcel  *	from: sigframe.h,v 1.1 2006/08/07 05:38:57 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SIGFRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGFRAME_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * WARNING: code in locore.s assumes the layout shown for sf_signum  * thru sf_addr so... don't alter them!  */
end_comment

begin_struct
struct|struct
name|sigframe
block|{
name|register_t
name|sf_signum
decl_stmt|;
name|register_t
name|sf_siginfo
decl_stmt|;
comment|/* code or pointer to sf_si */
name|register_t
name|sf_ucontext
decl_stmt|;
comment|/* points to sf_uc */
name|register_t
name|sf_addr
decl_stmt|;
comment|/* undocumented 4th arg */
name|ucontext_t
name|sf_uc
decl_stmt|;
comment|/* = *sf_ucontext */
name|siginfo_t
name|sf_si
decl_stmt|;
comment|/* = *sf_siginfo (SA_SIGINFO case) */
name|unsigned
name|long
name|__spare__
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|COMPAT_FREEBSD32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<compat/freebsd32/freebsd32_signal.h>
end_include

begin_struct
struct|struct
name|sigframe32
block|{
name|int32_t
name|sf_signum
decl_stmt|;
name|int32_t
name|sf_siginfo
decl_stmt|;
comment|/* code or pointer to sf_si */
name|int32_t
name|sf_ucontext
decl_stmt|;
comment|/* points to sf_uc */
name|int32_t
name|sf_addr
decl_stmt|;
comment|/* undocumented 4th arg */
name|ucontext32_t
name|sf_uc
decl_stmt|;
comment|/* = *sf_ucontext */
name|struct
name|siginfo32
name|sf_si
decl_stmt|;
comment|/* = *sf_siginfo (SA_SIGINFO case) */
name|uint32_t
name|__spare__
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SIGFRAME_H_ */
end_comment

end_unit

