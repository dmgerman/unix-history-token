begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PRIVATESPACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PRIVATESPACE_H_
end_define

begin_comment
comment|/*  * This is the upper (0xff800000) address space layout that is per-cpu.  * It is setup in locore.s and pmap.c for the BSP and in mp_machdep.c for  * each AP.  This is only applicable to the x86 SMP kernel.  */
end_comment

begin_struct
struct|struct
name|privatespace
block|{
comment|/* page 0 - data page */
name|struct
name|pcpu
name|pcpu
decl_stmt|;
name|char
name|__filler0
index|[
name|PAGE_SIZE
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
index|]
decl_stmt|;
comment|/* page 1 - idle stack (KSTACK_PAGES pages) */
name|char
name|idlekstack
index|[
name|KSTACK_PAGES
operator|*
name|PAGE_SIZE
index|]
decl_stmt|;
comment|/* page 1+KSTACK_PAGES... */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|privatespace
name|SMP_prvspace
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_PRIVATESPACE_H_ */
end_comment

end_unit

