begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)vnode_pager.h	7.1 (Berkeley) %G%  */
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

begin_define
define|#
directive|define
name|VNP_PAGING
value|0x01
end_define

begin_comment
comment|/* vnode used for pageout */
end_comment

begin_define
define|#
directive|define
name|VNP_CACHED
value|0x02
end_define

begin_comment
comment|/* vnode is cached */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|vnode_pager_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_pager_t
name|vnode_pager_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnode_pager_dealloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|vnode_pager_getpage
argument_list|()
decl_stmt|,
name|vnode_pager_putpage
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|boolean_t
name|vnode_pager_haspage
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|pagerops
name|vnodepagerops
init|=
block|{
name|vnode_pager_init
block|,
name|vnode_pager_alloc
block|,
name|vnode_pager_dealloc
block|,
name|vnode_pager_getpage
block|,
name|vnode_pager_putpage
block|,
name|vnode_pager_haspage
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VNODE_PAGER_ */
end_comment

end_unit

