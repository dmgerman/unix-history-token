begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)null.h	8.3 (Berkeley) 8/20/94  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|null_args
block|{
name|char
modifier|*
name|target
decl_stmt|;
comment|/* Target of loopback  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|null_mount
block|{
name|struct
name|mount
modifier|*
name|nullm_vfs
decl_stmt|;
name|struct
name|vnode
modifier|*
name|nullm_rootvp
decl_stmt|;
comment|/* Reference to root null_node */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * A cache of vnode references  */
end_comment

begin_struct
struct|struct
name|null_node
block|{
name|LIST_ENTRY
argument_list|(
argument|null_node
argument_list|)
name|null_hash
expr_stmt|;
comment|/* Hash list */
name|struct
name|vnode
modifier|*
name|null_lowervp
decl_stmt|;
comment|/* VREFed once */
name|struct
name|vnode
modifier|*
name|null_vnode
decl_stmt|;
comment|/* Back pointer */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nullfs_init
name|__P
argument_list|(
operator|(
expr|struct
name|vfsconf
operator|*
name|vfsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|null_node_create
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
name|target
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MOUNTTONULLMOUNT
parameter_list|(
name|mp
parameter_list|)
value|((struct null_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTONULL
parameter_list|(
name|vp
parameter_list|)
value|((struct null_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NULLTOV
parameter_list|(
name|xp
parameter_list|)
value|((xp)->null_vnode)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|null_checkvp
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|char
operator|*
name|fil
operator|,
name|int
name|lno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NULLVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|null_checkvp((vp), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULLVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTONULL(vp)->null_lowervp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|null_bypass
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|null_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

