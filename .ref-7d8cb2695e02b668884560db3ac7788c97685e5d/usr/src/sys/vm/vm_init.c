begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_init.c	7.7 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Initialize the Virtual Memory subsystem.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_comment
comment|/*  *	vm_init initializes the virtual memory system.  *	This is done only by the first cpu up.  *  *	The start and end address of physical memory is passed in.  */
end_comment

begin_function
name|void
name|vm_mem_init
parameter_list|()
block|{
specifier|extern
name|vm_offset_t
name|avail_start
decl_stmt|,
name|avail_end
decl_stmt|;
specifier|extern
name|vm_offset_t
name|virtual_avail
decl_stmt|,
name|virtual_end
decl_stmt|;
comment|/* 	 *	Initializes resident memory structures. 	 *	From here on, all physical memory is accounted for, 	 *	and we use only virtual addresses. 	 */
name|vm_set_page_size
argument_list|()
expr_stmt|;
name|vm_page_startup
argument_list|(
operator|&
name|avail_start
argument_list|,
operator|&
name|avail_end
argument_list|)
expr_stmt|;
comment|/* 	 * Initialize other VM packages 	 */
name|vm_object_init
argument_list|(
name|virtual_end
operator|-
name|VM_MIN_KERNEL_ADDRESS
argument_list|)
expr_stmt|;
name|vm_map_startup
argument_list|()
expr_stmt|;
name|kmem_init
argument_list|(
name|virtual_avail
argument_list|,
name|virtual_end
argument_list|)
expr_stmt|;
name|pmap_init
argument_list|(
name|avail_start
argument_list|,
name|avail_end
argument_list|)
expr_stmt|;
name|vm_pager_init
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

