begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pmap.h	7.4 (Berkeley) 5/7/91  *	$Id: pmap.h,v 1.2 1993/10/16 16:20:16 rgrimes Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|)
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

