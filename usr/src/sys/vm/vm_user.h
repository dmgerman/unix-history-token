begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_user.h	7.2 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Kernel memory management definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_USER_
end_ifndef

begin_define
define|#
directive|define
name|_VM_USER_
end_define

begin_function_decl
name|int
name|vm_allocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_deallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_inherit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_protect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_statistics
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_VM_USER_
end_endif

end_unit

