begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_kern.h	7.4 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Kernel memory management definitions.  */
end_comment

begin_decl_stmt
name|void
name|kmem_init
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|kmem_alloc
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|kmem_alloc_pageable
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kmem_free
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|kmem_suballoc
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|*
operator|,
name|vm_offset_t
operator|*
operator|,
name|vm_size_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|vm_move
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|kmem_alloc_wait
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kmem_free_wakeup
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|kernel_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|mb_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|kmem_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|exec_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|phys_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_map_t
name|buffer_map
decl_stmt|;
end_decl_stmt

end_unit

