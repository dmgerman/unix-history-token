begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1986, Avadis Tevanian, Jr.  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_pageout.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Header file for pageout daemon.  */
end_comment

begin_include
include|#
directive|include
file|"lock.h"
end_include

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
value|{ \ 			simple_lock(&vm_pages_needed_lock); \ 			thread_wakeup((int)&vm_pages_needed); \ 			thread_sleep((int)&vm_page_free_count, \&vm_pages_needed_lock, FALSE); \ 			}
end_define

end_unit

