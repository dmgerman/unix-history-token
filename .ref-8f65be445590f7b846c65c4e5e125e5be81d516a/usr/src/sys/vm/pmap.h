begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr.  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)pmap.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Machine address mapping definitions -- machine-independent  *	section.  [For machine-dependent section, see "machine/pmap.h".]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMAP_VM_
end_ifndef

begin_define
define|#
directive|define
name|_PMAP_VM_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"machine/pmap.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_map
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pmap_t
name|pmap_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pmap_t
name|pmap_kernel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_destroy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remove_all
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_copy_on_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_protect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_extract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_collect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_activate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_deactivate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_statistics
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_clear_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_is_referenced
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_redzone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_access
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|pmap_t
name|kernel_pmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|_PMAP_VM_
end_endif

end_unit

