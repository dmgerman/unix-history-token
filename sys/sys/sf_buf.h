begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SF_BUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SF_BUF_H_
end_define

begin_comment
comment|/*  * Options to sf_buf_alloc() are specified through its flags argument.  This  * argument's value should be the result of a bitwise or'ing of one or more  * of the following values.  */
end_comment

begin_define
define|#
directive|define
name|SFB_CATCH
value|1
end_define

begin_comment
comment|/* Check signals if the allocation 					   sleeps. */
end_comment

begin_define
define|#
directive|define
name|SFB_CPUPRIVATE
value|2
end_define

begin_comment
comment|/* Create a CPU private mapping. */
end_comment

begin_define
define|#
directive|define
name|SFB_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|SFB_NOWAIT
value|4
end_define

begin_comment
comment|/* Return NULL if all bufs are used. */
end_comment

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sfstat
block|{
comment|/* sendfile statistics */
name|uint64_t
name|sf_iocnt
decl_stmt|;
comment|/* times sendfile had to do disk I/O */
name|uint64_t
name|sf_allocfail
decl_stmt|;
comment|/* times sfbuf allocation failed */
name|uint64_t
name|sf_allocwait
decl_stmt|;
comment|/* times sfbuf allocation had to wait */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/sf_buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/counter.h>
end_include

begin_decl_stmt
specifier|extern
name|counter_u64_t
name|sfstat
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|sfstat
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SFSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|counter_u64_add(sfstat[offsetof(struct sfstat, name) / sizeof(uint64_t)],\ 	(val))
end_define

begin_define
define|#
directive|define
name|SFSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|SFSTAT_ADD(name, 1)
end_define

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
comment|/* !_SYS_SF_BUF_H_ */
end_comment

end_unit

