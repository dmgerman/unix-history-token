begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	7.4 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

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

begin_decl_stmt
name|void
name|pmap_pinit
name|__P
argument_list|(
operator|(
expr|struct
name|pmap
operator|*
name|pmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_release
name|__P
argument_list|(
operator|(
expr|struct
name|pmap
operator|*
name|pmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|pmap_page_protect
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

begin_ifndef
ifndef|#
directive|ifndef
name|pmap_kernel
end_ifndef

begin_function_decl
name|pmap_t
name|pmap_kernel
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

