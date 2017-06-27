begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: proc.h,v 1.2 1997/04/16 22:57:48 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROC_H_
end_define

begin_comment
comment|/*  * Machine-dependent part of the proc structure  */
end_comment

begin_struct
struct|struct
name|mdthread
block|{
name|int
name|md_spinlock_count
decl_stmt|;
comment|/* (k) */
name|register_t
name|md_saved_msr
decl_stmt|;
comment|/* (k) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdproc
block|{ }
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_define
define|#
directive|define
name|KINFO_PROC32_SIZE
value|816
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|816
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|syscall_args
block|{
name|u_int
name|code
decl_stmt|;
name|struct
name|sysent
modifier|*
name|callp
decl_stmt|;
name|register_t
name|args
index|[
literal|10
index|]
decl_stmt|;
name|int
name|narg
decl_stmt|;
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
file|<machine/pcb.h>
end_include

begin_comment
comment|/* Get the current kernel thread stack usage. */
end_comment

begin_define
define|#
directive|define
name|GET_STACK_USAGE
parameter_list|(
name|total
parameter_list|,
name|used
parameter_list|)
value|do {				\ 	struct thread *td = curthread;					\ 	(total) = td->td_kstack_pages * PAGE_SIZE - sizeof(struct pcb);	\ 	(used) = (char *)td->td_kstack +				\ 	    td->td_kstack_pages * PAGE_SIZE -				\ 	    (char *)&td;						\ } while (0)
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
comment|/* !_MACHINE_PROC_H_ */
end_comment

end_unit

