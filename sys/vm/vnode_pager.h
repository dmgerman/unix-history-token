begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vnode_pager.h	8.1 (Berkeley) 6/11/93  * $Id$  */
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

begin_comment
comment|/*  * VNODE pager private data.  */
end_comment

begin_struct
struct|struct
name|vnpager
block|{
name|int
name|vnp_flags
decl_stmt|;
comment|/* flags */
name|struct
name|vnode
modifier|*
name|vnp_vp
decl_stmt|;
comment|/* vnode */
name|vm_size_t
name|vnp_size
decl_stmt|;
comment|/* vnode current size */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vnpager
modifier|*
name|vn_pager_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VN_PAGER_NULL
value|((vn_pager_t)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VNODE_PAGER_ */
end_comment

end_unit

