begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_kern.h	8.1 (Berkeley) 6/11/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_VM_KERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_VM_KERN_H_
end_define

begin_comment
comment|/* Kernel memory management definitions. */
end_comment

begin_decl_stmt
specifier|extern
name|vm_map_t
name|kernel_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_map_t
name|exec_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_map_t
name|pipe_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vmem
modifier|*
name|kernel_arena
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vmem
modifier|*
name|kmem_arena
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vmem
modifier|*
name|buffer_arena
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vmem
modifier|*
name|transient_arena
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vmem
modifier|*
name|memguard_arena
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|swapbkva
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|vm_kmem_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|exec_map_entries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|exec_map_entry_size
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_VM_KERN_H_ */
end_comment

end_unit

