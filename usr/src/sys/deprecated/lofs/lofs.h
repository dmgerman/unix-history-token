begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)lofs.h	8.2 (Berkeley) %G%  *  * $Id: lofs.h,v 1.8 1992/05/30 10:05:43 jsp Exp jsp $  */
end_comment

begin_struct
struct|struct
name|lofs_args
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
name|lofsmount
block|{
name|struct
name|mount
modifier|*
name|looped_vfs
decl_stmt|;
name|struct
name|vnode
modifier|*
name|rootvp
decl_stmt|;
comment|/* Reference to root lofsnode */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|VT_LOFS
end_ifndef

begin_define
define|#
directive|define
name|VT_LOFS
value|VT_UFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A cache of vnode references  */
end_comment

begin_struct
struct|struct
name|lofsnode
block|{
name|struct
name|lofsnode
modifier|*
name|a_forw
decl_stmt|;
comment|/* Hash chain */
name|struct
name|lofsnode
modifier|*
name|a_back
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_lofsvp
decl_stmt|;
comment|/* Aliased vnode - VREFed once */
name|struct
name|vnode
modifier|*
name|a_vnode
decl_stmt|;
comment|/* Back pointer to vnode/lofsnode */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|make_lofs
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
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VFSTOLOFS
parameter_list|(
name|mp
parameter_list|)
value|((struct lofsmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|LOFSP
parameter_list|(
name|vp
parameter_list|)
value|((struct lofsnode *)(vp)->v_data)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOFS_DIAGNOSTIC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|lofs_checkvp
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
name|LOFSVP
parameter_list|(
name|vp
parameter_list|)
value|lofs_checkvp(vp, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOFSVP
parameter_list|(
name|vp
parameter_list|)
value|(LOFSP(vp)->a_lofsvp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|lofs_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|lofs_vfsops
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

