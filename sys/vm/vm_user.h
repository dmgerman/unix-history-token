begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_user.h	7.2 (Berkeley) 4/21/91  *	$Id: vm_user.h,v 1.3 1993/11/07 17:54:29 wollman Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"sys/cdefs.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_param.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_inherit.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_prot.h"
end_include

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pager_struct
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|munmapfd
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_mmap
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_region
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_size_t
modifier|*
parameter_list|,
name|vm_prot_t
modifier|*
parameter_list|,
name|vm_prot_t
modifier|*
parameter_list|,
name|vm_inherit_t
modifier|*
parameter_list|,
name|boolean_t
modifier|*
parameter_list|,
name|struct
name|vm_object
modifier|*
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_allocate_with_pager
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|,
name|struct
name|pager_struct
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_allocate
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_deallocate
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_inherit
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_inherit_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_protect
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|,
name|vm_prot_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_inherit.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_prot.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|vm_allocate
name|__P
argument_list|(
operator|(
name|void
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
name|int
name|vm_deallocate
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_inherit
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|vm_inherit_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_protect
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|boolean_t
operator|,
name|vm_prot_t
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

begin_comment
comment|/* not KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_USER_ */
end_comment

end_unit

