begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	8.1 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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

begin_comment
comment|/*  * Each machine dependent implementation is expected to  * keep certain statistics.  They may do this anyway they  * so choose, but are expected to return the statistics  * in the following structure.  */
end_comment

begin_struct
struct|struct
name|pmap_statistics
block|{
name|long
name|resident_count
decl_stmt|;
comment|/* # of pages mapped (total)*/
name|long
name|wired_count
decl_stmt|;
comment|/* # of pages wired */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pmap_statistics
modifier|*
name|pmap_statistics_t
typedef|;
end_typedef

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

begin_decl_stmt
name|__BEGIN_DECLS
name|void
modifier|*
name|pmap_bootstrap_alloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
comment|/* machine dependent */
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|pmap_change_wiring
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_clear_modify
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_clear_reference
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_collect
name|__P
argument_list|(
operator|(
name|pmap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_copy
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_copy_page
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
name|pmap_t
name|pmap_create
name|__P
argument_list|(
operator|(
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_destroy
name|__P
argument_list|(
operator|(
name|pmap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_enter
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|pmap_extract
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_init
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
name|boolean_t
name|pmap_is_modified
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|pmap_is_referenced
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|pmap_map
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_page_protect
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|vm_prot_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_pageable
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
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
name|pmap_phys_address
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_pinit
name|__P
argument_list|(
operator|(
name|pmap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_protect
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_reference
name|__P
argument_list|(
operator|(
name|pmap_t
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
name|pmap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_remove
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_update
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
name|pmap_zero_page
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMAP_VM_ */
end_comment

end_unit

