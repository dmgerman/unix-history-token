begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_param.h	8.1 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Machine independent virtual memory parameters.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PARAM_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PARAM_
end_define

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_comment
comment|/*  * This belongs in types.h, but breaks too many existing programs.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/*  *	The machine independent pages are refered to as PAGES.  A page  *	is some number of hardware pages, depending on the target machine.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/*  *	All references to the size of a page should be done with PAGE_SIZE  *	or PAGE_SHIFT.  The fact they are variables is hidden here so that  *	we can easily make them constant if we so desire.  */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|cnt.v_page_size
end_define

begin_comment
comment|/* size of page */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|page_mask
end_define

begin_comment
comment|/* size of page - 1 */
end_comment

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|page_shift
end_define

begin_comment
comment|/* bits to shift for pages */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|vm_size_t
name|page_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|page_shift
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CTL_VM identifiers  */
end_comment

begin_define
define|#
directive|define
name|VM_METER
value|1
end_define

begin_comment
comment|/* struct vmmeter */
end_comment

begin_define
define|#
directive|define
name|VM_LOADAVG
value|2
end_define

begin_comment
comment|/* struct loadavg */
end_comment

begin_define
define|#
directive|define
name|VM_MAXID
value|3
end_define

begin_comment
comment|/* number of valid vm ids */
end_comment

begin_define
define|#
directive|define
name|CTL_VM_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "vmmeter", CTLTYPE_STRUCT }, \ 	{ "loadavg", CTLTYPE_STRUCT }, \ }
end_define

begin_comment
comment|/*   *	Return values from the VM routines.  */
end_comment

begin_define
define|#
directive|define
name|KERN_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|KERN_INVALID_ADDRESS
value|1
end_define

begin_define
define|#
directive|define
name|KERN_PROTECTION_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|KERN_NO_SPACE
value|3
end_define

begin_define
define|#
directive|define
name|KERN_INVALID_ARGUMENT
value|4
end_define

begin_define
define|#
directive|define
name|KERN_FAILURE
value|5
end_define

begin_define
define|#
directive|define
name|KERN_RESOURCE_SHORTAGE
value|6
end_define

begin_define
define|#
directive|define
name|KERN_NOT_RECEIVER
value|7
end_define

begin_define
define|#
directive|define
name|KERN_NO_ACCESS
value|8
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASSEMBLER
end_ifndef

begin_comment
comment|/*  *	Convert addresses to pages and vice versa.  *	No rounding is used.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x))>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)((x)<< PAGE_SHIFT))
end_define

begin_comment
comment|/*  * Round off or truncate to the nearest page.  These will work  * for either addresses or counts (i.e., 1 byte rounds to 1 page).  */
end_comment

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
define|\
value|((vm_offset_t)((((vm_offset_t)(x)) + PAGE_MASK)& ~PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
define|\
value|((vm_offset_t)(((vm_offset_t)(x))& ~PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|num_pages
parameter_list|(
name|x
parameter_list|)
define|\
value|((vm_offset_t)((((vm_offset_t)(x)) + PAGE_MASK)>> PAGE_SHIFT))
end_define

begin_decl_stmt
specifier|extern
name|vm_size_t
name|mem_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of physical memory (bytes) */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|first_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first physical page */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|last_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last physical page */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* out-of-kernel versions of round_page and trunc_page */
end_comment

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
define|\
value|((((vm_offset_t)(x) + (vm_page_size - 1)) / vm_page_size) * vm_page_size)
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
define|\
value|((((vm_offset_t)(x)) / vm_page_size) * vm_page_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASSEMBLER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_PARAM_ */
end_comment

end_unit

