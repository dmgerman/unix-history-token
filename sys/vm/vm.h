begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm.h	7.1 (Berkeley) 5/5/91  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_H
end_ifndef

begin_define
define|#
directive|define
name|VM_H
end_define

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/lock.h>
end_include

begin_include
include|#
directive|include
file|<vm/queue.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_prot.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_inherit.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_statistics.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_comment
comment|/*  * Shareable process virtual address space.  * May eventually be merged with vm_map.  * Several fields are temporary (text, data stuff).  */
end_comment

begin_struct
struct|struct
name|vmspace
block|{
name|struct
name|vm_map
name|vm_map
decl_stmt|;
comment|/* VM address map */
name|struct
name|pmap
name|vm_pmap
decl_stmt|;
comment|/* private physical map */
name|int
name|vm_refcnt
decl_stmt|;
comment|/* number of references */
name|caddr_t
name|vm_shm
decl_stmt|;
comment|/* SYS5 shared memory private data XXX */
comment|/* we copy from vm_startcopy to the end of the structure on fork */
define|#
directive|define
name|vm_startcopy
value|vm_rssize
name|segsz_t
name|vm_rssize
decl_stmt|;
comment|/* current resident set size in pages */
name|segsz_t
name|vm_swrss
decl_stmt|;
comment|/* resident set size before last swap */
name|segsz_t
name|vm_tsize
decl_stmt|;
comment|/* text size (pages) XXX */
name|segsz_t
name|vm_dsize
decl_stmt|;
comment|/* data size (pages) XXX */
name|segsz_t
name|vm_ssize
decl_stmt|;
comment|/* stack size (pages) */
name|caddr_t
name|vm_taddr
decl_stmt|;
comment|/* user virtual address of text XXX */
name|caddr_t
name|vm_daddr
decl_stmt|;
comment|/* user virtual address of data XXX */
name|caddr_t
name|vm_maxsaddr
decl_stmt|;
comment|/* user VA at max stack growth */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|vmspace
modifier|*
name|vmspace_alloc
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|min
operator|,
name|vm_offset_t
name|max
operator|,
name|int
name|pageable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vmspace
modifier|*
name|vmspace_fork
name|__P
argument_list|(
operator|(
expr|struct
name|vmspace
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vmspace_free
name|__P
argument_list|(
operator|(
expr|struct
name|vmspace
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_H */
end_comment

end_unit

