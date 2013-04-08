begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 Konstantin Belousov<kib@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHINE_COUNTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACHINE_COUNTER_H__
end_define

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
operator|&&
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|counter_enter
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|counter_exit
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|counter_u64_add_protected
parameter_list|(
name|c
parameter_list|,
name|i
parameter_list|)
value|counter_u64_add(c, i)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|counter_u64_add
parameter_list|(
name|counter_u64_t
name|c
parameter_list|,
name|int64_t
name|inc
parameter_list|)
block|{
name|uint64_t
name|ccpu
decl_stmt|,
name|old
decl_stmt|;
asm|__asm __volatile("\n"
literal|"1:\n\t"
literal|"mfsprg	%0, 0\n\t"
literal|"ldarx	%1, %0, %2\n\t"
literal|"add	%1, %1, %3\n\t"
literal|"stdcx.	%1, %0, %2\n\t"
literal|"bne-	1b"
operator|:
literal|"=&b"
operator|(
name|ccpu
operator|)
operator|,
literal|"=&r"
operator|(
name|old
operator|)
operator|:
literal|"r"
operator|(
operator|(
name|char
operator|*
operator|)
name|c
operator|-
operator|(
name|char
operator|*
operator|)
operator|&
name|__pcpu
index|[
literal|0
index|]
operator|)
operator|,
literal|"r"
operator|(
name|inc
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* !AIM || !64bit */
end_comment

begin_define
define|#
directive|define
name|counter_enter
parameter_list|()
value|critical_enter()
end_define

begin_define
define|#
directive|define
name|counter_exit
parameter_list|()
value|critical_exit()
end_define

begin_define
define|#
directive|define
name|counter_u64_add_protected
parameter_list|(
name|c
parameter_list|,
name|inc
parameter_list|)
value|do {	\ 	CRITICAL_ASSERT(curthread);			\ 	*(uint64_t *)zpcpu_get(c) += (inc);		\ } while (0)
end_define

begin_function
unit|static
specifier|inline
name|void
name|counter_u64_add
parameter_list|(
name|counter_u64_t
name|c
parameter_list|,
name|int64_t
name|inc
parameter_list|)
block|{
name|counter_enter
argument_list|()
expr_stmt|;
name|counter_u64_add_protected
argument_list|(
name|c
argument_list|,
name|inc
argument_list|)
expr_stmt|;
name|counter_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIM 64bit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __MACHINE_COUNTER_H__ */
end_comment

end_unit

