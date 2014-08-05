begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Gleb Smirnoff<glebius@FreeBSD.org>  * Copyright (c) 2003-2004 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/types.h>
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

begin_comment
comment|/*  * Sf_bufs, or sendfile(2) buffers provide a vm_page that is mapped  * into kernel address space. Note, that they aren't used only  * by sendfile(2)!  *  * Sf_bufs could be implemented as a feature of vm_page_t, but that  * would require growth of the structure. That's why they are implemented  * as a separate hash indexed by vm_page address. Implementation lives in  * kern/subr_sfbuf.c. Meanwhile, most 64-bit machines have a physical map,  * so they don't require this hash at all, thus ignore subr_sfbuf.c.  *  * Different 32-bit architectures demand different requirements on sf_buf  * hash and functions. They request features in machine/vmparam.h, which  * enable parts of this file. They can also optionally provide helpers in  * machine/sf_buf.h  *  * Defines are:  * SFBUF		This machine requires sf_buf hash.  * 			subr_sfbuf.c should be compiled.  * SFBUF_CPUSET		This machine can perform SFB_CPUPRIVATE mappings,  *			that do no invalidate cache on the rest of CPUs.  * SFBUF_NOMD		This machine doesn't have machine/sf_buf.h  *  * SFBUF_OPTIONAL_DIRECT_MAP	Value of this define is used as boolean  *				variable that tells whether machine is  *				capable of direct map or not at runtime.  * SFBUF_MAP		This machine provides its own sf_buf_map() and  *			sf_buf_unmap().  * SFBUF_PROCESS_PAGE	This machine provides sf_buf_process_page()  *			function.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SFBUF
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SFBUF_CPUSET
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|sf_buf
block|{
name|LIST_ENTRY
argument_list|(
argument|sf_buf
argument_list|)
name|list_entry
expr_stmt|;
comment|/* list of buffers */
name|TAILQ_ENTRY
argument_list|(
argument|sf_buf
argument_list|)
name|free_entry
expr_stmt|;
comment|/* list of buffers */
name|vm_page_t
name|m
decl_stmt|;
comment|/* currently mapped page */
name|vm_offset_t
name|kva
decl_stmt|;
comment|/* va of mapping */
name|int
name|ref_count
decl_stmt|;
comment|/* usage of this mapping */
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SFBUF_CPUSET
argument_list|)
name|cpuset_t
name|cpumask
decl_stmt|;
comment|/* where mapping is valid */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SFBUF */
end_comment

begin_struct_decl
struct_decl|struct
name|sf_buf
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFBUF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SFBUF_NOMD
end_ifndef

begin_include
include|#
directive|include
file|<machine/sf_buf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SFBUF_OPTIONAL_DIRECT_MAP
end_ifdef

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SFBUF
end_ifdef

begin_function_decl
name|struct
name|sf_buf
modifier|*
name|sf_buf_alloc
parameter_list|(
name|struct
name|vm_page
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_buf_free
parameter_list|(
name|struct
name|sf_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
ifdef|#
directive|ifdef
name|SFBUF_OPTIONAL_DIRECT_MAP
if|if
condition|(
name|SFBUF_OPTIONAL_DIRECT_MAP
condition|)
return|return
operator|(
name|VM_PAGE_TO_PHYS
argument_list|(
operator|(
name|vm_page_t
operator|)
name|sf
argument_list|)
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|sf
operator|->
name|kva
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|vm_page_t
name|sf_buf_page
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SFBUF_OPTIONAL_DIRECT_MAP
if|if
condition|(
name|SFBUF_OPTIONAL_DIRECT_MAP
condition|)
return|return
operator|(
operator|(
name|vm_page_t
operator|)
name|sf
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|sf
operator|->
name|m
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|SFBUF_MAP
end_ifndef

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

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
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFBUF_MAP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SFBUF_CPUSET
argument_list|)
end_if

begin_function_decl
name|void
name|sf_buf_shootdown
parameter_list|(
name|struct
name|sf_buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SFBUF_PROCESS_PAGE
end_ifdef

begin_function_decl
name|boolean_t
name|sf_buf_process_page
parameter_list|(
name|vm_page_t
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|sf_buf
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SFBUF */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|sf_buf
modifier|*
name|sf_buf_alloc
parameter_list|(
name|struct
name|vm_page
modifier|*
name|m
parameter_list|,
name|int
name|pri
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|sf_buf
operator|*
operator|)
name|m
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sf_buf_free
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFBUF */
end_comment

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

