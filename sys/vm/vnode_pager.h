begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vnode_pager.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VNODE_PAGER_
end_ifndef

begin_define
define|#
directive|define
name|_VNODE_PAGER_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|vm_object_t
name|vnode_pager_alloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_ooffset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|vnode_pager_lock
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX Generic routines; currently called by badly written FS code; these  * XXX should go away soon.  */
end_comment

begin_function_decl
name|int
name|vnode_pager_generic_getpages
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|vm_page_t
modifier|*
name|m
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|reqpage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vnode_pager_generic_putpages
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|vm_page_t
modifier|*
name|m
parameter_list|,
name|int
name|count
parameter_list|,
name|boolean_t
name|sync
parameter_list|,
name|int
modifier|*
name|rtvals
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VNODE_PAGER_ */
end_comment

end_unit

