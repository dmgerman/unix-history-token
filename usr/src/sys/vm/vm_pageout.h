begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_pageout.h	8.2 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Header file for pageout daemon.  */
end_comment

begin_comment
comment|/*  *	Exported data structures.  */
end_comment

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
name|simple_lock_data_t
name|vm_pages_needed_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Exported routines.  */
end_comment

begin_comment
comment|/*  *	Signal pageout-daemon and wait for it.  */
end_comment

begin_define
define|#
directive|define
name|VM_WAIT
value|{ \ 			simple_lock(&vm_pages_needed_lock); \ 			thread_wakeup((int)&vm_pages_needed); \ 			thread_sleep((int)&cnt.v_free_count, \&vm_pages_needed_lock, FALSE); \ 			}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|vm_pageout
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pageout_scan
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

