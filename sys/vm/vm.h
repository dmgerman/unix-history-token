begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm.h	8.2 (Berkeley) 12/13/93  *	@(#)vm_prot.h	8.1 (Berkeley) 6/11/93  *	@(#)vm_inherit.h	8.1 (Berkeley) 6/11/93  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_H
end_ifndef

begin_define
define|#
directive|define
name|VM_H
end_define

begin_typedef
typedef|typedef
name|char
name|vm_inherit_t
typedef|;
end_typedef

begin_comment
comment|/* inheritance codes */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_SHARE
value|((vm_inherit_t) 0)
end_define

begin_define
define|#
directive|define
name|VM_INHERIT_COPY
value|((vm_inherit_t) 1)
end_define

begin_define
define|#
directive|define
name|VM_INHERIT_NONE
value|((vm_inherit_t) 2)
end_define

begin_define
define|#
directive|define
name|VM_INHERIT_DEFAULT
value|VM_INHERIT_COPY
end_define

begin_typedef
typedef|typedef
name|u_char
name|vm_prot_t
typedef|;
end_typedef

begin_comment
comment|/* protection codes */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_NONE
value|((vm_prot_t) 0x00)
end_define

begin_define
define|#
directive|define
name|VM_PROT_READ
value|((vm_prot_t) 0x01)
end_define

begin_define
define|#
directive|define
name|VM_PROT_WRITE
value|((vm_prot_t) 0x02)
end_define

begin_define
define|#
directive|define
name|VM_PROT_EXECUTE
value|((vm_prot_t) 0x04)
end_define

begin_define
define|#
directive|define
name|VM_PROT_OVERRIDE_WRITE
value|((vm_prot_t) 0x08)
end_define

begin_comment
comment|/* copy-on-write */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_ALL
value|(VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE)
end_define

begin_define
define|#
directive|define
name|VM_PROT_DEFAULT
value|VM_PROT_ALL
end_define

begin_union_decl
union_decl|union
name|vm_map_object
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
name|union
name|vm_map_object
name|vm_map_object_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_map_entry
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_map_entry
modifier|*
name|vm_map_entry_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_map
modifier|*
name|vm_map_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_object
modifier|*
name|vm_object_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * This is defined in<sys/types.h> for the kernel so that non-vm kernel  * sources (mainly Mach-derived ones such as ddb) don't have to include  * vm stuff.  Defining it there for applications might break things.  * Define it here for "applications" that include vm headers (e.g.,  * genassym).  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is defined in<sys/types.h> for the kernel so that vnode_if.h  * doesn't have to include<vm/vm.h>.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_page
modifier|*
name|vm_page_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Information passed from the machine-independant VM initialization code  * for use by machine-dependant code (mainly for MMU support)  */
end_comment

begin_struct
struct|struct
name|kva_md_info
block|{
name|vm_offset_t
name|buffer_sva
decl_stmt|;
name|vm_offset_t
name|buffer_eva
decl_stmt|;
name|vm_offset_t
name|clean_sva
decl_stmt|;
name|vm_offset_t
name|clean_eva
decl_stmt|;
name|vm_offset_t
name|pager_sva
decl_stmt|;
name|vm_offset_t
name|pager_eva
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|kva_md_info
name|kmi
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|vm_ksubmap_init
parameter_list|(
name|struct
name|kva_md_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_H */
end_comment

end_unit

