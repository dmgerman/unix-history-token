begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_pageout.h	8.2 (Berkeley) 1/12/94  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: vm_pageout.h,v 1.20 1997/02/22 09:48:34 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_VM_PAGEOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_VM_PAGEOUT_H_
end_define

begin_comment
comment|/*  *	Header file for pageout daemon.  */
end_comment

begin_comment
comment|/*  *	Exported data structures.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vm_page_max_wired
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vm_pages_needed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* should be some "event" structure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vm_pageout_pages_needed
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VM_PAGEOUT_ASYNC
value|0
end_define

begin_define
define|#
directive|define
name|VM_PAGEOUT_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|VM_PAGEOUT_FORCE
value|2
end_define

begin_comment
comment|/*  * Swap out requests  */
end_comment

begin_define
define|#
directive|define
name|VM_SWAP_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|VM_SWAP_IDLE
value|2
end_define

begin_comment
comment|/*  *	Exported routines.  */
end_comment

begin_comment
comment|/*  *	Signal pageout-daemon and wait for it.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pagedaemon_wakeup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VM_WAIT
value|vm_wait()
end_define

begin_decl_stmt
specifier|extern
name|void
name|vm_wait
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|vm_pageout_page
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pageout_cluster
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_pageout_flush
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

