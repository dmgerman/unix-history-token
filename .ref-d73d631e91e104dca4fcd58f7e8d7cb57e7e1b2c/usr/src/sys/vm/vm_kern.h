begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr., Michael Wayne Young  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_kern.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Kernel memory management definitions.  */
end_comment

begin_function_decl
name|void
name|kmem_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|kmem_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|kmem_alloc_pageable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kmem_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_map_t
name|kmem_suballoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|vm_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|kmem_alloc_wait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kmem_free_wakeup
parameter_list|()
function_decl|;
end_function_decl

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

