begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr., Michael Wayne Young  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_init.c	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Initialize the Virtual Memory subsystem.  */
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_param.h"
end_include

begin_include
include|#
directive|include
file|"lock.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_object.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_map.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_page.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_kern.h"
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
name|virtual_avail
operator|=
name|vm_page_startup
argument_list|(
name|avail_start
argument_list|,
name|avail_end
argument_list|,
name|virtual_avail
argument_list|)
expr_stmt|;
comment|/* 	 * Initialize other VM packages 	 */
name|vm_object_init
argument_list|()
expr_stmt|;
name|vm_map_init
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

